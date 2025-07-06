#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Data/PlayerData/PlayerData.h"
#include "Data/CerberusData/Cerberus.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

void EnemyHpBar(Cerbero& Cb) {
    int total_blocks = 10;
    int filled_blocks = (Cb.HP * total_blocks) / Cb.MAX_HP;
    if (Cb.HP > 0 && filled_blocks == 0) {
        filled_blocks = 1;
    }
    int empty_blocks = total_blocks - filled_blocks;

    string color = (Cb.HP > Cb.MAX_HP * 0.3) ? "\033[33m" : "\033[31m";
    cout << "HP:   " << color;
    for (int i = 0; i < filled_blocks; ++i) cout << "█";
    cout << "\033[30m";
    for (int i = 0; i < empty_blocks; ++i) cout << "█";
    cout << "\033[0m " << Cb.HP << "/" << Cb.MAX_HP << endl << endl;
}

void PlayerAttackCerbero(Player& p, Cerbero& Cb) {
    int RNG = rand() % 101;
    if (RNG < 25) {
        cout << "Atacas pero tus golpes rebotan contra la piel infernal de " << Cb.CerberoName << "." << endl;
        cout << "¡Has fallado el ataque!" << endl;
    } else if (RNG < 50) {
        cout << "Encuentras un punto vulnerable..." << endl;
        cout << "¡Golpe crítico!" << endl;
        int damage = p.CRITICAL_ATTACK - Cb.DEFENSE;
        if (damage > 0) {
            Cb.HP -= damage;
            cout << Cb.CerberoName << " recibió " << damage << " de daño crítico." << endl;
        } else {
            cout << "El ataque no logró hacerle daño..." << endl;
        }
    } else {
        cout << "Asestas un buen golpe..." << endl;
        int damage = p.ATTACK - Cb.DEFENSE;
        if (damage > 0) {
            Cb.HP -= damage;
            cout << Cb.CerberoName << " recibió " << damage << " de daño." << endl;
        } else {
            cout << "El ataque no logró hacerle daño..." << endl;
        }
    }
}

void PlayerMagic(Player& p, Cerbero& Cb, bool& Return) {
    int opcionPlayerMagic;
    if (p.MagicDefault == p.Magic1) {
        cout << "1. " << Cb.CerberoName << " HP: " << Cb.HP << "/" << Cb.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;
        Clear();
        switch (opcionPlayerMagic) {
            case 1:
                if (p.MANA < p.MANACOST_AT) {
                    cout << "No tienes suficiente \033[34mMANA\033[0m (" << p.MANA << "/" << p.MAX_MANA << ")" << endl;
                } else {
                    cout << "Usas: " << p.MagicDefault << endl;
                    Sleep(1000);
                    cout << "Pero no parece surtir efecto en Cerbero..." << endl;
                    p.MANA -= p.MANACOST_AT;
                }
                break;
            case 2:
                Return = true;
                break;
            default:
                DefaultError();
                break;
        }
    } else if (p.MagicDefault == p.Magic2) {
        cout << "1. " << p.PlayerName << " HP: " << p.HP << "/" << p.MAX_HP << endl;
        cout << "2. RETURN" << endl;
        cin >> opcionPlayerMagic;
        Clear();
        if (opcionPlayerMagic == 1) {
            if (p.MANA < p.MANACOST_HE) {
                cout << "No tienes suficiente \033[34mMANA\033[0m (" << p.MANA << "/" << p.MAX_MANA << ")" << endl;
            } else {
                int heal = min(p.HEALTH_MAGIC, p.MAX_HP - p.HP);
                p.HP += heal;
                p.MANA -= p.MANACOST_HE;
                cout << p.PlayerName << " se curó +" << heal << " HP" << endl;
            }
        }
    }
}

void CerberoAttackPlayer(Player& p, Cerbero& Cb, int MercyPoints) {
    int RNG = rand() % 101;
    int baseAttack = Cb.ATTACK;
    int baseCrit = Cb.CRITICAL_ATTACK;

    if (MercyPoints >= 75) {
    cout << "El feroz rugido de Cerbero se apaga un poco... parece dudar ante tu compasión." << endl;
    baseAttack -= 20;
    baseCrit -= 20;
    if (baseAttack < 0) baseAttack = 0;
    if (baseCrit < 0) baseCrit = 0;
}
else if (MercyPoints >= 50) {
    cout << "Por un instante, la mirada de Cerbero se suaviza... su rabia disminuye." << endl;
    baseAttack -= 15;
    baseCrit -= 15;
    if (baseAttack < 0) baseAttack = 0;
    if (baseCrit < 0) baseCrit = 0;
}
else if (MercyPoints >= 25) {
    cout << "Notas que tus cantos y bailes logran calmar ligeramente a Cerbero." << endl;
    baseAttack -= 5;
    baseCrit -= 5;
    if (baseAttack < 0) baseAttack = 0;
    if (baseCrit < 0) baseCrit = 0;
}

    if (RNG < 25) {
    cout << Cb.CerberoName << " se lanza rugiendo entre llamas..." << endl;
    Sleep(500);
    cout << "¡Pero resbaló sobre el terreno ardiente y falla el ataque!" << endl;
} else if (RNG < 50) {
    if (p.DEFENSE > baseCrit) {
        cout << "Cerbero se abalanza con furia, pero tu defensa resiste el impacto!" << endl;
    } else {
        cout << "¡Cerbero abre sus tres fauces y lanza un mordisco devastador!" << endl;
        Sleep(500);
        cout << "¡Es un golpe crítico!" << endl;
        int damage = baseCrit - p.DEFENSE;
        p.HP -= damage;
        cout << "\033[34m" << p.PlayerName << "\033[0m recibió: " << damage << " de daño crítico, tambaleándose ante el poder infernal." << endl;
    }
} else {
    if (p.DEFENSE > baseAttack) {
        cout << Cb.CerberoName << " ataca con rabia..." << endl;
        Sleep(500);
        cout << "¡Pero tu armadura resiste el impacto del fuego infernal!" << endl;
    } else {
        cout << Cb.CerberoName << " muerde ferozmente con sus fauces llameantes!" << endl;
        int damage = baseAttack - p.DEFENSE;
        p.HP -= damage;
        cout << "\033[34m" << p.PlayerName << "\033[0m recibió: " << damage << " de daño." << endl;
    }
}
}

void CerberoBattle(Player& p, Cerbero& Cb) {
    srand(time(0));
    int TempDefense = p.DEFENSE;
    int MercyPoints = 0;
    int PlayerHp = p.HP;
    int PlayerMana = p.MANA;
    int option, option_attack, option_action, option_GameOver, option_exmagic, option_item;
    bool battleOver = false;
    bool Return = false;

    do {
        int RNGSing = rand() % 101;
        bool RegMana = true;

        cout << "Enemigo: " << Cb.CerberoName << endl;
        EnemyHpBar(Cb);
        cout << "\033[34m" << p.PlayerName << "\033[0m" << endl;
        HpBar(p); ManaBar(p);
        cout << "Piedad: " << MercyPoints << "/100" << endl << endl;
        cout << "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY" << endl;
        cin >> option; Clear();

        switch(option){
            case 1:
                cout << "1. Atacar a " << Cb.CerberoName << endl << "2. RETURN" << endl;
                cin >> option_attack;
                if(option_attack == 1){
                    Clear(); 
                    PlayerAttackCerbero(p, Cb);
                    CerberoAttackPlayer(p, Cb, MercyPoints);
                } else {
                    RegMana = false; Clear();
                }
                break;
            case 2:
                RegMana = false;
                PlayerMagic(p, Cb, Return);
                if(!Return) CerberoAttackPlayer(p, Cb, MercyPoints);
                break;
            case 3:
                cout << "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. CANTAR/Bailar\n5. DEFEND\n6. RETURN" << endl;
                cin >> option_action;
            Clear();

            switch(option_action) {
                case 1:
                    RegMana = false;
                    ShowStats(p);
                    cin.ignore();
                    cin.get();
                    Clear();
                break;

                case 2:
                    RegMana = false;
                    ShowStatsCerbero(Cb);
                    cin.ignore();
                    cin.get();
                    Clear();
            break;

                case 3:
                    RegMana = false;
                    cout << "1. Magia Vendaval\n2. Magia curacion\n";
                    cin >> option_exmagic;
                if(option_exmagic == 1){
                    p.MagicDefault = p.Magic1;
                }else if(option_exmagic == 2){
                    p.MagicDefault = p.Magic2;}
                else {
                    RegMana = false; 
                    Clear();}
                Sleep(1000);
                Clear();
            break;

                case 4:
                    cout << "Te acercas lentamente, alzando la voz..." << endl;
                Sleep(1000);
                    cout << "Comienzas a cantar o a bailar con determinación, intentando calmar el furor ardiente de " << Cb.CerberoName << "..." << endl;
                Sleep(1500);
                    cout << "Las llamas que brotan de sus fauces titilan, como dudando ante tu melodía..." << endl;
                Sleep(1500);

                if(RNGSing < 10) {
                    cout << "El gigantesco perro parece hipnotizado... cierra lentamente tres de sus ojos." << endl;
                    cout << "¡Has ganado +25 puntos de piedad!" << endl;
                    MercyPoints += 25;
                } else if(RNGSing < 25) {
                    cout << Cb.CerberoName << " sacude la cabeza, pero por un momento su respiración se calma." << endl;
                    cout << "+10 puntos de piedad." << endl;
                    MercyPoints += 10;
                } else if(RNGSing < 50) {
                    cout << "Tus notas logran calmarlo apenas... su furia titubea un instante." << endl;
                    cout << "+5 puntos de piedad." << endl;
                    MercyPoints += 5;
                } else {
                    cout << "A pesar de tus esfuerzos, Cerbero apenas baja la guardia." << endl;
                    cout << "+1 punto de piedad." << endl;
                MercyPoints += 1;
                }

                Sleep(1000);
                cout << endl;
                cout << "Pero aún no está completamente calmado... ¡Te ataca!" << endl;
                CerberoAttackPlayer(p, Cb, MercyPoints);
                break;

        case 5:
            RegMana = false;
            p.DEFENSE = TempDefense * 3;
            p.MANA = min(p.MANA + 30, p.MAX_MANA);
            CerberoAttackPlayer(p, Cb, MercyPoints);
            p.DEFENSE = TempDefense;
            break;

        case 6:
            RegMana = false;
            Clear();
            break;

        default:
            RegMana = false;
            DefaultError();
            break;
    }
    break;
            // case 4: // ITEM
            case 4:
                RegMana=false; Items(p,option_item);
                break;
            case 5:
                if(MercyPoints>=100){
                    cout<<"Cerbero cierra los ojos... perdonado!"<<endl;
                    p.PacifistPoints++; battleOver=true;
                }else{
                    cout<<"Aún no tienes suficiente piedad."<<endl;
                    CerberoAttackPlayer(p,Cb,MercyPoints);
                }
                break;
            default:DefaultError();break;
        }
        if(p.HP<=0){
            cout<<Cb.CerberoName<<" ha derrotado a "<<p.PlayerName<<endl;
            cout<<"GAME OVER\n1. YES\n2. NO"<<endl;
            cin>>option_GameOver;
            if(option_GameOver==1){
                p.HP=PlayerHp;
                p.MANA=PlayerMana;
                Clear();}
            else {cout<<"Adiós..."<<endl;exit(0);}
        }
        if(RegMana) p.MANA=min(p.MANA+10,p.MAX_MANA);
    }while(!battleOver);
}
