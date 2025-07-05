#ifndef NIHILUSBATTLE_H
#define NIHILUSBATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/NihilusData/Nihilus.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

void NihilusBattle(Player& p, Nihilus& Nihi);
void DefaultError();
void Items(Player& p, int option_item);
void HpBar(Player& p);
void ManaBar(Player& p);

#endif
