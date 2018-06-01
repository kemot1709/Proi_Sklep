#ifndef KLIENT_H
#define KLIENT_H

enum k_zajecie {en_k_cos_robi, en_k_przy_kasie, en_k_wybiera_towar, en_k_rozmawia_z_pracownikiem, en_k_sprawdza_cene, en_k_oglada_towar,en_k_wyszedl};

class Szkic_klient {
public:
    virtual int klient_f_ID()=0;
    virtual int klient_f_zajecie()=0;
    virtual void klient_zmiana_zajecia(k_zajecie)=0;
};

class Klient : public Szkic_klient {
    int klient_ID;
    k_zajecie klient_zajecie;
public:
    Klient(int); // konstruktor
    //~Klient(); // destruktor
    virtual int klient_f_ID(); // zwraca nr klienta
    virtual int klient_f_zajecie(); // zwraca zajecie klienta
    virtual void klient_zmiana_zajecia(k_zajecie); // zmiana zajecia klienta na podany

};

#endif // KLIENT_H
