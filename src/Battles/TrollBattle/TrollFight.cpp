#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/TrollData/Troll.h"

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
                cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << " se comio la BANANA..." << endl;
                cout << "POTACIO" << endl;
                cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << " se siente poderoso... sus estadisticas aumentaron!" << endl;
                cout << "+30 HP, +30 MANA, +5 Ataque y +5 Defensa" << endl;
                p.ATTACK += 5;
                p.DEFENSE += 5;
                p.HP = min(p.HP + 30, p.MAX_HP);
                p.MANA = min(p.MANA + 10, p.MAX_MANA);
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

void Checkpoint(Player& p, Troll& troll, int PlayerHP, int PlayerMana, int TrollHp, int TrollMana) { 
    // Guardar las variables localmente para poder usar checkpoint
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    troll.HP = TrollHp;
    troll.MANA = TrollMana;
} // función local

void EnemyHpBar(Troll& troll) {
    int total_blocks = 10;
    int filled_blocks = (troll.HP * total_blocks) / troll.MAX_HP;
    if (troll.HP > 0 && filled_blocks == 0) {
        filled_blocks = 1;
    }
    int empty_blocks = total_blocks - filled_blocks;

    string color = (troll.HP > troll.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;

    for (int i = 0; i < filled_blocks; ++i) {
        cout << "█";
    }

    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) {
        cout << "█";
    }

    cout << "\033[0m " << troll.HP << "/" << troll.MAX_HP << endl << endl;
}

void PlayerMagic(Player& p, Troll& troll) {
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1) { // si magia es vendaval
        cout << "1. " << troll.TrollName << " HP: " << troll.HP << "/" << troll.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch (opcionPlayerMagic) {
        case 1:
            system("cls");
            if (p.MANA < 30) {
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                     << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                cout << "Usaste: " << p.MagicDefault << endl;
                Sleep(1000);
                cout << "El viento daño emocionalmente a " << troll.TrollName << endl;
                p.MANA -= 30;
                troll.HP -= 20;
                cout << troll.TrollName << " recibió 20 de daño!" << endl;
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            DefaultError();
            break;
        }

    } else if (p.MagicDefault == p.Magic2) { // si esta magia de curacion
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        system("cls");
        switch (opcionPlayerMagic) {
        case 1:
            if (p.MANA < 50) {
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                     << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                int HPbefore = p.HP; // para calcular solo la vida curada
                int opcion_heal;
                int HPtemp = p.HP + 20;

                if (HPtemp > p.MAX_HP) {
                    cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte o la totalidad del hechizo.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                    system("cls");
                    switch (opcion_heal) {
                    case 1:
                        p.HP = min(p.HP + 20, p.MAX_HP);
                        p.MANA -= 50;
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó: +" << p.HP - HPbefore << " HP";
                        break;
                    case 2:
                        system("cls");
                        break;
                    default:
                        system("cls");
                        cout << "Opción de comando inválida" << endl;
                        Sleep(1000); cout << endl;
                        system("cls");
                        break;
                    }
                } else {
                    p.HP += 20;
                    p.MANA -= 50;
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó, +20 HP";
                }
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opción de comando inválida" << endl;
            Sleep(1000); cout << endl;
            system("cls");
            break;
        }
    }
}

void TrollShowStats(Troll& troll) {
    cout << "Nombre: " << troll.TrollName << endl;
    cout << "HP: " << troll.HP << "/" << troll.MAX_HP << endl;
    cout << "MANA: " << troll.MANA << "/" << troll.MAX_MANA << endl;
    cout << "ATK: " << troll.ATTACK << " | DEF: " << troll.DEFENSE << endl;
}

void PlayerAttackTroll(Player& p, Troll& troll) {
    int RNG = rand() % 101;
    if (RNG < 25) {
        cout << "¡Fallaste el ataque!" << endl;
    } else if (RNG < 50) {
        cout << "¡Ataque crítico!" << endl;
        int damage = max(0, p.CRITICAL_ATTACK - troll.DEFENSE);
        troll.HP -= damage;
        cout << troll.TrollName << " recibió " << damage << " de daño crítico!" << endl;
    } else {
        cout << "Ataque exitoso!" << endl;
        int damage = max(0, p.ATTACK - troll.DEFENSE);
        troll.HP -= damage;
        cout << troll.TrollName << " recibió " << damage << " de daño!" << endl;
    }
}

void TrollAttackPlayer(Player& p, Troll& troll) {
    int RNG = rand() % 101;
    if (RNG < 25) {
        cout << troll.TrollName << " falló el ataque!" << endl;
    } else if (RNG < 50) {
        cout << troll.TrollName << " realizó un ataque crítico!" << endl;
        int damage = max(0, troll.CRITICAL_ATTACK - p.DEFENSE);
        p.HP -= damage;
        cout << p.PlayerName << " recibió " << damage << " de daño crítico!" << endl;
    } else {
        cout << troll.TrollName << " atacó exitosamente!" << endl;
        int damage = max(0, troll.ATTACK - p.DEFENSE);
        p.HP -= damage;
        cout << p.PlayerName << " recibió " << damage << " de daño!" << endl;
    }
 // MECÁNICA ESPECIAL: El troll te quita 10 de mana
    if (p.MANA >= 10) {
        p.MANA -= 10;
        troll.MANA = min(troll.MANA + 10, troll.MAX_MANA);
        cout << troll.TrollName << " drenó 10 de tu MANA y regeneró 10 de MANA!" << endl;
    } else {
        cout << troll.TrollName << " intentó drenar MANA pero no tienes suficiente!" << endl;
    }
}
