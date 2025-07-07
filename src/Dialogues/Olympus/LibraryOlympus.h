#ifndef LIBRARYOLYMPUS_H
#define LIBRARYOLYMPUS_H
#include <string>
#include "Data/PlayerData/PlayerData.h"
#include "Battles/KMBattle/KMBattle.h"
using namespace std;

void PrintWithPause_Oly(const string& Text, int Pause);
void LongPause_Oly(int MiliSeconds);
void MountOlympus(Player& p, KingMagnus& Km);

#endif