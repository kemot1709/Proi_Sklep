#include "Pracownik.h"

Pracownik::Pracownik(int n) {
    pracownik_ID = n;
    pracownik_zajecie = en_p_wolne;
    pracownik_stan [0] = n % 3;
    pracownik_stan [1] = 0;
    pracownik_stan [2] = 0;
    pracownik_stan [3] = 0;
    pracownik_kasa = 0;
}

int Pracownik::pracownik_f_ID() {
    return pracownik_ID;
}

int Pracownik::pracownik_f_zajecie() {
    return pracownik_zajecie;
}

int Pracownik::pracownik_f_stan(int n) {
    return pracownik_stan[n];
}

void Pracownik::pracownik_zmien_zajecie(p_zajecie zaj) {
    pracownik_zajecie = zaj;
}

void Pracownik::pracownik_nowy_dzien() {
    pracownik_zajecie = en_p_wolne;
    pracownik_stan[0] = (pracownik_stan [0] + 1) % 3;
    pracownik_stan [1] = 0;
    pracownik_stan [2] = 0;
    pracownik_stan [3] = 0;
    pracownik_kasa = 0;
}

void Pracownik::pracownik_zmien_stan(int i, int n) {
    pracownik_stan[i] = pracownik_stan[i] + n;
}

int Pracownik::pracownik_f_kasa() {
    return pracownik_kasa;
}

void Pracownik::pracownik_zmien_kasa(int n) {
    pracownik_kasa = n;
}
