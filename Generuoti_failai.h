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
