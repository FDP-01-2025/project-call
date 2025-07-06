#ifndef CERBERO_H
#define CERBERO_H
#include <string>
using namespace std;

struct Cerbero{
    string CerberoName;
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

Cerbero Cerbero_Data();
void ShowStatsCerbero(const Cerbero& Cb);

#endif