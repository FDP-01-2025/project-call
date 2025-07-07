#ifndef HYPNOS_H
#define HYPNOS_H
#include <string>
using namespace std;

struct DHypnos {
    string DHName;
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

DHypnos DH_Data();
void ShowStats(const DHypnos& h);

#endif