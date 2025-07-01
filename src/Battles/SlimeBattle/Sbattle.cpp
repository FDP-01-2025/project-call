#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> 
#include "Data/PlayerData/PlayerData.h"
#include "Data/EliteSData/EliteSlime.h"
#include "BattleUtils/BattleUtils.h"
#include "Sbattle.h"

using namespace std;

void EnemyHpBar(EliteS& S){
    int total_blocks = 10;
    int filled_blocks = (S.HP * total_blocks) / S.MAX_HP;
    if (S.HP > 0 && filled_blocks == 0) {
    filled_blocks = 1;
    }   
    int empty_blocks = total_blocks - filled_blocks;

    string color = (S.HP > S.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;

    for (int i = 0; i < filled_blocks; ++i){
        cout << "█";
    }

    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i){
        cout << "█";
    }

    cout << "\033[0m " << S.HP << "/" << S.MAX_HP << endl << endl;
}

void Checkpoint(Player& p, EliteS& S, int PlayerHP, int PlayerMana, int EliteSHp, int EliteSMana){ // guardar las variables localmente para poder usar checkpoint
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    S.HP = EliteSHp;
    S.MANA = EliteSMana;
} // funcion local

void PlayerMagic(Player& p, EliteS& S){
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1){ // si magia es vendaval
    cout << "1. " << S.EliteSName << " HP: " << S.HP << "/" << S.MAX_HP << endl;
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
            cout << "El viento dano emocionalmente a " << S.EliteSName << endl;
            p.MANA -= p.MANACOST_AT;
            S.HP -= p.MAGIC_ATTACK;
            cout << S.EliteSName << " Recibio " << p.MAGIC_ATTACK << " de daño magico!" << endl;
            }
        break;
    case 2:
        Clear();
        break;
    default:
        DefaultError();
        break;
        }
    } else if (p.MagicDefault == p.Magic2){ // si esta magia de curacion
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

    Clear();
        switch (opcionPlayerMagic){
        case 1:
            if (p.MANA < p.MANACOST_HE){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                int HPbefore = p.HP; // variables temporales
                int opcion_heal;
                int HPtemp = p.HP + p.HEALTH_MAGIC;

                if (HPtemp > p.MAX_HP){
                    cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte o la totalidad del hechizo.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                Clear();
                    switch (opcion_heal){
                    case 1:
                        p.HP = min(p.HP + p.HEALTH_MAGIC, p.MAX_HP);
                        p.MANA -= p.MANACOST_HE;
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curo: +" << p.HP - HPbefore << " HP" << endl;
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
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curo +" << p.HEALTH_MAGIC << " HP" << endl;
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

void PlayerAttackEliteS(Player& p, EliteS& S){
    int RNGPlayer = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGPlayer < 25){
        Clear();
        cout << "Fallaste el ataque!" << endl;
    } else if (RNGPlayer < 50){
        Clear();
        if (S.DEFENSE > p.CRITICAL_ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            cout << "Ataque critico!" << endl;
            S.HP -= p.CRITICAL_ATTACK - S.DEFENSE;
        }
        cout << S.EliteSName << " Recibio: " << p.CRITICAL_ATTACK - S.DEFENSE << " de dano critico!" << endl;
    } else {
        Clear();
        cout << "Ataque exitoso" << endl;
        if (S.DEFENSE > p.ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            S.HP -= p.ATTACK - S.DEFENSE;
        }
        cout << S.EliteSName << " Recibio: " << p.ATTACK - S.DEFENSE << " de dano!" << endl;
    }
}

void SlimeAttack(Player& p, EliteS& S){
    int RNGEliteS = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGEliteS < 25){
        cout << S.EliteSName << " Fallo el ataque!" << endl << endl;
    } else if (RNGEliteS < 50){
        if (p.DEFENSE > S.CRITICAL_ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << S.EliteSName << " realizo un ataque critico!" << endl;
            p.HP -= S.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << S.CRITICAL_ATTACK - p.DEFENSE << " de dano critico!" << endl << endl;
        }
    } else {
        if (p.DEFENSE > S.ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << S.EliteSName << " realizo un ataque exitoso" << endl;
            p.HP -= S.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << S.ATTACK - p.DEFENSE << " de dano." << endl << endl;
        }
    }
}

void EliteSAttackPlayer(Player& p, EliteS& S){
    int RNGHealthAttack = rand() % 101;

    if (S.HP <= S.MAX_HP * 0.75){ // se curara si tiene un 75% de vida o menos
        if (RNGHealthAttack <= 25){ // probabilidad del 25 % de curarse
            if (S.MANA != 0){ // si el mana queda a 0 atacar es del 100%
                cout << S.EliteSName << " vio su HP bajar, y opto por regenerarse en este turno." << endl;
                cout << S.EliteSName << " Se curo +20 Hp" << endl;
                S.MANA -= S.MANA * 0.25;
                S.HP = min(S.HP += 20, S.MAX_HP);
            } else { // sin mana
                SlimeAttack(p, S);
            }
        } else { // 75% de atacar
            SlimeAttack(p, S);
        }
    } else {
        SlimeAttack(p, S);
    }
}

string TalkEliteS[] = { // agregar conversacion con el slime de elite
    "Intentas sacarle platica al slime de Elite...", // 0
    "\033[31mSlime de Elite\033[0m te tira su baba...", // 1 
    "Intenta huir del \033[31mSlime de Elite\033[0m...", // 2
    "Intentaste pegarle al slime...", // 3
    "Intentas acariciar al slime..."  // 4
};

string TalkMercyEliteS[] = { // agregar dialogos de perdon
    "Abrazas al Sliem de Elite...", // 0
    "Le sonríes al slime en señal de paz...", // 1
    "Decides no atacar...", // 3
    "Le ofreces paz..." // 4
};

void EliteSBattle(Player& p, EliteS& S){

    int TempDefense = p.DEFENSE; // guardamos una variable de defensa temporal, para evitar posibles conflictos futuros en caso de que se cambie
    int MercyPoints = 0; // puntos de piedad
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int EliteSHP = S.HP;
    int EliteSMana = S.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;  // variables de opciones dentro de switchs                              // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;  // bandera para terminar la batalla
    bool RageEliteS = false;   // bandera para el modo rage del enemigo
    bool Mercy = false;       // bandera para victoria pacifista
    int FireShifts = 0;       // la cantidad de turnos por las que se quemara el jugador

    do{
        int RNGTalkEliteS = rand() % 101; // variables RNG dentro del do para que se generen nuevos numeros
        int RNGMercy = rand() % 101;
        bool RegMana = true;      // bandera para regenerar MANA
        int RandomEvent = rand() % 101;
        cout << "Oponente: " << "\033[33m" << S.EliteSName << "\033[0m" << endl; // Codigo ANSI amarillo
        EnemyHpBar(S);
        if (Mercy == false){
            cout << S.EliteSName << " Esta determinado" << endl << endl;
        } else {
            cout << S.EliteSName << " Parece agotado" << endl << endl;
        }
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;

        HpBar(p); // barra de vida dinamica
        ManaBar(p); // barra de mana dinamica
        cout << "Piedad: " << MercyPoints << endl << endl; // puntos de piedad

        if (Mercy == false){
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        } else {
            cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. \033[33mMERCY\033[0m\n";
        }
        cin >> option;

    Clear();
        switch (option){ // switch general
        case 1: // ATTACK
            cout << "1. " << S.EliteSName << " HP: " << S.HP << "/" << S.MAX_HP << endl;
            cout << "2. RETURN" << endl; 
            cin >> option_attack;

            switch (option_attack){ // switch de case 1
            case 1: 
                    PlayerAttackEliteS(p, S); // atacas al enemigo // 25% de fallar // 25% de critico
                    cout << endl;
                    
                    EliteSAttackPlayer(p, S); // el enemigo te ataca // 25% de fallar
                break;
            case 2: // RETURN
            RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                break; // break de default
                }
            break; // break de case 1
// end case 1
        case 2: // MAGIC
        RegMana = false;
            if (p.MagicDefault != p.Magic2){ // si te curas dummy no te atacara
                Clear();
                PlayerMagic(p, S);
                cout << endl;
                Sleep(500);
                EliteSAttackPlayer(p, S);
            } else {
                Clear();
                PlayerMagic(p, S);
                cout << endl;
                Sleep(500);
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
                //EliteSlimeShowStats(S); // llamar funcion
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
                    break;
                }
                break;
            case 4: // ACT 1 - RAGE MODE
                Clear();
            
                if (!RageEliteS) {
                    cout << "Te burlaste de la patetica apariencia de " << S.EliteSName << endl;
                    cout << "...Provocaste al enemigo\n \n";
                    Sleep(1500);
                    cout << S.EliteSName << " se enojo!\n";
                    cout << "Empieza a burbujear su baba por su ira! y desea tu muerte a toda costa...\n\n"; 
                    RageEliteS = true;
                
                    // Aumentar estadisticas cuando se enoja
                    S.ATTACK += 20;
                    S.DEFENSE = 0;
                    S.MAX_HP += 25;
                    S.HP = min(S.HP + 25, S.MAX_HP);
                    Sleep(1500);
                    cout << S.EliteSName << " incremento su vida!\n";
                    cout << S.EliteSName << " incremento su ataque!\n";
                    cout << S.EliteSName << " La defensa de muñeco de Naika ha caido!\n";
                } else {
                    RegMana = false;
                    cout << S.EliteSName << " ya esta enojado\n";
                    cout << S.EliteSName << " tiembla de furia!\n";
                }
                cout << endl;
                break;
            case 5: // HABLAR, tomar importancia luego de arreglar el codigo
                cout << "Intentas hablar con " << S.EliteSName << endl;
                Sleep(1500);

                if (RNGTalkEliteS <= 20){
                    cout << TalkEliteS[0] << endl;
                    cout << "( " << S.EliteSName << " escribe en la tierra )\n";
                    cout << "¿Hablar? ¿Sabes que no tengo boca, verdad? Pero aprecio el intento. " << endl;
                    RegMana = false;

                } else if (RNGTalkEliteS > 20 && RNGTalkEliteS <= 40){
                    cout << TalkEliteS[1] << endl;
                    cout << "Bueno, dicen que la baba de slime es un buen humectante de piel\n";
                    p.HP = min(p.HP += 5, p.MAX_HP);
                
                } else if (RNGTalkEliteS > 40 && RNGTalkEliteS <= 60){
                    cout << TalkEliteS[2] << endl;
                    cout << "¡Ey, no te vayas! ¿Quién más va a rebotar conmigo después?\n";
                    RegMana = false;

                } else if (RNGTalkEliteS > 60 && RNGTalkEliteS <= 80){
                    cout << TalkEliteS[3] << endl;
                    cout <<"Pero tu mano decidió tomarse vacaciones. ¿Mano floja?\n";

                } else if (RNGTalkEliteS > 80 && RNGTalkEliteS <= 100){
                    cout << TalkEliteS[4] << endl;
                    cout << "¡Cuidado! Soy más resbaloso que tu promedio de matemáticas.\n";
                }

                Sleep(2500);
                cout << "\n¡El Slime de Elite ataca repentinamente!" << endl;
                Sleep(1000);
                EliteSAttackPlayer(p, S);
                break;

            case 6: // ACT 3 PIEDAD
                Clear();
                if (RNGMercy <= 25){ // 25 % de que aparezca el arreglo
                    cout << TalkMercyEliteS[0] << endl;
                    string RealELiteS= "Hey! Estas peleando! no abrazando!...";
                    cout << "\033[31mSlime de Elite\033[0m: ";
                    for (char c : RealELiteS) {
                        cout << c;
                        Sleep(30); }
                        cout << endl;
                        if (RandomEvent < 50){ // 50%
                            cout << S.EliteSName << ": ¿Me perdonas? ¡Eso es pegajosamente amable! " << endl;
                            MercyPoints++;
                            cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                        } else {
                        cout << S.EliteSName <<" No acepto tu abrazo >:(" << endl;
                        EliteSAttackPlayer(p, S);
                    }

                } else if (RNGMercy > 25 && RNGMercy <= 50){ // 25%  de que aparezca el arreglo
                    cout << TalkMercyEliteS[1] << endl;
                    if (RandomEvent <= 25){ // 25%
                        cout << S.EliteSName << ": ¿Eso fue una sonrisa? ¡Cuidado, puedo derretirme de ternura!" << endl;
                        MercyPoints += 3;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                        
                    } else {
                        cout  << S.EliteSName << " no le importo tu gesto de paz"<< endl;
                        S.ATTACK += 5;
                    }

                } else if (RNGMercy <= 75){ // 25% de que aparezca el arreglo
                    cout << TalkMercyEliteS[2] << endl;
                    cout << S.EliteSName << " se ha sometido a un exorcismo..." << endl;
                    Sleep(1500);
                    if (RandomEvent <= 15){ // 15%
                        cout << S.EliteSName << " esta siendo exorcisada... lo estas logrando..." << endl;
                        MercyPoints += 2;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                    Sleep(1500);
                    } else {
                        cout << "El exorcismo esta fallando... el demonio se apodera de ella..." << endl;
                        cout << S.EliteSName << " incremento su ataque +5 por el exorcismo fallido..." << endl;
                        S.ATTACK += 5;
                    }

                } else { // otro 25% de que aparezca el arreglo
                    cout << TalkMercyEliteS[3] << endl;
                    Sleep(1500);
                    if (RandomEvent <= 50){ // 50%
                        cout << S.EliteSName << " se relaja y empieza a hacer burbujas de alegría...." << endl;
                        MercyPoints += 1;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                    } else {
                        cout << "Te abofeteo... eso fue sexista... deberias sentirte culpable" << endl;
                        cout << S.EliteSName << " Se prepara para darte una leccion..." << endl;
                        EliteSAttackPlayer(p, S);
                    }
                }
                cout << endl;
                Sleep(1000);
                break;
            case 7: // DEFEND
            RegMana = false;
            Clear();
                cout << "Te defiendes del proximo ataque de " << S.EliteSName << endl;
                cout << "Tu defensa de multiplico x2 este turno." << endl;
                cout << "Recuperas +20 \033[34mMANA\033[0m" << endl << endl;
                p.MANA = min(p.MANA + 20, p.MAX_MANA);
                p.DEFENSE = TempDefense * 2;
                EliteSAttackPlayer(p, S);
                p.DEFENSE = TempDefense;
                break;
            case 8: // RETURN
            RegMana = false;
                Clear();
                break;
            default:
                DefaultError();
                break; // break de default
            }
            break; // break de case 3
// end case 3
        case 4: // ITEM
        RegMana = false;
            Items(p, option_item);
        break;
// end case 4
        case 5: // MERCY
            if (Mercy == false){
                cout << S.EliteSName << " No acepta tu piedad..." << endl;
                EliteSAttackPlayer(p, S);
            } else {
                cout << S.EliteSName << " Acepto tu perdon... VICTORIA!" << endl;
                battleOver = true;
            }
            break;
        default:
            DefaultError();
            break;
        }

        if(p.HP <= 0){
            cout << S.EliteSName << " ha derrotado a " << "\033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;

            switch (option_GameOver){ // switch de case 1 - gameover
            case 1:
                Clear();
                cout << "Retornando con valor..." << endl;
                cout << "Volviendo al último checkpoint...\n" << endl;
                Sleep(1000);
                Checkpoint(p, S, PlayerHp, PlayerMana, EliteSHP, EliteSMana);
                Clear();
                break;
            case 2:
                cout << "Adios... " << p.PlayerName << endl;
                Sleep(2000);
                exit(0); // termina el programa 
                break;
            default:
                DefaultError();
                break;  // variable para continuar o no
                }
            }

        if(S.HP <= 0){
            cout << S.EliteSName << " ha sido derrotada!" << endl; // condicional si el enemigo ha sido derrotado
            p.KilledEliteSlime = true;
            p.KILLS++;
            battleOver = true;
        }

        // variable para a regeneracion de MANA en cada turno, SI no se ha usado magia
    /*   if (FireShifts > 0){
            cout << p.PlayerName << " se quemo en este turno, pierde -5 HP" << endl;
            cout << "";
        }*/
        if (RegMana){
        p.MANA = min(p.MANA + 10, p.MAX_MANA);
        }
        if (S.HP <= 20 || MercyPoints == 3){ // condicion pacifista
            Mercy = true;
        }

    } while (!battleOver); // condicion para que termine la batalla
}