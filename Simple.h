#pragma once
#include "Studentas.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <numeric>
#include "is_number.h"
#include "mediana.h"
#include <cstdlib>
#include <ctime>

Studentas Stud_iv(int k);
Studentas Stud_iv_atsitiktinai(int k);
void skaitymas(vector <Studentas>& Grupe);
void rasymas(vector <Studentas> Grupe, string spr);