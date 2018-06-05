#ifndef KASA_H
#define KASA_H

#include <queue>
#include <cstdlib>

#include "Klient.h"

//using namespace std;

class Szkic_kasa {
public:
    virtual int kasa_f_ID() = 0; // zwraca nr kasy
    virtual int kasa_f_sprzedawca() = 0; // zwraca sprzedawce na kasie
    virtual void kasa_f_zmien_sprzedawce(int) = 0; // zmienia sprzedawce na kasie na podanego
    virtual bool kasa_f_stan() = 0; // zwraca stan kasy
    virtual void kasa_zmien_stan() = 0; // zmienia stan kasy na odwrotny
    virtual void kasa_reset(); // wywala klientow ze sklepu


    virtual int kasa_pierwszy() = 0; // zwraca nr pierwszej os w kolejce
    virtual void kasa_dodaj_osobe(int) = 0; // obsluga kolejki kasy, jedna kolejka do wszystkich kas
    virtual double kasa_usun_osobe(Klient) = 0; // obsluga kolejki kasy
    virtual int kasa_ilosc_osob() = 0; // obsluga kolejki kasy
    virtual double kasa_f_utarg_netto() = 0; // zwraca utarg netto
};

class Kasa {
    int kasa_ID;
    int kasa_nr_sprzedawcy;
    std::queue <int> kasa_kolejka; // kolejka klientow do danej kasy
    bool kasa_stan;
    double kasa_na_rachunku_kasy;
    double kasa_na_rachunku_netto;
    bool kasa_postoj;
public:
    Kasa(int); // konstruktor kasy
    //~Kasa(); // destruktor kasy
    virtual int kasa_f_ID(); // zwraca nr kasy
    virtual int kasa_f_sprzedawca(); // zwraca sprzedawce na kasie
    virtual void kasa_f_zmien_sprzedawce(int); // zmienia sprzedawce na kasie na podanego
    virtual bool kasa_f_stan(); // zwraca stan kasy
    virtual void kasa_zmien_stan(); // zmienia stan kasy na odwrotny
    virtual void kasa_reset(); // wywala klientow ze sklepu

    virtual int kasa_pierwszy(); // zwraca nr pierwszej os w kolejce
    virtual void kasa_dodaj_osobe(int); // obsluga kolejki kasy, jedna kolejka do wszystkich kas
    virtual double kasa_usun_osobe(Klient); // obsluga kolejki kasy
    virtual int kasa_ilosc_osob(); // obsluga kolejki kasy
    virtual double kasa_f_utarg_netto(); // zwraca utarg netto
};
#endif // KASA_H
