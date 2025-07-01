#ifndef BATTLE_UTILS_H
#define BATTLE_UTILS_H
#include "Data/PlayerData/PlayerData.h"

void Clear();
void SleepMS(int milliseconds);
void DefaultError();
void Items(Player& p, int option_item);
void HpBar(Player& p);
void ManaBar(Player& p);

#endif