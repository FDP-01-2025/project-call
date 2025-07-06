#ifndef KINGMAGNUSBATTLE_H
#define KINGMAGNUSBATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/KingMagnus/KingMagnus.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

void KingMagnusBattle(Player& p, KingMagnus& Km);
void DefaultError();
void Items(Player& p, int option_item);
void HpBar(Player& p);
void ManaBar(Player& p);

#endif
