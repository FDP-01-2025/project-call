#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/KingMagnus/KingMagnus.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

void Checkpoint(Player& p, KingMagnus& Km, int PlayerHP, int PlayerMana, int MagnusHp, int MagnusMana, int MagnusMaxHp) {
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Km.HP = MagnusHp;
    Km.MANA = MagnusMana;
    Km.MAX_HP = Km.MAX_HP;
}

void EnemyHpBar(KingMagnus& Km) {
    int total_blocks = 10;
    int filled_blocks = (Km.HP * total_blocks) / Km.MAX_HP;
    if (Km.HP > 0 && filled_blocks == 0) filled_blocks = 1;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (Km.HP > Km.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << Km.HP << "/" << Km.MAX_HP << endl << endl;
}

void PlayerMagic(Player& p, KingMagnus& Km, bool& Return) {
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1) { // si magia es vendaval
        cout << "1. " << Km.KingMagnusName << " HP: " << Km.HP << "/" << Km.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch (opcionPlayerMagic) {
        case 1:
            Clear();
            if (p.MANA < p.MANACOST_AT) {
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                    << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                cout << "Usaste: " << p.MagicDefault << endl;
                Sleep(1000);
                cout << "El viento daño emocionalmente a " << Km.KingMagnusName << endl;
                p.MANA -= p.MANACOST_AT;
                Km.HP -= p.MAGIC_ATTACK;
                cout << Km.KingMagnusName << " recibió " << p.MAGIC_ATTACK << " de daño!" << endl;
            }
            break;
        case 2:
        Return = true;
            Clear();
            break;
        default:
            DefaultError();
            break;
        }

    } else if (p.MagicDefault == p.Magic2) { // si esta magia de curacion
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        Clear();
        switch (opcionPlayerMagic) {
        case 1:
            if (p.MANA < p.MANACOST_HE) {
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente "
                    << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                int HPbefore = p.HP; // para calcular solo la vida curada
                int opcion_heal;
                int HPtemp = p.HP + p.HEALTH_MAGIC;

                if (HPtemp > p.MAX_HP) {
                    cout << "\033[31mDANGER:\033[0m Vas a desperdiciar parte de la cura.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                    Clear();
                    switch (opcion_heal) {
                    case 1:
                        p.HP = min(p.HP + p.HEALTH_MAGIC, p.MAX_HP);
                        p.MANA -= p.MANACOST_HE;
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó: +" << p.HP - HPbefore << " HP" << endl;
                        break;
                    case 2:
                        Clear();
                        break;
                    default:
                        Clear();
                        cout << "Opción de comando inválida" << endl;
                        Sleep(1000); cout << endl;
                        Clear();
                        break;
                    }
                } else {
                    p.HP += p.HEALTH_MAGIC;
                    p.MANA -= p.MANACOST_HE;
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó, +" << p.HP - HPbefore << " HP" << endl;
                    }
                }
            break;
        case 2:
            Clear();
            break;
        default:
            Clear();
            cout << "Opción de comando inválida" << endl;
            Sleep(1000); cout << endl;
            Clear();
            break;
        }
    }
}

void PlayerAttackMagnus(Player& p, KingMagnus& Km) {
    int RNG = rand() % 101;
    if (RNG < 25) {
        cout << "Te lanzas al ataque, pero tus golpes rebotan torpemente contra la armadura de " << Km.KingMagnusName << "." << endl;
        cout << "¡Has fallado el ataque!" << endl;
    } else if (RNG < 50) {
        cout << "Con determinación, encuentras un punto débil..." << endl;
        cout << "¡Golpe crítico!" << endl;
        Km.HP -= p.CRITICAL_ATTACK - Km.DEFENSE;
        cout << Km.KingMagnusName << " recibió " << p.CRITICAL_ATTACK - Km.DEFENSE << " de daño crítico." << endl;
    } else {
        cout << "Avanzas con cautela y asestas un buen golpe..." << endl;
        Km.HP -= p.ATTACK - Km.DEFENSE;
        cout << Km.KingMagnusName << " recibió " << p.ATTACK - Km.DEFENSE << " de daño." << endl;
    }
}

void MagnusAttackPlayer(Player& p, KingMagnus& Km) {
    int RNG = rand() % 101;

    if (RNG < 25) {
        cout << Km.KingMagnusName << " vacila por un momento." << endl;
        cout << "¡El ataque falla!" << endl << endl;
    } else if (RNG < 50) {
        if (p.DEFENSE > Km.CRITICAL_ATTACK) {
            cout << Km.KingMagnusName << " no logra penetrar tu defensa!" << endl;
        } else {
            cout << Km.KingMagnusName << " lanza un demoledor golpe..." << endl;
            cout << "¡Es un impacto crítico!" << endl;
            p.HP -= Km.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m recibió: " << Km.CRITICAL_ATTACK - p.DEFENSE << " de daño crítico." << endl;
        }
    } else {
        if (p.DEFENSE > Km.ATTACK) {
            cout << Km.KingMagnusName << " no logra penetrar tu defensa!" << endl;
        } else {
            cout << Km.KingMagnusName << " lanza un golpe firme..." << endl;
            p.HP -= Km.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m recibió: " << Km.ATTACK - p.DEFENSE << " de daño." << endl;
        }
    }

    cout << endl;
    if (p.MANA >= 10) {
        p.MANA -= 20;
        Km.MANA = min(Km.MANA + 10, Km.MAX_MANA);
        cout << Km.KingMagnusName << " absorbe -10 de tu \033[34mMANA\033[0m para fortalecerse." << endl;
    } else {
        cout << Km.KingMagnusName << " intenta absorber tu \033[34mMANA\033[0m, pero no tienes suficiente..." << endl;
    }
}

void KingMagnusBattle(Player& p, KingMagnus& Km) {
    int TempDefense = p.DEFENSE;
    int MercyPoints = 0;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int MagnusMaxHp = Km.MAX_HP;
    int MagnusHp = Km.HP;
    int MagnusMana = Km.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;
    bool battleOver = false;
    bool RageMagnus = false;
    bool Mercy = false;
    bool Return = false;

    do {
        int RNGTalk = rand() % 101;
        int RNGMercy = rand() % 101;
        bool RegMana = true;

        cout << "Oponente: \033[33m" << Km.KingMagnusName << "\033[0m" << endl;
        if (!Mercy)
            cout << Km.KingMagnusName << " está determinado a pelear contigo!" << endl << endl;
        else
            cout << Km.KingMagnusName << " parece cansado... pero no deja su espada." << endl << endl;

        EnemyHpBar(Km);
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        HpBar(p);
        ManaBar(p);
        cout << "Piedad: " << MercyPoints << endl << endl;

        if (!Mercy)
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        else
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. \033[33mMERCY\033[0m\n";
        cin >> option;

        Clear();
        switch (option) {
        case 1:
            cout << "1. " << Km.KingMagnusName << " HP: " << Km.HP << "/" << Km.MAX_HP << endl;
            cout << "2. RETURN" << endl;
            cin >> option_attack;
            switch (option_attack) {
            case 1:
                Clear();
                PlayerAttackMagnus(p, Km);
                cout << endl;
                MagnusAttackPlayer(p, Km);
                cout << endl;
                break;
            case 2:
                RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                RegMana = false;
                break;
            }
            break;

        case 2:
            RegMana = false;
            if (p.MagicDefault != p.Magic2) {
                Clear();
                PlayerMagic(p, Km, Return);
                cout << endl;
                if (!Return) {
                    MagnusAttackPlayer(p, Km);
                    cout << endl;
                    Return = false;
                }
            } else {
                Clear();
                PlayerMagic(p, Km, Return);
                cout << endl;
            }
            break;

        case 3:
            Clear();
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. PROVOCAR\n5. PLATICAR\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;
            switch (option_action) {
            case 1:
                RegMana = false;
                Clear();
                ShowStats(p);
                cin.ignore();
                cin.get();
                Clear();
                break;
            case 2:
                RegMana = false;
                Clear();
                ShowStatsKingMagnus(Km);
                cin.ignore();
                cin.get();
                Clear();
                break;
            case 3:
                RegMana = false;
                Clear();
                cout << "Intercambiar magia actual:\n1. Magia Vendaval\n2. Magia curacion\n3. RETURN\n\n";
                cin >> option_exmagic;
                switch (option_exmagic) {
                case 1:
                    Clear();
                    if (p.MagicDefault == p.Magic1)
                        cout << "Ya tienes equipada esta magia" << endl;
                    else {
                        p.MagicDefault = p.Magic1;
                        cout << "Te equipaste: " << p.MagicDefault << endl;
                    }
                    Sleep(1000); cout << endl;
                    break;
                case 2:
                    Clear();
                    if (p.MagicDefault == p.Magic2)
                        cout << "Ya tienes equipada esta magia" << endl;
                    else {
                        p.MagicDefault = p.Magic2;
                        cout << "Te equipaste: " << p.MagicDefault << endl;
                    }
                    Sleep(1000); cout << endl;
                    break;
                case 3:
                    RegMana = false;
                    Clear();
                    break;
                default:
                    DefaultError();
                    RegMana = false;
                    break;
                }
                break;

            case 4:
                Clear();
                if (!RageMagnus) {
                    cout << "Provocas al viejo rey con palabras hirientes..." << endl;
                    Sleep(1500);
                    cout << Km.KingMagnusName << " se enfurece!" << endl;
                    RageMagnus = true;
                    Km.ATTACK += 20;
                    Km.DEFENSE = 0;
                    Km.MAX_HP += 25;
                    Km.HP = min(Km.HP + 25, Km.MAX_HP);
                    Sleep(1500);
                    cout << Km.KingMagnusName << " incrementó su vida y ataque! Su defensa cayó a 0!" << endl;
                } else {
                    RegMana = false;
                    cout << Km.KingMagnusName << " ya está enfurecido..." << endl;
                }
                cout << endl;
                break;

            case 5:
                Clear();
                cout << "Intentas hablar con " << Km.KingMagnusName << endl;
                Sleep(1500);
                if (RNGTalk <= 20) {
                    cout << "El rey se ofende... pierdes -10 HP." << endl;
                    p.HP -= 10;
                } else if (RNGTalk <= 40) {
                    cout << "No responde a tus palabras." << endl;
                    RegMana = false;
                } else if (RNGTalk <= 60) {
                    cout << "Parece dudar, baja su defensa..." << endl;
                    p.HP = min(p.HP + 5, p.MAX_HP);
                    Km.DEFENSE -= 10;
                    cout << "Y recuperas +5 HP." << endl;
                } else {
                    cout << Km.KingMagnusName << " se molesta y contraataca!" << endl;
                    MagnusAttackPlayer(p, Km);
                }
                cout << endl;
                break;

            case 6:
                Clear();
                cout << "Intentas pacificar a " << Km.KingMagnusName << "..." << endl;
                Sleep(1000);
                if (RNGMercy <= 15) {
                    cout << Km.KingMagnusName << " parece escuchar... (+1 piedad)" << endl;
                    MercyPoints++;
                } else if (RNGMercy <= 30) {
                    cout << "El rey parece dudar... (+2 piedad)" << endl;
                    MercyPoints += 2;
                } else if (RNGMercy <= 60) {
                    cout << Km.KingMagnusName << " rechaza tu piedad y contraataca!" << endl;
                    MagnusAttackPlayer(p, Km);
                } else {
                    cout << Km.KingMagnusName << " se enfurece aún más!" << endl;
                    MagnusAttackPlayer(p, Km);
                }
                cout << endl;
                Sleep(1000);
                break;

            case 7:
                RegMana = false;
                Clear();
                cout << "Te defiendes, tu defensa se triplica y recuperas +30 de MANA" << endl;
                p.MANA = min(p.MANA + 30, p.MAX_MANA);
                p.DEFENSE = TempDefense * 3;
                MagnusAttackPlayer(p, Km);
                p.DEFENSE = TempDefense;
                break;

            case 8:
                RegMana = false;
                Clear();
                break;

            default:
                DefaultError();
                RegMana = false;
                break;
            }
            break;

        case 4:
            RegMana = false;
            Items(p, option_item);
            cout << endl;
            break;

        case 5:
            if (!Mercy) {
                cout << Km.KingMagnusName << " no acepta tu piedad..." << endl;
                MagnusAttackPlayer(p, Km);
            } else {
                cout << Km.KingMagnusName << " acepta tu piedad... ¡Victoria pacifista!" << endl;
                p.PacifistPoints++;
                battleOver = true;
            }
            break;

        default:
            DefaultError();
            break;
        }

        if (p.HP <= 0) {
            cout << Km.KingMagnusName << " ha derrotado a \033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;
            switch (option_GameOver) {
            case 1:
                Clear();
                cout << "Retornando al último checkpoint..." << endl;
                Sleep(1000);
                Checkpoint(p, Km, PlayerHp, PlayerMana, MagnusHp, MagnusMana, MagnusMaxHp);
                Clear();
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

        if (Km.HP <= 0) {
            cout << Km.KingMagnusName << " ha sido derrotado!" << endl;
            p.KILLS++;
            battleOver = true;
        }

        if (RegMana) p.MANA = min(p.MANA + 10, p.MAX_MANA);
        if (Km.HP <= 50 || MercyPoints == 5) Mercy = true;
        else Mercy = false;

    } while (!battleOver);
}
