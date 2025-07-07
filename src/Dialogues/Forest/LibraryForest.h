#ifndef LIBRARYFOREST_H
#define LIBRARYFOREST_H
#include <string>
#include "Data/EliteSData/EliteSlime.h"
#include "Battles/SlimeBattle/Sbattle.h"
#include "Data/TrollData/Troll.h"
#include "Battles/TrollBattle/TrollFight.h"
using namespace std;

void PrintWithPause_F(const string& Text, int Pause);
void LongPause_F(int MiliSeconds);
void Forest(Player& p, EliteS& , Troll& Tr);

#endif 