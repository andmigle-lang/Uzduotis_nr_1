// Uzduotis_nr_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "palyginimas.h"
#include "Generuoti_failai.h"
#include "is_number.h"
#include "mediana.h"
#include "Simple.h"
#include "Studentas.h"

using std::cin;
using std::cout;

int main()
{
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
        rasymas(Grupe, spr);
    }
    else {
        failu_generavimas(1000);
        vector <Studentas> Grupe1;
        skaitymas_is_genruoto_failo(Grupe1, "Generuoti_studentai1000.txt");
        studentu_rusiavimas(Grupe1, 1000);
        //vector<int> sizes = { 1000, 10000, 100000, 1000000, 10000000 };
        //for (int size : sizes) {
        //    failu_generavimas(size);
        //}
        //for (int size : sizes) {
        //    string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
        //    vector <Studentas> Grupe1;
        //    skaitymas_is_genruoto_failo(Grupe1, input_file);
        //    studentu_rusiavimas(Grupe1, size);
        //}
    }
    return 0;
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
