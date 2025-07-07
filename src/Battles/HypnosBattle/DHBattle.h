#ifndef DHBATTLE_H
#define DHBATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/HypnosData/Hypnos.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

    void DHBattle(Player& p, DHypnos& h);
    void DefaultError();
    void Items(Player& p, int option_item);
    void HpBar(Player& p);
    void ManaBar(Player& p);

#endif