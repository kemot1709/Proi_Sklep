#include <ctime>

#include "random"

#include "towar.h"

//using namespace std;

double losuj_cene(){
    std::default_random_engine e1;
    std::uniform_int_distribution <int> uniform_dist(100, 100000);
    double los = uniform_dist(e1)/100;
    return los;
}

Towar_5::Towar_5(int n){
    towar_ID=n;
    towar_cena_netto=losuj_cene();
    towar_VAT=5;
}

Towar_8::Towar_8(int n){
    towar_ID=n;
    towar_cena_netto=losuj_cene();
    towar_VAT=8;
}

Towar_23::Towar_23(int n){
    towar_ID=n;
    towar_cena_netto=losuj_cene();
    towar_VAT=23;
}

Towar_51::Towar_51(int n){
    towar_ID=n;
    towar_cena_netto=losuj_cene();
    towar_VAT=51;
}

int Szkic_towar::towar_f_ID(){
    return towar_ID;
}

double Szkic_towar::towar_f_cena(){
    return towar_cena_netto;
}

double Szkic_towar::towar_f_cena_brutto(){
    return towar_cena_netto*(100+towar_VAT)/100;
}
