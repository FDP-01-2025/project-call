#ifndef LIBRARYSKY_H
#define LIBRARYSKY_H
#include <string>
#include "Data/PlayerData/PlayerData.h"
#include "Battles/HypnosBattle/DHBattle.h"
using namespace std;

    void PrintWithPause_Sky(const string& Text, int Pause);
    void LongPause_Sky(int MiliSeconds);
    void Sky(Player& p, DHypnos& h);

#endif