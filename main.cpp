#include <iostream>
#include <windows.h>
#include <time.h>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Dialogues/Tutorial/LibraryTutorial.h"
#include "src/Dialogues/Forest/LibraryForest.h"
#include "src/Dialogues/DeepCave/LibraryCave.h"
#include "src/Dialogues/AtenasCity/LibraryAtenas.h"
#include "src/Data/PlayerData/PlayerData.h"
#include "src/Data/NaikaData/Naika.h"
#include "src/Battles/NaikaDummy/NaBattle.h"
#include "src/Data/EliteSData/EliteSlime.h"
#include "src/Battles/SlimeBattle/Sbattle.h"
#include "src/Data/TrollData/Troll.h"
#include "src/Battles/TrollBattle/TrollFight.h"
#include "src/Data/GolemData/Golem.h"
#include "src/Battles/GolemBattle/GolemFight.h"
#include "src/Data/NihilusData/Nihilus.h"
#include "src/Battles/NihilusBattle/NihilusFight.h"

using namespace std;

int main(){

    SetConsoleOutputCP(CP_UTF8); // util para que en la terminar se usen caracteres especiales como ñ, tildes, etc...
    srand(time(NULL)); // generador de semilla RNG
    Clear();

    cout << "Bienvenido a Ashes of Olympus" << endl;
    Player p = Global_Data(); // funcion para declarar el parametro de Player
    ShowStats(p);             // funcion para mostrar las estadisticas

    cout << "Tienes un momento para ver tus estadisticas iniciales";
    Naika Na = Naika_Data(); // funciones para declarar parametros de Naika y enemigos
    NaikaDummy Ndum = Dummy_Data();
    EliteS S = EliteS_Data();
    Troll Tr = Troll_Data();
    Golem Gol = Golem_Data();
    Nihilus Nihi = Nihilus_Data();

    cout << endl;
    cout << "\033[3;4mLoading to continue your adventure...\033[0m" << endl;
    Sleep(6000);

Clear();
    // Prologue();
    // Training(p);
    // Tutorial(p, Na, Ndum);
    //Forest(p, S, Tr); // Capitulo 1 - Bosque
    // CaveDialogue(p, Gol);
    AtenasCity(p, Nihi);

    // EliteSBattle(p, S);
    // GolemBattle(p, Gol);
    // NihilusBattle(p, Nihi);

    return 0;
}