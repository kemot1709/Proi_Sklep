#ifndef PRACOWNIK_H
#define PRACOWNIK_H

enum p_zajecie {en_p_wolne, en_p_kasa, en_p_sklep, en_p_magazyn, en_p_przerwa, en_p_chodzi};


class Szkic_pracownik {
public:
    virtual int pracownik_f_ID() = 0; // zwraca nr pracownika
    virtual int pracownik_f_zajecie() = 0; // zwraca co robi pracownik
    virtual int pracownik_f_stan(int) = 0; // zwracanie stanu pracownika w konkretnej kwestii
    virtual int pracownik_f_kasa() = 0;
    virtual void pracownik_zmien_kasa(int) = 0;
    virtual void pracownik_zmien_stan(int, int) = 0; // zmiana konkretnego parametru o tyle (suma)
    virtual void pracownik_zmien_zajecie(p_zajecie) = 0; // zmienia zajecie pracownika
    virtual void pracownik_nowy_dzien() = 0; // resetuje stan pracownika na nasteny dzien
};

class Pracownik {
    int pracownik_ID;
    p_zajecie pracownik_zajecie;
    int pracownik_stan [4]; // stan pracy pracownika: system zmianowy, czas na kasie, czas na przerwie, ile jeszcze jest zajety
    int pracownik_kasa;
public:
    Pracownik(int); // konstruktor
    //~Pracownik(); // destruktor
    virtual int pracownik_f_ID(); // zwraca nr pracownika
    virtual int pracownik_f_zajecie(); // zwraca co robi pracownik
    virtual int pracownik_f_stan(int); // zwracanie stanu pracownika w konkretnej kwestii
    virtual int pracownik_f_kasa();
    virtual void pracownik_zmien_kasa(int);
    virtual void pracownik_zmien_stan(int, int); // zmiana konkretnego parametru o tyle (suma)
    virtual void pracownik_zmien_zajecie(p_zajecie); // zmienia zajecie pracownika
    virtual void pracownik_nowy_dzien(); // resetuje stan pracownika na nasteny dzien
};

#endif // PRACOWNIK_H
