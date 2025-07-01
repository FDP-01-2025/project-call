#ifndef ESBATTLE_H
#define ESBATTLE_H
#include "Data/PlayerData/PlayerData.h"
#include "Data/EliteSData/EliteSlime.h"
using namespace std;

    void PlayerAttackSlime(Player& p, EliteS& S);
    void SlimeAttackPlayer(Player& p, EliteS& S);
    void SlimeAttack(Player &p, EliteS &S);
    void EliteSBattle(Player &p, EliteS &S);

#endif