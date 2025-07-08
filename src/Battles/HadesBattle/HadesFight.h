#ifndef DHADESBATTLE_H
#define DHADESBATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/Hades_Data/Hades.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

    void HadesBattle(Player& p, DHades& inf);
    void DefaultError();
    void Items(Player& p, int option_item);
    void HpBar(Player& p);
    void ManaBar(Player& p);

#endif