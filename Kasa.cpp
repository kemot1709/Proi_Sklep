#include "Kasa.h"

Kasa::Kasa(int n) {
    kasa_ID = n;
    kasa_nr_sprzedawcy = 0;
}

int Kasa::kasa_f_ID() {
    return kasa_ID;
}

int Kasa::kasa_f_sprzedawca() {
    return kasa_nr_sprzedawcy;
}

void Kasa::kasa_f_zmien_sprzedawce(int n) {
    kasa_nr_sprzedawcy = n;
}
