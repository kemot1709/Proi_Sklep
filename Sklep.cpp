#include "Sklep.h"

Sklep::Sklep(int n, int m, int o) {
    int towar_ilosc = o;
    sklep_ilosc_kas = n;
    sklep_ilosc_pracownikow = m;
    sklep_ilosc_klientow = 0;
    sklep_stan = true;
    sklep_utarg = 0;
    sklep_klienci.clear();
    sklep_kasy.reserve(n);
    for(int i = 1; i <= n; i++) { // rezerwacja miejsca na kasy
        sklep_kasy.push_back(Kasa(i));
    }
    sklep_pracownicy.reserve(m);
    for(int i = 1; i <= m; i++) { // rezerwacja miejsca dla pracownikow
        sklep_pracownicy.push_back(Pracownik(i));
    }
    sklep_towary.reserve(towar_ilosc);
    int o1 = o / 3, o2 = o / 8, o3 = o / 5, o4 = o - o1 - o2 - o3;
    int i = 0;
    for(; i < o1; i++) { // rezerwacja miejsca na towary
        sklep_towary.push_back(Towar_8(i));
    }
    for(; i < o1 + o2; i++) { // rezerwacja miejsca na towary
        sklep_towary.push_back(Towar_51(i));
    }
    for(; i < o2 + o1 + o3; i++) { // rezerwacja miejsca na towary
        sklep_towary.push_back(Towar_5(i));
    }
    for(; i < o; i++) { // rezerwacja miejsca na towary
        sklep_towary.push_back(Towar_23(i));
    }
}

int Sklep::sklep_f_ilosc_kas() {
    return sklep_ilosc_kas;
}

int Sklep::sklep_f_ilosc_pracownikow() {
    return sklep_ilosc_pracownikow;
}

int Sklep::sklep_f_ilosc_klientow() {
    return sklep_ilosc_klientow;
}

bool Sklep::sklep_f_stan() {
    return sklep_stan;
}

void Sklep::sklep_wszedl_klient() {
    sklep_ilosc_klientow++;
    sklep_klienci.push_back(sklep_ilosc_klientow);
}

void Sklep::sklep_nowy_dzien() {
    sklep_klienci.clear(); // resetowanie stanu klientow
    sklep_ilosc_klientow = 0;
    for(int i = 0; i < sklep_ilosc_pracownikow; i++) { // resetowawnie stanu pracownikow
        Pracownik prac = sklep_pracownik(i);
        prac.pracownik_nowy_dzien();
        sklep_akt_pracownik(i, prac);
    }
    for(int i = 0; i < sklep_ilosc_kas; i++) {
        Kasa kasa = sklep_kasa(i);
        kasa.kasa_reset();
        kasa.kasa_f_zmien_sprzedawce(0);
        sklep_akt_kasa(i, kasa);
    }
}

Pracownik Sklep::sklep_pracownik(int n) {
    return sklep_pracownicy[n];
}

Klient Sklep::sklep_klient(int n) {
    return sklep_klienci[n];
}

Kasa  Sklep::sklep_kasa(int n) {
    return sklep_kasy[n];
}

Szkic_towar Sklep::sklep_towar(int n) {
    return sklep_towary[n];
}

void Sklep::sklep_akt_pracownik(int i, Pracownik x) {
    sklep_pracownicy[i] = x;
}

void Sklep::sklep_akt_klient(int i, Klient x) {
    sklep_klienci [i] = x;
}

void Sklep::sklep_akt_kasa(int i, Kasa x) {
    sklep_kasy[i] = x;
}

double Sklep::sklep_f_utarg() {
    double ut = 0;
    for(int i = 0; i < sklep_f_ilosc_kas(); i++) {
        ut += sklep_kasy[i].kasa_f_utarg_netto();
    }
    sklep_utarg += ut;
    return ut;
}
