#ifndef PRACOWNIK_H
#define PRACOWNIK_H

enum p_zajecie {en_p_wolne,en_p_kasa,en_p_sklep,en_p_magazyn,en_p_przerwa,en_p_chodzi};


class Szkic_pracownik{
public:
    virtual int pracownik_f_ID()=0;
    virtual int pracownik_f_zajecie()=0;
    virtual void pracownik_nowy_dzien()=0;
    virtual void pracownik_zmien_zajecie()=0;
};

class Pracownik {
    int pracownik_ID;
    p_zajecie pracownik_zajecie;
    int pracownik_stan [3]; // stan pracy pracownika: system zmianowy, czas na kasie, czas na przerwie
public:
    Pracownik(int); // konstruktor
    //~Pracownik(); // destruktor
    virtual int pracownik_f_ID(); // zwraca nr pracownika
    virtual int pracownik_f_zajecie(); // zwraca co robi pracownik
    // zwracanie stanu pracownika
    virtual void pracownik_zmien_zajecie(p_zajecie); // zmienia zajecie pracownika
    virtual void pracownik_nowy_dzien(); // resetuje stan pracownika na nasteny dzien
};

#endif // PRACOWNIK_H
