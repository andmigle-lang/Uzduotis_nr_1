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

void failu_generavimas(int k);
void studentu_rusiavimas(const vector <Studentas>& Grupe, int k);
void skaitymas_is_genruoto_failo(vector<Studentas>& Grupe, const string& failo_vardas);