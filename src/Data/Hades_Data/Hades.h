#ifndef HADES_H
#define HADES_H
#include <string>
using namespace std;

struct DHades {
    string HadesName;
    int Level;
    int HP;
    int MAX_HP;
    int ATTACK;
    int DEFENSE;
    int MANA;
    int MAX_MANA;
    string WEAPON;
    string ARMOR;
};

DHades Hades_Data();
void ShowStats(const DHades& h);

#endif