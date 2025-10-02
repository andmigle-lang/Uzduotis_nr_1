#include "palyginimas.h"

bool palyginimas_vardas(Studentas pirm, Studentas antr) {
    return pirm.var < antr.var;
}

bool palyginimas_pavarde(Studentas pirm, Studentas antr) {
    return pirm.pav < antr.pav;
}

bool palyginimas_galutinis(Studentas pirm, Studentas antr) {
    return pirm.gal < antr.gal;
}