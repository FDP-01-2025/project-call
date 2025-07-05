#ifndef NIHILUS_H
#define NIHILUS_H
#include <string>
using namespace std;

struct Nihilus {
    string NihilusName;
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

Nihilus Nihilus_Data();
void ShowStatsNihilus(const Nihilus& Nihi);

#endif