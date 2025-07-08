#ifndef BATTLE_UTILS_H
#define BATTLE_UTILS_H
#include "Data/PlayerData/PlayerData.h"

void ShowAshesOfOlympus(); // muestra el titulo del juego
void ShowGameOver(); // muestra el game over
void PtC(); // Press to continue
void Clear(); // Clear the console
void SleepMS(int milliseconds); // Sleep for a specified number of milliseconds
void DefaultError(); // Display a default error message in switch cases
void Items(Player& p, int option_item); // Manage player items in battle
void HpBar(Player& p); // Display the player's HP bar
void ManaBar(Player& p); // Display the player's mana bar

#endif