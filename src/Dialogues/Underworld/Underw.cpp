#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
using namespace std;

void PrintWithPause_UW(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(0); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_UW(int MiliSeconds){
    Sleep(0); // 1000 para pausa larga.  // "MiliSeconds" to normal
}
void Underworld(){
    string UnderW[] = {
        "\033[3mTú y naika atraviesan cada rincón del inframundo.\033[0m", // 0
        "\033[3mVencen a cada bestia... atraviesan el río estigia.\033[0m", // 1
        "\033[3mAgradecen de que Cerbero este en la veterinaria.\033[0m", // 2
        "\033[3mPero se dirigen al palacio de los 3 jueces del inframundo\033[0m", // 3
        "\033[3mTardan pero finalmente llegan.\033[0m", // 4
        "\033[31Naika: \033[0mBien chico, llegamos a un punto sin retorno.", // 5
        "\033[31Naika: \033[0mNo ensangrente mi espada de puro gusto. A darle!", // 6
        "\033[3mPasan por los pasillos del palacio.\033[0m", // 7
        "\033[3mLlegan a una sala con 3 tronos.\033[0m", // 8
        "\033[31Naika: \033[0mSon ellos... ", // 9
        "\033[31Naika: \033[0mRadamantis: sabio, severo, muy justo. Gobernaba el Elíseo.", // 10
        "\033[31Naika: \033[0mMinos: el juez supremo, imparcial, aunque un poco frío.", // 11
        "\033[31Naika: \033[0mÉaco: riguroso, disciplinado, con una fuerte devoción por las normas.", // 12
        "\033[35mÉaco: \033[0mHmm…  almas vivas... ¿Qué demonios hacen mortales en el inframundo?", // 13
        "\033[35mRadamantis: \033[0mPuedo sentirlo… su almas laten. Esto no es una muerte… es una intromisión.", // 14
        "\033[35mÉaco: \033[0mPodemos saber que hacen aquí?", // 15
        "\033[3mLes explicas que quieren ir a los campos Éliseos.\033[0m", // 16
        "\033[35mMinos: \033[0mNo es cualquier intromisión… Ellos buscan los Campos Elíseos.", // 17
        "\033[35mÉaco: \033[0m¿Los Elíseos? ¿Acaso se creen héroes? ¿Vienen a vacacionar con los justos??", // 18
        "\033[35mRadamantis: \033[0mPara entrar a los Campos Éliseos, deben haber vivido con virtud, compasión y honor.", // 19
        "\033[35mRadamantis: \033[0mDime, ¿cuántas veces se han manchado las manos?", // 20
        "\033[35mMinos: \033[0m¿Qué buscan allí, mortales?", // 21
        "\033[3mLes explicas que van a detener a Hades\033[0m", // 22
        "\033[35mÉaco: \033[0mHades... ¿¡Detener al señor de este reino!?", // 23
        "\033[35mÉaco: \033[0m¿¡Tú!? Esta es la mejor broma en siglos.", // 24
        "\033[35mRadamantis: \033[0m¿No prefieres unirme al festín de las almas condenadas primero? Más acorde a tu audacia.", // 25
        "\033[35mMinos: \033[0m¿O tienes algún permiso?", // 26
        "\033[3mLes explicas que tiene el permiso de Hypnos, hermano de Thanatos\033[0m", // 27
        "\033[3mLos tres jueces quedan callados... Saben que no mientes.\033[0m", // 28
        "\033[35mÉaco: \033[0m¿Hypnos? Ese insensato que juega con el equilibrio del sueño y la muerte...", // 29
        "\033[35mRadamantis: \033[0mSiempre metiéndose donde no debe... si él te dio su bendición, no podemos negarlo.", // 30
        "\033[35mMinos: \033[0mEl camino no te será fácil. No eres digno por tu historia...", // 31
        "\033[35mMinos: \033[0mPero si los dioses aún te observan, adelante.", // 32
        "\033[35mÉaco: \033[0mEntra. Pero recuerda:", // 33
        "\033[35mÉaco: \033[0mSi caes, no habrá segunda oportunidad.", // 34
        "\033[35mRadamantis: \033[0mQue los Éliseos te juzguen con su propia luz.", // 35
        "\033[35mMinos: \033[0mY que la sombra de Hades no te consuma antes de llegar.", // 36
        "\033[3mSe abre un portal dorado y os dejan pasar\033[0m", // 37
        "Andando chico, no tenemos tiempo que perder", // 38
        "Cruza... y observan un hermoso Jardín...", // 39
        "Es... hermoso... peor debemos ir rapido al templo de Hades.", // 40
        "Caminan y...", // 41
        "Se topan con lo que parece ser Thanatos...", // 42
        "Esta dormido... así que pasan de él...", // 43
        "Llegan al templo de Hades.", // 44
        "Bien... preparados...", // 45
        "Derriban la puerta.", // 46
        "Que vacio...", // 47
        "Entran...", // 48
        "Sienten una presión enorme dentro...", // 49
        "", // 50
        "", // 51
        "", // 52
        "", // 53
        "", // 54
        "", // 55
        "", // 56
        "", // 57
        "", // 58
        "", // 59
        "", // 61
        "", // 62
        "", // 63
        "", // 64
        "", // 65
        "", // 66
        "", // 67
        "", // 68
        "", // 69
        "", // 70
    };
}