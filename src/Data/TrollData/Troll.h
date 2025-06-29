#ifndef TROLL_H
#define TROLL_H
#include <string>
using namespace std;

struct Troll{
    string TrollName;
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

Troll Troll_Data();
void ShowStatsTroll(const Troll& Tr);

#endif