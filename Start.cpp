#include <ctime>
#include <chrono>

#include "windows.h"
#include "random"

#include "Sklep.h"

void jadymy_z_szalotem() {
//    unsigned seed1 = std::chrono::system_clock::now();
    std::default_random_engine e1;
    int n, m, o; // kasy, pracownicy, towary
    n = 4, m = 9, o = 1000;
    Sklep supermarket(n, m, o);
    for(int i = 1;; i++) { // licznik dni
        std::cout << "Dzien " << i << "\n\n";
        supermarket.sklep_nowy_dzien();
        for(int j = 1; j <= 120; j++) { // jeden tick - 6 min
            std::cout << "Tick " << j << "\n\n";
            int czas_komend = 0;
            // wejscie klientow
            if(j < 111) {
                std::uniform_int_distribution <int> uniform_dist(0, n); // losowanie ilosci klientow wchdzacych do sklepu
                int r = uniform_dist(e1);
                for(int k = 0; k < r; k++) { // rezerwacja miejsca dla kientow
                    supermarket.sklep_wszedl_klient();
                }
                if(r > 0) {
                    std:: cout << "Do sklepu wchodzi " << r << " klientow" << std::endl;
                    Sleep(100);
                }
            }
            // ogarniecie zajec pracownikom
            for(int k = 0; k < m; k++) {
                Pracownik prac = supermarket.sklep_pracownik(k);
                if(prac.pracownik_f_stan(0) != 0) { // sprawdzenie czy pracownik ma wolne
                    if(prac.pracownik_f_stan(3) != 0) { // sprawdzenie czy pracownik jest zajety i skorygowanie czasu pracy
                        prac.pracownik_zmien_stan(3, -1);
                    }
                    else {
                        if(prac.pracownik_f_zajecie() == en_p_kasa) { // wylaczanie kasy jesli byl na kasie
                            Kasa kasa = supermarket.sklep_kasa(prac.pracownik_f_kasa());
                            kasa.kasa_zmien_stan();
                            kasa.kasa_f_zmien_sprzedawce(k);
                            supermarket.sklep_akt_kasa(prac.pracownik_f_kasa(), kasa);
                        }
                        std::uniform_int_distribution <int> uniform_dist(0, 99);
                        int losuj_zajecie = uniform_dist(e1);
                        if(losuj_zajecie < 25 && prac.pracownik_f_stan(1) < 4) { // pracownik idzie na kase
                            int wolna_kasa = -1;
                            for(int l = 0; l < n; l++) { // szukanie wolnej kasy
                                if(supermarket.sklep_kasa(l).kasa_f_stan() == false) {
                                    wolna_kasa = l;
                                    break;
                                }
                            }
                            if(wolna_kasa == -1) {
                                continue;
                            }
                            prac.pracownik_zmien_stan(1, 1);
                            prac.pracownik_zmien_stan(3, 20);
                            prac.pracownik_zmien_zajecie(en_p_kasa);
                            prac.pracownik_zmien_kasa(wolna_kasa);
                            Kasa kasa = supermarket.sklep_kasa(wolna_kasa);
                            kasa.kasa_zmien_stan();
                            kasa.kasa_f_zmien_sprzedawce(k);
                            supermarket.sklep_akt_kasa(wolna_kasa, kasa);
                            std::cout << "Pracownik " << k + 1 << " idzie na kase nr " << wolna_kasa + 1 << std::endl;
                        }
                        else if(losuj_zajecie < 40) { // pracownik idzie wyk³adaæ towar
                            prac.pracownik_zmien_stan(3, 5);
                            prac.pracownik_zmien_zajecie(en_p_sklep);
                            std::cout << "Pracownik " << k + 1 << " idzie wykladac towar" << std::endl;
                        }
                        else if(losuj_zajecie < 48 && prac.pracownik_f_stan(2) < 2) { // przerwa
                            prac.pracownik_zmien_stan(3, 5);
                            prac.pracownik_zmien_stan(2, 1);
                            prac.pracownik_zmien_zajecie(en_p_przerwa);
                            std::cout << "Pracownik " << k + 1 << " idzie na przerwe" << std::endl;
                        }
                        else if(losuj_zajecie < 50) { // robi na magazynie
                            prac.pracownik_zmien_stan(3, 2);
                            prac.pracownik_zmien_zajecie(en_p_magazyn);
                            std::cout << "Pracownik " << k + 1 << " idzie na magazyn" << std::endl;
                        }
                        else { // chodzi po sklepie
                            prac.pracownik_zmien_zajecie(en_p_chodzi);
                            std::cout << "Pracownik " << k + 1 << " chodzi po sklepie" << std::endl;
                        }
                        czas_komend++;
                    }
                }
                supermarket.sklep_akt_pracownik(k, prac);
            }
            // ogarniecie zajec klientow
            int p = supermarket.sklep_f_ilosc_klientow();
            for(int k = 0; k < p; k++) {
                Klient klie = supermarket.sklep_klient(k);
                if(klie.klient_f_zajecie() != en_k_wyszedl && klie.klient_f_zajecie() != en_k_przy_kasie) { // sprawdza czy klient jeszcz jest w sklepie lub juz przy kasie
                    std::uniform_int_distribution <int> uniform_dist(0, 99);
                    int losuj_zajecie = uniform_dist(e1);
                    if(losuj_zajecie < 15 && klie.klient_ilosc_zakupow() > 0) { // idzie do kasy
                        klie.klient_zmiana_zajecia(en_k_przy_kasie);
                        int kol_kasa = -1;
                        int kol_ile;
                        for(int l = 0; l < n; l++) { // szukanie najlepszej kasy
                            if(supermarket.sklep_kasa(l).kasa_f_stan() == true) {
                                if(kol_kasa == -1) {
                                    kol_kasa = l;
                                    kol_ile = supermarket.sklep_kasa(l).kasa_ilosc_osob();
                                }
                                else {
                                    if(kol_ile > supermarket.sklep_kasa(l).kasa_ilosc_osob()) {
                                        kol_kasa = l;
                                        kol_ile = supermarket.sklep_kasa(l).kasa_ilosc_osob();
                                    }
                                }
                            }
                        }
                        Kasa kasa = supermarket.sklep_kasa(kol_kasa);
                        kasa.kasa_dodaj_osobe(k);
                        supermarket.sklep_akt_kasa(kol_kasa, kasa);
                        std::cout << "Klient " << k + 1 << " podchodzi do kolejki do kasy nr " << kol_kasa + 1 << std::endl;
                    }
                    else if(losuj_zajecie < 20) { // chodzi po sklepie
                        klie.klient_zmiana_zajecia(en_k_cos_robi);
                    }
                    else if(losuj_zajecie < 28) { // rozmawia z pracownikiem
                        for(int l = 0; l < m; l++) { // szukanie wolnego pracownika
                            Pracownik prac = supermarket.sklep_pracownik(l);
                            if(prac.pracownik_f_zajecie() == en_p_chodzi || prac.pracownik_f_zajecie() == en_p_sklep) {
                                klie.klient_zmiana_zajecia(en_k_rozmawia_z_pracownikiem);
                                prac.pracownik_zmien_stan(3, 1);
                                std::cout << "Klient " << k + 1 << " rozmawia z pracownikiem nr " << l + 1 << std::endl;
                                break;
                            }
                        }
                    }
                    else if(losuj_zajecie < 30) { // oglada towar
                        klie.klient_zmiana_zajecia(en_k_oglada_towar);
                    }
                    else if(losuj_zajecie < 35) { // sprawdza cene
                        klie.klient_zmiana_zajecia(en_k_sprawdza_cene);
                        std::uniform_int_distribution <int> uniform_dist(0, o - 1);
                        int wybrany_tow = uniform_dist(e1);
                        std::cout << "Klient " << k + 1 << " sprawdza cene towaru nr " << wybrany_tow << ", wynosi ona " << supermarket.sklep_towar(wybrany_tow).towar_f_cena_brutto() << std::endl;
                    }
                    else { // wybiera towar do koszyka
                        klie.klient_zmiana_zajecia(en_k_wybiera_towar);
                        std::uniform_int_distribution <int> uniform_dist(0, o - 1);
                        int wybrany_tow = uniform_dist(e1);
                        klie.klient_dodaj_zakupy(supermarket.sklep_towar(wybrany_tow));
                        std::cout << "Klient " << k + 1 << " bierze do koszyka produkt nr " << wybrany_tow + 1 << std::endl;
                    }
                    czas_komend++;
                }
                supermarket.sklep_akt_klient(k, klie);
            }
            //obsluga kas
            for(int k = 0; k < n; k++) {
                Kasa kasa = supermarket.sklep_kasa(k);
                if(kasa.kasa_f_stan() == true) { // sprawdzenie czy kasa jest otwarta
                    if(kasa.kasa_ilosc_osob() > 0) { // sprawdza czy ktos jest w kolejce
                        kasa.kasa_usun_osobe(supermarket.sklep_klient(kasa.kasa_pierwszy()));
                        czas_komend++;
                    }
                }
                supermarket.sklep_akt_kasa(k, kasa);
            }
            Sleep(100 * czas_komend + 1000); // czas oczekiwania - przerwa na czytanie zdarzen
        }
        std::cout << "Zarobek sklepu w dniu " << i << " : " << supermarket.sklep_f_utarg() << std::endl;
        Sleep(1000);
    }
}
