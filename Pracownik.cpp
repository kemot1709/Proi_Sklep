#include "Pracownik.h"

Pracownik::Pracownik(int n) {
    pracownik_ID = n;
    pracownik_zajecie = en_p_wolne;
    pracownik_stan [0] = n % 3;
    pracownik_stan [1] = 0;
    pracownik_stan [2] = 0;
}

int Pracownik::pracownik_f_ID() {
    return pracownik_ID;
}

int Pracownik::pracownik_f_zajecie() {
    return pracownik_zajecie;
}

void Pracownik::pracownik_zmien_zajecie(p_zajecie zaj){
    pracownik_zajecie=zaj;
}

void Pracownik::pracownik_nowy_dzien() {
    pracownik_zajecie = en_p_wolne;
    pracownik_stan[0] = (pracownik_stan [0]++) % 3;
}
