#include <iostream>

#include <queue>

#include "Kasa.h"
#include "Klient.h"
#include "Sklep.h"

//using namespace std;

Kasa::Kasa(int n) {
    kasa_ID = n;
    kasa_nr_sprzedawcy = 0;
    kasa_stan = false;
    kasa_postoj = true;
    kasa_na_rachunku_kasy = 0;
    kasa_na_rachunku_netto = 0;
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

bool Kasa::kasa_f_stan() {
    return kasa_stan;
}

void Kasa::kasa_zmien_stan(){
    if( kasa_stan==true){
         kasa_stan==false;
    }
    else{
         kasa_stan==true;
    }
}

int Kasa::kasa_pierwszy() {
    return kasa_kolejka.front();
}

void Kasa::kasa_dodaj_osobe(int n) {
    kasa_kolejka.push(n);
    std::cout << "Klient " << n << " podchodzi do kolejki do kasy nr " << std::endl;
}

void Kasa::kasa_usun_osobe(Klient kl) {
    if(kasa_postoj == true) {
        kasa_postoj = false;
        return;
    }
    int n = kasa_kolejka.front();
    if(n != kl.klient_f_ID()) {
        std::cout << "ERROR usuwanie os - niewlasciwy ID" << std::endl;
    }
    int kon = kl.klient_ilosc_zakupow();
    double brutto = 0;
    double netto = 0;
    for(int i = 0; i < kon; i++) {
        Szkic_towar tow = kl.klient_towar(i);
        brutto += tow.towar_f_cena_brutto();
        netto += tow.towar_f_cena();
    }
    kasa_kolejka.pop();
    std::cout <<"Klient "<< n<< " wyszedl i zaplacil "<< brutto<<std::endl;
    k_zajecie i = en_k_wyszedl;
    kl.klient_zmiana_zajecia(i);
    kasa_na_rachunku_kasy += brutto;
    kasa_na_rachunku_netto += netto;
    kasa_postoj = true;
}

int Kasa::kasa_ilosc_osob() {
    return kasa_kolejka.size();
}

double Kasa::kasa_f_utarg_netto() {
    return kasa_na_rachunku_netto;
}
