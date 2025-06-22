#include <iostream>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Battles/Tutorial/LibraryTutorial.h"

using namespace std;

struct Player {
    string PlayerName;
};

int main(){

    string PlayerName;

    /*
system("cls");
    cout << "Bienvenido a Ashes of Olympus" << endl;
    cout << "Ingrese el nombre de su jugador: " << endl;
    cin >> PlayerName;
    */

    // Prologue();
    // Training(PlayerName);
    Tutorial();
    return 0;
}