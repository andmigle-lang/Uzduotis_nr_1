// Uzduotis_nr_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cctype> //funckijai isdigit(), nes kai kuriems kompiliatoriams neveikia
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::stoi;
using std::ifstream;
using std::ofstream;
using std::accumulate;
using std::to_string;
using std::stringstream;

struct Studentas {
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    double med;
};

Studentas Stud_iv(int k);
Studentas Stud_iv_atsitiktinai(int k);
float Rask_mediana(vector <int> paz);
void skaitymas(vector <Studentas>& Grupe);
bool palyginimas(Studentas pirm, Studentas antr);
void rasymas(vector <Studentas> Grupe, string spr);
bool isNumber(string s);
void failu_generavimas(int k);
void studentu_rusiavimas(const vector <Studentas>& Grupe, int k);
void skaitymas_is_genruoto_failo(vector<Studentas>& Grupe, const string& failo_vardas);


int main()
{
    /*
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
    sort(Grupe.begin(), Grupe.end(), palyginimas);
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
    rasymas(Grupe, spr);*/
    /*
    for (int i=3; i<=7; i++){
        failu_generavimas(pow(10, i));
    }
    */
    vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    for (int size : sizes) {
        failu_generavimas(size);
    }
    for (int size : sizes) {
        string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
        vector <Studentas> Grupe1;
        skaitymas_is_failo(Grupe1, input_file);
        studentu_rusiavimas(Grupe1, size);
    }
    return 0;
}

float Rask_mediana(vector <int> paz) {
    float mediana;
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0)
        mediana = (float(paz[(paz.size() / 2) - 1]) + float(paz[paz.size() / 2])) / 2;
    else
        mediana = float(paz[(paz.size() / 2)]);
    return mediana;
}

Studentas Stud_iv(int k) {
    int laik_paz, sum = 0;
    float mediana;
    Studentas Pirmas;
    string laik_paz_pr;
    cout << "Iveskite studento nr. " << k << " duomenis: " << endl;
    cout << "Vardas: "; cin >> Pirmas.var;
    cout << "Pavarde: "; cin >> Pirmas.pav;
    cout << "Veskite studento pazymius (1-10). 0 ivedimas zymi pazymiu pabaiga: " << endl;
    int n = 1;
    while (true) {
        cout << "Pazymys nr. " << n << ": ";
        cin >> laik_paz_pr;
        if (isNumber(laik_paz_pr) && stoi(laik_paz_pr) <= 10 && stoi(laik_paz_pr) >= 1) {
            laik_paz = stoi(laik_paz_pr);
            Pirmas.paz.push_back(laik_paz);
            sum += laik_paz;
            n++;
        }
        else if (isNumber(laik_paz_pr) && stoi(laik_paz_pr) == 0) {
            break;
        }
        else {
            cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10 arba 0 uzbaigti). Veskite studento pazymius (1-10). 0 ivedimas zymi pazymiu pabaiga: " << endl;
        }
    }
    cout << "Iveskite egzamino pazymi: ";
    string egz_pr;
    while (true) {
        cin >> egz_pr;
        if (isNumber(egz_pr) && stoi(egz_pr) >= 1 && stoi(egz_pr) <= 10) {
            Pirmas.egz = stoi(egz_pr);
            break;
        }
        else {
            cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Iveskite egzamino pazymi: ";
        }
    }
    if (Pirmas.paz.size() == 0) {
        Pirmas.gal = Pirmas.egz * 0.6;
        Pirmas.med = Pirmas.egz * 0.6;
    }
    else {
        Pirmas.gal = double(sum) / double(Pirmas.paz.size()) * 0.4 + Pirmas.egz * 0.6;
        mediana = Rask_mediana(Pirmas.paz);
        Pirmas.med = mediana * 0.4 + Pirmas.egz * 0.6;
    }
    return Pirmas;
}

Studentas Stud_iv_atsitiktinai(int k) {
    int laik_paz, sum = 0;
    float mediana;
    Studentas Pirmas;
    cout << "Iveskite studento nr. " << k << " duomenis: " << endl;
    cout << "Vardas: "; cin >> Pirmas.var;
    cout << "Pavarde: "; cin >> Pirmas.pav;
    srand(time(0));
    int pazymiu_sk = rand() % 21;
    cout << "Atsitiktinai generuojamu pazymiu skaicius (gali buti nuo 0 iki 20 pazymiu): " << pazymiu_sk << endl;
    cout << "Isvedami atsitiktinai generuojami pazymiai: " << endl;

    for (int i = 0; i < pazymiu_sk; i++) {
        laik_paz = (rand() % 10) + 1;
        cout << "Generuotas pazymys nr. " << i + 1 << ": " << laik_paz << endl;
        Pirmas.paz.push_back(laik_paz);
        sum += laik_paz;
    }
    int egzamino_paz = (rand() % 10) + 1;
    cout << "Isvedamas sugeneruotas egzamino pazymys: " << egzamino_paz << endl;
    Pirmas.egz = egzamino_paz;
    if (Pirmas.paz.size() == 0) {
        Pirmas.gal = Pirmas.egz * 0.6;
        Pirmas.med = Pirmas.egz * 0.6;
    }
    else {
        Pirmas.gal = double(sum) / double(pazymiu_sk) * 0.4 + Pirmas.egz * 0.6;
        mediana = Rask_mediana(Pirmas.paz);
        Pirmas.med = mediana * 0.4 + Pirmas.egz * 0.6;
    }
    return Pirmas;
}

void skaitymas(vector <Studentas>& Grupe) {
    string failo_vardas;
    ifstream F;
    while (true) {
        cout << "Iveskite failo varda: ";
        cin >> failo_vardas;
        F.open(failo_vardas);
        if (F) {
            break;
        }
        else {
            string pasirink;
            while (true) {
                cout << "Failo nepavyko atidaryti. Ar norite bandyti dar karta (rasykite 1), ar norite uzbaigti programa (rasykite 2)? ";
                cin >> pasirink;
                if (pasirink == "1") {
                    break;
                }
                else if (pasirink == "2") {
                    exit(0);
                }
                else {
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
                }
            }
        }
    }
    string pavadinimai;
    getline(F, pavadinimai);
    Studentas Pirmas;
    int skait = 0;
    while (F.peek() != EOF) {
        F >> Pirmas.var >> Pirmas.pav;
        skait++;
        float mediana;
        int sum;
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

bool palyginimas(Studentas pirm, Studentas antr) {
    return pirm.var < antr.var;
}

void rasymas(vector <Studentas> Grupe, string spr) {
    ofstream R("rezultatai.txt");
    if (!R) {
        cout << "Klaida: Nepavyko sukurti arba atidaryti failo 'rezultatai.txt'. Patikrinkite direktorija ir teises." << endl;
        return;
    }
    if (spr == "vidurki") {
        R << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
        for (int i = 0; i < 58; i++) {
            R << "-";
        }
    }
    else if (spr == "mediana") {
        R << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
        for (int i = 0; i < 58; i++) {
            R << "-";
        }
    }
    else if (spr == "abu") {
        R << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
        for (int i = 0; i < 76; i++) {
            R << "-";
        }
    }

    R << endl;
    if (spr == "vidurki") {
        for (auto Past : Grupe)
            R << setw(20) << left << Past.var << setw(20) << left << Past.pav << setw(18) << left << fixed << setprecision(2) << Past.gal << endl;
    }
    else if (spr == "mediana") {
        for (auto Past : Grupe)
            R << setw(20) << left << Past.var << setw(20) << left << Past.pav << setw(18) << left << fixed << setprecision(2) << Past.med << endl;
    }
    else if (spr == "abu") {
        for (auto Past : Grupe)
            R << setw(20) << left << Past.var << setw(20) << left << Past.pav << setw(18) << left << fixed << setprecision(2) << Past.gal << setw(18) << left << fixed << setprecision(2) << Past.med << endl;
    }

    R.close();
}

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

/*void failu_generavimas(int k) {
    string k1 = to_string(k);
    string failo_vardas = "Generuoti_studentai" + k1 + ".txt";
    ofstream G(failo_vardas);
    string vardas, pavarde;
    srand(time(0));
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
    G << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for (int i = 0; i < paz_sk; i++) {
        G << setw(8) << right << "ND" + to_string(i + 1);
    }
    G << setw(8) << right << "Egz." << endl;
    for (int i = 0; i < k; i++) {
        vardas = "Vardas" + to_string(i + 1);
        pavarde = "Pavarde" + to_string(i + 1);
        G << setw(20) << left << vardas << setw(20) << left << pavarde;
        for (int i = 0; i <= paz_sk; i++) {
            G << setw(8) << right << (rand() % 10) + 1;
        }
        G << endl;
    }
    G.close();
}
*/

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
    for (int i = 0; i < 50; i++) {
        vargsiukai_buffer << "-";
    }
    for (const auto& studentas : vargsiukai) {
        vargsiukai_buffer << setw(20) << left << studentas.var << setw(20) << left << studentas.pav << setw(18) << left << fixed << setprecision(2) << studentas.gal << endl;
    }

    kietiakai_buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 50; i++) {
        kietiakai_buffer << "-";
    }
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
    cout << "Kietiakiai (>= 5.0): " << kietiakai.size() << " studentai" << endl;
}

void skaitymas_is_genruoto_failo(vector<Studentas>& Grupe, const string& failo_vardas) {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



