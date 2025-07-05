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
void Checkpoint(Player& p, Nihilus& Nihi, int PlayerHP, int PlayerMana, int NihiHp, int NihiMana){
    p.HP = PlayerHP;
    p.MANA = PlayerMana;
    Nihi.HP = NihiHp;
    Nihi.MANA = NihiMana;
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
        if (RNG2 < 25){
            cout << Nihi.NihilusName << " falla su ataque!" << endl;
        } else if (RNG2 < 50){
            cout << "¡Golpe crítico del vacío!" << endl;
            p.HP -= max(0, Nihi.CRITICAL_ATTACK - p.DEFENSE);
            cout << p.PlayerName << " recibió " << max(0, Nihi.CRITICAL_ATTACK - p.DEFENSE) << " de daño crítico!" << endl;
        } else {
            cout << Nihi.NihilusName << " ataca con su daga oscura." << endl;
            p.HP -= max(0, Nihi.ATTACK - p.DEFENSE);
            cout << p.PlayerName << " recibió " << max(0, Nihi.ATTACK - p.DEFENSE) << " de daño!" << endl;
        }
    }
}

