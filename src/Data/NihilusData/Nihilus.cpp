#include <iostream>
#include "Nihilus.h"
using namespace std;

Nihilus Nihilus_Data() {
    Nihilus Nihi;
    Nihi.NihilusName = "\033[35mNihilus, el Vacío Andante\033[0m"; // Color morado para un toque siniestro
    Nihi.Level = 18;
    Nihi.HP = 250;
    Nihi.MAX_HP = 250;
    Nihi.ATTACK = 30;
    Nihi.CRITICAL_ATTACK = Nihi.ATTACK * 2; // 50
    Nihi.DEFENSE = 30;
    Nihi.MANA = 50;
    Nihi.MAX_MANA = 50;
    Nihi.WEAPON = "Daga del Vacío";
    Nihi.ARMOR = "Capa que devora la luz";
    return Nihi;
}

void ShowStatsNihilus(const Nihilus& Nihi) {
    cout << "\033[3;4m-- NIHILUS STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << Nihi.NihilusName << "\033[0m" << endl;
    cout << "Nivel:    " << Nihi.Level << endl;
    cout << "Vida:     " << Nihi.HP << "/" << Nihi.MAX_HP << endl;
    cout << "Mana:     " << Nihi.MANA << "/" << Nihi.MAX_MANA << endl;
    cout << "Ataque:   " << Nihi.ATTACK << endl;
    cout << "Defensa:  " << Nihi.DEFENSE << endl;
    cout << "Arma:     " << Nihi.WEAPON << endl;
    cout << "Armadura: " << Nihi.ARMOR << endl;
}