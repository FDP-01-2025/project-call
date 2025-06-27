#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm> // sirve para usar min y max
#include "Data/PlayerData/PlayerData.h" // el lib de Player es obligatorio en cada batalla
#include "Data/NaikaDummy/NaikaDummy.h" // enlazar librerias para la batalla, jugador y Naika Dummy.
using namespace std;
//Muñeco con forma de Naika aparecio*

#include <iostream>
using namespace std;

void HpBar(Player& p) {
    int total_blocks = 10; // variable de la cantidad de bloques
    int filled_blocks = (p.HP * total_blocks) / p.MAX_HP; // calcula cuantos se deben llenar
    int empty_blocks = total_blocks - filled_blocks; // calcula los bloques vacios

    string color = (p.HP > p.MAX_HP * 0.3) ? "\033[33m" : "\033[31m"; // Amarillo o rojo dependiendo de la vida
    cout << "HP:   " << color;

    for (int i = 0; i < filled_blocks; ++i){ // imprime la barra de vida actual
        cout << "█";
    }

    cout << "\033[30m"; // Color gris
    for (int i = 0; i < empty_blocks; ++i){ // imprime la vida restada
        cout << "█";
    }

    cout << "\033[0m " << p.HP << "/" << p.MAX_HP << endl; // muestra el estado actual de tu vida
}

void ManaBar(Player& p){
    int total_blocks = 10;
    int filled_blocks = (p.MANA * total_blocks) / p.MAX_MANA;
    int empty_blocks = total_blocks - filled_blocks;

    string color = (p.MANA > p.MAX_MANA * 0.3) ? "\033[34m" : "\033[35m"; // Amarillo o rojo dependiendo de la vida
    cout << "MANA: " << color;

    for (int i = 0; i < filled_blocks; i++){
        cout << "█";
    }

    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; i++){
        cout << "█";
    }

    cout << "\033[0m " << p.MANA << "/" << p.MAX_MANA << endl; // muestra el estado actual de tu mana
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
        if (p.MANA < 30){
            cout << "No cuentas con el \033[34mMANA\033[0m suficiente " << "\033[31m" << p.MANA << "\033[0m/" << p.MAX_MANA << endl;
            } else {
            cout << "Usaste: " << p.MagicDefault << endl;
            Sleep(1000);
            cout << endl;
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

string TalkDummy[] = {
    "Le hablas al muñeco de Naika... te ignora...", // 0
    "Intentas asustar al muñeco de Naika...", // 1 
    "Hablas de tus problemas con el muñeco de Naika...", // 2
    "", // 3
    ""  // 4
};
string TalkMercyDummy[] = {
    "Abrazas al muñeco de Naika para reconciliarse", // 0
    "Intentas negociar con Naika con darle tus dinero", // 1
    "Intentas purificar al muñeco endemoniado", // 3
    "Le tiras un halago al muñeco de Naika... (La verdadera \033[31mNaika\033[0m se sonroja)" // 4
};

void NaikaDummyBattle(Player& p, NaikaDummy& Ndum){

    int RNGTalkDummy = rand() % 101;
    int RNGMercy = rand() % 101;
    int RandomEvent = rand() % 101;
    int MercyPoints = 0; // puntos de piedad
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int DummyHP = Ndum.HP;
    int DummyMana = Ndum.MANA;
    int opcion, opcion_attack, option_action, option_GameOver, option_exmagic;  // variables de opciones dentro de switchs                              // variable para pausar el codigo y proceder cuando el usuario decida
    bool battleOver = false;                   // bandera para terminar la batalla
    bool RageDummy = false;

    do{
        cout << "Oponente: " << "\033[33m" << Ndum.NaDummyName << "\033[0m" << endl << endl; // Codigo ANSI amarillo
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;

        HpBar(p); // barra de vida dinamica
        ManaBar(p); // barra de mana dinamica
        if (p.HP <= 30) cout << "\033[31mDANGER:\033[0m low life";
        cout << endl;

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
            if (p.MagicDefault != p.Magic2){ // si te curas dummy no te atacara
                system("cls");
                PlayerMagic(p, Ndum);
                cout << endl;
                Sleep(500);
                DummyAttackPlayer(p, Ndum);
                cout << endl;
            } else {
                system("cls");
                PlayerMagic(p, Ndum);
                cout << endl;
                Sleep(500);
                cout << endl;
            }
            break;
// end case 2
        case 3: // ACTION
            system("cls");
            cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. BURLARTE\n5. HABLARLE 2\n6. PACIFICAR\n7. DEFEND\n8. RETURN\n";
            cin >> option_action;
        
            switch (option_action){
            case 1: // MY STATS
                system("cls");
                ShowStats(p); // llamar funcion
                cin.ignore(); // es como un cin, para que el jugador decida cuando avanzar,  descarta el '\n' pendiente
                cin.get();    // esto es util porque switch solo acepta numeros, si se ingresa una letra colapsa,  ahora sí espera a que el usuario presione Enter
                cout << endl;
                system("cls");
                break;
            case 2: // ENEMY DESCRIPTION
                system("cls");
                DummyShowStats(Ndum); // llamar funcion
                cout << endl;
                cin.ignore();
                cin.get();
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
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "Opcion de comando invalida" << endl;
                    Sleep(1000); cout << endl;
                    system("cls");
                    break;
                }
                break;
            case 4: // ACT 1 - RAGE MODE
                system("cls");
            
                if (!RageDummy) {
                    cout << "Te burlaste de la patetica apariencia de " << Ndum.NaDummyName << endl;
                    cout << "...Provocaste al enemigo\n \n";
                    Sleep(1500);
                    cout << "muñeco de Naika se enojo!\n";
                    cout << "Sus ojos se vuelven rojos! y desea tu muerte a toda costa...\n\n"; 
                    RageDummy = true;
                
                    // Aumentar estadisticas cuando se enoja
                    Ndum.ATTACK += 20;
                    Ndum.DEFENSE = 0;
                    Ndum.MAX_HP += 25;
                    Ndum.HP = min(Ndum.HP + 25, Ndum.MAX_HP);
                    Sleep(1500);
                    cout << "Muñeco de Naika incremento su vida!\n";
                    cout << "Muñeco de Naika incremento su ataque!\n";
                    cout << "La defensa de muñeco de Naika ha caido!\n";
                } else {
                    cout << "muñeco de Naika ya esta enojado\n";
                    cout << "muñeco de Naika tiembla de furia!\n";
                }
                cout << endl;
                break; // ACT 2 HABLARLE
            case 5:
                // agregar un dialogo en que se queme el dummy por un cigarro
                // p.HP = min(p.HP + 10, p.MAX_HP); para agregar vida al usuario
            if (RNGTalkDummy <= 20){ 
                cout << TalkDummy[0] << endl;
                p.HP -= 5;
                cout << p.PlayerName << " recibio dano emocional..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
            } else if (RNGTalkDummy > 20 && RNGTalkDummy <= 40){
                cout << TalkDummy[1] << endl;
                cout << "El Dummy no hace absolutamente nada. Ni parpadea. Ni puede." << endl;
                cin.ignore();
                cin.get();
                system("cls");
            } else if (RNGTalkDummy > 40 && RNGTalkDummy <= 60){
                cout << TalkDummy[2] << endl;
                cout << "El hablar con el Dummy te ayudo a sentirte mejor con tigo mismo\n" << endl;
                p.HP = min(p.HP + 15, p.MAX_HP);
                cout << " Has recuperado 15 de HP" << endl;
                cin.ignore();
                cin.get();
                system("cls");
            } else if (RNGTalkDummy > 60 && RNGTalkDummy <= 80){
                cout << "";
            } else {
                cout << "";
            }
                break;
            case 6: // ACT 3 PIEDAD
                if (RNGMercy <= 25){
                    cout << TalkMercyDummy[0] << endl;
                    string RealNaika= "Hey! Estas peleando! no abrazando!... y ya tienes a la real... olvidalo sigue o yo misma te rompere cada hueso!";
                    cout << "\033[31mNaika\033[0m: ";
                    for (char c : RealNaika){
                        cout << c << endl;
                        Sleep(30);
                    }
                    if (RandomEvent < 50){ // 50%
                        cout << Ndum.NaDummyName << " ha aceptado tu abrazo :3" << endl;
                        MercyPoints++;
                        cout << "Puntos de piedad actuales: " << MercyPoints << endl;
                    } else {
                        cout << "No acepto tu abrazo >:(" << endl;
                        DummyAttackPlayer(p, Ndum);
                    }
                } else if (RNGMercy <= 50){
                    cout << TalkMercyDummy[1] << endl;
                    if (RandomEvent < 25){ // 25%
                        cout << Ndum.NaDummyName << " ha aceptado tu perdon... por tu dinero... yey!" << endl;
                        MercyPoints += 3;
                        p.MONEY = 0;
                        cout << "Te quedaste con los bolsillos vacios..." << endl;
                    } else {
                        cout << "Le ofreciste tu dinero a " << Ndum.NaDummyName << endl;
                        cout << Ndum.NaDummyName << "Se ofendio... penso que la querias comprar..." << endl;
                        cout << Ndum.NaDummyName << "Se enojo tanto que incremento su ataque en +5..." << endl;
                        Ndum.ATTACK += 5;
                    }
                } else if (RNGMercy <= 75){
                    cout << "";
                } else {
                    cout << "";
                }
                cin.ignore();
                cin.get();
                system("cls");
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
// end case 4
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
            cout << Ndum.NaDummyName << " ha sido derrotada!" << endl; // condicional si el enemigo ha sido derrotado
            battleOver = true;
        }

        if (opcion != 2 || option_action != 1 || option_action != 2 || option_action != 3){ // variable para a regeneracion de MANA en cada turno, SI no se ha usado magia
            p.MANA = min(p.MANA + 10, p.MAX_MANA);
        }

    } while (!battleOver); // condicion para que termine la batalla
}
/*
variable para el fuego simple:
30% array
bool fire = true
if (bool fire == true){
    i = 3
    fire = false;
}

if (i > 0){
HPPLAYER- 10
} else {
i--
}
*/
