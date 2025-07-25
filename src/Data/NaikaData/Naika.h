#ifndef NAIKA_H
#define NAIKA_H
#include <string>
using namespace std;

struct Naika {
    string NaikaName;
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

Naika Naika_Data();
void ShowStats(const Naika& Na);

#endif