#include <random>

#include "towar.h"

Towar::Towar(int n) {
    towar_ID = n;
    //ustlenie ceny
    //ustalenie VATu
}

int Towar::towar_f_ID() {
    return towar_cena;
}

int Towar::towar_f_cena() {
    return towar_cena;
}

t_VAT Towar::towar_f_VAT() {
    return towar_VAT;
}
