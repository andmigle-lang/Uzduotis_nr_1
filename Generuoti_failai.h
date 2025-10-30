#pragma once
#include <iostream>
#include "Studentas.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include "mediana.h"
#include "is_number.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "palyginimas.h"
#include <random>

#include <vector>
#include <list>
#include <algorithm>    // for sort
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::stringstream;
using std::left;
using std::right;
using std::ofstream;
using std::ifstream;
using std::accumulate;
using std::to_string;
using std::fixed;
using std::setprecision;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

void failu_generavimas(int k, int pazymiu_sk);

template <typename T> void pagalbine_funkcija(vector <T>& Grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_vardas);
    }
    else if (pasirinkimas == 2) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_pavarde);
    }
    else if (pasirinkimas == 3) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_galutinis);
    }
}

template <typename T> void pagalbine_funkcija(list <T>& Grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        Grupe.sort(palyginimas_vardas);
    }
    else if (pasirinkimas == 2) {
        Grupe.sort(palyginimas_pavarde);
    }
    else if (pasirinkimas == 3) {
        Grupe.sort(palyginimas_galutinis);
    }
}

template <typename T> void studentu_rusiavimas(T& Grupe, int k,
	double& diff_rusiavimas1, double& diff_irasu_dalijimo1,
	double& diff_irasymas_i_vargsiuku_faila1,
	double& diff_irasymas_i_kietiaku_faila1, int i) {
    int pasirinkimas = i;

    auto start_rusiavimas = high_resolution_clock::now();
    pagalbine_funkcija(Grupe, pasirinkimas);
    duration<double> diff_rusiavimas = high_resolution_clock::now() - start_rusiavimas;

    cout << k << " irasu rusiavimo didejimo tvarka laikas, su sort funkcija: " << diff_rusiavimas.count() << " s" << endl;
    diff_rusiavimas1 = diff_rusiavimas.count();
    T vargsiukai;
    T kietiakai;

    auto start_irasu_dalijimo = high_resolution_clock::now();
    for (const auto& studentas : Grupe) {
        if (studentas.gal < 5.0) {
            vargsiukai.push_back(studentas);
        }
        else {
            kietiakai.push_back(studentas);
        }
    }
    duration<double> diff_irasu_dalijimo = high_resolution_clock::now() - start_irasu_dalijimo;
    cout << k << " irasu dalijimo i dvi grupes laikas: " << diff_irasu_dalijimo.count() << " s" << endl;
    diff_irasu_dalijimo1 = diff_irasu_dalijimo.count();

    auto start_irasymas_i_vargsiuku_faila = high_resolution_clock::now();
    stringstream vargsiukai_buffer, kietiakai_buffer;
    vargsiukai_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 58; i++) {
        vargsiukai_buffer << "-";
    }
    vargsiukai_buffer << endl;
    for (const auto& studentas : vargsiukai) {
        vargsiukai_buffer << setw(20) << left << studentas.var << setw(20) << left << studentas.pav << setw(18) << left << fixed << setprecision(2) << studentas.gal << endl;
    }

    string failo_vardas1 = "vargsiukai" + to_string(k) + ".txt";
    ofstream vargsiukai_failas(failo_vardas1);
    vargsiukai_failas << vargsiukai_buffer.str();
    vargsiukai_failas.close();
    duration<double> diff_irasymas_i_vargsiuku_faila = high_resolution_clock::now() - start_irasymas_i_vargsiuku_faila;
    cout << k << " irasu irasymo i vargsiuku faila laikas: " << diff_irasymas_i_vargsiuku_faila.count() << " s" << endl;
    diff_irasymas_i_vargsiuku_faila1 = diff_irasymas_i_vargsiuku_faila.count();

    auto start_irasymas_i_kietiaku_faila = high_resolution_clock::now();
    kietiakai_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 58; i++) {
        kietiakai_buffer << "-";
    }
    kietiakai_buffer << endl;
    for (const auto& studentas : kietiakai) {
        kietiakai_buffer << setw(20) << left << studentas.var << setw(20) << left << studentas.pav << setw(18) << left << fixed << setprecision(2) << studentas.gal << endl;
    }

    string failo_vardas2 = "kietiakai" + to_string(k) + ".txt";
    ofstream kietiakai_failas(failo_vardas2);
    kietiakai_failas << kietiakai_buffer.str();
    kietiakai_failas.close();
    duration<double> diff_irasymas_i_kietiaku_faila = high_resolution_clock::now() - start_irasymas_i_kietiaku_faila;
    cout << k << " irasu irasymo i kietiaku faila laikas: " << diff_irasymas_i_kietiaku_faila.count() << " s" << endl;
    diff_irasymas_i_kietiaku_faila1 = diff_irasymas_i_kietiaku_faila.count();

    cout << "Surusiuota studentu:" << endl;
    cout << "Vargsai (< 5.0): " << vargsiukai.size() << " studentai" << endl;
    cout << "Kietiakai (>= 5.0): " << kietiakai.size() << " studentai" << endl;
}

template <typename T> void skaitymas_is_generuoto_failo(T& Grupe, const string& failo_vardas, double& diff_skaitymas1) {
    auto start_skaitymas = high_resolution_clock::now();
    ifstream F(failo_vardas);
    if (!F) {
        cout << "Klaida: Nepavyko atidaryti failo " << failo_vardas << endl;
        exit(0);
    }
    string pavadinimai;
    getline(F, pavadinimai);
    Studentas Pirmas;
    int skait = 0;
    while (F.peek() != EOF) {
        F >> Pirmas.var >> Pirmas.pav;
        if (F.fail() || Pirmas.var.size() == 0 || Pirmas.pav.size() == 0) {
            F.clear();
            break;
        }
        skait++;
        float mediana;
        int sum = 0;
        Pirmas.paz.clear();
        while (F.peek() != '\n' && F.peek() != EOF) {
            int pazymys;
            string pazymys_pr;
            F >> pazymys_pr;
            if (isNumber(pazymys_pr)) {
                if (stoi(pazymys_pr) >= 1 && stoi(pazymys_pr) <= 10) {
                    pazymys = stoi(pazymys_pr);
                    Pirmas.paz.push_back(pazymys);
                }
                else {
                    cout << "Studento nr. " << skait << " pazymiuose buvo klaida (ne sveikasis skaicius nuo 1 iki 10): " << pazymys_pr << ". Klaida pasalinta is skaiciavimu" << endl;
                }
            }
            else {
                cout << "Studento nr. " << skait << " pazymiuose buvo klaida (ne sveikasis skaicius nuo 1 iki 10): " << pazymys_pr << ". Klaida pasalinta is skaiciavimu" << endl;
            }
        }
        if (Pirmas.paz.size() != 0) {
            Pirmas.egz = Pirmas.paz.back();
            Pirmas.paz.pop_back();
        }
        else {
            Pirmas.egz = 0;
        }
        sum = accumulate(Pirmas.paz.begin(), Pirmas.paz.end(), 0);
        int n;
        n = Pirmas.paz.size();
        if (Pirmas.paz.size() == 0) {
            Pirmas.gal = Pirmas.egz * 0.6;
            Pirmas.med = Pirmas.egz * 0.6;
        }
        else {
            Pirmas.gal = double(sum) / double(n) * 0.4 + Pirmas.egz * 0.6;
            mediana = Rask_mediana(Pirmas.paz);
            Pirmas.med = mediana * 0.4 + Pirmas.egz * 0.6;
        }
        Grupe.push_back(Pirmas);
        Pirmas.paz.clear();
    }
    F.close();
    duration<double> diff_skaitymas = high_resolution_clock::now() - start_skaitymas;
    cout << "\nFailo is " << Grupe.size() << " irasu nuskaitymo laikas: " << diff_skaitymas.count() << " s" << endl;
    diff_skaitymas1 = diff_skaitymas.count();
    cout << "Duomenys nuskaityti is failo. Rastas studentu skaicius: " << Grupe.size() << endl;
}
