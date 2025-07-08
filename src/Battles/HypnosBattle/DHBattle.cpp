#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> // para usar min y max
#include "Data/PlayerData/PlayerData.h"
#include "Data/HypnosData/Hypnos.h" // librería del jefe Nihilus
#include "BattleUtils/BattleUtils.h"
using namespace std;
// Nihilus, el Vacío Andante ha emergido*

// Barra de vida dinámica del enemigo
void EnemyHpBar(DHypnos& h){
    int total_blocks = 10;
    int filled_blocks = (h.HP * total_blocks) / h.MAX_HP;
    if (h.HP > 0 && filled_blocks == 0) filled_blocks = 1;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (h.HP > h.MAX_HP * 0.3) ? "\033[35m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << h.HP << "/" << h.MAX_HP << endl << endl;
}

// Función local: restaurar checkpoint
void Checkpoint(Player& p, DHypnos& h, int PlayerHP, int PlayerMana, int DHHp, int DHMana, int DHMaxHp){
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    h.HP = DHHp;
    h.MANA = DHMana;
    h.MAX_HP = DHMaxHp;
}

void PlayerMagic(Player& p, DHypnos& h, bool& Return){
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1){ // si magia es vendaval
    cout << "1. " << h.DHName << " HP: " << h.HP << "/" << h.MAX_HP << endl;
    cout << "2. RETURN" << endl;
    cin >> opcionPlayerMagic;

    switch (opcionPlayerMagic){
    case 1:
    Clear();
        if (p.MANA < p.MANACOST_AT){
            cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
            cout << "Usaste: " << p.MagicDefault << endl;
            Sleep(1000);
            cout << "El viento dano emocionalmente a " << h.DHName << endl;
            p.MANA -= p.MANACOST_AT;
            h.HP -= p.MAGIC_ATTACK;
            cout << h.DHName << " recibió " << p.MAGIC_ATTACK << " de daño!" << endl;
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
    } else if (p.MagicDefault == p.Magic2){ // si esta magia de curacion
        cout << "1. " << "\033[34m" << p.PlayerName << "\033[0m" << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

    Clear();
        switch (opcionPlayerMagic){
        case 1:
            if (p.MANA < p.MANACOST_HE){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                int HPbefore = p.HP; // variable para calcular solo la vida curada, no el exceso
                int opcion_heal;
                int HPtemp = p.HP + p.HEALTH_MAGIC; // variable temporal para saber si la vida sobrepasa la vida maxima

                if (HPtemp > p.MAX_HP){
                    cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte o la totalidad del hechizo.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                Clear();
                    switch (opcion_heal){
                    case 1:
                        p.HP = min(p.HP + p.HEALTH_MAGIC, p.MAX_HP);
                        p.MANA -= p.MANACOST_HE;
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó: +" << p.HP - HPbefore << " HP";
                        Sleep(1000);
                        cout << endl;
                        break;
                    case 2: // RETURN
                        Clear();
                        break;
                    default:
                        Clear();
                        cout << "Opcion de comando invalida" << endl;
                        Sleep(1000); cout << endl;
                        Clear();
                        break;
                    }
                } else {
                    p.HP += p.HEALTH_MAGIC;
                    p.MANA -= p.MANACOST_HE;
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curó: +" << p.HP - HPbefore << " HP";
                    Sleep(1000);
                    cout << endl;
                }
            }
            break;
        case 2:
            Clear();
            break;
        default:
            Clear();
            cout << "Opcion de comando invalida" << endl;
            Sleep(1000); cout << endl;
            Clear();
            break;
        }
    }
}

void PlayerAttackDH(Player& p, DHypnos& h){
    int RNGPlayer = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGPlayer < 25){
        Clear();
        cout << "Fallaste el ataque!" << endl;
    } else if (RNGPlayer < 50){
        Clear();
        if (h.DEFENSE > p.CRITICAL_ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            cout << "Ataque critico!" << endl;
            h.HP -= p.CRITICAL_ATTACK - h.DEFENSE;
        }
        cout << h.DHName << " Recibio: " << p.CRITICAL_ATTACK - h.DEFENSE << " de dano critico!" << endl;
    } else {
        Clear();
        cout << "Ataque exitoso" << endl;
        if (h.DEFENSE > p.ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            h.HP -= p.ATTACK - h.DEFENSE;
        }
        cout << h.DHName << " Recibio: " << p.ATTACK - h.DEFENSE << " de dano!" << endl;
    }
}

void DHAttackPlayer(Player& p, DHypnos& h){
    int RNGDH = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGDH < 25){
        cout << h.DHName << " Fallo el ataque!" << endl << endl;
    } else if (RNGDH < 50){
        if (p.DEFENSE > h.CRITICAL_ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << h.DHName << " realizo un ataque critico!" << endl;
            p.HP -= h.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << h.CRITICAL_ATTACK - p.DEFENSE << " de dano critico!" << endl << endl;
        }
    } else {
        if (p.DEFENSE > h.ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << h.DHName << " realizo un ataque exitoso" << endl;
            p.HP -= h.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << h.ATTACK - p.DEFENSE << " de dano." << endl << endl;
        }
    }
    cout << endl;
}

string TalkDH[] = {
    "Intentas hablar con el \033[31mdios Hypnos\033[0m", // 0
    "Le haces una peticion al \033[31mdios Hypnos\033[0m", // 1 
    "Intentas sacarle platica al \033[31mdios Hypnos\033[0m ", // 2
    "Intentas sacarle platica al \033[31mdios Hypnos\033[0m ", // 3
    "Intentas sacarle platica al \033[31mdios Hypnos\033[0m "  // 4
};

void DHBattle(Player& p, DHypnos& h){

    int TempDefense = p.DEFENSE; // guardamos una variable de defensa temporal, para evitar posibles conflictos futuros en caso de que se cambie
    int PlayerHp = p.HP; // variables para guardar los datos del Player y Enemy en una funcion checkpoint
    int PlayerMana = p.MANA;
    int DHMaxHp = h.MAX_HP;
    int DHHP = h.HP;
    int DHMana = h.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;  // variables de opciones dentro de switchs                              // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;  // bandera para terminar la batalla
    bool RageDH = false;   // bandera para el modo rage del enemigo
    bool Return = false;
    int TurnCount = 0;       // la cantidad de turnos a sobrevivir para completar la pelea

    do{
        int RNGTalkDH = rand() % 101; // variables RNG dentro del do para que se generen nuevos numeros
        bool RegMana = true;      // bandera para regenerar MANA
        int RandomEvent = rand() % 101;
        cout << "Oponente: " << "\033[33m" << h.DHName << "\033[0m" << endl; // Codigo ANSI amarillo
        EnemyHpBar(h);
        cout << h.DHName << " Esta observando tus sueños." << endl << endl;
        HpBar(p); // barra de vida dinamica
        ManaBar(p); // barra de mana dinamica
        cout << "Turno: " << "\033[33m" << TurnCount << "\033[0m" << endl;
        cout << "Resiste 20 turnos lo mejor que puedas..." << endl;
        cout << endl;
        
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        cin >> option;      

    Clear();
        switch (option){ // switch general
        case 1: // ATTACK
            cout << "1. " << h.DHName << " HP: " << h.HP << "/" << h.MAX_HP << endl;
            cout << "2. RETURN" << endl; 
            cin >> option_attack;

            switch (option_attack){ // switch de case 1
            case 1: 
                    PlayerAttackDH(p, h); // atacas al enemigo // 25% de fallar // 25% de critico
                    cout << endl;
                    DHAttackPlayer(p, h); // el enemigo te ataca // 25% de fallar
                break;
            case 2: // RETURN
            RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                RegMana = false;
                break; // break de default
                }
            break; // break de case 1
// end case 1
        case 2: // MAGIC
        RegMana = false;
            if (p.MagicDefault != p.Magic2){ // si te curas dummy no te atacara
                Clear();
                PlayerMagic(p, h, Return);
                cout << endl;
                if (!Return) {
                    DHAttackPlayer(p, h);
                    Return = false;
                }
            } else {
                Clear();
                PlayerMagic(p, h, Return);
                cout << endl;
            }
            break;
// end case 2
        case 3: // ACTION
            Clear();
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. BURLARTE\n5. PLATICAR\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;
        
            switch (option_action){
            case 1: // MY STATS
            RegMana = false;
                Clear();
                ShowStats(p); // llamar funcion
                cin.ignore(); // es como un cin, para que el jugador decida cuando avanzar,  descarta el '\n' pendiente
                cin.get();    // esto es util porque switch solo acepta numeros, si se ingresa una letra colapsa,  ahora sí espera a que el usuario presione Enter
                cout << endl;
                Clear();
                break;
            case 2: // ENEMY DESCRIPTION

            RegMana = false;
                Clear();
                ShowStats(h); // llamar funcion
                cout << endl;
                cin.ignore();
                cin.get();
                Clear();
                break;
            case 3: // EXCHANGE MAGIC

            RegMana = false;
                Clear();
                cout << "Intercambiar magia actual:\n";
                cout << "1. Magia Vendaval\n2. Magia curacion\n3. RETURN\n\n";
                cin >> option_exmagic;
            
                switch (option_exmagic){
                case 1:
                    Clear();
                    if (p.MagicDefault == p.Magic1){
                        cout << "Ya tienes equipada esta magia" << endl;
                    } else {
                        p.MagicDefault = p.Magic1;
                        cout << "Te equipaste: " << p.MagicDefault << endl;
                    }
                    Sleep(1000);
                    cout << endl;
                    break;
                case 2:
                    Clear();
                    if (p.MagicDefault == p.Magic2){
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
                    Clear();
                    break;
                default:
                    DefaultError();
                    RegMana = false;
                    break;
                }
                break;
            case 4: // ACT 1 - RAGE MODE
                Clear();
            
                if (!RageDH) {
                    cout << "Intentas de alguna manera ofender a Hypnos... pero eres conciente que su actitud es irracional" << endl;
                    RageDH = true;
                    Sleep(1500);
                    
                } else {
                    RegMana = false;
                    cout << "Ya has intentado hacer enojar al " << h.DHName << " y no surtio ningun efecto en el...\n";
                }
                cout << endl;
                break;
            case 5: // HABLAR
            Clear();
                cout << "Intentas hablar con " << h.DHName << endl;
                Sleep(1500);

                cout << h.DHName << " No hablara contigo. Te pide que te concentres y des lo mejor de tí." << endl;
                break;

            case 6: // PACIFY
            RegMana = false;
            Clear();
                cout << "Intentas pacificar a Hypnos... él ya es pacifico..." << endl << endl;
                break;
            case 7:
            Clear();
                cout << "Te defiendes del proximo ataque de " << h.DHName << endl;
                cout << "Tu defensa de multiplico x2 este turno." << endl;
                cout << "Recuperas +20 \033[34mMANA\033[0m" << endl << endl;
                p.MANA = min(p.MANA + 20, p.MAX_MANA);
                p.DEFENSE = TempDefense * 2;
                DHAttackPlayer(p, h);
                p.DEFENSE = TempDefense;
                break;
            case 8: // RETURN
            RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                RegMana = false;
                break; // break de default
            }
            break; // break de case 3
// end case 3
        case 4: // ITEM
        RegMana = false;
            Items(p, option_item);
            cout << endl;
        break;
// end case 4
        case 5:
            Clear();
            cout << "Intentas perdonar a Hypnos pero el ya te ha perdonado a tí... solo te prueba como si fueras su hijo." << endl;
            break;
        default:
            DefaultError();
            break;
        }

        if (RegMana) {
            p.MANA = min(p.MANA + 10, p.MAX_MANA);
        }

        TurnCount++;
        Clear();
            if(TurnCount >= 20){
            cout << "\n\033[32mHaz pasado la prueba\033[0m" << endl;
            battleOver = true;
            }

        if(p.HP <= 0){
            cout << h.DHName << " ha derrotado a " << "\033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;

            switch (option_GameOver){ // switch de case 1 - gameover
            case 1:
                Clear();
                cout << "Retornando con valor..." << endl;
                cout << "Volviendo al último checkpoint...\n" << endl;
                Sleep(1000);
                Checkpoint(p, h, PlayerHp, PlayerMana, DHHP, DHMana, DHMaxHp); // llamar funcion de checkpoint
                Clear();
                break;
            case 2:
                cout << "Adios... " << p.PlayerName << endl;
                Sleep(2000);
                exit(0); // termina el programa 
                break;
            default:
                DefaultError();
                RegMana = false;
                break;  // variable para continuar o no
                }
            }

    } while (!battleOver); // condicion para que termine la batalla
}
