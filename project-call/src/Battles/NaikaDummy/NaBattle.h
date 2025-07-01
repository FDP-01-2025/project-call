#ifndef NABATTLE_H
#define NABATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/NaikaDummy/NaikaDummy.h"
#include "BattleUtils/BattleUtils.h"

using namespace std;

    void NaikaDummyBattle(Player& p, NaikaDummy& Ndum);
    void DefaultError();
    void Items(Player& p, int option_item);
    void HpBar(Player& p);
    void ManaBar(Player& p);

#endif