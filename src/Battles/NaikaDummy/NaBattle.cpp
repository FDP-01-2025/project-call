#include <iostream>
#include <windows.h>
#include <time.h>
#include "Data/PlayerData/PlayerData.h" // 
#include "Data/NaikaDummy/NaikaDummy.h" // enlazar librerias para la batalla, jugador y Naika Dummy.
using namespace std;
//Muñeco con forma de Naika aparecio*

void Checkpoint(Player& p, NaikaDummy& Ndum, int PlayerHP, int PlayerMana, int DummyHp, int DummyMana){ // guardar las variables localmente para poder usar checkpoint
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Ndum.HP = DummyHp;
    Ndum.MANA = DummyMana;
} // funcion local

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
            cout << p.PlayerName << " Recibio: " << Ndum.CRITICAL_ATTACK - p.DEFENSE << " de dano critico!" << endl << endl;
        }
    } else {
        if (p.DEFENSE > Ndum.ATTACK){
            cout << "El enemigo no es capaz de penetrar tu defensa!" << endl;
        } else {
            cout << Ndum.NaDummyName << " realizo un ataque exitoso" << endl;
            p.HP -= Ndum.ATTACK - p.DEFENSE;
            cout << p.PlayerName << " Recibio: " << Ndum.ATTACK - p.DEFENSE << " de dano." << endl << endl;
        }
    }
}

void NaikaDummyBattle(Player& p, NaikaDummy& Ndum){

    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int DummyHP = Ndum.HP;
    int DummyMana = Ndum.MANA;
    int opcion, opcion_attack, option_action, option_GameOver;  // variables de opciones dentro de switchs
    string x;                                  // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;                   // bandera para terminar la batalla
    do{
        cout << "Oponente: " << "\033[33m" << Ndum.NaDummyName << "\033[0m" << endl << endl; // Codigo ANSI amarillo
        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        cin >> opcion;

    system("cls");
        switch (opcion){ // switch general
        case 1: // ATTACK
            cout << "1. " << Ndum.NaDummyName << " HP: " << Ndum.HP << "/" << Ndum.MAX_HP << endl;
            cout << "2. RETURN" << endl; 
            cin >> opcion_attack;

            switch (opcion_attack){ // switch de case 1
            case 1: // ATTACK a Naika Dummy
                if(opcion_attack == 1){
                    PlayerAttackDummy(p, Ndum); // atacas al enemigo // 25% de fallar // 25% de critico
                    cout << endl;
                    DummyAttackPlayer(p, Ndum); // el enemigo te ataca // 25% de fallar
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
                            system("cls");
                            cout << "Opcion de comando invalida" << endl;
                            Sleep(1000); cout << endl;
                            system("cls");
                            break;  // variable para continuar o no
                        }
                    }
                    if(Ndum.HP <= 0){
                        cout << Ndum.NaDummyName << " ha sido derrotado!" << endl;
                        battleOver = true;
                    }
                }
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
                break; // break de default
                }
            break; // break de case 1
// end case 1
        case 2: // MAGIC
            
            break;
// end case 2
        case 3: // ACTION
            system("cls");
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. ACT 1\n5. ACT 2\n6. ACT 3\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;

            switch (option_action){
            case 1:
                system("cls");
                ShowStats(p); // llamar funcion
                cin >> x;
                cout << endl;
                system("cls");
                break;
            case 2:
                system("cls");
                DummyShowStats(Ndum); // llamar funcion
                cin >> x;
                cout << endl;
                system("cls");
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                system("cls");
                cout << "Opcion de comando invalida" << endl;
                Sleep(1000); cout << endl;
                system("cls");
                break; // break de default
            }
            break; // break de case 3
// end case 3
        case 4: // ITEM
            
            break;
        case 5: // MERCY
            
            break;
        default:
            cout << "Opcion de comando invalida" << endl;
            Sleep(1000); cout << endl;
            system("cls");
            break;
        }

    } while (!battleOver); // condicion para que termine la batalla
}