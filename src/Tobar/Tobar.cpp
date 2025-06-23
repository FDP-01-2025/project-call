#include <iostream>
#include "Tobar.h"
using namespace std;

struct Tobar Data(){
    struct Tobar t;
    t.TobName = "Tobar";
    t.altura = 1.82;
    t.edad = 16;
    t.poder = 9000;

    return t;
}

void MostrarT (Tobar t){
    cout << "Este es mi nombre: " << t.TobName << endl;
    cout << "Mi altura: " << t.altura << endl;
    cout << "Mi edad: " << t.edad << endl;
    cout << "MI NIVEL DE PODER: " << t.poder << endl;
}