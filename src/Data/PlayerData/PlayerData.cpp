#include <iostream>
#include "PlayerData.h"

struct Player Global_Data(){
    struct Player p;
    int Difficulty;

    cout << "Ingrese el nombre de su jugador: " << endl;
    cin >> p.PlayerName;
    system("cls");
    p.Level = 1;
    cout << "Escoja su dificultad:\n1. Normal\n2. Dificil\n3. Modo Desarrollador\n" << endl;
    cin >> Difficulty;

system("cls");
    switch (Difficulty){
    case 1:
    cout << "Escogiste la dificultad normal, buena suerte en tu viaje!" << endl;
        p.HP = 100;
        p.MAX_HP = 100;
        p.ATTACK = 20;
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 0;
        p.MANA = 100;
        p.MAX_MANA = 100;
        p.MONEY = 50;
        break;
    case 2:
    cout << "Elegiste algo desafiante, buena eleccion. Ahora tienes:\n1. 25% menos de vida.\n2. 50% menos de dano.\n3. 50% menos capacidad de mana.\nY comienzas sin un centavo.\nBuena suerte!." << endl << endl;
        p.HP = 75; 
        p.MAX_HP = 75; // 25% menos de hp
        p.ATTACK = 10; // 50% menos de daño
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 0;
        p.MANA = 50;
        p.MAX_MANA = 50; // 50% menos de mana
        p.MONEY = 0; // inicias sin dinero
        break;
    case 3:
    cout << "Activaste el modo desarrollador" << endl;
        p.HP = 9999;
        p.MAX_HP = 9999;
        p.ATTACK = 9999;
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 9999;
        p.MANA = 9999;
        p.MAX_MANA = 9999;
        p.MONEY = 9999;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    return p;
}

void ShowStats(Player p) {
    cout << "\033[3;4m-- Your STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
    cout << "Nivel:   " << p.Level << endl;
    cout << "Vida:    " << p.HP << "/" << p.MAX_HP << endl;
    cout << "Mana:    " << p.MANA << "/" << p.MAX_MANA << endl;
    cout << "Ataque:  " << p.ATTACK << endl;
    cout << "Defensa: " << p.DEFENSE << endl;
    cout << "Dinero:  " << p.MONEY << endl << endl;
}