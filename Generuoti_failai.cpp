#include "Generuoti_failai.h"
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

void failu_generavimas(int k) {
    string failo_vardas = "Generuoti_studentai" + to_string(k) + ".txt";
    string outputas;
    stringstream my_buffer;
    string vardas, pavarde;
    srand(time(0));
    cout << "Generuojamas failas " + failo_vardas << endl;
    cout << "Kiek pazymiu sugeneruoti (nuo 1 iki 20)? ";
    string paz_sk_pr;
    int paz_sk;
    while (true) {
        cin >> paz_sk_pr;
        if (isNumber(paz_sk_pr)) {
            if (stoi(paz_sk_pr) <= 20 && stoi(paz_sk_pr) >= 1) {
                paz_sk = stoi(paz_sk_pr);
                break;
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik sveikus skaicius nuo 1 iki 20): ";
            }
        }
        else {
            cout << "Ivedete neteisinga duomeni (galima vesti tik sveikus skaicius nuo 1 iki 20): ";
        }
    }
    my_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for (int i = 0; i < paz_sk; i++) {
        my_buffer << setw(8) << right << "ND" + to_string(i + 1);
    }
    my_buffer << setw(8) << right << "Egz." << endl;
    for (int i = 0; i < k; i++) {
        vardas = "Vardas" + to_string(i + 1);
        pavarde = "Pavarde" + to_string(i + 1);
        my_buffer << setw(20) << left << vardas << setw(20) << left << pavarde;
        for (int i = 0; i <= paz_sk; i++) {
            my_buffer << setw(8) << right << (rand() % 10) + 1;
        }
        my_buffer << endl;
    }
    outputas = my_buffer.str();
    ofstream G(failo_vardas);
    G << outputas;
    G.close();
}

void studentu_rusiavimas(const vector <Studentas>& Grupe, int k) {
    vector <Studentas> vargsiukai;
    vector <Studentas> kietiakai;

    for (const auto& studentas : Grupe) {
        if (studentas.gal < 5.0) {
            vargsiukai.push_back(studentas);
        }
        else {
            kietiakai.push_back(studentas);
        }
    }
    stringstream vargsiukai_buffer, kietiakai_buffer;
    vargsiukai_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 58; i++) {
        vargsiukai_buffer << "-";
    }
    vargsiukai_buffer << endl;
    for (const auto& studentas : vargsiukai) {
        vargsiukai_buffer << setw(20) << left << studentas.var << setw(20) << left << studentas.pav << setw(18) << left << fixed << setprecision(2) << studentas.gal << endl;
    }

    kietiakai_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 58; i++) {
        kietiakai_buffer << "-";
    }
    kietiakai_buffer << endl;
    for (const auto& studentas : kietiakai) {
        kietiakai_buffer << setw(20) << left << studentas.var << setw(20) << left << studentas.pav << setw(18) << left << fixed << setprecision(2) << studentas.gal << endl;
    }
    string failo_vardas1 = "vargsiukai" + to_string(k) + ".txt";
    ofstream vargsiukai_failas(failo_vardas1);
    vargsiukai_failas << vargsiukai_buffer.str();
    vargsiukai_failas.close();

    string failo_vardas2 = "kietiakai" + to_string(k) + ".txt";
    ofstream kietiakai_failas(failo_vardas2);
    kietiakai_failas << kietiakai_buffer.str();
    kietiakai_failas.close();

    cout << "Surusiuota studentu:" << endl;
    cout << "Vargsai (< 5.0): " << vargsiukai.size() << " studentai" << endl;
    cout << "Kietiakai (>= 5.0): " << kietiakai.size() << " studentai" << endl;
}

void skaitymas_is_genruoto_failo(vector<Studentas>& Grupe, const string& failo_vardas) {
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
    cout << "Duomenys nuskaityti is failo. Rastas studentu skaicius: " << Grupe.size() << endl;
}