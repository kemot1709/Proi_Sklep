#ifndef KASA_H
#define KASA_H

class Szkic_kasa {
public:
    virtual int kasa_f_ID() = 0;
    virtual int kasa_f_sprzedawca() = 0;
    virtual void kasa_f_zmien_sprzedawce(int) = 0;
};

class Kasa {
    int kasa_ID;
    int kasa_nr_sprzedawcy;
public:
    Kasa(int); // konstruktor kasy
    //~Kasa(); // destruktor kasy
    virtual int kasa_f_ID(); // zwraca nr kasy
    virtual int kasa_f_sprzedawca(); // zwraca sprzedawce na kasie
    virtual void kasa_f_zmien_sprzedawce(int); // zmienia sprzedawce na kasie na podanego
};
#endif // KASA_H
