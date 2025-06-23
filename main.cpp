#include <iostream>
#include <windows.h>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Battles/Tutorial/LibraryTutorial.h"
#include "src/Data/PlayerData/PlayerData.h"
#include "src/Data/NaikaData/Naika.h"

using namespace std;

int main(){
    int x;
    system("cls");

    cout << "Bienvenido a Ashes of Olympus" << endl;
    Player p = Global_Data(); // funcion para elegir la dificultad
    ShowStats(p);             // funcion para mostrar las estadisticas
    cout << "Tienes un momento para ver tus estadisticas iniciales";
    Naika Na = Naika_Data();

    cout << endl;
    cout << "\033[3;4mLoading to continue your adventure...\033[0m" << endl;
    Sleep(5000);

system("cls");
    Prologue();
    Training(p);
    Tutorial(p, Na);

    return 0;
}