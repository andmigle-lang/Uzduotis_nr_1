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

void failu_generavimas(int k);
void studentu_rusiavimas(vector <Studentas>& Grupe, int k, double& diff_rusiavimas1, double& diff_irasu_dalijimo1, double& diff_irasymas_i_vargsiuku_faila1, double& diff_irasymas_i_kietiaku_faila1, int i);
void skaitymas_is_genruoto_failo(vector<Studentas>& Grupe, const string& failo_vardas, double& diff_skaitymas1);
