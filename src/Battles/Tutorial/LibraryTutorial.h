#ifndef LIBRARYTUTORIAL_H
#define LIBRARYTUTORIAL_H
#include <string>
#include "Data/PlayerData/PlayerData.h"
#include "Data/NaikaData/Naika.h"
using namespace std;

void PrintWithPause_Tu(const string& Text, int Pause);
void LongPause_Tu(int MiliSeconds);
void Tutorial(Player p, Naika Na);

#endif