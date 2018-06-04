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

//using namespace std;

void jadymy_z_szalotem();

class Szkic_sklep {
public:
    virtual int sklep_f_ilosc_kas() = 0;
    virtual int sklep_f_ilosc_pracownikow() = 0;
    virtual bool sklep_f_stan() = 0;
    virtual void sklep_wszedl_klient() = 0;
    virtual void sklep_nowy_dzien() = 0;
};

class Sklep {
    int sklep_ilosc_kas; // ilosc kas w sklepie
    int sklep_ilosc_pracownikow; // ilosc pracownikow
    int sklep_ilosc_klientow; // ilosc klientow w sklepie danego dnia
    bool sklep_stan; // sklep otwarty/zamkniety
    double sklep_utarg; // calkowity utarg sklepu
    std::vector <Kasa> sklep_kasy; // kontener na kasy
    std::vector <Klient> sklep_klienci; // wektor klientow (abo inny kibel)
    std::vector <Pracownik> sklep_pracownicy; // kontener na pracownikow
    std::vector <Szkic_towar> sklep_towary; // kontener na towary
public:
    Sklep(int, int, int); // konstruktor sklepu
    //~Sklep(); // destruktor sklepu
    virtual int sklep_f_ilosc_kas(); // zwraca ilosc kas w sklepie
    virtual int sklep_f_ilosc_pracownikow(); // zwraca ilosc pracownikow w sklepie
    virtual int sklep_f_ilosc_klientow(); // zwraca ilosc klientow w sklepie
    virtual bool sklep_f_stan(); // zwraca stan sklepu

    virtual Pracownik sklep_pracownik(int); // zwraca konkretnego pracownika
    virtual Klient sklep_klient(int); // zwraca konkretnego klienta
    virtual Kasa sklep_kasa(int); // zwraca konkretna kase
    virtual Szkic_towar sklep_towar(int); // zwraca podany towar

    virtual void sklep_wszedl_klient(); // dodanie nowego klienta do sklepu
    virtual void sklep_nowy_dzien(); // zresetowanie stanu sklepu do dnia nastepnego
    virtual double sklep_f_utarg(); // zwraca utarg sklepu, bez VAT
};

#endif // SKLEP_H
