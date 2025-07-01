#ifndef NAIKADUMMY_H
#define NAIKADUMMY_H
#include <string>
using namespace std;

struct NaikaDummy{
    string NaDummyName;
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

NaikaDummy Dummy_Data();
void DummyShowStats(const NaikaDummy& Ndum);

#endif