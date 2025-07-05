#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include <string>
using namespace std;

struct Player {
    // Player attributes
    string PlayerName;
    int Level;
    int HP;
    int MAX_HP;
    int ATTACK;
    int CRITICAL_ATTACK;
    int MAGIC_ATTACK;
    int HEALTH_MAGIC;
    int DEFENSE;
    int MONEY;
    string WEAPON;
    string ARMOR;
    // attributes for player magic
    int MANA;
    int MAX_MANA;
    int MANACOST_AT;
    int MANACOST_HE;
    string MagicDefault;
    string Magic1;
    string Magic2;
    // attributes for player items and effects
    string Item1;
    string Item2;
    string Item3;
    int PotionsHP;
    int PotionsMANA;
    int CantItem3;
    int PoEffectHP;
    int PoEffectMANA;
    int EffectItem3;
    // attributes for player relations and events
    int KILLS;
    int PacifistPoints;
    bool BadRelationNaika;
    bool KilledNaikaDummy;
    bool KilledEliteSlime;
    bool KilledTroll;
};

Player Global_Data();
void ShowStats(const Player& p);

#endif