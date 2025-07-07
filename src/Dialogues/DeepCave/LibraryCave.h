#ifndef LIBRARYCAVE_H
#define LIBRARYCAVE_H
#include <string>
#include "Data/PlayerData/PlayerData.h"
#include "Battles/GolemBattle/GolemFight.h"
using namespace std;

void PrintWithPause_Cv(const string& Text, int Pause);
void LongPause_Cv(int MiliSeconds);
void CaveDialogue(Player& p, Golem& Gol);

#endif