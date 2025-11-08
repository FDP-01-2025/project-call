#include <iostream>
#include <windows.h>
#include <time.h>
#include "src/Dialogues/Prologue/LibraryPrologue.h"
#include "src/Dialogues/Training/LibraryTraining.h"
#include "src/Dialogues/Tutorial/LibraryTutorial.h"
#include "src/Dialogues/Forest/LibraryForest.h"
#include "src/Dialogues/DeepCave/LibraryCave.h"
#include "src/Dialogues/AtenasCity/LibraryAtenas.h"
#include "src/Dialogues/Olympus/LibraryOlympus.h"
#include "src/Dialogues/Sky/LibrarySky.h"
#include "src/Dialogues/Underworld/LibraryUnderw.h"
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
#include "src/Data/HypnosData/Hypnos.h"
#include "src/Battles/HypnosBattle/DHBattle.h"
#include "src/Data/Hades_Data/Hades.h"
#include "src/Battles/HadesBattle/HadesFight.h"

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8); // util para que en la terminal se usen caracteres especiales como ñ, tildes, etc...
    srand(time(NULL)); // generador de semilla RNG

    int menu;
    Clear();
    ShowAshesOfOlympus();
    cout << endl;
    cout << "1.     NUEVA PARTIDA\n2.     CREDITOS\n3.     SALIR\n";
    cin >> menu;

    switch (menu){
    case 1: {
        Clear();

        Player p = Global_Data(); // funcion para declarar el parametro de Player
        Naika Na = Naika_Data(); // funciones para declarar parametros de Naika y enemigos
        NaikaDummy Ndum = Dummy_Data();
        EliteS S = EliteS_Data();
        Troll Tr = Troll_Data();
        Golem Gol = Golem_Data();
        Nihilus Nihi = Nihilus_Data();
        KingMagnus Km = KMagnus_Data();
        DHypnos h = DH_Data();
        DHades inf = Hades_Data();

        ShowStats(p);
        cout << "Tienes un momento para ver tus estadisticas iniciales" << endl;
        cout << "\033[3;4mLoading to continue your adventure...\033[0m" << endl;
        Sleep(6000);
        
        Prologue();
        Training(p);
        Tutorial(p, Na, Ndum);
        Forest(p, S, Tr);
        CaveDialogue(p, Gol);
        AtenasCity(p, Nihi);
        MountOlympus(p, Km);
        Sky(p, h);
        Underworld(p, inf);

    cout << "Tu final: " << endl;
    PtC();
        if (!p.BadRelationNaika){
            cout << "Al tener una buena relación con Naika y de que te admirara que te hayas vuelto más fuerte se convirtio en tu esposa. Con la paz ya establecida vivieron felices.";
        } else {
            cout << "Te llegas a reconciliar con Naika, y se vuelven excelentes compañeros de equipo.";
        }
        cout << endl;
        if (p.MONEY >= 200) cout << "Termianste tu aventura con una buena suma de dinero, ya puedes vivir feliz.";
        if (p.KILLS == 0){
            cout << "Y como tu camino fue pacifista... Hades no es capaz de tomar posesión de tu alma... y el mundo no vera por tercera vez a un genocida.";
        } else {
            cout << "Lastimosamente como has derramado sangr... sucumbiras progresivamente al control de Hades... y tarde o temprano terminaras como Magnus o Azael...";
        }
        break;
    }

    case 2:
        Clear();
        cout << "UNIVERSIDAD CENTROAMERICANA JOSÉ SIMEON CAÑAS(UCA)" << endl;
        cout << "Proyecto final de Fundamentos de programación." << endl << endl;
        cout << " --INTEGRANTES-- " << endl;
        cout << "- Ricardo Alexei Valle Avalos #00080525\n- Edgar Alejandro Ventura Zelaya #00210925\n- Carlos David Toledo García #00228725\n- Herberth Ariel Tobar Sermeño #00158525\nGracias a este equipo por ser parte de este proyecto!.\n";
        break;

    case 3:
        cout << "Saliendo...";
        return 0;

    default:
        DefaultError();
        break;
    }
    return 0;
}