#include <iostream>
#include "PlayerData.h"
#include <windows.h>

Player Global_Data(){
    struct Player p;
    int Difficulty;

    cout << "Ingrese el nombre de su jugador: " << endl;
    cin >> p.PlayerName;
    system("cls");
    p.Level = 1;
    do {
    cout << "Escoja su dificultad:\n1. Normal\n2. Dificil\n3. Modo Desarrollador\n" << endl;
    cin >> Difficulty;
    if (Difficulty < 1 || Difficulty > 3) {
        cout << "Opcion invalida, intente otra vez." << endl;
    }
} while (Difficulty < 1 || Difficulty > 3);

system("cls");
    switch (Difficulty){
    case 1:
    cout << "Escogiste la dificultad normal, buena suerte en tu viaje!" << endl;
        p.HP = 100;
        p.MAX_HP = 100;
        p.ATTACK = 20;
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 5;
        p.MANA = 100;
        p.MAX_MANA = 100;
        p.MONEY = 100;
        p.KILLS = 0;
        p.PacifistPoints = 0;
        p.WEAPON = "Nothing";
        p.ARMOR = "Armadura de cuero";
        p.MagicDefault = "Magia vendaval (costo: 30 \033[34mMANA\033[0m)";
        p.Magic1 = "Magia vendaval (costo: 30 \033[34mMANA\033[0m)";
        p.Magic2 = "Magia curacion (costo: 50 \033[34mMANA\033[0m)";
        p.Item1 = "Pocion HP";
        p.Item2 = "Pocion MANA";
        p.Item3 = "Banana"; 
        p.PotionsHP = 2;
        p.PotionsMANA = 2;
        p.CantItem3 = 1;
        p.PoEffectHP = 30;
        p.PoEffectMANA = 30;
        p.KilledNaikaDummy = false;
        break;
    case 2:
    cout << "Elegiste algo desafiante, buena eleccion. Ahora tienes:\n1. 25% menos de vida.\n2. 50% menos de dano.\n3. 50% menos capacidad de mana.\ncomienzas sin un centavo.\nY sin armadura.\nMenos cantidad de pociones\n50% menos de eficiencia en pociones\nBuena suerte!." << endl << endl;
        p.HP = 75; 
        p.MAX_HP = 75; // 25% menos de hp
        p.ATTACK = 10; // 50% menos de daño
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 0;
        p.MANA = 50;
        p.MAX_MANA = 50; // 50% menos capacidad de mana
        p.MONEY = 0; // inicias sin dinero
        p.KILLS = 0;
        p.PacifistPoints = 0;
        p.WEAPON = "Nothing";
        p.ARMOR = "Nothing";
        p.MagicDefault = "Magia vendaval";
        p.Magic1 = "Magia vendaval (costo: 30 \033[34mMANA\033[0m)";
        p.Magic2 = "Magia curacion (costo: 50 \033[34mMANA\033[0m)";
        p.Item1 = "Pocion HP";
        p.Item2 = "Pocion MANA";
        p.Item3 = "Banana";
        p.PotionsHP = 1;
        p.PotionsMANA = 1;
        p.CantItem3 = 0;
        p.PoEffectHP = 15;
        p.PoEffectMANA = 15;
        p.KilledNaikaDummy = false;
        break;
    case 3:
    cout << "Activaste el modo desarrollador" << endl;
        p.Level = 100;
        p.HP = 9999;
        p.MAX_HP = 9999;
        p.ATTACK = 9999;
        p.CRITICAL_ATTACK = p.ATTACK*2;
        p.DEFENSE = 9999;
        p.MANA = 9999;
        p.MAX_MANA = 9999;
        p.MONEY = 9999;
        p.KILLS = 0;
        p.PacifistPoints = 0;
        p.WEAPON = "Arma de desarrollador";
        p.ARMOR = "Armadura de desarrollador";
        p.MagicDefault = "Magia vendaval";
        p.Magic1 = "Magia vendaval (costo: 30 \033[34mMANA\033[0m)";
        p.Magic2 = "Magia curacion (costo: 50 \033[34mMANA\033[0m)";
        p.Item1 = "Pocion HP";
        p.Item2 = "Pocion MANA";
        p.Item3 = "Banana";
        p.PotionsHP = 9999;
        p.PotionsMANA = 9999;
        p.CantItem3 = 9999;
        p.PoEffectHP = 9999;
        p.PoEffectMANA = 9999;
        p.KilledNaikaDummy = false;
        p.KilledEliteSlime = false;
        p.KilledTroll = false;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    return p;
}

void ShowStats(const Player& p){
    cout << "\033[3;4m-- Your STATS --\033[0m" << endl << endl;
    cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
    cout << "Nivel:    " << p.Level << endl;
    cout << "Vida:     " << p.HP << "/" << p.MAX_HP << endl;
    cout << "Mana:     " << p.MANA << "/" << p.MAX_MANA << endl;
    cout << "Ataque:   " << p.ATTACK << endl;
    cout << "Defensa:  " << p.DEFENSE << endl;
    cout << "Dinero:   " << p.MONEY << endl;
    cout << "Arma:     " << p.WEAPON << endl; 
    cout << "Armadura: " << p.ARMOR << endl;
    cout << "Magia:    " << p.MagicDefault << endl << endl;
}