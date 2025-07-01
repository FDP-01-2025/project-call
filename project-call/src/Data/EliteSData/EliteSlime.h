#ifndef ELITESLIME_H
#define ELITESLIME_H
#include <string>
using namespace std;

struct EliteS {
    string EliteSName;
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

EliteS EliteS_Data();
void ShowStats(const EliteS& Na);

#endif