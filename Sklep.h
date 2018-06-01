#ifndef SKLEP_H
#define SKLEP_H

#include <iostream>
#include <array>
#include <queue>
#include <vector>

#include "Kasa.h"
#include "Pracownik.h"
#include "Towar.h"
#include "Klient.h"

using namespace std;

void jadymy_z_szalotem();

class Szkic_sklep {
public:
    virtual int sklep_f_ilosc_kas() = 0;
    virtual int sklep_f_ilosc_pracownikow() = 0;
    virtual bool sklep_f_stan() = 0;
    virtual void sklep_dodaj_osobe() = 0;
    virtual void sklep_usun_osobe() = 0;
    virtual int sklep_ilosc_osob() = 0;
    virtual void sklep_wszedl_klient() = 0;
    virtual void sklep_nowy_dzien() = 0;
};

class Sklep {
    int sklep_ilosc_kas; // ilosc kas w sklepie
    int sklep_ilosc_pracownikow; // ilosc pracownikow
    int sklep_ilosc_klientow; // ilosc klientow w sklepie danego dnia
    bool sklep_stan; // sklep otwarty/zamkniety
    queue <int> sklep_kolejka ; // kolejka klientow
    vector <Klient> sklep_klienci; // wektor klientow (abo inny kibel)
    vector <Pracownik> sklep_pracownicy; // kontener na pracownikow
    vector <Towar> sklep_towary; // kontener na towary
public:
    Sklep(int, int, int); // konstruktor sklepu
    //~Sklep(); // destruktor sklepu
    virtual int sklep_f_ilosc_kas(); // zwraca ilosc kas w sklepie
    virtual int sklep_f_ilosc_pracownikow(); // zwraca ilosc pracownikow w sklepie
    virtual bool sklep_f_stan(); // zwraca stan sklepu

    virtual void sklep_dodaj_osobe(int); // obsluga kolejki kasy, jedna kolejka do wszystkich kas
    virtual void sklep_usun_osobe(); // obsluga kolejki kasy
    virtual int sklep_ilosc_osob(); // obsluga kolejki kasy

    virtual void sklep_wszedl_klient(); // dodanie nowego klienta do sklepu
    virtual void sklep_nowy_dzien(); // zresetowanie stanu sklepu do dnia nastepnego
};

#endif // SKLEP_H
