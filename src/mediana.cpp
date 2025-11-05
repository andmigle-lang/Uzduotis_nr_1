#include "mediana.h"

float Rask_mediana(vector <int> paz) {
    float mediana;
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0)
        mediana = (float(paz[(paz.size() / 2) - 1]) + float(paz[paz.size() / 2])) / 2;
    else
        mediana = float(paz[(paz.size() / 2)]);
    return mediana;
}
