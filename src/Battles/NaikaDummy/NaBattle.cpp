#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> // sirve para usar min y max
#include "Data/PlayerData/PlayerData.h" // el lib de Player es obligatorio en cada batalla
#include "Data/NaikaDummy/NaikaDummy.h" // enlazar librerias para la batalla, jugador y Naika Dummy.
#include "BattleUtils/BattleUtils.h"
using namespace std;
//Muñeco con forma de Naika aparecio*

void EnemyHpBar(NaikaDummy& Ndum){
    int total_blocks = 10;
    int filled_blocks = (Ndum.HP * total_blocks) / Ndum.MAX_HP;
    if (Ndum.HP > 0 && filled_blocks == 0) {
    filled_blocks = 1;
    }   
    int empty_blocks = total_blocks - filled_blocks;

    string color = (Ndum.HP > Ndum.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;

    for (int i = 0; i < filled_blocks; ++i){
        cout << "█";
    }

    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i){
        cout << "█";
    }

    cout << "\033[0m " << Ndum.HP << "/" << Ndum.MAX_HP << endl << endl;
}

void Checkpoint(Player& p, NaikaDummy& Ndum, int PlayerHP, int PlayerMana, int DummyHp, int DummyMana){ // guardar las variables localmente para poder usar checkpoint
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Ndum.HP = DummyHp;
    Ndum.MANA = DummyMana;
} // funcion local

void PlayerMagic(Player& p, NaikaDummy& Ndum){
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1){ // si magia es vendaval
    cout << "1. " << Ndum.NaDummyName << " HP: " << Ndum.HP << "/" << Ndum.MAX_HP << endl;
    cout << "2. RETURN" << endl;
    cin >> opcionPlayerMagic;

    switch (opcionPlayerMagic){
    case 1:
    system("cls");
        if (p.MANA < 30){
            cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
            cout << "Usaste: " << p.MagicDefault << endl;
            Sleep(1000);
            cout << "El viento dano emocionalmente a " << Ndum.NaDummyName << endl;
            p.MANA -= 30;
            Ndum.HP -= 20;
            cout << Ndum.NaDummyName << " Recibio 20 de dano!" << endl;
            }
        break;
    case 2:
        system("cls");
        break;
    default:
        DefaultError();
        break;
        }
    } else if (p.MagicDefault == p.Magic2){ // si esta magia de curacion
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

    system("cls");
        switch (opcionPlayerMagic){
        case 1:
            if (p.MANA < 50){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                int HPbefore = p.HP; // variable para calcular solo la vida curada, no el exceso
                int opcion_heal;
                int HPtemp = p.HP; // variable temporal para saber si la vida sobrepasa la vida maxima
                HPtemp += 20;

                if (HPtemp > p.MAX_HP){
                    cout << "\033[31mDANGER:\033[0m Si te curas ahora desperdicias parte o la totalidad del hechizo.\nProceder?\n1. Si\n2. No\n";
                    cin >> opcion_heal;

                system("cls");
                    switch (opcion_heal){
                    case 1:
                        p.HP = min(p.HP + 20, p.MAX_HP);
                        p.MANA -= 50;
                        cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curo: +" << p.HP - HPbefore << " HP";
                        break;
                    case 2: // RETURN
                        system("cls");
                        break;
                    default:
                        system("cls");
                        cout << "Opcion de comando invalida" << endl;
                        Sleep(1000); cout << endl;
                        system("cls");
                        break;
                    }
                } else {
                    p.HP += 20;
                    p.MANA -= 50;
                    cout << "\033[34m" << p.PlayerName << "\033[0m" << " se curo, +20 HP";
                }
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion de comando invalida" << endl;
            Sleep(1000); cout << endl;
            system("cls");
            break;
        }
    }
}

void PlayerAttackDummy(Player& p, NaikaDummy& Ndum){
    int RNGPlayer = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGPlayer < 25){
        system("cls");
        cout << "Fallaste el ataque!" << endl;
    } else if (RNGPlayer < 50){
        system("cls");
        if (Ndum.DEFENSE > p.CRITICAL_ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            cout << "Ataque critico!" << endl;
            Ndum.HP -= p.CRITICAL_ATTACK - Ndum.DEFENSE;
        }
        cout << Ndum.NaDummyName << " Recibio: " << p.CRITICAL_ATTACK - Ndum.DEFENSE << " de dano critico!" << endl;
    } else {
        system("cls");
        cout << "Ataque exitoso" << endl;
        if (Ndum.DEFENSE > p.ATTACK){
            cout << "No lograste penetrar la defensa enemiga!" << endl;
        } else {
            Ndum.HP -= p.ATTACK - Ndum.DEFENSE;
        }
        cout << Ndum.NaDummyName << " Recibio: " << p.ATTACK - Ndum.DEFENSE << " de dano!" << endl;
    }
}

void DummyAttackPlayer(Player& p, NaikaDummy& Ndum){
    int RNGDummy = rand() % 101; // RNG 0-100 (se le agregua el 101 porque si es 100, seria 0-99)

    if (RNGDummy < 25){
        cout << Ndum.NaDummyName << " Fallo el ataque!" << endl << endl;
    } else if (RNGDummy < 50){
        if (p.DEFENSE > Ndum.CRITICAL_ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << Ndum.NaDummyName << " realizo un ataque critico!" << endl;
            p.HP -= Ndum.CRITICAL_ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Ndum.CRITICAL_ATTACK - p.DEFENSE << " de dano critico!" << endl << endl;
        }
    } else {
        if (p.DEFENSE > Ndum.ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << Ndum.NaDummyName << " realizo un ataque exitoso" << endl;
            p.HP -= Ndum.ATTACK - p.DEFENSE;
            cout << "\033[34m" << p.PlayerName << "\033[0m" << " Recibio: " << Ndum.ATTACK - p.DEFENSE << " de dano." << endl << endl;
        }
    }
}

string TalkDummy[] = {
    "El muñeco... te ignora...", // 0
    "Intentas asustar al muñeco de Naika...", // 1 
    "Hablas de tus problemas con el muñeco...", // 2
    "Hablas mal de \033[31mNaika\033[0m...", // 3
    "El muñeco te dice algo sobre una profecia..."  // 4
};

string TalkMercyDummy[] = {
    "Abrazas al muñeco de Naika para reconciliarse", // 0
    "Intentas negociar con Naika con darle tus dinero", // 1
    "Intentas purificar al muñeco endemoniado", // 3
    "Le tiras un halago al muñeco de Naika... (La verdadera \033[31mNaika\033[0m se sonroja)" // 4
};

void NaikaDummyBattle(Player& p, NaikaDummy& Ndum){

    int TempDefense = p.DEFENSE; // guardamos una variable de defensa temporal, para evitar posibles conflictos futuros en caso de que se cambie
    int MercyPoints = 0; // puntos de piedad
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int DummyHP = Ndum.HP;
    int DummyMana = Ndum.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;  // variables de opciones dentro de switchs                              // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;  // bandera para terminar la batalla
    bool RageDummy = false;   // bandera para el modo rage del enemigo
    bool Mercy = false;       // bandera para victoria pacifista
    int FireShifts = 0;       // la cantidad de turnos por las que se quemara el jugador

    do{
        int RNGTalkDummy = rand() % 101; // variables RNG dentro del do para que se generen nuevos numeros
        int RNGMercy = rand() % 101;
        bool RegMana = true;      // bandera para regenerar MANA
        int RandomEvent = rand() % 101;
        cout << "Oponente: " << "\033[33m" << Ndum.NaDummyName << "\033[0m" << endl; // Codigo ANSI amarillo
        EnemyHpBar(Ndum);
        if (Mercy == false){
            cout << Ndum.NaDummyName << " Esta determinada" << endl << endl;
        } else {
            cout << Ndum.NaDummyName << " Parece agotada" << endl << endl;
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

    system("cls");
        switch (option){ // switch general
        case 1: // ATTACK
            cout << "1. " << Ndum.NaDummyName << " HP: " << Ndum.HP << "/" << Ndum.MAX_HP << endl;
            cout << "2. RETURN" << endl; 
            cin >> option_attack;

            switch (option_attack){ // switch de case 1
            case 1: // ATTACK a Naika Dummy
                    PlayerAttackDummy(p, Ndum); // atacas al enemigo // 25% de fallar // 25% de critico
                    cout << endl;
                    DummyAttackPlayer(p, Ndum); // el enemigo te ataca // 25% de fallar
                break;
            case 2: // RETURN
            RegMana = false;
                system("cls");
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
                system("cls");
                PlayerMagic(p, Ndum);
                cout << endl;
                Sleep(500);
                DummyAttackPlayer(p, Ndum);
            } else {
                system("cls");
                PlayerMagic(p, Ndum);
                cout << endl;
                Sleep(500);
                DummyAttackPlayer(p, Ndum);
            }
            break;
// end case 2
        case 3: // ACTION
            system("cls");
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. BURLARTE\n5. PLATICAR\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;
        
            switch (option_action){
            case 1: // MY STATS
            RegMana = false;
                system("cls");
                ShowStats(p); // llamar funcion
                cin.ignore(); // es como un cin, para que el jugador decida cuando avanzar,  descarta el '\n' pendiente
                cin.get();    // esto es util porque switch solo acepta numeros, si se ingresa una letra colapsa,  ahora sí espera a que el usuario presione Enter
                cout << endl;
                system("cls");
                break;
            case 2: // ENEMY DESCRIPTION
            RegMana = false;
                system("cls");
                DummyShowStats(Ndum); // llamar funcion
                cout << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3: // EXCHANGE MAGIC
            RegMana = false;
                system("cls");
                cout << "Intercambiar magia actual:\n";
                cout << "1. Magia Vendaval\n2. Magia curacion\n3. RETURN\n\n";
                cin >> option_exmagic;
            
                switch (option_exmagic){
                case 1:
                    system("cls");
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
                    system("cls");
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
                    system("cls");
                    break;
                default:
                    DefaultError();
                    RegMana = false;
                    break;
                }
                break;
            case 4: // ACT 1 - RAGE MODE
                system("cls");
            
                if (!RageDummy) {
                    cout << "Te burlaste de la patetica apariencia de " << Ndum.NaDummyName << endl;
                    cout << "...Provocaste al enemigo\n \n";
                    Sleep(1500);
                    cout << Ndum.NaDummyName << " se enojo!\n";
                    cout << "Sus ojos se vuelven rojos! y desea tu muerte a toda costa...\n\n"; 
                    RageDummy = true;
                
                    // Aumentar estadisticas cuando se enoja
                    Ndum.ATTACK += 20;
                    Ndum.DEFENSE = 0;
                    Ndum.MAX_HP += 25;
                    Ndum.HP = min(Ndum.HP + 25, Ndum.MAX_HP);
                    Sleep(1500);
                    cout << Ndum.NaDummyName << " incremento su vida!\n";
                    cout << Ndum.NaDummyName << " incremento su ataque!\n";
                    cout << Ndum.NaDummyName << " La defensa de muñeco de Naika ha caido!\n";
                } else {
                    RegMana = false;
                    cout << Ndum.NaDummyName << " ya esta enojado\n";
                    cout << Ndum.NaDummyName << " tiembla de furia!\n";
                }
                cout << endl;
                break;
            case 5: // HABLAR
            system("cls");
                cout << "Intentas hablar con " << Ndum.NaDummyName << endl;
                Sleep(1500);

                if (RNGTalkDummy <= 20){
                    cout << TalkDummy[0] << endl;
                    cout << "-10 de daño emocional... " << endl;
                    p.HP -= 10;
                } else if (RNGTalkDummy > 20 && RNGTalkDummy <= 40){
                    cout << TalkDummy[1] << endl;
                    cout << "Pero no reacciona... no hace nada... no parpadea... ni puede" << endl;
                    RegMana = false;
                } else if (RNGTalkDummy > 40 && RNGTalkDummy <= 60){
                    cout << TalkDummy[2] << endl;
                    cout << "Te entiende y trata de sanarte con sana sana colita de rana...?" << endl;
                    cout << "Funciono... eso crees... te curas +5 HP" << endl;
                    p.HP = min(p.HP += 5, p.MAX_HP);
                } else if (RNGTalkDummy > 60 && RNGTalkDummy <= 80){
                    cout << TalkDummy[3] << endl;
                    cout << Ndum.NaDummyName << " Se enojo tanto que te lanzo una bomba molotov... auch" << endl;
                    cout << "Te restaran -5 HP durante los proximos 2 turnos" << endl;
                    FireShifts += 2;
                }

                Sleep(2500);
                cout << "\n¡El muñeco de Naika ataca repentinamente!" << endl;
                Sleep(1000);
                DummyAttackPlayer(p, Ndum);
                break;

            case 6: // ACT 3 PIEDAD
                system("cls");
                if (RNGMercy <= 25){ // 25 % de que aparezca el arreglo
                    cout << TalkMercyDummy[0] << endl;
                    string RealNaika= "Hey! Estas peleando! no abrazando!... y ya tienes a la real... olvidalo sigue o yo misma te rompere cada hueso!";
                    cout << "\033[31mNaika\033[0m: ";
                    for (char c : RealNaika) {
                        cout << c;
                        Sleep(30); }
                        cout << endl;
                        if (RandomEvent < 50){ // 50%
                            cout << Ndum.NaDummyName << " ha aceptado tu abrazo :3" << endl;
                            MercyPoints++;
                            cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                        } else {
                        cout << Ndum.NaDummyName <<" No acepto tu abrazo >:(" << endl;
                        DummyAttackPlayer(p, Ndum);
                    }

                } else if (RNGMercy > 25 && RNGMercy <= 50){ // 25%  de que aparezca el arreglo
                    cout << TalkMercyDummy[1] << endl;
                    if (RandomEvent <= 25){ // 25%
                        cout << Ndum.NaDummyName << " ha aceptado tu perdon... por tu dinero... yey!" << endl;
                        MercyPoints += 3;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                        p.MONEY = 0;
                        cout << "Te quedaste con los bolsillos vacios..." << endl;
                    } else {
                        cout << "Le ofreciste tu dinero a " << Ndum.NaDummyName << endl;
                        cout << Ndum.NaDummyName << "Se ofendio... penso que la querias comprar..." << endl;
                        cout << Ndum.NaDummyName << "Se enojo tanto que incremento su ataque en +5..." << endl;
                        Ndum.ATTACK += 5;
                    }

                } else if (RNGMercy <= 75){ // 25% de que aparezca el arreglo
                    cout << TalkMercyDummy[2] << endl;
                    cout << Ndum.NaDummyName << " se ha sometido a un exorcismo..." << endl;
                    Sleep(1500);
                    if (RandomEvent <= 15){ // 15%
                        cout << Ndum.NaDummyName << " esta siendo exorcisada... lo estas logrando..." << endl;
                        MercyPoints += 2;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                    Sleep(1500);
                    } else {
                        cout << "El exorcismo esta fallando... el demonio se apodera de ella..." << endl;
                        cout << Ndum.NaDummyName << " incremento su ataque +5 por el exorcismo fallido..." << endl;
                        Ndum.ATTACK += 5;
                    }

                } else { // otro 25% de que aparezca el arreglo
                    cout << TalkMercyDummy[3] << endl;
                    cout << "Halagas su... cuerpo de madera a " << Ndum.NaDummyName << endl;
                    Sleep(1500);
                    if (RandomEvent <= 50){ // 50%
                        cout << Ndum.NaDummyName << " se halaga... la haces sentir joven... apenas tiene 5 minutos de vida..." << endl;
                        MercyPoints += 1;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                    } else {
                        cout << "Te abofeteo... eso fue sexista... deberias sentirte culpable" << endl;
                        cout << Ndum.NaDummyName << " Se prepara para darte una leccion..." << endl;
                        DummyAttackPlayer(p, Ndum);
                    }
                }
                cout << endl;
                Sleep(1000);
                break;
            case 7: // DEFEND
            RegMana = false;
            system("cls");
                cout << "Te defiendes del proximo ataque de " << Ndum.NaDummyName << endl;
                cout << "Tu defensa de multiplico x2 este turno." << endl;
                cout << "Recuperas +20 \033[34mMANA\033[0m" << endl << endl;
                p.MANA = min(p.MANA + 20, p.MAX_MANA);
                p.DEFENSE = TempDefense * 2;
                DummyAttackPlayer(p, Ndum);
                p.DEFENSE = TempDefense;
                break;
            case 8: // RETURN
            RegMana = false;
                system("cls");
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
            DummyAttackPlayer(p, Ndum);
        break;
// end case 4
        case 5: // MERCY
            if (Mercy == false){
                cout << Ndum.NaDummyName << " No acepta tu piedad..." << endl;
                DummyAttackPlayer(p, Ndum);
            } else {
                cout << Ndum.NaDummyName << " Acepto tu perdon... VICTORIA!" << endl;
                p.PacifistPoints++;
                battleOver = true;
            }
            break;
        default:
            DefaultError();
            break;
        }

        if (FireShifts > 0){
            cout << p.PlayerName << " se quemo en este turno, pierde -5 HP" << endl;
            p.HP -= 5;
            FireShifts--;
        }

        if(p.HP <= 0){
            cout << Ndum.NaDummyName << " ha derrotado a " << "\033[34m" << p.PlayerName << "\033[0m" << endl;
            cout << "\033[31mGAME OVER\033[0m" << endl;
            cout << "\033[33mContinue?\033[0m\n1. YES\n2. NO\n\n";
            cin >> option_GameOver;

            switch (option_GameOver){ // switch de case 1 - gameover
            case 1:
                system("cls");
                cout << "Retornando con valor..." << endl;
                cout << "Volviendo al último checkpoint...\n" << endl;
                Sleep(1000);
                Checkpoint(p, Ndum, PlayerHp, PlayerMana, DummyHP, DummyMana);
                system("cls");
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

        if(Ndum.HP <= 0){
            cout << Ndum.NaDummyName << " ha sido derrotada!" << endl; // condicional si el enemigo ha sido derrotado
            p.KilledNaikaDummy = true;
            p.KILLS++;
            battleOver = true;
        }
        if (RegMana){ // variable para a regeneracion de MANA en cada turno, SI no se ha usado magia
        p.MANA = min(p.MANA + 10, p.MAX_MANA);
        }
        if (Ndum.HP <= 20 || MercyPoints == 3){ // condicion pacifista
            Mercy = true;
        }

    } while (!battleOver); // condicion para que termine la batalla
}