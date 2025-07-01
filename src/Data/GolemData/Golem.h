#ifndef Golem_H
#define Golem_H
#include <string>
using namespace std;

struct Golem{
    string GolemName;
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

Golem Golem_Data();
void ShowStatsGolem(const Golem& Gol);

#endif