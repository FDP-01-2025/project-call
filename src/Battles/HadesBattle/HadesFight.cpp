#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/Hades_Data/Hades.h"
#include "BattleUtils/BattleUtils.h"
#include "HadesFight.h"
using namespace std;

void EnemyHpBar(DHades& inf){
    int total_blocks = 10;
    int filled_blocks = (inf.HP * total_blocks) / inf.MAX_HP;
    if (inf.HP > 0 && filled_blocks == 0) filled_blocks = 1;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (inf.HP > inf.MAX_HP * 0.3) ? "\033[35m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << inf.HP << "/" << inf.MAX_HP << endl << endl;
}

// Función local: restaurar checkpoint
void Checkpoint(Player& p, DHades& inf, int PlayerHP, int PlayerMana, int HadesHp, int HadesMana, int HadesMaxHp){
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    inf.HP = HadesHp;
    inf.MANA = HadesMana;
    inf.MAX_HP = HadesMaxHp;
}

void PlayerMagic(Player& p, DHades& inf, bool& Return){
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1){ // si magia es vendaval
    cout << "1. " << inf.HadesName << " HP: " << inf.HP << "/" << inf.MAX_HP << endl;
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
            cout << "El viento daño emocionalmente a " << inf.HadesName << endl;
            p.MANA -= p.MANACOST_AT;
            inf.HP -= p.MAGIC_ATTACK;
            cout << inf.HadesName << " recibió " << p.MAGIC_ATTACK << " de daño!" << endl;
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

void PlayerAttackHades(Player& p, DHades& inf){
    int RNGPlayer = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGPlayer < 25){
        Clear();
        cout << "Fallaste el ataque!" << endl;
    } else if (RNGPlayer < 50){
        Clear();
        if (inf.DEFENSE > p.CRITICAL_ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            cout << "Ataque critico!" << endl;
            inf.HP -= p.CRITICAL_ATTACK - inf.DEFENSE;
        }
        cout << inf.HadesName << " Recibio: " << p.CRITICAL_ATTACK - inf.DEFENSE << " de dano critico!" << endl;
    } else {
        Clear();
        cout << "Ataque exitoso" << endl;
        if (inf.DEFENSE > p.ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            inf.HP -= p.ATTACK - inf.DEFENSE;
        }
        cout << inf.HadesName << " Recibio: " << p.ATTACK - inf.DEFENSE << " de dano!" << endl;
    }
}


void HadesAttackPlayer(Player& p, DHades& inf){
    int RNGHades = rand() % 101; // RNG 0-100
    int damageBonus = 0;
    string damageType = "";

    if (RNGHades < 25){
        cout << inf.HadesName << " Fallo el ataque!" << endl << endl;
    } else {
        // Determinar si hay bonus de daño
        int bonusRNG = rand() % 101;
        if (bonusRNG < 20) { // 20% probabilidad de +25 daño
            damageBonus = 25;
            damageType = " \033[33m(+25 daño infernal)\033[0m";
        } else if (bonusRNG < 35) { // 15% probabilidad de +50 daño (35-20=15)
            damageBonus = 50;
            damageType = " \033[31m(+50 daño devastador)\033[0m";
        }

        // Calcular daño total
        int totalDamage = (inf.ATTACK - p.DEFENSE) + damageBonus;
        
        if (p.DEFENSE > inf.ATTACK && damageBonus == 0){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << inf.HadesName << " realizo un ataque exitoso" << damageType << endl;
            
            // Asegurar que el daño mínimo sea 1 si hay bonus
            if (totalDamage < 1 && damageBonus > 0) {
                totalDamage = damageBonus;
            }
            
            if (totalDamage > 0) {
                p.HP -= totalDamage;
                cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << totalDamage << " de dano." << endl << endl;
            } else {
                cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
            }
        }
    }
}

void HadesSpecialAbility(Player& p, DHades& inf){
    int RNGSpecial = rand() % 101;
    int manaCost = 40; // Costo de mana para la habilidad especial
    
    if (inf.MANA >= manaCost){
        inf.MANA -= manaCost;
        
        if (RNGSpecial <= 33){
            // Llamarada Infernal
            cout << "\033[31m" << inf.HadesName << " invoca una LLAMARADA INFERNAL!\033[0m" << endl;
            Sleep(1000);
            cout << "¡Las llamas del inframundo te envuelven!" << endl;
            int damage = (inf.ATTACK * 2) - p.DEFENSE;
            if (damage > 0){
                p.HP -= damage;
                cout << "\033[34m" << p.PlayerName << "\033[0m" << " recibió " << damage << " de daño infernal!" << endl;
            } else {
                cout << "Tu defensa resistió las llamas!" << endl;
            }
        } else if (RNGSpecial <= 66){
            // Drenaje de Almas
            cout << "\033[35m" << inf.HadesName << " usa DRENAJE DE ALMAS!\033[0m" << endl;
            Sleep(1000);
            cout << "¡Sientes como tu esencia vital es absorbida!" << endl;
            int drainAmount = 30;
            p.HP -= drainAmount;
            inf.HP = min(inf.HP + drainAmount, inf.MAX_HP);
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " pierde " << drainAmount << " HP!" << endl;
            cout << inf.HadesName << " se cura " << drainAmount << " HP!" << endl;
        } else {
            // Sombras Paralizantes
            cout << "\033[90m" << inf.HadesName << " conjura SOMBRAS PARALIZANTES!\033[0m" << endl;
            Sleep(1000);
            cout << "¡Las sombras del inframundo te drenan la energía mágica!" << endl;
            int manaDrain = 25;
            p.MANA = max(0, p.MANA - manaDrain);
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " pierde " << manaDrain << " de MANA!" << endl;
        }
    } else {
        // Si no tiene mana suficiente, ataque normal
        HadesAttackPlayer(p, inf);
    }
}

void DhadesBattle(Player& p, DHades& inf){

    int TempDefense = p.DEFENSE; // guardamos una variable de defensa temporal, para evitar posibles conflictos futuros en caso de que se cambie
    int PlayerHp = p.HP; // variables para guardar los datos del Player y Enemy en una funcion checkpoint
    int PlayerMana = p.MANA;
    int HadesMaxHp = inf.MAX_HP;
    int HadesHP = inf.HP;
    int HadesMana = inf.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;  // variables de opciones dentro de switchs                              // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;  // bandera para terminar la batalla
    bool RageHades = false;   // bandera para el modo rage del enemigo
    bool Return = false;

    do{
        int RNGTalkHades = rand() % 101; // variables RNG dentro del do para que se generen nuevos numeros
        int RNGHadesSpecial = rand() % 101; // RNG para habilidad especial de Hades
        bool RegMana = true;      // bandera para regenerar MANA
        int RandomEvent = rand() % 101;
        cout << "Oponente: " << "\033[33m" << inf.HadesName << "\033[0m" << endl; // Codigo ANSI amarillo
        EnemyHpBar(inf);
        HpBar(p); // barra de vida dinamica
        ManaBar(p); // barra de mana dinamica
     
        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n\n";
        cin >> option;

        Clear();
        switch (option){ // switch general
        case 1: // ATTACK
            cout << "1. " << inf.HadesName << " HP: " << inf.HP << "/" << inf.MAX_HP << endl;
            cout << "2. RETURN" << endl; 
            cin >> option_attack;

            switch (option_attack){ // switch de case 1
            case 1: 
                    PlayerAttackHades(p, inf); // atacas al enemigo // 25% de fallar // 25% de critico
                    cout << endl;
                    
                    // Decidir si Hades usa habilidad especial (20% probabilidad si tiene mana suficiente)
                    if (RNGHadesSpecial <= 20 && inf.MANA >= 40){
                        HadesSpecialAbility(p, inf);
                    } else {
                        HadesAttackPlayer(p, inf); // el enemigo te ataca con posibilidad de daño multiplicado
                    }
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
            if (p.MagicDefault != p.Magic2){ // si te curas no te atacara
                Clear();
                PlayerMagic(p, inf, Return);
                cout << endl;
                if (!Return) {
                    // Decidir si Hades usa habilidad especial
                    if (RNGHadesSpecial <= 20 && inf.MANA >= 40){
                        HadesSpecialAbility(p, inf);
                    } else {
                        HadesAttackPlayer(p, inf);
                    }
                    Return = false;
                }
            } else {
                Clear();
                PlayerMagic(p, inf, Return);
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
                ShowStats(inf); // llamar funcion
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
                        cout << "Te quipaste: " << p.MagicDefault << endl;
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
                        cout << "Te quipaste: " << p.MagicDefault << endl;
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
            
                if (!RageHades) {
                    cout << "Intentas de alguna manera ofender a Hades... pero eres conciente que nada de esto funcionara." << endl;
                    RageHades = true;
                    Sleep(1500);
                    
                } else {
                    RegMana = false;
                    cout << "Ya has intentado hacer enojar al " << inf.HadesName << " y no surtio ningun efecto en el...\n";
                }
                cout << endl;
                break;
            case 5: // HABLAR
            Clear();
                cout << "Intentas hablar con " << inf.HadesName << endl;
                Sleep(1500);

                if (RNGTalkHades <= 20){
                    cout << " " << endl;
                    cout << p.PlayerName << ": Devuelve la paz a este mundo o te detendré con mi propia fuerza, Hades\n";
                    cout << inf.HadesName << ":  La paz es una ilusión efímera. Yo soy el fin inevitable. Ven y demuestra que puedes desafiar al destino.";

                } else if (RNGTalkHades > 20 && RNGTalkHades <= 40){
                    cout << " " << endl;
                    cout << p.PlayerName << ": Tu oscuridad no tiene lugar aquí. Me enfrentaré a ti para salvar todo lo que amo.\n";
                    cout << inf.HadesName << ": El amor es débil ante el poder de la muerte. Ven, y que tu valentía sea tu último suspiro.";
                    RegMana = false;
                } else if (RNGTalkHades > 40 && RNGTalkHades <= 60){
                    cout << " " << endl;
                    cout << p.PlayerName << ": He cruzado el abismo y desafiado a la muerte misma para llegar hasta ti, Hades. Hoy, tu oscuridad conocerá la luz de mi voluntad.\n";
                    cout << inf.HadesName << ": Solo los necios desafían al dios del inframundo. Tu llama se extinguirá y tu nombre será olvidado entre las sombras eternas.";
                } else if (RNGTalkHades > 60 && RNGTalkHades <= 80){
                    cout << " " << endl;
                    cout << p.PlayerName << ": No temo a la muerte, porque lucho por la vida. Y esa fuerza es más poderosa que tu reino oscuro.\n";
                    cout << inf.HadesName << ": La vida es solo un suspiro antes del abismo. Ven, y deja que te muestre el verdadero poder del inframundo.";
                }

                Sleep(2500);
                cout << "\n¡El \033[31mRey de los Muertos\033[0m ataca repentinamente!" << endl;
                Sleep(1000);
                
                // Decidir si usa habilidad especial después de hablar
                if (RNGHadesSpecial <= 20 && inf.MANA >= 40){
                    HadesSpecialAbility(p, inf);
                } else {
                    HadesAttackPlayer(p, inf);
                }
                break;

            
            case 7: // DEFEND
            RegMana = false;
            Clear();
                cout << "Te defiendes del proximo ataque de " << inf.HadesName << endl;
                cout << "Tu defensa de multiplico x2 este turno." << endl;
                cout << "Recuperas +20 \033[34mMANA\033[0m" << endl << endl;
                p.MANA = min(p.MANA + 20, p.MAX_MANA);
                p.DEFENSE = TempDefense * 2;
                
                // Decidir si usa habilidad especial mientras te defiendes
                if (RNGHadesSpecial <= 20 && inf.MANA >= 40){
                    HadesSpecialAbility(p, inf);
                } else {
                    HadesAttackPlayer(p, inf);
                }
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
        default:
            DefaultError();
            break;
        }

        // Regeneración de mana para Hades cada turno
        if (RegMana && inf.MANA < inf.MAX_MANA){
            inf.MANA = min(inf.MANA + 10, inf.MAX_MANA);
        }

        if(p.HP <= 0){
            cout << inf.HadesName << " ha derrotado a " << "\033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;

            switch (option_GameOver){ // switch de case 1 - gameover
            case 1:
                Clear();
                cout << "Retornando con valor..." << endl;
                cout << "Volviendo al último checkpoint...\n" << endl;
                Sleep(1000);
                Checkpoint(p, inf, PlayerHp, PlayerMana, HadesHP, HadesMana, HadesMaxHp); // llamar funcion de checkpoint
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
            
        // Verificar si Hades fue derrotado
        if(inf.HP <= 0){
            cout << "\033[32m¡Has derrotado a " << inf.HadesName << "!\033[0m" << endl;
            cout << "\033[33m¡VICTORIA!\033[0m" << endl;
            battleOver = true;
        }

    } while (!battleOver); // condicion para que termine la batalla
}