#ifndef LIBRARYUNDERW_H
#define LIBRARYUNDERW_H
#include <string>
#include "Data/PlayerData/PlayerData.h"
#include "Battles/HadesBattle/HadesFight.h"
using namespace std;

    void PrintWithPause_UW(const string& Text, int Pause);
    void LongPause_UW(int MiliSeconds);
    void Underworld(Player& p, DHades& inf);

#endif