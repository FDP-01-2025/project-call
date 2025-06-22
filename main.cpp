#include <iostream>
#include <windows.h>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Battles/Tutorial/LibraryTutorial.h"
#include "src/Data/PlayerData/PlayerData.h"

using namespace std;

int main(){
    int x;
    system("cls");

    cout << "Bienvenido a Ashes of Olympus" << endl;
    Player p = Global_Data(); // funcion para elegir la dificultad
    ShowStats(p); // funcion para mostrar las estadisticas

    cout << endl;
    system("cls");
    cout << "\033[3;4mLoading to continue your adventure...\033[0m" << endl;
    cout << p.HP << endl;
    cout << "Recibiste 10 de dano" << endl;
    p.HP -= 10;
    cout << p.HP << endl;
    Sleep(2500);

    // Prologue();
    // Training(p.PlayerName);
    Tutorial();

    return 0;
}