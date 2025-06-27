#ifndef PLAYERDATA_H
#define PLAYERDATA_H
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
    string WEAPON;
    string ARMOR;
    string MagicDefault;
    string Magic1;
    string Magic2;
    int PotionsHP;
    int PotionsMANA;
    int PoEffectHP;
    int PoEffectMANA;
};

Player Global_Data();
void ShowStats(const Player& p);

#endif