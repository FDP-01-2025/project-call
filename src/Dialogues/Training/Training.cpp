#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Data/PlayerData/PlayerData.h"
#include <BattleUtils.h>
#include "LibraryTraining.h"
using namespace std; 
void PrintWithPause_T(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(Pause); // 0 para lectura rapida.  // "Pause" to normal
    }
}
void LongPause_T(int MiliSeconds){
    Sleep(MiliSeconds); // 0 para lectura rapida.  // "MiliSeconds" to normal
}
void Training(Player& p){
    string x;
    string General[] = {
        "\033[1m-- 7 ANOS DESPUES --\033[0m", // 0
        "Bien muchachos, estais aqui presentes porque ya teneis edad para comenzar el entrenamiento militar.", // 2
        "Algunos han estado aqui en nuestras filas desde muy ninos, y eso los ha vuelto fuertes de corazon y mente.", //3
        "Y ahora los formaremos para ser leales y poderosos soldados que sirvan a nuestra nacion.", //4
        "Y tu ", //5 
        "Has pasado por mucho.", //6
        "Te encontramos luego del asedio que se realizo en esa misma manana por parte de los que se rebelaron en contra de nuestra Reina.", //7 
        "Te encontramos inconciente en ese momento.", //8
        "fue un \033[31mmilagro de los dioses\033[0m que hayas sobrevivido.", //9
        "Pero lo has conseguido, luchaste y ahora no dentro de mucho seras parte de las filas del ejercito de tu nacion.", //10
        "Daras tus frutos luego de tanto sufrimiento.", //11
        "Igual espero lo mismo de ustedes muchachos.", //12
        "Sin mas preambulos, comenzamos su entrenamiento pronto.", //13
        "Pero un anuncio antes.", //14
        "Les quiero presentar a su oficial \033[31mNaika\033[0m.", //15
        "Ella sera quien supervise su entrenamiento, ahora ya no los interrumpo.", //16
        "Buena suerte, y que Zeus os bendiga. ", //17
        "Bien Naika, te cedo la palabra.", //18
        "Mucho gusto soldados, he oido que tienen un fuerte potencial para el ejercito de nuestra reina.", //19
        "Tienen suerte de que los rebeldes se hayan rendido no hace mucho.", //20
        "Porque les hubiese dado un entrenamiento \033[31mINTENSIVO\033[0m.", //21
        "Ejem*, perdon perdi la compostura.", //22
        "Bien, menos charla mas accion, vayan al campo ya! ya! ya!.", //23
        ".....", //24
    };

    string G = "General: ";
    string Na = "Naika: ";
    string Green = "\033[32m";
    string Red = "\033[31m";

    string colors[] = {
    "", Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green, Green,
    Red, Red, Red, Red, Red, ""
    };

    string prefixes[] = {
    "", G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, Na,  
    Na, Na, Na, Na, ""
    };

    for (int i = 0; i < 24; i++) {
    if (i == 4) {
        cout << colors[i] << prefixes[i] << "\033[0m";
        PrintWithPause_T(General[i], 30); 
        cout << "\033[34m" << p.PlayerName << "\033[0m";
        SleepMS(1000); 
        cout << endl;
        PtC();
        Clear();
    }
    else if (i == 23) {
        PrintWithPause_T(General[i], 500);
        SleepMS(1000); 
        cout << endl;
        PtC();
        Clear();
    }
    else {
        cout << colors[i] << prefixes[i] << "\033[0m";
        PrintWithPause_T(General[i], 30);
        SleepMS(1000); 
        cout << endl;
<<<<<<< HEAD
        PtC();
        Clear();
    }
=======
        cin >> x;
        system("cls");
        }
>>>>>>> 1d5a6d9 (Update 2.3 Finish Tutorial Dialogues)
    }
}