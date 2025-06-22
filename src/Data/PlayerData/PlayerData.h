#ifndef PLAYERUTILS_H
#define PLAYERUTILS_H

#include <string>
using namespace std;

struct Player {
    string PlayerName;
    int Level;
    int HP;
    int MAX_HP;
    int ATTACK;
    int CRITICAL_ATTACK;
    int DEFENSE;
    int MANA;
    int MAX_MANA;
    int MONEY;
};

struct Player Global_Data();
void ShowStats(Player p);

#endif