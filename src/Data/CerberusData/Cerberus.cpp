#include <iostream>
#include "Cerberus.h"
using namespace std;

Cerbero Cerbero_Data(){
    struct Cerbero Cb;
    Cb.CerberoName = "\033[31mCerbero\033[0m";
    Cb.Level = 80;
    Cb.HP = 8000;
    Cb.MAX_HP = 8000;
    Cb.ATTACK = 50;
    Cb.CRITICAL_ATTACK = Cb.ATTACK*2;
    Cb.DEFENSE = 100;
    Cb.MANA = 0;
    Cb.MAX_MANA = 0;
    Cb.WEAPON = "Garras de fuego";
    Cb.ARMOR = "Piel infernal";
    return Cb;
}

void ShowStatsCerbero(const Cerbero& Cb){
    cout << "\033[3;4m-- Cerbero STATS --\033[0m" << endl << endl;
    cout << "\033[34m" <<  Cb.CerberoName << "\033[0m" << endl;
    cout << "Nivel:    " << Cb.Level << endl;
    cout << "Vida:     " << Cb.HP << "/" << Cb.MAX_HP << endl;
    cout << "Mana:     " << Cb.MANA << "/" << Cb.MAX_MANA << endl;
    cout << "Ataque:   " << Cb.ATTACK << endl;
    cout << "Defensa:  " << Cb.DEFENSE << endl;
    cout << "Arma:     " << Cb.WEAPON << endl;
    cout << "Armadura: " << Cb.ARMOR << endl;
}
