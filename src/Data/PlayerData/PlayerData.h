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
    int MAGIC_ATTACK;
    int HEALTH_MAGIC;
    int MANACOST_AT;
    int MANACOST_HE;
    int DEFENSE;
    int MANA;
    int MAX_MANA;
    int MONEY;
    int KILLS;
    int PacifistPoints;
    string WEAPON;
    string ARMOR;
    string MagicDefault;
    string Magic1;
    string Magic2;
    string Item1;
    string Item2;
    string Item3;
    int PotionsHP;
    int PotionsMANA;
    int CantItem3;
    int PoEffectHP;
    int PoEffectMANA;
    int EffectItem3;
    bool KilledNaikaDummy;
    bool KilledEliteSlime;
    bool KilledTroll;
};

Player Global_Data();
void ShowStats(const Player& p);

#endif