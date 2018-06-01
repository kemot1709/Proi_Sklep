#include "Sklep.h"

void jadymy_z_szalotem(){
    int n,m,o;
    n=4,m=9,o=1000;
    Sklep supermarket(n,m,o);
    for (int i=1;;i++){ // licznik dni
        supermarket.sklep_nowy_dzien();
        for(int j=1;j<=120;j++){ // jeden tick - 6 min
            // wejscie klientow
            // ogarniecie zajec pracownikom
            // ogarniecie zajec klientow
            // czas oczekiwania - przerwa na czytanie zdarzen
        }
    }
}
