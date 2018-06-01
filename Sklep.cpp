#include "Sklep.h"

Sklep::Sklep(int n, int m, int o) {
    int towar_ilosc = o;
    sklep_ilosc_kas = n;
    sklep_ilosc_pracownikow = m;
    sklep_stan = false;
    sklep_klienci.clear();
    sklep_pracownicy.reserve(m);
    for(int i = 1; i <= m; i++) { // rezerwacja miejsca dla pracownikow
        sklep_pracownicy.push_back(Pracownik(i));
    }
    sklep_towary.reserve(towar_ilosc);
    for(int i = 1; i <= o; i++) { // rezerwacja miejsca na towary
        sklep_towary.push_back(Towar(i));
    }
}

int Sklep::sklep_f_ilosc_kas() {
    return sklep_ilosc_kas;
}

int Sklep::sklep_f_ilosc_pracownikow() {
    return sklep_ilosc_pracownikow;
}

bool Sklep::sklep_f_stan() {
    return sklep_stan;
}

void Sklep::sklep_dodaj_osobe(int n) {
    sklep_kolejka.push(n);
    cout << "Klient " << n << " podchodzi do kolejki do kas" << endl;
}

void Sklep::sklep_usun_osobe() {
    int n = sklep_kolejka.front();
    sklep_kolejka.pop();
    sklep_klienci[n].klient_zmiana_zajecia(k_zajecie i=en_k_wyszedl);
}

int Sklep::sklep_ilosc_osob() {
    return sklep_kolejka.size();
}

void Sklep::sklep_wszedl_klient() {
    sklep_ilosc_klientow++;
    sklep_klienci.push_back(sklep_ilosc_klientow);
}

void Sklep::sklep_nowy_dzien() {
    sklep_klienci.clear(); // resetowanie stanu klientow
    for (int i=1;i<=sklep_ilosc_pracownikow;i++){ // resetowawnie stanu pracownikow
        sklep_pracownicy[i].pracownik_nowy_dzien();
    }

}
