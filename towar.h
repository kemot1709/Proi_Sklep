#ifndef TOWAR_H
#define TOWAR_H

enum t_VAT {vat_8, vat_23, vat_5, vat_51};

class Szkic_towar {
public:
    virtual int towar_f_ID() = 0;
    virtual int towar_f_cena() = 0;
    virtual t_VAT towar_f_VAT() = 0;
};

class Towar : public Szkic_towar {
    int towar_ID;
    int towar_cena;
    t_VAT towar_VAT;
public:
    Towar(int); // konstruktor kasy
    //~Towar(); // destruktor kasy
    virtual int towar_f_ID(); // zwraca ID towaru
    virtual int towar_f_cena(); // zwraca cene towaru
    virtual t_VAT towar_f_VAT(); // zwraca VAT towaru
};
#endif // TOWAR_H
