#include <iostream>
using namespace std;

int main() {
    // Definir códigos de color ANSI
    const string RED = "\033[31m";
    const string RESET = "\033[0m";

    cout << "Hola mundo, soy " << RED << "Alex" << RESET << ", un gusto" << endl << endl;

    cout << "Siempre usar /033m[0m (digitos del color y final m)" << endl << endl;

    cout << "Colores basicos de texto (foreground)" << endl;

    cout << "\033[30mNegro [30m]\033[0m" << endl;
    cout << "\033[31mRojo [31m]\033[0m" << endl;
    cout << "\033[32mVerde [32m]\033[0m" << endl;
    cout << "\033[33mAmarillo [33m]\033[0m" << endl;
    cout << "\033[34mAzul [34m]\033[0m" << endl;
    cout << "\033[35mMagenta [35m]\033[0m" << endl;
    cout << "\033[36mCian [36m]\033[0m" << endl;
    cout << "\033[37mBlanco [37m]\033[0m" << endl << endl;

    cout << "Colores brillantes (high-intensity)" << endl;

    cout << "\033[90mGris oscuro [90m]\033[0m" << endl;
    cout << "\033[91mRojo brillante [91m]\033[0m" << endl;
    cout << "\033[92mVerde brillante [92m]\033[0m" << endl;
    cout << "\033[93mAmarillo brillante [93m]\033[0m" << endl;
    cout << "\033[94mAzul brillante [94m]\033[0m" << endl;
    cout << "\033[95mMagenta brillante [95m]\033[0m" << endl;
    cout << "\033[96mCian brillante [96m]\033[0m" << endl;
    cout << "\033[97mBlanco brillante [97m]\033[0m" << endl << endl;

    cout << "Colores de fondo (background)" << endl;

    cout << "\033[40mFondo negro [40m]\033[0m" << endl;
    cout << "\033[41mFondo rojo [41m]\033[0m" << endl;
    cout << "\033[42mFondo verde [42m]\033[0m" << endl;
    cout << "\033[43mFondo amarillo [43m]\033[0m" << endl;
    cout << "\033[44mFondo azul [44m]\033[0m" << endl;
    cout << "\033[45mFondo magenta [45m]\033[0m" << endl;
    cout << "\033[46mFondo cian [46m]\033[0m" << endl;
    cout << "\033[47mFondo blanco [47m]\033[0m" << endl <<endl;

    cout << "Estilos de texto adicionales" << endl;
    cout << "\033[1mNegrita [1m]\033[0m" << endl;
    cout << "\033[2mTenue [2m]\033[0m" << endl;
    cout << "\033[3mCursiva [3m]\033[0m" << endl;
    cout << "\033[4mSubrayado [4m]\033[0m" << endl;
    cout << "\033[5mParpadeo lento [5m]... (no parece funcionar)\033[0m" << endl;
    cout << "\033[7mInvertir colores [7m]\033[0m" << endl;
    cout << "\033[8mOculto (no visible) [8m]\033[0m" << endl; // no visible en la terminal
    cout << "\033[9mTachado [9m]\033[0m" << endl << endl;

    //forma de combiar
    cout << "Para combinarlos" << endl;
    cout << "\033[31mRojo normal\033[0m" << endl;
    cout << "\033[91mRojo brillante\033[0m" << endl;
    cout << "\033[1;34mAzul negrita\033[0m" << endl;
    cout << "\033[4;32mVerde subrayado\033[0m" << endl;
    cout << "\033[1;93;41mAmarillo brillante, negrita, fondo rojo\033[0m" << endl << endl;
    return 0;
}