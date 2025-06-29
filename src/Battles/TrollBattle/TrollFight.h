#ifndef TROLFIGHT_H
#define TROLLFIGHT_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/TrollData/Troll.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

    void TrollBattle(Player& p, Troll& Tr);
    void DefaultError();
    void Items(Player& p, int option_item);
    void HpBar(Player& p);
    void ManaBar(Player& p);

#endif