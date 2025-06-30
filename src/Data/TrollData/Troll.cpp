#include <iostream>
#include "Troll.h"
using namespace std;

Troll Troll_Data(){
    struct Troll Tr;
    Tr.TrollName = "\033[31mTroll de mana\033[0m";
    Tr.Level = 15;
    Tr.HP = 250;
    Tr.MAX_HP = 250;
    Tr.ATTACK = 25;
    Tr.CRITICAL_ATTACK = Tr.ATTACK*2;
    Tr.DEFENSE = 10;
    Tr.MANA = 100;
    Tr.MAX_MANA = 100;
    Tr.WEAPON = "Garrotazo";
    Tr.ARMOR = "Armadura de cuero negro";
    return Tr;
}

void ShowStatsTroll(const Troll& Tr){
    cout << "\033[3;4m-- TROLL STATS --\033[0m" << endl << endl;
    cout << "\033[34m" <<  Tr.TrollName << "\033[0m" << endl;
    cout << "Nivel:    " << Tr.Level << endl;
    cout << "Vida:     " << Tr.HP << "/" << Tr.MAX_HP << endl;
    cout << "Mana:     " << Tr.MANA << "/" << Tr.MAX_MANA << endl;
    cout << "Ataque:   " << Tr.ATTACK << endl;
    cout << "Defensa:  " << Tr.DEFENSE << endl;
    cout << "Arma:     " << Tr.WEAPON << endl;
    cout << "Armadura: " << Tr.ARMOR << endl;
}