#include <iostream>
#include "Hades.h"
using namespace std;

DHades Hades_Data(){
    struct DHades inf;
    inf.HadesName = "\033[31mRey del inframundo Hades\033[0m";
    inf.Level = 100;
    inf.HP = 10000;
    inf.MAX_HP = 10000;
    inf.ATTACK = 30;
    inf.DEFENSE = 40;
    inf.MANA = 100;
    inf.MAX_MANA = 100;
    inf.WEAPON = "Guadaña del Abismo eterno";
    inf.ARMOR = "Manto del Tártaro";
    return inf;
}

void ShowStats(const DHades& h){
    cout << "\033[31m=== ESTADÍSTICAS DEL ENEMIGO ===\033[0m" << endl;
    cout << "Nombre: " << h.HadesName << endl;
    cout << "Nivel: " << h.Level << endl;
    cout << "HP: " << h.HP << "/" << h.MAX_HP << endl;
    cout << "MANA: " << h.MANA << "/" << h.MAX_MANA << endl;
    cout << "Ataque: " << h.ATTACK << endl;
    cout << "Defensa: " << h.DEFENSE << endl;
    cout << "Arma: " << h.WEAPON << endl;
    cout << "Armadura: " << h.ARMOR << endl;
    cout << "\033[31m================================\033[0m" << endl;
}