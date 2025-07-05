#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/GolemData/Golem.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

void Checkpoint(Player& p, Golem& Gol, int PlayerHP, int PlayerMana, int GolemHp, int GolemMana, int GolemMaxHp) {
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Gol.HP = GolemHp;
    Gol.MANA = GolemMana;
    Gol.MAX_HP = GolemMaxHp;
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
    static bool UniqueMessage = false; // bandera para mostrar el mensaje de vulenrabildiad una sola vez
    if (p.MagicDefault == p.Magic1) { // magia ofensiva
        cout << "1. " << Gol.GolemName << " HP: " << Gol.HP << "/" << Gol.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch (opcionPlayerMagic) {
            case 1:
                system("cls");
                if (p.MANA < p.MANACOST_AT) {
                    cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                        << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
                } else {
                    cout << "Invocas tu magia y lanzas un hechizo contra el golem..." << endl;
                    p.MANA -= p.MANACOST_AT;
                    Gol.HP -= p.MAGIC_ATTACK * 2;
                    cout << Gol.GolemName << " recibió " << p.MAGIC_ATTACK * 2 << " de daño mágico!" << endl << endl;
                    if (!UniqueMessage) cout << "\033[33mEso fue super efectivo!. Te das cuenta que\033[0m " << Gol.GolemName << " \033[33mes vulnerable a la magia!\033[0m" << endl << endl;
                    UniqueMessage = true;
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
                if (p.MANA < p.MANACOST_HE) {
                    cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                        << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
                } else {
                    int HPbefore = p.HP;
                    int opcion_heal;
                    int HPtemp = p.HP + p.HEALTH_MAGIC;
                    if (HPtemp > p.MAX_HP) {
                        cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte del hechizo. ¿Proceder?\n1. Si\n2. No\n";
                        cin >> opcion_heal;
                        system("cls");
                        switch (opcion_heal) {
                            case 1:
                                p.HP = min(p.HP + p.HEALTH_MAGIC, p.MAX_HP);
                                p.MANA -= p.MANACOST_HE;
                                cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << p.HEALTH_MAGIC << " HP." << endl;
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
                        p.HP += p.HEALTH_MAGIC;
                        p.MANA -= p.MANACOST_HE;
                        cout << "\033[34m" << p.PlayerName << "\033[0m se curó +" << p.HEALTH_MAGIC << " HP." << endl;
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
    cout << "Pero su defensa es tan alta que el golpe no tiene efecto." << endl << endl;
}

void GolemAttackPlayer(Player& p, Golem& Gol) {
    int RNGolem = rand() % 101;
    int damage = (RNGolem < 50) ? Gol.ATTACK : Gol.CRITICAL_ATTACK;

    cout << Gol.GolemName << " levanta sus pesados brazos de piedra y golpea..." << endl << endl;
    if (RNGolem < 10){
        cout << Gol.GolemName << " Pese a su abrumador tamaño, logras esquivar su ataque!" << endl << endl;
    } else if (RNGolem < 30){
        if (p.DEFENSE > Gol.CRITICAL_ATTACK){
            cout << "El Golem es incapaz de penetrar tu gloriosa defensa" << endl;
        } else {
            cout << Gol.GolemName << " Te acesto un golpe crítico! Te mando a volar al otro lado de la cueva!" << endl;
            p.HP -= Gol.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Gol.CRITICAL_ATTACK - p.DEFENSE << " de daño critico y contundente! auch..." << endl << endl;
        }
    } else {
        if (p.DEFENSE > Gol.ATTACK){
            cout << "El Golem es incapaz de penetrar tu gloriosa defensa" << endl;
        } else {
            cout << Gol.GolemName << " Te demolio exitosamente! tus huesos sufren..." << endl;
            p.HP -= Gol.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Gol.ATTACK - p.DEFENSE << " de daño." << endl << endl;
        }
    }
}

void GolemBattle(Player& p, Golem& Gol) {
    int TempDefense = p.DEFENSE;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int GolemMaxHp = Gol.MAX_HP;
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
            cout << Gol.GolemName << " con su corazón de frío te pone a prueba!" << endl << endl;

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
                        cout << "Intentas provocar al golem, pero permanece imperturbable como una roca..." << endl << endl;
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

    bool ManaDepleted = (p.MANA <= 10);
        if (p.HP <= 0 || ManaDepleted) {
            if (!ManaDepleted){
                cout << Gol.GolemName << " ha derrotado a \033[34m" << p.PlayerName << "\033[0m" << endl;
            } else {
                cout << Gol.GolemName << " Aplasto a \033[34m" << p.PlayerName << "\033[0m En la oscuridad..." << endl;
            }

            while (option_GameOver != 1 && option_GameOver != 2){
            cout << "\033[31mGAME OVER\033[0m\n1. YES\n2. NO\n";
            cin >> option_GameOver;
            if (option_GameOver < 1 || option_GameOver > 2){
                DefaultError();
            }
        }

            switch (option_GameOver) {
                case 1:
                    system("cls");
                    Checkpoint(p, Gol, PlayerHp, PlayerMana, GolemHp, GolemMana, GolemMaxHp);
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

        if (Gol.HP <= Gol.MAX_HP * 0.5) { // mitad de vida
            cout << Gol.GolemName << " se detiene... y asiente lentamente. Baja los puños y sus ojos se volvieron pacificos..." << endl;
            Sleep(5000);
            Clear();
            cout << "¡Has pasado la prueba!...??" << endl;
            battleOver = true;
        }

        if (RegMana) p.MANA = min(p.MANA + 10, p.MAX_MANA);
    } while (!battleOver);
}
