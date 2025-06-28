#include <iostream>
#include "NaikaDummy.h"
using namespace std;

NaikaDummy Dummy_Data(){
    struct NaikaDummy Ndum;
    Ndum.NaDummyName = "\033[31mMuñeco de Naika\033[0m";
    Ndum.Level = 1;
    Ndum.HP = 75;
    Ndum.MAX_HP = 75;
    Ndum.ATTACK = 10;
    Ndum.CRITICAL_ATTACK = Ndum.ATTACK*2;
    Ndum.DEFENSE = 5;
    Ndum.MANA = 0;
    Ndum.MAX_MANA = 0;
    Ndum.WEAPON = "Espada de madera";
    Ndum.ARMOR = "Cuerpo de madera";
    return Ndum;
}

void DummyShowStats(const NaikaDummy& Ndum){
    cout << "\033[3;4m-- NAIKA STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << Ndum.NaDummyName << "\033[0m" << endl;
    cout << "Nivel:    " << Ndum.Level << endl;
    cout << "Vida:     " << Ndum.HP << "/" << Ndum.MAX_HP << endl;
    cout << "Mana:     " << Ndum.MANA << "/" << Ndum.MAX_MANA << endl;
    cout << "Ataque:   " << Ndum.ATTACK << endl;
    cout << "Defensa:  " << Ndum.DEFENSE << endl;
    cout << "Arma:     " << Ndum.WEAPON << endl;
    cout << "Armadura: " << Ndum.ARMOR << endl;
}