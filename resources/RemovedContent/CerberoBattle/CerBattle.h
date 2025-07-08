#ifndef CERBEROFIGHT_H
#define CERBEROFIGHT_H
#include "Data/PlayerData/PlayerData.h"
#include "Cerberus.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

void CerberoBattle(Player& p, Cerbero& Cb);
void DefaultError();
void Items(Player& p, int option_item);
void HpBar(Player& p);
void ManaBar(Player& p);

#endif
