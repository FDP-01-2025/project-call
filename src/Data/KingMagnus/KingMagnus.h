#ifndef KINGMAGNUS_H
#define KINGMAGNUS_H
#include <string>
using namespace std;

struct KingMagnus {
    string KingMagnusName;
    int Level;
    int HP;
    int MAX_HP;
    int ATTACK;
    int CRITICAL_ATTACK;
    int DEFENSE;
    int MANA;
    int MAX_MANA;
    string WEAPON;
    string ARMOR;
};

KingMagnus KMagnus_Data();
void ShowStatsKingMagnus(const KingMagnus& Km);

#endif
