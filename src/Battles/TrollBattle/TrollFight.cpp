#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/TrollData/Troll.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

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

void TrollBattle(Player& p, Troll& Tr){
    cout << "HOLA" << endl;
}