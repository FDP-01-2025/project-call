#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> // para usar min y max
#include "Data/PlayerData/PlayerData.h"
#include "Data/NihilusData/Nihilus.h" // librería del jefe Nihilus
#include "BattleUtils/BattleUtils.h"
using namespace std;
// Nihilus, el Vacío Andante ha emergido*

// Barra de vida dinámica del enemigo
void EnemyHpBar(Nihilus& Nihi){
    int total_blocks = 10;
    int filled_blocks = (Nihi.HP * total_blocks) / Nihi.MAX_HP;
    if (Nihi.HP > 0 && filled_blocks == 0) filled_blocks = 1;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (Nihi.HP > Nihi.MAX_HP * 0.3) ? "\033[35m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << Nihi.HP << "/" << Nihi.MAX_HP << endl << endl;
}

// Función local: restaurar checkpoint
void Checkpoint(Player& p, Nihilus& Nihi, int PlayerHP, int PlayerMana, int NihiHp, int NihiMana, int NihiMaxHp){
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Nihi.HP = NihiHp;
    Nihi.MANA = NihiMana;
    Nihi.MAX_HP = NihiMaxHp;
}

// Función para magia del jugador
void PlayerMagic(Player& p, Nihilus& Nihi, bool& Return){
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1){ // magia ofensiva
        cout << "1. " << Nihi.NihilusName << " HP: " << Nihi.HP << "/" << Nihi.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch(opcionPlayerMagic){
        case 1:
            Clear();
            if (p.MANA < p.MANACOST_AT){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente (" << p.MANA << "/" << p.MAX_MANA << ")" << endl;
            } else {
                cout << "Usaste: " << p.MagicDefault << endl;
                Sleep(1000);
                Nihi.HP -= p.MAGIC_ATTACK;
                p.MANA -= p.MANACOST_AT;
                cout << Nihi.NihilusName << " recibió " << p.MAGIC_ATTACK << " de daño!" << endl;
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
    } else { // magia de curación
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;
        Clear();

        switch(opcionPlayerMagic){
        case 1:
            if (p.MANA < p.MANACOST_HE){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente." << endl;
            } else {
                int HPbefore = p.HP;
                int HPtemp = p.HP + p.HEALTH_MAGIC;
                if (HPtemp > p.MAX_HP){
                    cout << "\033[31mDANGER:\033[0m Vas a desperdiciar parte de la curación.\n1. Sí\n2. No\n";
                    cin >> opcionPlayerMagic;
                    Clear();
                    if (opcionPlayerMagic == 1){
                        p.HP = min(HPtemp, p.MAX_HP);
                        p.MANA -= p.MANACOST_HE;
                        cout << p.PlayerName << " se curó +" << p.HP - HPbefore << " HP" << endl;
                    }
                } else {
                    p.HP = HPtemp;
                    p.MANA -= p.MANACOST_HE;
                    cout << p.PlayerName << " se curó +" << p.HEALTH_MAGIC << " HP" << endl;
                }
            }
            break;
        case 2:
            Clear();
            break;
        default:
            Clear();
            DefaultError();
            break;
        }
    }
}

// Ataque normal del jugador a Nihilus
void PlayerAttackNihilus(Player& p, Nihilus& Nihi){
    int RNG = rand() % 101;
    if (RNG < 25){
        Clear();
        cout << "Tu ataque se desvanece en el vacío... fallaste!" << endl;
    } else if (RNG < 50){
        Clear();
        if (Nihi.DEFENSE > p.CRITICAL_ATTACK){
            cout << "El vacío bloquea incluso tu golpe crítico!" << endl;
        } else {
            cout << "¡Golpe crítico!" << endl;
            Nihi.HP -= p.CRITICAL_ATTACK - Nihi.DEFENSE;
            cout << Nihi.NihilusName << " recibió " << p.CRITICAL_ATTACK - Nihi.DEFENSE << " de daño crítico!" << endl;
        }
    } else {
        Clear();
        if (Nihi.DEFENSE > p.ATTACK){
            cout << "El vacío desvía tu golpe..." << endl;
        } else {
            Nihi.HP -= p.ATTACK - Nihi.DEFENSE;
            cout << Nihi.NihilusName << " recibió " << p.ATTACK - Nihi.DEFENSE << " de daño!" << endl;
        }
    }
}

// Nihilus puede robar o atacar
void NihilusAttackOrSteal(Player& p, Nihilus& Nihi, int turn){
    int stealChance = min(60, 20 + turn * 2); // cada turno mayor chance de robar
    int RNG = rand() % 100;
    if (RNG < stealChance){
        cout << Nihi.NihilusName << " se mueve en sombras y roba algo..." << endl;
        if (p.MONEY >= 50){
            p.MONEY -= 50;
            cout << "Perdiste 50 de oro!" << endl;
        } else if (p.MONEY > 0){
            cout << "Perdiste " << p.MONEY << " de oro!" << endl;
            p.MONEY = 0;
        } else {
            cout << "No tienes nada que pueda robarte..." << endl;
        }
        cout << "No te ataca este turno." << endl;
    } else {
        int RNG2 = rand() % 101;
        if (RNG2 < 25) {
            cout << Nihi.NihilusName << " falla su ataque!" << endl;
        } else if (RNG2 < 50) {
            if (p.DEFENSE > Nihi.CRITICAL_ATTACK) {
                cout << "Nihilus no es capaz de penetrar tu defensa!" << endl;
            } else {
                cout << Nihi.NihilusName << " convoca las sombras y lanza un golpe crítico..." << endl;
                cout << "¡Es un impacto crítico del vacío!" << endl;
                p.HP -= Nihi.CRITICAL_ATTACK - p.DEFENSE;
                cout << "\033[34m" << p.PlayerName << "\033[0m" 
                    << " recibió: " << Nihi.CRITICAL_ATTACK - p.DEFENSE 
                    << " de daño crítico, tambaleándose por la fuerza oscura." << endl;
                }
            } else {
            if (p.DEFENSE > Nihi.ATTACK) {
                cout << "Nihilus intenta herirte, pero tu defensa lo detiene!" << endl;
            } else {
                cout << Nihi.NihilusName << " ataca con su daga maldita..." << endl;
                p.HP -= Nihi.ATTACK - p.DEFENSE;
                cout << "\033[34m" << p.PlayerName << "\033[0m" 
                    << " recibió: " << Nihi.ATTACK - p.DEFENSE << " de daño." << endl;
            }
        }
    }
}
// Función principal de la batalla contra Nihilus
void NihilusBattle(Player& p, Nihilus& Nihi){

    int TempDefense = p.DEFENSE;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int NihiMaxHp = Nihi.MAX_HP;
    int NihiHP = Nihi.HP;
    int NihiMana = Nihi.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;
    bool battleOver = false;
    bool RageMode = false;
    bool Return = false;
    int turnCount = 0;  // cuenta turnos para aumentar probabilidad de robo

    do{
        turnCount++;
        bool RegMana = true;
        int RNGTalk = rand() % 101;
        int RNGMercy = rand() % 101;
        int RandomEvent = rand() % 101;

        cout << "Jefe: \033[35m" << Nihi.NihilusName << "\033[0m" << endl;
        EnemyHpBar(Nihi);

        cout << Nihi.NihilusName << " Esta determinado en matarlos..." << endl << endl;

        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        HpBar(p);
        ManaBar(p);
        cout << "Piedad: No... el no merece compasión" << endl;

        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";

        cin >> option;
        Clear();

        switch(option){
        case 1: // ATTACK
            cout << "1. " << Nihi.NihilusName << " HP: " << Nihi.HP << "/" << Nihi.MAX_HP << endl;
            cout << "2. RETURN" << endl;
            cin >> option_attack;
            switch(option_attack){
            case 1:
                PlayerAttackNihilus(p, Nihi);
                cout << endl;
                NihilusAttackOrSteal(p, Nihi, turnCount);
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

        case 2: // MAGIC
            RegMana = false;
            PlayerMagic(p, Nihi, Return);
            cout << endl;
            if (!Return) NihilusAttackOrSteal(p, Nihi, turnCount);
            Return = false;
            break;

        case 3: // ACTION
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. BURLARTE\n5. HABLAR\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;
            switch(option_action){
            case 1:
                RegMana = false;
                Clear();
                ShowStats(p);
                cin.ignore(); cin.get();
                Clear();
                break;
            case 2:
                RegMana = false;
                Clear();
                ShowStatsNihilus(Nihi);
                cin.ignore(); cin.get();
                Clear();
                break;
            case 3: // EXCHANGE MAGIC
                RegMana = false;
                Clear();
                cout << "Intercambiar magia actual:\n1. Ofensiva\n2. Curacion\n3. RETURN\n";
                cin >> option_exmagic;
                switch(option_exmagic){
                case 1:
                    Clear();
                    if (p.MagicDefault == p.Magic1)
                        cout << "Ya tienes equipada esta magia." << endl;
                    else {
                        p.MagicDefault = p.Magic1;
                        cout << "Te equipaste: " << p.MagicDefault << endl;
                    }
                    Sleep(1000); cout << endl;
                    break;
                case 2:
                    Clear();
                    if (p.MagicDefault == p.Magic2)
                        cout << "Ya tienes equipada esta magia." << endl;
                    else {
                        p.MagicDefault = p.Magic2;
                        cout << "Te equipaste: " << p.MagicDefault << endl;
                    }
                    Sleep(1000); cout << endl;
                    break;
                case 3:
                    Clear();
                    break;
                default:
                    DefaultError();
                    break;
                }
                break;
            case 4: // activa Rage
                Clear();
                if (!RageMode){
                    cout << "Te burlas del vacío... pero es muy orgulloso y no lo provocas... pero siente que no lo ven como un desafío." << endl;
                    Sleep(1500);
                    cout << "\033[31mRAGE MODE ACTIVADO!\033[0m" << endl;
                    Nihi.ATTACK += 20;
                    Nihi.DEFENSE = 0;
                    Nihi.MAX_HP += 30;
                    Nihi.HP = min(Nihi.HP + 30, Nihi.MAX_HP);
                    RageMode = true;
                    Sleep(1500);
                } else {
                    RegMana = false;
                    cout << "Nihilus ya está consumido por la furia..." << endl;
                }
                cout << endl;
                break;
            case 5: // TALK
                Clear();
                cout << "Intentas hablar con el vacío..." << endl;
                Sleep(1500);
                if(RNGTalk <= 25){
                    cout << "Una voz susurra: 'Toda luz muere'... Te invade el frío. Pierdes 10 HP." << endl;
                    p.HP -= 10;
                } else if(RNGTalk <= 50){
                    cout << "Escuchas ecos de antiguas ruinas... nada ocurre." << endl;
                    RegMana = false;
                } else if(RNGTalk <= 75){
                    cout << "El vacío responde con compasión inesperada. +5 HP." << endl;
                    p.HP = min(p.HP + 5, p.MAX_HP);
                } else {
                    cout << "Una sombra se retuerce y lanza un susurro mortal. Nihilus incrementa su ataque +5." << endl;
                    Nihi.ATTACK += 5;
                }
                Sleep(2000);
                NihilusAttackOrSteal(p, Nihi, turnCount);
                break;
            case 6: // PACIFY
            Clear();
                cout << "No es posible pacificarlos..." << endl;
            cout << endl;
            Sleep(1000);
            break;

            case 7: // DEFEND
                RegMana = false;
                Clear();
                cout << "Te envuelves en un manto de sombras. Defensa x2 y +20 MANA." << endl;
                p.MANA = min(p.MANA + 20, p.MAX_MANA);
                p.DEFENSE = TempDefense * 2;
                NihilusAttackOrSteal(p, Nihi, turnCount);
                p.DEFENSE = TempDefense;
                break;
            case 8:
                RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                break;
            }
            break;

        case 4: // ITEM
            RegMana = false;
            Items(p, option_item);
            cout << endl;
            NihilusAttackOrSteal(p, Nihi, turnCount);
            break;

        case 5: // MERCY
            cout << "Tu enemigo no merece compasion..." << endl;
            cout << endl;
            break;

        default:
            DefaultError();
            break;
        }

        if(p.HP <= 0){
            cout << Nihi.NihilusName << " ha derrotado a " << p.PlayerName << " y lo llevo al vacío..." << endl;
            cout << "\033[31mGAME OVER\033[0m\n\033[33mContinue?\033[0m\n1. YES\n2. NO\n";
            cin >> option_GameOver;
            switch(option_GameOver){
            case 1:
                Clear();
                cout << "Retornando al último checkpoint..." << endl;
                Sleep(1000);
                Checkpoint(p, Nihi, PlayerHp, PlayerMana, NihiHP, NihiMana, NihiMaxHp);
                Clear();
                break;
            case 2:
                cout << "Adiós..." << endl;
                Sleep(2000);
                exit(0);
                break;
            default:
                DefaultError();
                break;
            }
        }

        if(Nihi.HP <= 0){
            cout << Nihi.NihilusName << " se desvanece en el abismo... ¡VICTORIA!" << endl;
            Sleep(2000);
            Clear();
            battleOver = true;
        }

        if(RegMana)
            p.MANA = min(p.MANA + 10, p.MAX_MANA);

    } while(!battleOver);
}
