#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/GolemData/Golem.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

void Checkpoint(Player& p, Golem& Gol, int PlayerHP, int PlayerMana, int GolemHp, int GolemMana) {
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Gol.HP = GolemHp;
    Gol.MANA = GolemMana;
}

void EnemyHpBar(Golem& Gol) {
    int total_blocks = 10;
    int filled_blocks = (Gol.HP * total_blocks) / Gol.MAX_HP;
    if (Gol.HP > 0 && filled_blocks == 0) filled_blocks = 1;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (Gol.HP > Gol.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << Gol.HP << "/" << Gol.MAX_HP << endl << endl;
}

void PlayerMagic(Player& p, Golem& Gol, bool& Return) {
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1) { // magia ofensiva
        cout << "1. " << Gol.GolemName << " HP: " << Gol.HP << "/" << Gol.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch (opcionPlayerMagic) {
            case 1:
                system("cls");
                if (p.MANA < 30) {
                    cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                        << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
                } else {
                    cout << "Invocas tu magia y lanzas un hechizo contra el golem..." << endl;
                    p.MANA -= 30;
                    Gol.HP -= 20;
                    cout << Gol.GolemName << " recibió 20 de daño mágico!" << endl;
                }
                break;
            case 2:
                Return = true;
                system("cls");
                break;
            default:
                DefaultError();
                break;
        }

    } else if (p.MagicDefault == p.Magic2) { // magia de curación
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
                    int HPbefore = p.HP;
                    int opcion_heal;
                    int HPtemp = p.HP + 20;
                    if (HPtemp > p.MAX_HP) {
                        cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte del hechizo. ¿Proceder?\n1. Si\n2. No\n";
                        cin >> opcion_heal;
                        system("cls");
                        switch (opcion_heal) {
                            case 1:
                                p.HP = min(p.HP + 20, p.MAX_HP);
                                p.MANA -= 50;
                                cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << p.HP - HPbefore << " HP" << endl;
                                break;
                            case 2:
                                system("cls");
                                break;
                            default:
                                system("cls");
                                cout << "Opción inválida" << endl;
                                Sleep(1000);
                                break;
                        }
                    } else {
                        p.HP += 20;
                        p.MANA -= 50;
                        cout << "\033[34m" << p.PlayerName << "\033[0m se curó +20 HP" << endl;
                    }
                }
                break;
            case 2:
                system("cls");
                break;
            default:
                system("cls");
                cout << "Opción inválida" << endl;
                Sleep(1000);
                break;
        }
    }
}

void PlayerAttackGolem(Player& p, Golem& Gol) {
    cout << "Intentas atacar al golem con tus armas..." << endl;
    cout << "Pero su defensa es tan alta que el golpe no tiene efecto." << endl;
}

void GolemAttackPlayer(Player& p, Golem& Gol) {
    int RNG = rand() % 101;
    int damage = (RNG < 50) ? Gol.ATTACK : Gol.CRITICAL_ATTACK;

    cout << Gol.GolemName << " levanta sus pesados brazos de piedra y golpea..." << endl;
    if (p.DEFENSE > damage) {
        cout << "¡Bloqueaste el golpe gracias a tu defensa!" << endl;
    } else {
        int final_damage = damage - p.DEFENSE;
        p.HP -= final_damage;
        if (damage == Gol.CRITICAL_ATTACK)
            cout << "¡Golpe crítico! ";
        cout << p.PlayerName << " recibe " << final_damage << " de daño." << endl;
    }
}

void GolemBattle(Player& p, Golem& Gol) {
    int TempDefense = p.DEFENSE;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int GolemHp = Gol.HP;
    int GolemMana = Gol.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;
    bool battleOver = false;
    bool RageGolem = false;
    bool Return = false;

    do {
        bool RegMana = true;

        cout << "Oponente: \033[33m" << Gol.GolemName << "\033[0m" << endl;
        EnemyHpBar(Gol);
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        HpBar(p);
        ManaBar(p);
        cout << endl;
        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. HABLAR\n";
        cin >> option;
        system("cls");

        switch (option) {
            case 1: // ATTACK
                cout << "1. Atacar a " << Gol.GolemName << endl;
                cout << "2. RETURN" << endl;
                cin >> option_attack;
                switch (option_attack) {
                    case 1:
                        system("cls");
                        PlayerAttackGolem(p, Gol);
                        GolemAttackPlayer(p, Gol);
                        break;
                    case 2:
                        RegMana = false;
                        system("cls");
                        break;
                    default:
                        DefaultError();
                        RegMana = false;
                        break;
                }
                break;

            case 2: // MAGIC
                RegMana = false;
                PlayerMagic(p, Gol, Return);
                if (!Return) {
                    GolemAttackPlayer(p, Gol);
                    Return = false;
                }
                break;

            case 3: // ACTION
                system("cls");
                cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. PROVOCAR\n5. DEFEND\n6. RETURN\n";
                cin >> option_action;
                switch (option_action) {
                    case 1:
                        RegMana = false;
                        system("cls");
                        ShowStats(p);
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;
                    case 2:
                        RegMana = false;
                        system("cls");
                        ShowStatsGolem(Gol);
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;
                    case 3:
                        RegMana = false;
                        system("cls");
                        cout << "Intercambiar magia:\n1. Vendaval\n2. Curación\n3. RETURN\n";
                        cin >> option_exmagic;
                        switch (option_exmagic) {
                            case 1:
                                if (p.MagicDefault != p.Magic1) {
                                    p.MagicDefault = p.Magic1;
                                    cout << "Equipaste: " << p.MagicDefault << endl;
                                } else {
                                    cout << "Ya tienes equipada esta magia." << endl;
                                }
                                Sleep(1000);
                                break;
                            case 2:
                                if (p.MagicDefault != p.Magic2) {
                                    p.MagicDefault = p.Magic2;
                                    cout << "Equipaste: " << p.MagicDefault << endl;
                                } else {
                                    cout << "Ya tienes equipada esta magia." << endl;
                                }
                                Sleep(1000);
                                break;
                            case 3:
                                RegMana = false;
                                system("cls");
                                break;
                            default:
                                DefaultError();
                                RegMana = false;
                                break;
                        }
                        break;
                    case 4: // PROVOCAR
                        RegMana = false;
                        system("cls");
                        cout << "Intentas provocar al golem, pero permanece imperturbable como una roca..." << endl;
                        break;
                    case 5: // DEFEND
                        RegMana = false;
                        system("cls");
                        cout << "Te pones en guardia, duplicas tu defensa este turno y recuperas +20 MANA." << endl;
                        p.MANA = min(p.MANA + 20, p.MAX_MANA);
                        p.DEFENSE = TempDefense * 2;
                        GolemAttackPlayer(p, Gol);
                        p.DEFENSE = TempDefense;
                        break;
                    case 6:
                        RegMana = false;
                        system("cls");
                        break;
                    default:
                        DefaultError();
                        RegMana = false;
                        break;
                }
                break;

            case 4: // ITEM
                RegMana = false;
                Items(p, option_item);
                GolemAttackPlayer(p, Gol);
                break;

            case 5: // HABLAR
                RegMana = false;
                system("cls");
                cout << "Intentaste hablar con el golem... Solo entiende el idioma de los golpes." << endl;
                Sleep(1500);
                GolemAttackPlayer(p, Gol);
                break;

            case 6: // HABLAR
                RegMana = false;
                system("cls");
                cout << "Intentaste hablar con el golem..." << endl;
                Sleep(1000);
                cout << "Pero solo entiende el idioma de los golpes." << endl;
                Sleep(1500);
                break;

            default:
                DefaultError();
                break;
        }

        if (p.HP <= 0) {
            cout << Gol.GolemName << " ha derrotado a \033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m\n1. YES\n2. NO\n";
            cin >> option_GameOver;
            switch (option_GameOver) {
                case 1:
                    system("cls");
                    Checkpoint(p, Gol, PlayerHp, PlayerMana, GolemHp, GolemMana);
                    break;
                case 2:
                    cout << "Adiós, " << p.PlayerName << endl;
                    exit(0);
                    break;
                default:
                    DefaultError();
                    break;
            }
        }

        if (Gol.HP <= 150) { // mitad de vida
            cout << Gol.GolemName << " se detiene... y asiente lentamente." << endl;
            cout << "¡Has pasado la prueba!" << endl;
            battleOver = true;
        }

        if (RegMana) p.MANA = min(p.MANA + 10, p.MAX_MANA);
    } while (!battleOver);
}
