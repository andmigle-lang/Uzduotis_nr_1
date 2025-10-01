#include "Simple.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::setw;


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