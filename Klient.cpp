#include "Klient.h"

Klient::Klient(int n) {
    klient_ID = n;
}

int Klient::klient_f_ID(){
    return klient_ID;
}

k_zajecie Klient::klient_f_zajecie(){
    return klient_zajecie;
}

void Klient::klient_zmiana_zajecia(k_zajecie zaj){
    klient_zajecie=zaj;
}

int Klient::klient_ilosc_zakupow(){
    return klient_zakupy.size();
}

Szkic_towar Klient::klient_towar(int n){
    return klient_zakupy[n];
}

void Klient::klient_dodaj_zakupy(Szkic_towar tow){
    klient_zakupy.push_back(tow);
}
