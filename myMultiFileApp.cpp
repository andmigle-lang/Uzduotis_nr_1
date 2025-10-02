// Uzduotis_nr_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "palyginimas.h"
#include "Generuoti_failai.h"
#include "is_number.h"
#include "mediana.h"
#include "Simple.h"
#include "Studentas.h"
#include <chrono>

using std::cin;
using std::cout;
using std::to_string;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(){
    string d_pr;
    int d;
    cout << "Ar norite dirbti su studentai.txt failais (rasyti 1), ar generuoti naujus failus (5 failai su nuo 1000 iki 10000000 studentu) (rasyti 2): ";
    while (true) {
        cin >> d_pr;
        if (isNumber(d_pr)) {
            if (stoi(d_pr) == 1 || stoi(d_pr) == 2) {
                d = stoi(d_pr);
                break;
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
            }
        }
        else {
            cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
        }
    }
    if (d == 1) {
        vector <Studentas> Grupe;
        string pasirinkimas_pries_pr;
        int pasirinkimas_pries;
        cout << "Pasirinkite, ar norite, kad duomenys butu skaitomi is failo (rasyti 1), ar ne (rasyti 2): ";
        while (true) {
            cin >> pasirinkimas_pries_pr;
            if (isNumber(pasirinkimas_pries_pr)) {
                if (stoi(pasirinkimas_pries_pr) == 1 || stoi(pasirinkimas_pries_pr) == 2) {
                    pasirinkimas_pries = stoi(pasirinkimas_pries_pr);
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
                }
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
            }
        }
        if (pasirinkimas_pries == 1) {
            skaitymas(Grupe);
        }
        else {
            cout << "Kiek studentu grupeje? ";
            string m_pr;
            int m;
            while (true) {
                cin >> m_pr;
                if (isNumber(m_pr)) {
                    if (stoi(m_pr) >= 0) {
                        m = stoi(m_pr);
                        break;
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                    }
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                }
            }
            string pasirinkimas_pr;
            int pasirinkimas;
            for (auto z = 0; z < m; z++) {
                cout << "Pasirinkite, ar pazymius studentui nr. " << z + 1 << " ivesite rankomis (rasyti 1), ar norite, kad jie butu generuoti atsitiktinai (rasyti 2): ";
                while (true) {
                    cin >> pasirinkimas_pr;
                    if (isNumber(pasirinkimas_pr)) {
                        if (stoi(pasirinkimas_pr) == 1 || stoi(pasirinkimas_pr) == 2) {
                            pasirinkimas = stoi(pasirinkimas_pr);
                            break;
                        }
                        else {
                            cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
                        }
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
                    }
                }
                if (pasirinkimas == 1) {
                    Grupe.push_back(Stud_iv(z + 1));
                }
                else {
                    Grupe.push_back(Stud_iv_atsitiktinai(z + 1));
                }
            }
        }
        sort(Grupe.begin(), Grupe.end(), palyginimas_vardas);
        string spr;
        string spr_pr;
        cout << "Ar isvesti galutini vidurki/mediana/abu (irasykite zodi mazosiomis raidemis)? ";
        while (true) {
            cin >> spr_pr;
            if (spr_pr == "vidurki" || spr_pr == "mediana" || spr_pr == "abu") {
                spr = spr_pr;
                break;
            }
            else {
                cout << "Ivedete neteisinga duomeni. Iveskite tik viena is siu zodziu: vidurki/mediana/abu: ";
            }
        }
        rasymas(Grupe, spr);
    }
    else {
        vector<int> sizes = { 1000, 10000, 100000, 1000000, 10000000 };
        for (int size : sizes) {
            failu_generavimas(size);
        }

        vector<double> vid_skaitymas(sizes.size(), 0.0);
        vector<double> vid_rusiavimas(sizes.size(), 0.0);
        vector<double> vid_dalijimas(sizes.size(), 0.0);
        vector<double> vid_vargsiukai(sizes.size(), 0.0);
        vector<double> vid_kietiakai(sizes.size(), 0.0);
        int a = sizes.size();
        const int runs = 3;
        for (int j = 0; j < runs; ++j) {
            cout << j+1 << " iteracija:" << endl;
            
            
            for (int i = 0; i < a; ++i) {
                int size = sizes[i];
                string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
                vector<Studentas> Grupe1;

                double diff_skaitymas1 = 0.0;
                double diff_rusiavimas1 = 0.0;
                double diff_irasu_dalijimo1 = 0.0;
                double diff_irasymas_i_vargsiuku_faila1 = 0.0;
                double diff_irasymas_i_kietiaku_faila1 = 0.0;

                skaitymas_is_genruoto_failo(Grupe1, input_file, diff_skaitymas1);
                studentu_rusiavimas(Grupe1, size,
                    diff_rusiavimas1,
                    diff_irasu_dalijimo1,
                    diff_irasymas_i_vargsiuku_faila1,
                    diff_irasymas_i_kietiaku_faila1);

                vid_skaitymas[i] += diff_skaitymas1;
                vid_rusiavimas[i] += diff_rusiavimas1;
                vid_dalijimas[i] += diff_irasu_dalijimo1;
                vid_vargsiukai[i] += diff_irasymas_i_vargsiuku_faila1;
                vid_kietiakai[i] += diff_irasymas_i_kietiaku_faila1;
                cout << size<< " irasu testo laikas: " << diff_skaitymas1+ diff_rusiavimas1 + diff_irasu_dalijimo1+ diff_irasymas_i_vargsiuku_faila1+ diff_irasymas_i_kietiaku_faila1 << " s" << endl;
            }
            
        }

        cout << "VIDURKIAI IS " << runs << " ITERACIJU: " << endl;
        for (int i = 0; i < a; ++i) {
            cout << "\nFailo dydis: " << sizes[i] << endl;
            cout << "Skaitymo vidurkis: " << (vid_skaitymas[i] / runs) << " s" << endl;
            cout << "Rusiavimo vidurkis: " << (vid_rusiavimas[i] / runs) << " s" << endl;
            cout << "Dalijimo vidurkis: " << (vid_dalijimas[i] / runs) << " s" << endl;
            cout << "Vargsiuku irasymo vidurkis: " << (vid_vargsiukai[i] / runs) << " s" << endl;
            cout << "Kietiaku irasymo vidurkis: " << (vid_kietiakai[i] / runs) << " s" << endl;
        }
    }
    return 0;
}