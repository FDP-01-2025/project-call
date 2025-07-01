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

void PlayerMagic(Player& p, Troll& troll, bool& Return) {
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
        Return = true;
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
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó: +" << p.HP - HPbefore << " HP" << endl;
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
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó, ++" << p.HP - HPbefore << " HP" << endl;
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

void PlayerAttackTroll(Player& p, Troll& troll) {
    int RNG = rand() % 101;
    if (RNG < 25) {
        cout << "Te lanzas al ataque, pero tus golpes rebotan torpemente contra la dura piel de " << troll.TrollName << "." << endl;
        cout << "¡Has fallado el ataque!" << endl;
    } else if (RNG < 50) {
        cout << "Con determinación, encuentras un punto débil..." << endl;
        cout << "¡Golpe crítico!" << endl;
        int damage = max(0, p.CRITICAL_ATTACK - troll.DEFENSE);
        troll.HP -= damage;
        cout << troll.TrollName << " se retuerce de dolor tras recibir " << damage << " de daño crítico." << endl;
    } else {
        cout << "Avanzas con cautela y asestas un buen golpe..." << endl;
        int damage = max(0, p.ATTACK - troll.DEFENSE);
        troll.HP -= damage;
        cout << troll.TrollName << " recibió " << damage << " de daño." << endl;
    }
}

void TrollAttackPlayer(Player& p, Troll& Tr){
    int RNG = rand() % 101;

    if (RNG < 25){
        cout << Tr.TrollName << " levanta su enorme brazo, pero tropieza torpemente." << endl;
        cout << "¡El ataque falla!" << endl << endl;
    } else if (RNG < 50){
        if (p.DEFENSE > Tr.CRITICAL_ATTACK){
            cout << "El Troll no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << Tr.TrollName << " ruge con furia y lanza un demoledor golpe..." << endl;
            cout << "¡Es un impacto crítico!" << endl;
            p.HP -= Tr.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Tr.CRITICAL_ATTACK - p.DEFENSE << " de daño crítico, tambaleándose por la fuerza del golpe." << endl;
        }
    } else {
        if (p.DEFENSE > Tr.ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << Tr.TrollName << " balancea su garrote con fuerza bruta..." << endl;
            p.HP -= Tr.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Tr.ATTACK - p.DEFENSE << " de daño." << endl;
        }
    }

    // MECÁNICA ESPECIAL: El troll te quita 10 de mana
    cout << endl;
    if (p.MANA >= 10) {
        p.MANA -= 20;
        Tr.MANA = min(Tr.MANA + 10, Tr.MAX_MANA);
        cout << Tr.TrollName << " extiende su mano rúnica y drena 10 tu \033[34mMANA\033[0m, absorbiéndolo para fortalecerse." << endl;
    } else {
        cout << Tr.TrollName << " intenta absorber tu \033[34mMANA\033[0m, pero descubre que no tienes suficiente..." << endl;
    }
}

void TrollBattle(Player& p, Troll& Tr){
    int TempDefense = p.DEFENSE;
    int MercyPoints = 0;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int TrollHp = Tr.HP;
    int TrollMana = Tr.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;
    bool battleOver = false;
    bool RageTroll = false;
    bool Mercy = false;
    bool Return = false;

    do {
        int RNGTalk = rand() % 101;
        int RNGMercy = rand() % 101;
        bool RegMana = true;
        int RandomEvent = rand() % 101;

        cout << "Oponente: " << "\033[33m" << Tr.TrollName << "\033[0m" << endl;
        if (Mercy == false){
            cout << Tr.TrollName << " Esta determinado en pelear contigo!" << endl << endl;
        } else {
            cout << Tr.TrollName << " Parece agotado... pero le satisface su batalla" << endl << endl;
        }
        EnemyHpBar(Tr);
        if (!Mercy) {
            cout << Tr.TrollName << " Esta determinada" << endl << endl;
        } else {
            cout << Tr.TrollName << " Parece agotada" << endl << endl;
        }
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        HpBar(p);
        ManaBar(p);
        cout << "Piedad: " << MercyPoints << endl << endl;

        if (!Mercy) {
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        } else {
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. \033[33mMERCY\033[0m\n";
        }
        cin >> option;

    system("cls");
        switch (option) {
            case 1: // ATTACK
                cout << "1. " << Tr.TrollName << " HP: " << Tr.HP << "/" << Tr.MAX_HP << endl;
                cout << "2. RETURN" << endl;
                cin >> option_attack;
                switch (option_attack){
                    case 1:
                    system("cls");
                        PlayerAttackTroll(p, Tr);
                        cout << endl;
                        TrollAttackPlayer(p, Tr);
                        cout << endl;
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
            if (p.MagicDefault != p.Magic2){ // si te curas no te atacara
                system("cls");
                PlayerMagic(p, Tr, Return);
                cout << endl;
                if (!Return) {
                    TrollAttackPlayer(p, Tr);
                    cout << endl;
                    Return = false;
                }
            } else {
                system("cls");
                PlayerMagic(p, Tr, Return);
                cout << endl;
            }
            break;

            case 3: // ACTION
                system("cls");
                cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. PROVOCAR\n5. PLATICAR\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
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
                        ShowStatsTroll(Tr);
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;
                    case 3:
                        RegMana = false;
                        system("cls");
                        cout << "Intercambiar magia actual:\n";
                        cout << "1. Magia Vendaval\n2. Magia curacion\n3. RETURN\n\n";
                        cin >> option_exmagic;
                        switch (option_exmagic) {
                            case 1:
                                system("cls");
                                if (p.MagicDefault == p.Magic1) {
                                    cout << "Ya tienes equipada esta magia" << endl;
                                } else {
                                    p.MagicDefault = p.Magic1;
                                    cout << "Te equipaste: " << p.MagicDefault << endl;
                                }
                                Sleep(1000);
                                cout << endl;
                                break;
                            case 2:
                                system("cls");
                                if (p.MagicDefault == p.Magic2) {
                                    cout << "Ya tienes equipada esta magia" << endl;
                                } else {
                                    p.MagicDefault = p.Magic2;
                                    cout << "Te equipaste: " << p.MagicDefault << endl;
                                }
                                Sleep(1000);
                                cout << endl;
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

                    case 4: // PROVOCAR / RAGE
                        system("cls");
                        if (!RageTroll) {
                            cout << "Te burlaste de la patética apariencia de " << Tr.TrollName << endl;
                            cout << "...Provocaste al enemigo\n \n";
                            Sleep(1500);
                            cout << Tr.TrollName << " se enojó!\n";
                            cout << "Sus ojos se vuelven rojos! y desea tu muerte a toda costa...\n\n";
                            RageTroll = true;
                            Tr.ATTACK += 20;
                            Tr.DEFENSE = 0;
                            Tr.MAX_HP += 25;
                            Tr.HP = min(Tr.HP + 25, Tr.MAX_HP);
                            Sleep(1500);
                            cout << Tr.TrollName << " incrementó su vida!\n";
                            cout << Tr.TrollName << " incrementó su ataque!\n";
                            cout << Tr.TrollName << " La defensa ha caído!\n";
                        } else {
                            RegMana = false;
                            cout << Tr.TrollName << " ya está enojado\n";
                            cout << "El" << Tr.TrollName << " tiembla de furia!\n";
                        }
                        cout << endl;
                        break;

                    case 5: // HABLAR
                        system("cls");
                        cout << "Intentas hablar con El " << Tr.TrollName << endl;
                        Sleep(1500);
                        if (RNGTalk <= 20) {
                            cout << "El troll gruñe con desprecio... Te hiere emocionalmente (-10 HP)" << endl;
                            p.HP -= 10;
                        } else if (RNGTalk <= 40) {
                            cout << "Te ignora... permanece impasible." << endl;
                            RegMana = false;
                        } else if (RNGTalk <= 60) {
                            cout << "Su mirada se suaviza... Tal vez entiende tu oferta de paz... y su defensa baja!" << endl;
                            p.HP = min(p.HP + 5, p.MAX_HP);
                            Tr.DEFENSE -= 10;
                            cout << "Y recuperas +5 HP" << endl;
                        } else {
                            cout << "El troll se molesta y te arroja un pedrusco... cuidado!" << endl;
                            TrollAttackPlayer(p, Tr);
                        }
                        cout << endl;
                        break;

                    case 6: // PACIFICAR
                        system("cls");
                        cout << "Intentas pacificar a " << Tr.TrollName << "..." << endl;
                        Sleep(1000);

                    if (RNGMercy <= 15) { // 15% chance
                        cout << Tr.TrollName << " baja su enorme maza, te observa fijamente..." << endl;
                        Sleep(1500);
                        cout << "Y decide escucharte, aunque sea por un momento. (+1 piedad)" << endl;
                        MercyPoints++;
                    } else if (RNGMercy > 15 && RNGMercy <= 30) { // otro 15%
                        cout << "Sorprendentemente, " << Tr.TrollName << " suelta un gruñido extraño..." << endl;
                        Sleep(1500);
                        cout << "¡Parece conmovido por tus palabras! (+2 piedad)" << endl;
                        MercyPoints += 2;
                    } else if (RNGMercy > 30 && RNGMercy <= 60) { // 30%
                        cout << "El troll gruñe, dudoso..." << endl;
                        Sleep(1000);
                        cout << "Pero al final sacude la cabeza con fuerza y rechaza tu piedad." << endl;
                        Sleep(1000);
                        cout << "¡Te ataca en respuesta!" << endl;
                        TrollAttackPlayer(p, Tr);
                    } else { // 40%
                        cout << "Tus palabras rebotan en la dura mente del troll." << endl;
                        Sleep(1000);
                        cout << Tr.TrollName << " parece incluso más enfurecido... ¡se prepara para atacarte!" << endl;
                        TrollAttackPlayer(p, Tr);
                    }
                        cout << endl;
                        Sleep(1000);
                        break;


                    case 7: // DEFEND
                        RegMana = false;
                        system("cls");
                        cout << "Te defiendes del próximo ataque..." << endl;
                        cout << "Tu defensa se multiplica x3 y recuperas +30 de MANA" << endl << endl;
                        p.MANA = min(p.MANA + 30, p.MAX_MANA);
                        p.DEFENSE = TempDefense * 3;
                        TrollAttackPlayer(p, Tr);
                        p.DEFENSE = TempDefense;
                        break;

                    case 8:
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
                cout << endl;
                break;

            case 5: // MERCY
                if (!Mercy) {
                    cout << Tr.TrollName << " no acepta tu piedad..." << endl;
                    TrollAttackPlayer(p, Tr);
                } else {
                    cout << Tr.TrollName << " acepta tu piedad... ¡Victoria pacifista!" << endl;
                    p.PacifistPoints++;
                    battleOver = true;
                }
                break;

            default:
                DefaultError();
                break;
        }

        if (p.HP <= 0) {
            cout << Tr.TrollName << " ha derrotado a " << "\033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;
            switch (option_GameOver) {
                case 1:
                    system("cls");
                    cout << "Retornando al último checkpoint...\n" << endl;
                    Sleep(1000);
                    Checkpoint(p, Tr, PlayerHp, PlayerMana, TrollHp, TrollMana);
                    system("cls");
                    break;
                case 2:
                    cout << "Adiós... " << p.PlayerName << endl;
                    Sleep(2000);
                    exit(0);
                    break;
                default:
                    DefaultError();
                    break;
            }
        }

        if (Tr.HP <= 0) {
            cout << Tr.TrollName << " ha sido derrotado!" << endl;
            p.KILLS++;
            battleOver = true;
        }

        if (RegMana) {
            p.MANA = min(p.MANA + 10, p.MAX_MANA);
        }

        if (Tr.HP <= 50 || MercyPoints == 5) {
            Mercy = true;
        } else {
            Mercy = false;
        }
    } while (!battleOver);
}