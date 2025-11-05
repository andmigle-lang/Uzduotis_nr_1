#include "palyginimas.h"

bool palyginimas_vardas(const Studentas& pirm, const Studentas& antr) {
    return pirm.var < antr.var;
}

bool palyginimas_pavarde(const Studentas& pirm, const Studentas& antr) {
    return pirm.pav < antr.pav;
}

bool palyginimas_galutinis(const Studentas& pirm, const Studentas& antr) {
    return pirm.gal < antr.gal;
}

bool palyginimas_2_strategija(const Studentas& pirm, const Studentas& antr) {
    return pirm.gal > antr.gal;
}
