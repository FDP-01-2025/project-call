#include <iostream>
#include "EliteSlime.h"
using namespace std;

EliteS EliteS_Data(){
    struct EliteS S;
    S.EliteSName = "\033[31mElite Slime\033[0m";
    S.Level = 5;
    S.HP = 120;
    S.MAX_HP = 120;
    S.ATTACK = 15;
    S.CRITICAL_ATTACK = S.ATTACK*2;
    S.DEFENSE = 0;
    S.MANA = 100;
    S.MAX_MANA = 100;
    S.WEAPON = "Espada de Baba";
    S.ARMOR = "Cuerpo de Baba";
    return S;
}

void ShowStats(const EliteS& S){
    cout << "\033[3;4m-- Elite Slime STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << S.EliteSName << "\033[0m" << endl;
    cout << "Nivel:    "  << S.Level << endl;
    cout << "Vida:     "  << S.HP << "/" << S.MAX_HP << endl;
    cout << "Mana:     "  << S.MANA << "/" << S.MAX_MANA << endl;
    cout << "Ataque:   "  << S.ATTACK << endl;
    cout << "Defensa:  "  << S.DEFENSE << endl;
    cout << "Arma:     "     << S.WEAPON << endl;
    cout << "Armadura: " << S.ARMOR << endl;
}