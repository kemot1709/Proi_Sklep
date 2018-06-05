#ifndef TOWAR_H
#define TOWAR_H

#include <iostream>

//using namespace std;

double losuj_cene(int);

class Szkic_towar {
protected:
    int towar_ID;
    int towar_VAT;
    double towar_cena_netto;
public:
    virtual int towar_f_ID() ;
    virtual double towar_f_cena() ;
    virtual double towar_f_cena_brutto();
};

class Towar_5 : public Szkic_towar {
public:
    Towar_5(int); // konstruktor kasy
    //~Towar(); //destruktor kasy
};
class Towar_8 : public Szkic_towar {
public:
    Towar_8(int); // konstruktor kasy
    //~Towar(); // destruktor kasy
};
class Towar_23 : public Szkic_towar {
public:
    Towar_23(int); // konstruktor kasy
    //~Towar(); // destruktor kasy

};
class Towar_51 : public Szkic_towar {
public:
    Towar_51(int); // konstruktor kasy
    //~Towar(); // destruktor kasy
};
#endif // TOWAR_H
