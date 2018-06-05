#ifndef KLIENT_H
#define KLIENT_H

#include <vector>
#include <iostream>

#include "towar.h"

//using namespace std;

enum k_zajecie {en_k_cos_robi, en_k_przy_kasie, en_k_wybiera_towar, en_k_rozmawia_z_pracownikiem, en_k_sprawdza_cene, en_k_oglada_towar, en_k_wyszedl};

class Szkic_klient {
public:
    virtual int klient_f_ID() = 0; // zwraca nr klienta
    virtual k_zajecie klient_f_zajecie() = 0; // zwraca zajecie klienta
    virtual void klient_zmiana_zajecia(k_zajecie) = 0; // zmiana zajecia klienta na podany
    virtual int klient_ilosc_zakupow() = 0; // zwraca ilosc rzecze w koszyku
    virtual Szkic_towar klient_towar(int) = 0; // zwraca podany przedmiot z koszyka
    virtual void klient_dodaj_zakupy(Szkic_towar) = 0; // dodaje towar do koszyka
};

class Klient : public Szkic_klient {
    int klient_ID;
    k_zajecie klient_zajecie;
    std::vector <Szkic_towar> klient_zakupy; // zakupy klienta
public:
    Klient(int); // konstruktor
    //~Klient(); // destruktor
    virtual int klient_f_ID(); // zwraca nr klienta
    virtual k_zajecie klient_f_zajecie(); // zwraca zajecie klienta
    virtual void klient_zmiana_zajecia(k_zajecie); // zmiana zajecia klienta na podany
    virtual int klient_ilosc_zakupow(); // zwraca ilosc rzecze w koszyku
    virtual Szkic_towar klient_towar(int); // zwraca podany przedmiot z koszyka
    virtual void klient_dodaj_zakupy(Szkic_towar); // dodaje towar do koszyka

};

#endif // KLIENT_H
