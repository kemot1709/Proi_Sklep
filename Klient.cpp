#include "Klient.h"

Klient::Klient(int n) {
    klient_ID = n;
}

int Klient::klient_f_ID(){
    return klient_ID;
}

int Klient::klient_f_zajecie(){
    return klient_zajecie;
}

void Klient::klient_zmiana_zajecia(k_zajecie zaj){
    klient_zajecie=zaj;
}
