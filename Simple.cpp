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

