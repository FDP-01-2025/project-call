#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
#include "Battles/HadesBattle/HadesFight.h"
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
void Underworld(Player& p, DHades& inf){
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
        "Cruzan... y observan un hermoso Jardín...", // 39
        "Es... hermoso... pero debemos ir rapido al templo de Hades.", // 40
        "Caminan y...", // 41
        "Se topan con lo que parece ser Thanatos...", // 42
        "Esta dormido... así que pasan de él...", // 43
        "Llegan al templo de Hades.", // 44
        "Se preparan y que sea lo que Zeus quiera.", // 45
        "Derriban la puerta.", // 46
        "Notan que esta muy vacío... pero hay una vasija al fondo.", // 47
        "Entran...", // 48
        "Sienten una presión enorme dentro...", // 49
        "Esto no me gusta chic...", // 50
        "Cuando de repente una enorme explosión de energia los saca del tempo!", // 51
        "MIERDA!", // 52
        "Se lograron cubrir por los pelos... estan afuera del templo", // 53
        "El cielo se pone oscuro... la hierba se seca... Él... ha despertado.", // 54
        "Ven a una figura majestuosa salir del templo poco a poco.", // 55
        "...Interesante.", // 56
        "Desde que inicie mi guerra contra la humanidad era yo quien iba tras ustedes...", // 57
        "Y ahora... han decidido en venir aqui a plantarme cara en mi propio hogar?", // 58
        "Esplendido.", // 59
        "Ademas de interrumpir mi sueño...", // 61
        "Tú... vienes a plantarme batalla cara a cara.", // 62
        "pero que agallas. Debo reconocer que te admiro por ser tan valiente. O muy estupido...", // 63
        "...", // 64
        "Bien, las veces que me he confiado termine donde estoy.", // 65
        "Terminare este ciclo sin fin... Gran huamno, el destino nos enlazo por tercera vez para nuestra revancha.", // 66
        "Y que chica tan linda trajiste por cierto.", // 67
        "!!!", // 68
        "Naika es incapaz de hacer algo... la mera presencia de Hades la hizo caer al piso", // 69
        "C-c..chico... no te preocupes por mi... tu... tu puedes... no llegaste hasta aqui para rendirte... hazlo... por... mí...", // 70
        "Naika cae inconciente", // 71
        "Bien... ", // 72
        "Hades saca su Guadaña", // 73
        "Que el destino de la humanidad se decida aquí y ahora.", // 74

        //FINAL BATTLE
        "Una fulminante luz envuelve a Hades", // 75
        "NOOOO", // 76
        "Como es posible que este gusano vuelva a sellarme.", // 77
        "NOOO", // 78
        "NO LO PERMI...TIREEE", // 79
        "Sellas a Hade sun su teplo por otros 500 años...", // 80
        "Él caos... ha terminado.", // 81
        "Agarras en brazos a Naika y regresas al mundo terrenal... ya no como un chico... ya eres un hombre.", // 82
        "Y evitaste que la humanidad observe una vez más el terror de Hades.", // 83
        "Y diste fin a su reinado del terror.", // 84
        "Los humanos veran nuevamente el amanecer de un nuevo día. La flora crecera nuevamente.", // 85
        "Bendito sea este mundo maravilloso.", // 86
        "FIN", // 87
    };

    string Pla = "\033[3m";
    string Nai = "\033[31Naika: \033[0m";
    string Hds = "\033[30Hades: \033[0m";

    for (int i = 0; i < 88; i++){
        if (i == 39 || i >= 41 && i <= 49 || i == 51 || i >= 53 && i <= 55 || i == 69 || i == 71 || i == 73 || i == 75 || i >= 80 && i <= 87){
            cout << Pla;
        } else {
            cout << (i >= 56 && i <= 59 || i >= 61 && i <= 66 || i == 72 || i == 74 || i >= 76 && i <= 79 ? Hds:Nai);
        }
            PrintWithPause_UW(UnderW[i], 20);
            LongPause_UW(1000);
            cout << endl;
            PtC();
        Clear();
        if(i == 74) HadesBattle(p, inf); 
    }
}