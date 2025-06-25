#include <iostream>
#include <windows.h>
#include <time.h>
#include "Data/PlayerData/PlayerData.h" 
#include "Data/NaikaDummy/NaikaDummy.h" // enlazar librerias para la batalla, jugador y Naika Dummy.
using namespace std;
//Muñeco con forma de Naika aparecio*

void Checkpoint(Player& p, NaikaDummy& Ndum, int PlayerHP, int PlayerMana, int DummyHp, int DummyMana){ // guardar las variables localmente para poder usar checkpoint
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Ndum.HP = DummyHp;
    Ndum.MANA = DummyMana;
} // funcion local

void PlayerMagic(Player& p, NaikaDummy& Ndum){
    int opcionPlayerMagic;
    if (p.MagicDefault == "Magia vendaval"){ // si magia es vendaval
    cout << "1. " << Ndum.NaDummyName << " HP: " << Ndum.HP << "/" << Ndum.MAX_HP << endl;
    cout << "2. RETURN" << endl;
    cin >> opcionPlayerMagic;

    switch (opcionPlayerMagic){
    case 1:
        if (p.MANA < 30){
            cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
            cout << "Usaste: " << p.MagicDefault << endl;
            Sleep(2000);
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
        system("cls");
        cout << "Opcion de comando invalida" << endl;
        Sleep(1000); cout << endl;
        system("cls");
        break;
        }
    } else if (p.MagicDefault == "Magia curacion"){ // si esta magia de curacion
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;

        switch (opcionPlayerMagic){
        case 1:
            if (p.MANA < 50){
                cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
                p.HP += 20;
                if (p.HP > p.MAX_HP) {
                cout << "\033[33m¡Has excedido tu vida máxima! Parte de la curación se ha perdido.\033[0m" << endl;
                p.HP = p.MAX_HP;
                }
                p.MANA -= 50;
                cout << p.PlayerName << " se curo, +20 HP" << endl;
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

    bool RageDummy = false;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int DummyHP = Ndum.HP;
    int DummyMana = Ndum.MANA;
    int opcion, opcion_attack, option_action, option_GameOver, option_exmagic;  // variables de opciones dentro de switchs
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
            system("cls");
            PlayerMagic(p, Ndum);
            cin >> x;
            break;
// end case 2
        case 3: // ACTION
            system("cls");
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. BURLARTE\n5. HABLARLE \n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;

            switch (option_action){
            case 1: // MY STATS
                system("cls");
                ShowStats(p); // llamar funcion
                cin >> x;
                cout << endl;
                system("cls");
                break;
            case 2: // ENEMY DESCRIPTION
                system("cls");
                DummyShowStats(Ndum); // llamar funcion

                cin >> x;
                cout << endl;
                system("cls");
                break;
            case 3: // EXCHANGE MAGIC
                system("cls");
                cout << "Intercambiar magia actual:\n";
                cout << "1. Magia Vendaval\n2. Magia curacion\n3. RETURN\n\n";
                cin >> option_exmagic;

                switch (option_exmagic){
                case 1:
                    system("cls");
                    if (p.MagicDefault == "Magia vendaval"){
                        cout << "Ya tienes equipada esta magia" << endl;
                        cout << endl;
                    } else {
                        p.MagicDefault = "Magia vendaval";
                        cout << "Te quipaste: " << p.MagicDefault << endl;
                    }
                    cin >> x;
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    if (p.MagicDefault == "Magia curacion"){
                        cout << "Ya tienes equipada esta magia" << endl;
                    } else {
                        p.MagicDefault = "Magia curacion";
                        cout << "Te quipaste: " << p.MagicDefault << endl;
                    }
                    cin >> x;
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "Opcion de comando invalida" << endl;
                    Sleep(1000); cout << endl;
                    system("cls");
                    break;
                }
                system("cls");
                break;
            case 4: // BURLA
                system("cls");

                if (!RageDummy) {
                    cout << "Te burlaste de la patetica apariencia de " << Ndum.NaDummyName << endl;
                    cout << "...Provocaste al enemigo\n \n";
                    Sleep(1500);
                    cout << "muneco de Naika se enojo!\n";
                    cout << "Sus ojos se vuelven rojos! y desea tu muerte a toda costa...\n\n"; 
                    RageDummy = true;

                    // Aumentar estadisticas cuando se enoja
                    Ndum.ATTACK += 20;
                    Ndum.DEFENSE = 0;
                    Ndum.MAX_HP += 25;
                    Ndum.HP += 25;
                    Sleep(1500);
                    cout << "Muneco de Naika incremento su ataque!\n";
                    cout << "La defensa de muneco de Naika ha caido!\n";
                    cin >> x;
                    system("cls");
                } else {
                    cout << "Muneco de Naika ya esta enojado\n";
                    cout << "Muneco de Naika tiembla de furia!\n";
                    cin >> x;
                    system("cls");
                }
                system("cls");
                break;
            case 5: // HABLAR
                cout << "Intentas conectar con el muñeco de Naika..." << endl;
                Sleep(1500);
    
                int dialogChance = rand() % 100;
    
                if (dialogChance < 15) {
                    cout << "\"Fui creada para probar tu determinación!\"" << endl;
                    cout << "\"Si fallas aquí, no sobrevivirás a lo que viene...\"" << endl;
                } else if (dialogChance < 30) {
                    cout << "\"Tu moriras!!\"" << endl;
                } else if (dialogChance < 45) {
                    cout << "\"Mi creador... debo protegerlo a toda costa!\"" << endl;
                    cout << "\"Él me dio vida cuando nadie más lo haría...\"" << endl;
                } else if (dialogChance < 60) {
                    cout << "\"¿Por qué luchas? ¿Qué te impulsa realmente?\"" << endl;
                    cout << "\"Todos tenemos nuestras razones para pelear...\"" << endl;
                } else if (dialogChance < 75) {
                    cout << "\"Al final... todos somos marionetas de alguien\"" << endl;
                    cout << "\"¿Quién tira de tus hilos, " << p.PlayerName << "?\"" << endl;
                } else if (dialogChance < 85) {
                    cout << "\"El dolor es solo una señal de que sigues vivo\"" << endl;
                    cout << "\"Aprende a abrazarlo o te destruirá...\"" << endl;
                } else if (dialogChance < 90) {
                    cout << "\"La oscuridad que combates vive dentro de ti\"" << endl;
                    cout << "\"¿Podrás enfrentar tus propios demonios?\"" << endl;
                }
                 Sleep(2500);
                // Naika ataque después del diálogo
                cout << "\n¡El muñeco de Naika ataca repentinamente!" << endl;
                Sleep(1000);
                DummyAttackPlayer(p, Ndum);
                break;
            case 6: // PACIFICAR
                break;
            case 7: // DEFEND
                break;
            case 8: // RETURN
                system("cls");
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
            cout << Ndum.NaDummyName << " ha sido derrotada!" << endl;
            battleOver = true;
        }
    } while (!battleOver); // condicion para que termine la batalla
}