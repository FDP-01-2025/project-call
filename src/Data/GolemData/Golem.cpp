#include <iostream>
#include "Golem.h"
using namespace std;

Golem Golem_Data(){
    Golem Gol;
    Gol.GolemName = "\033[35mGolem de piedra\033[0m";
    Gol.Level = 20;
    Gol.HP = 300;
    Gol.MAX_HP = 300;
    Gol.ATTACK = 20;
    Gol.CRITICAL_ATTACK = Gol.ATTACK * 3;
    Gol.DEFENSE = 100;
    Gol.MANA = 0;
    Gol.MAX_MANA = 0;
    Gol.WEAPON = "Puños de granito";
    Gol.ARMOR = "Placas de roca";
    return Gol;
}

void ShowStatsGolem(const Golem& Gol){
    cout << "\033[3;4m-- GOLEM STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << Gol.GolemName << "\033[0m" << endl;
    cout << "Nivel:    " << Gol.Level << endl;
    cout << "Vida:     " << Gol.HP << "/" << Gol.MAX_HP << endl;
    cout << "Mana:     " << Gol.MANA << "/" << Gol.MAX_MANA << endl;
    cout << "Ataque:   " << Gol.ATTACK << endl;
    cout << "Defensa:  " << Gol.DEFENSE << endl;
    cout << "Arma:     " << Gol.WEAPON << endl;
    cout << "Armadura: " << Gol.ARMOR << endl;
}
