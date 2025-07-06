#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> // para usar min y max
#include "Data/PlayerData/PlayerData.h"
#include "Data/KingMagnus/KingMagnus.h" // incluir struct del Rey Magnus
#include "BattleUtils/BattleUtils.h"
using namespace std;

// Barra de vida dinámica para el Rey Magnus
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

// Guardar variables del checkpoint para reiniciar stats básicos
void Checkpoint(Player& p, KingMagnus& Km, int PlayerHP, int PlayerMana, int KmHp, int KmMana, int KmMaxHp) {
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Km.HP = KmHp;
    Km.MANA = KmMana;
    Km.MAX_HP = KmMaxHp; // restaurar también la vida máxima si se altera
}

// Ataque con magia (puede ser ofensiva o curativa)
void PlayerMagic(Player& p, KingMagnus& Km, bool& Return) {
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1) { // magia ofensiva
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
                cout << "Golpeas a " << Km.KingMagnusName << " con tu magia..." << endl;
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

    } else if (p.MagicDefault == p.Magic2) { // magia curativa
        cout << "1. " << "\033[34m" << p.PlayerName << "\033[0m" << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        Clear();
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
                    cout << "\033[31mDANGER:\033[0m Vas a desperdiciar parte de la cura.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                    Clear();
                    if (opcion_heal == 1) {
                        p.HP = min(p.HP + p.HEALTH_MAGIC, p.MAX_HP);
                        p.MANA -= p.MANACOST_HE;
                        cout << p.PlayerName << " se curó: +" << p.HP - HPbefore << " HP" << endl;
                    }
                } else {
                    p.HP += p.HEALTH_MAGIC;
                    p.MANA -= p.MANACOST_HE;
                    cout << p.PlayerName << " se curó: +" << p.HP - HPbefore << " HP" << endl;
                }
            }
            break;
        case 2:
            Clear();
            break;
        default:
            DefaultError();
            break;
        }
    }
}

void KingMagnusBattle(Player& p, KingMagnus& Km) {
    int TempDefense = p.DEFENSE;
    int MercyPoints = 0;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int MagnusHp = Km.HP;
    int MagnusMana = Km.MANA;
    int MagnusMaxHp = Km.MAX_HP;

    int option, option_action, option_exmagic, option_item, option_GameOver;
    bool battleOver = false;
    bool Mercy = false;
    bool Return = false;

    do {
        int RNGTalk = rand() % 101;
        int RNGMercy = rand() % 101;
        bool RegMana = true;  // bandera para regenerar mana

        cout << "Oponente: \033[33m" << Km.KingMagnusName << "\033[0m" << endl;
        if (!Mercy)
            cout << Km.KingMagnusName << " observa con cansancio, pero sigue dispuesto a pelear..." << endl << endl;
        else
            cout << Km.KingMagnusName << " parece ceder ante el peso del pasado..." << endl << endl;

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
            case 1: // ATTACK
                cout << "Golpeas con tus puños al debilitado rey..." << endl;
                Sleep(1000);
                int dmg = max(0, p.ATTACK - Km.DEFENSE);
                Km.HP -= dmg;
                cout << Km.KingMagnusName << " recibe " << dmg << " de daño." << endl;
                Sleep(1000);

                // Magnus ataca de vuelta
                cout << Km.KingMagnusName << " responde con un golpe pesado..." << endl;
                Sleep(1000);
                int dmgFromMagnus = max(0, Km.ATTACK - p.DEFENSE);
                p.HP -= dmgFromMagnus;
                cout << "\033[34m" << p.PlayerName << "\033[0m recibe " << dmgFromMagnus << " de daño." << endl;
                Sleep(1000);
                break;

            case 2: // MAGIC
                RegMana = false;
                Clear();
                PlayerMagic(p, Km, Return);
                cout << endl;
                if (!Return) {
                    cout << Km.KingMagnusName << " reacciona y contraataca..." << endl;
                    Sleep(1000);
                    int counterDmg = max(0, Km.ATTACK - p.DEFENSE);
                    p.HP -= counterDmg;
                    cout << "\033[34m" << p.PlayerName << "\033[0m recibe " << counterDmg << " de daño." << endl;
                    Sleep(1000);
                }
                break;

            case 3: // ACTION
                Clear();
                cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. HABLAR\n5. PACIFICAR\n6. DEFEND\n7. RETURN\n";
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
                        cout << "Intercambiar magia actual:\n";
                        cout << "1. Magia Vendaval\n2. Magia Curación\n3. RETURN\n";
                        cin >> option_exmagic;
                        switch (option_exmagic) {
                            case 1:
                                if (p.MagicDefault == p.Magic1)
                                    cout << "Ya tienes equipada esta magia." << endl;
                                else {
                                    p.MagicDefault = p.Magic1;
                                    cout << "Te equipaste: " << p.MagicDefault << endl;
                                }
                                Sleep(1000);
                                break;
                            case 2:
                                if (p.MagicDefault == p.Magic2)
                                    cout << "Ya tienes equipada esta magia." << endl;
                                else {
                                    p.MagicDefault = p.Magic2;
                                    cout << "Te equipaste: " << p.MagicDefault << endl;
                                }
                                Sleep(1000);
                                break;
                            default:
                                break;
                        }
                        Clear();
                        break;

                    case 4: // HABLAR
                        Clear();
                        cout << "Intentas hablar al corazón del antiguo rey..." << endl;
                        Sleep(1000);
                        if (RNGTalk < 20) {
                            cout << "Recuerdos de su pasado lo estremecen... su defensa disminuye." << endl;
                            Km.DEFENSE -= 5;
                        } else if (RNGTalk < 40) {
                            cout << "El rey parece dudar por un segundo... pero vuelve a endurecer su mirada." << endl;
                        } else {
                            cout << Km.KingMagnusName << " no reacciona, perdido en su propia culpa." << endl;
                        }
                        break;

                    case 5: // PACIFICAR
                        Clear();
                        cout << "Buscas tocar su alma rota..." << endl;
                        Sleep(1000);
                        if (RNGMercy < 15) {
                            cout << Km.KingMagnusName << " baja la guardia, recordando días más pacíficos. (+1 piedad)" << endl;
                            MercyPoints++;
                        } else if (RNGMercy < 30) {
                            cout << "Una lágrima resbala por su mejilla... (+2 piedad)" << endl;
                            MercyPoints += 2;
                        } else {
                            cout << "El rey descarta tu piedad con un suspiro cansado." << endl;
                        }
                        break;

                    case 6: // DEFEND
                        RegMana = false;
                        Clear();
                        cout << "Te preparas para defenderte..." << endl;
                        p.DEFENSE = TempDefense * 2;
                        Sleep(1000);
                        cout << Km.KingMagnusName << " intenta atacarte, pero resistes mejor gracias a tu defensa reforzada." << endl;
                        int dmgReduced = max(0, Km.ATTACK - p.DEFENSE);
                        p.HP -= dmgReduced;
                        cout << "\033[34m" << p.PlayerName << "\033[0m recibe " << dmgReduced << " de daño." << endl;
                        p.DEFENSE = TempDefense;
                        break;

                    case 7:
                        RegMana = false;
                        Clear();
                        break;

                    default:
                        break;
                }
                break;

            case 4: // ITEM
                RegMana = false;
                Items(p, option_item);
                break;

            case 5: // MERCY
                if (MercyPoints >= 3 || Km.HP <= 30) {
                    cout << Km.KingMagnusName << " acepta tu piedad... la batalla termina." << endl;
                    p.PacifistPoints++;
                    battleOver = true;
                } else {
                    cout << Km.KingMagnusName << " no está listo para rendirse aún." << endl;
                    int counter = max(0, Km.ATTACK - p.DEFENSE);
                    p.HP -= counter;
                    cout << "\033[34m" << p.PlayerName << "\033[0m recibe " << counter << " de daño." << endl;
                }
                break;

            default:
                DefaultError();
                break;
        }

        // Check de muerte
        if (p.HP <= 0) {
            cout << Km.KingMagnusName << " ha derrotado a " << p.PlayerName << endl;
            cout << "\033[31mGAME OVER\033[0m\n1. YES\n2. NO\n";
            cin >> option_GameOver;
            switch (option_GameOver) {
                case 1:
                    Clear();
                    cout << "Retornando al último checkpoint...\n";
                    Sleep(1000);
                    Checkpoint(p, Km, PlayerHp, PlayerMana, MagnusHp, MagnusMana, MagnusMaxHp);
                    break;
                default:
                    cout << "Adiós, valiente." << endl;
                    exit(0);
            }
        }

        if (Km.HP <= 0) {
            cout << Km.KingMagnusName << " cae derrotado..." << endl;
            p.KILLS++;
            battleOver = true;
        }

        if (RegMana)
            p.MANA = min(p.MANA + 10, p.MAX_MANA);

        // Condición para que el rey acepte piedad
        if (MercyPoints >= 3 || Km.HP <= 30)
            Mercy = true;
        else
            Mercy = false;

    } while (!battleOver);
}
