#include <iostream>
#include <windows.h>
#include <time.h>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Dialogues/Tutorial/LibraryTutorial.h"
#include "src/Data/PlayerData/PlayerData.h"
#include "src/Data/NaikaData/Naika.h"
#include "src/Battles/NaikaDummy/NaBattle.h"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8); // util para que en la terminar se usen caracteres especiales como ñ, tildes, etc...
    srand(time(NULL)); // generador de semilla RNG
    int x;
    system("cls");

    cout << "Bienvenido a Ashes of Olympus" << endl;
    Player p = Global_Data(); // funcion para declarar el parametro
    ShowStats(p);             // funcion para mostrar las estadisticas
    cout << "Tienes un momento para ver tus estadisticas iniciales";
    Naika Na = Naika_Data();
    NaikaDummy Ndum = Dummy_Data();

    cout << endl;
    cout << "\033[3;4mLoading to continue your adventure...\033[0m" << endl;
    Sleep(6000);

system("cls");
    // Prologue();
    // Training(p);
    Tutorial(p, Na, Ndum); // no es necesario Num porque es una variable local, se llamara la funcion de batalla, nacera y morira en Tutorial.cpp

    return 0;
}