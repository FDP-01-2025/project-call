#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Data/PlayerData/PlayerData.h"
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
        "\033[1m-- 7 AÑOS DESPUES --\033[0m", // 0
        "Bien muchachos, estàis aquì presentes porque ya tenéis edad para comenzar el entrenamiento militar.", // 2
        "Algunos han estado aquí en nuestras filas desde muy niños, y eso los ha vuelto fuertes de corazón y mente.", //3
        "Y ahora los formaremos para ser leales y poderosos soldados que sirvan a nuestra nación.", //4
        "Y tú ", //5
        "Has pasado por mucho.", //6
        "Te encontramos luego del asedio que se realizo en esa misma mañana por parte de los que se rebelaron en contra de nuestra Reina.", //7
        "Te encontramos inconsciente en ese momento.", //8
        "fue un \033[31mmilagro de los dioses\033[0m que hayas sobrevivido.", //9
        "Pero lo has conseguido, luchaste y ahora no dentro de mucho seràs parte de las filas del ejèrcito de tu naciòn.", //10
        "Daràs tus frutos luego de tanto sufrimiento.", //11
        "Igual espero lo mismo de ustedes muchachos.", //12
        "Sin más preámbulos, comenzamos su entrenamiento pronto.", //13
        "Pero un anuncio antes.", //14
        "Les quiero presentar a su oficial \033[31mNaika\033[0m.", //15
        "Ella será quien supervise su entrenamiento, ahora ya no los interrumpo.", //16
        "Buena suerte, y que Zeus os bendiga. ", //17
        "Bien Naika, te cedo la palabra.", //18
        "Mucho gusto soldados, he oído que tienen un fuerte potencial para el ejército de nuestra reina.", //19
        "Tienen suerte de que los rebeldes se hayan rendido no hace mucho.", //20
        "Porque les hubiese dado un entrenamiento \033[31mINTENSIVO\033[0m.", //21
        "Ejem*, perdón perdí la compostura.", //22
        "Bien, menos charla más acción, vayan al campo ya! ya! ya!.", //23
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
        LongPause_T(1000); 
        cout << endl;
        cin >> x;
        system("cls");
    }
    else if (i == 23) {
        PrintWithPause_T(General[i], 500);
        LongPause_T(1000); 
        cout << endl;
        cin >> x;
        system("cls");
    }
    else {
        cout << colors[i] << prefixes[i] << "\033[0m";
        PrintWithPause_T(General[i], 30);
        LongPause_T(1000); 
        cout << endl;
        cin >> x;
        system("cls");
    }
    }
}