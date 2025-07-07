#include <iostream>
#include "Hypnos.h"
using namespace std;

DHypnos DH_Data(){
    struct DHypnos h;
    h.DHName = "\033[31mDios Hypnos\033[0m";
    h.Level = 60;
    h.HP = 5000;
    h.MAX_HP = 5000;
    h.ATTACK = 25;
    h.CRITICAL_ATTACK = h.ATTACK*2;
    h.DEFENSE = 0;
    h.MANA = 2000;
    h.MAX_MANA = 2000;
    h.WEAPON = "Somnífero de Ébano";
    h.ARMOR = "Manto del Letargo";
    return h;
}

void ShowStats(const DHypnos& h){
    cout << "\033[3;4m-- Dios Hypnos STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << h.DHName << endl;
    cout << "Nivel:    "  << h.Level << endl;
    cout << "Vida:     "  << h.HP << "/" << h.MAX_HP << endl;
    cout << "Mana:     "  << h.MANA << "/" << h.MAX_MANA << endl;
    cout << "Ataque:   "  << h.ATTACK << endl;
    cout << "Defensa:  "  << h.DEFENSE << endl;
    cout << "Arma:     "     << h.WEAPON << endl;
    cout << "Armadura: " << h.ARMOR << endl;
}