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
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

void failu_generavimas(int k, int pazymiu_sk) {

    string failo_vardas = "Generuoti_studentai" + to_string(k) + ".txt";
    string outputas;
    stringstream my_buffer;
    string vardas, pavarde;
    //srand(time(0));
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);
    cout << "\nGeneruojamas failas " + failo_vardas << endl;
    int paz_sk = pazymiu_sk;
    auto start = high_resolution_clock::now();
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
            my_buffer << setw(8) << right << dist(mt);
        }
        my_buffer << endl;
    }
    outputas = my_buffer.str();
    duration<double> diff = high_resolution_clock::now() - start;
    cout << "Irasymas i buferi failui "<<failo_vardas<<" uztruko: " << diff.count() << endl;
    auto start2 = high_resolution_clock::now();
    ofstream G(failo_vardas);
    G << outputas;
    G.close();
    duration<double> diff2 = high_resolution_clock::now() - start2;
    cout << "Irasymas i faila failui " << failo_vardas << "  uztruko: " << diff2.count() << endl;
}

bool partition_palyginimas(const Studentas& s) {
    return s.gal >= 5.0;
}
