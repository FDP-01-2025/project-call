#include <iostream>
#include "Naika.h"
using namespace std;

Naika Naika_Data(){
    struct Naika Na;
    Na.NaikaName = "\033[31mNaika\033[0m";
    Na.Level = 50;
    Na.HP = 800;
    Na.MAX_HP = 800;
    Na.ATTACK = 40;
    Na.DEFENSE = 20;
    Na.MANA = 200;
    Na.MAX_MANA = 200;
    Na.WEAPON = "Espada de oficial";
    Na.ARMOR = "Armadura de oficial";
    return Na;
}

void ShowStats(const Naika& Na){
    cout << "\033[3;4m-- NAIKA STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << Na.NaikaName << "\033[0m" << endl;
    cout << "Nivel:    "  << Na.Level << endl;
    cout << "Vida:     "  << Na.HP << "/" << Na.MAX_HP << endl;
    cout << "Mana:     "  << Na.MANA << "/" << Na.MAX_MANA << endl;
    cout << "Ataque:   "  << Na.ATTACK << endl;
    cout << "Defensa:  "  << Na.DEFENSE << endl;
    cout << "Arma:     "     << Na.WEAPON << endl;
    cout << "Armadura: " << Na.ARMOR << endl;
}