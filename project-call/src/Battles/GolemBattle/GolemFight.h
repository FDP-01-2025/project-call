#ifndef GOLEMFIGHT_H
#define GOLEMFIGHT_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/GolemData/Golem.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

void GolemBattle(Player& p, Golem& Gol);
void DefaultError();
void Items(Player& p, int option_item);
void HpBar(Player& p);
void ManaBar(Player& p);

#endif
