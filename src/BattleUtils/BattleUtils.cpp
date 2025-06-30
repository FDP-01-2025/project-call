#include <iostream>
#include <windows.h>
#include <algorithm>
#include "BattleUtils.h"

using namespace std;

void DefaultError(){
    system("cls");
    cout << "Opcion de comando invalida" << endl;
    Sleep(1000); cout << endl;
    system("cls");
}

void Items(Player& p, int option_item){
        system("cls");
            cout << "           -- INVENTARIO -- " << endl;
            cout << "   ITEM        CANTIDAD      EFECTO" << endl;
            cout << p.Item1 << ":        " << p.PotionsHP << "           +" << p.PoEffectHP << endl;
            cout << p.Item2 << ":      " << p.PotionsMANA << "           +" << p.PoEffectMANA << endl;
            cout << p.Item3 << ":           " << p.CantItem3 << "            " << "???" <<endl << endl;
            cout << "Seleccione que ITEM usar:\n1. HP\n2. MANA\n3. BANANA\n4. RETURN" << endl;
            cin >> option_item;

        system("cls");
            switch (option_item) {
            case 1: { // Pocion HP
                if (p.PotionsHP < 1) {
                    cout << "Ya no te quedan pociones de HP" << endl;
                } else {
                    int HPbefore = p.HP;
                    int HPtemp = p.HP + p.PoEffectHP;

                    if (HPtemp > p.MAX_HP) {
                        cout << "\033[31mDANGER:\033[0m Curarte ahora desperdiciará parte del efecto.\nProceder?\n1. Sí\n2. No\n";
                        int opcion_heal;
                        cin >> opcion_heal;
                        system("cls");

                        if (opcion_heal == 1) {
                            p.HP = min(p.HP + p.PoEffectHP, p.MAX_HP);
                            p.PotionsHP--;
                            cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << (p.HP - HPbefore) << " HP." << endl << endl;
                            } else {
                        }
                    } else {
                        p.HP = min(p.HP + p.PoEffectHP, p.MAX_HP);
                        p.PotionsHP--;
                        cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << p.PoEffectHP << " HP." << endl << endl;
                    }
                }
                break;
            }
            case 2: { // Pocion MANA
                if (p.PotionsMANA < 1) {
                    cout << "Ya no te quedan pociones de MANA" << endl;
                } else {
                    int MANAbefore = p.MANA;
                    int MANAtemp = p.MANA + p.PoEffectMANA;

                    if (MANAtemp > p.MAX_MANA) {
                        cout << "\033[31mDANGER:\033[0m Recuperar MANA ahora desperdiciará parte del efecto.\nProceder?\n1. Sí\n2. No\n";
                        int opcion_mana;
                        cin >> opcion_mana;
                        system("cls");

                        if (opcion_mana == 1) {
                            p.MANA = min(p.MANA + p.PoEffectMANA, p.MAX_MANA);
                            p.PotionsMANA--;
                            cout << "\033[34m" << p.PlayerName << "\033[0m recupero +" << (p.MANA - MANAbefore) << " \033[34mMANA\033[0m." << endl << endl;
                        } else {
                            system("cls");
                        }
                    } else {
                        p.MANA = min(p.MANA + p.PoEffectMANA, p.MAX_MANA);
                        p.PotionsMANA--;
                        cout << "\033[34m" << p.PlayerName << "\033[0m recupero +" << p.PoEffectMANA << " \033[34mMANA\033[0m." << endl << endl;
                    }
                }
                break;
            }
        case 3:
        system("cls");
            if (p.CantItem3 < 1){
                cout << "Ya no tienes BANANAS... tu triste..." << endl << endl;
            } else {
                cout << "\033[34m" << p.PlayerName << "\033[0m se comio la BANANA..." << endl;
                cout << "POTACIO" << endl;
                cout << "\033[34m" << p.PlayerName << "\033[0m se siente poderoso... sus estadisticas aumentaron!" << endl;
                cout << "+30 HP, +30 MANA, +5 Ataque y +5 Defensa" << endl;
                p.ATTACK += 5;
                p.DEFENSE += 5;
                p.HP = min(p.HP + 30, p.MAX_HP);
                p.MANA = min(p.MANA + 30, p.MAX_MANA);
                p.CantItem3--;
            }
            break;
        case 4:
        system("cls");
            break;
        default:
            DefaultError();
        break;
    }
}

void HpBar(Player& p) {
    int total_blocks = 10; // variable de la cantidad de bloques
    int filled_blocks = (p.HP * total_blocks) / p.MAX_HP; // calcula cuantos se deben llenar
    if (p.HP > 0 && filled_blocks == 0) { // funcion que evita si el jugador tiene < 10 de vida ya no hayan barras
    filled_blocks = 1;
    }   
    int empty_blocks = total_blocks - filled_blocks; // calcula los bloques vacios

    string color = (p.HP > p.MAX_HP * 0.3) ? "\033[33m" : "\033[31m"; // Amarillo o rojo dependiendo de la vida
    cout << "HP:   " << color;

    for (int i = 0; i < filled_blocks; ++i){ // imprime la barra de vida actual
        cout << "█";
    }

    cout << "\033[30m"; // Color gris
    for (int i = 0; i < empty_blocks; ++i){ // imprime la vida restada
        cout << "█";
    }

    cout << "\033[0m " << p.HP << "/" << p.MAX_HP << endl; // muestra el estado actual de tu vida
}

void ManaBar(Player& p){
    int total_blocks = 10;
    int filled_blocks = (p.MANA * total_blocks) / p.MAX_MANA;
    if (p.MANA > 0 && filled_blocks == 0){
    filled_blocks = 1;
    }
    int empty_blocks = total_blocks - filled_blocks;

    string color = (p.MANA > p.MAX_MANA * 0.3) ? "\033[34m" : "\033[35m"; // Amarillo o rojo dependiendo de la vida
    cout << "MANA: " << color;

    for (int i = 0; i < filled_blocks; i++){
        cout << "█";
    }

    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; i++){
        cout << "█";
    }

    cout << "\033[0m " << p.MANA << "/" << p.MAX_MANA << endl; // muestra el estado actual de tu mana
}