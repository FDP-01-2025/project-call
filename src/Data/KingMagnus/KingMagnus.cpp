#include <iostream>
#include "KingMagnus.h"
using namespace std;

// Función para inicializar los datos de King Magnus
KingMagnus KMagnus_Data(){
    KingMagnus Km;
    Km.KingMagnusName = "\033[33mKing Magnus, el Rey Implacable\033[0m";  // Nombre con color amarillo
    Km.Level = 30;
    Km.HP = 500;
    Km.MAX_HP = 500;
    Km.ATTACK = 40;
    Km.CRITICAL_ATTACK = Km.ATTACK * 3;
    Km.DEFENSE = 50;
    Km.MANA = 150;
    Km.MAX_MANA = 150;
    Km.WEAPON = "Espada Real de Magnus";
    Km.ARMOR = "Armadura del León Dorado";
    return Km;
}

// Función para mostrar las estadísticas del Rey Magnus
void ShowStatsKingMagnus(const KingMagnus& Km){
    cout << "\033[3;4m-- KING MAGNUS STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << Km.KingMagnusName << "\033[0m" << endl;
    cout << "Nivel:    " << Km.Level << endl;
    cout << "Vida:     " << Km.HP << "/" << Km.MAX_HP << endl;
    cout << "Mana:     " << Km.MANA << "/" << Km.MAX_MANA << endl;
    cout << "Ataque:   " << Km.ATTACK << endl;
    cout << "Critico:  " << Km.CRITICAL_ATTACK << endl;
    cout << "Defensa:  " << Km.DEFENSE << endl;
    cout << "Arma:     " << Km.WEAPON << endl;
    cout << "Armadura: " << Km.ARMOR << endl;
}
// Fin del código para KingMagnus.cpp