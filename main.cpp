#include <iostream>
#include <fstream>

#include "Pracownik.h"
#include "Kasa.h"
#include "Klient.h"
#include "Sklep.h"
#include "towar.h"

int main() {
    std::fstream plik;
    try {
        plik.open("dane.txt");
        if(!plik.good()) {
            int i = 1;
            throw i;
        }
        int a, b, c;
        plik >> a >> b >> c;
        if(a < 1) {
            std::string s = "Brak kas w sklepie";
            throw s;
        }
        if(b < 3) {
            std::string s = "Brak odpowiednie ilosci ludzi do obslugi sklepu";
            throw s;
        }
        if(c < 1) {
            std::string s = "Brak towarow w sklepie";
            throw s;
        }
        jadymy_z_szalotem(a, b, c);
    }
    catch(int n) {
        std::cout << "plik nie zostal otwarty, uruchamianie w trybie domyslnym" << std::endl;
        jadymy_z_szalotem();
    }
    catch(std::string n) {
        std::cout << n << ", uruchamianie w trybie domyslnym" << std::endl;
        jadymy_z_szalotem();
    }
    catch(...) {
        std::cout << "ERROR cos sie zepsulo" << std::endl;
    }
}
