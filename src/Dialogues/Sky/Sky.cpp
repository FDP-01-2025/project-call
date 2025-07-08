#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
#include "Battles/HypnosBattle/DHBattle.h"
using namespace std;

void PrintWithPause_Sky(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(0); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_Sky(int MiliSeconds){
    Sleep(0); // 1000 para pausa larga.  // "MiliSeconds" to normal
}
void Sky(Player& p, DHypnos& h){
    string SkyKingdom[] = {
        "Caminan lo más rapido posible y logran pasar todos sin problemas.", // 0
        "Agradeceme chico, que conmigo tenemos pleno derecho de entrar al Palacio Blanco.", // 1
        "Los guardias les palacio los detienen, pero Naika saca sus encantos y logra convencer a los guarias.", // 2
        "Mentira los amenazo con una corte marcial...", // 3
        "Bien chico. Ya hice mi parte. Como eres el gran humano deberías saber con que conexiones tienes... anda busca.", // 4
        "Cierran las puertas", // 5
        "Se ponen a investigar cada sección del palacio.", // 6
        "Pasan las horas y solo sientes un leve aura.", // 7
        "Ok ya me aburri de buscar...", // 8
        "Joder como haremos.", // 9
        "El estres... Hades podria llegar muy prnto y no podriamos hacer nada!", // 10
        "Rompe una pared", // 11
        "Atras de ellos se escondia un pasillo.", // 12
        "Huh... Supongo que en la remodelación tambien sellaron esto.", // 13
        "Sientes una enorme aura adentro y se lo dices.", // 14
        "Perfecto, pues que esperamos.", // 15
        "La detienes...", // 16
        "Sucede algo?", // 17
        "Le comentas que no solo hay un aura fuerte... hay alguien más dentro...", // 18
        "Ok.", // 19
        "Se ponen en guaria y atraviesan el pasillo.", // 20
        "Hay una enorme habitación redonda... pero en el centro.", // 21
        "Oye... hay alguien en el centro mirando al techo...", // 22
        "Oye, quien eres! como llegaste aqui!", // 23
        "Le mencionas que se calle.", // 24
        "Él ser los noto... y despliega... alas?!?", // 25
        "Oye chico... porque le salieron alas? acaso es un... ángel?", // 26
        "Con una enorme velocidad encima de ustedes volando!", // 27
        "Oh WHAT THE", // 28
        "Naika intenta golpearlo pero el ser esquiva sin mucna dificultad.", // 29
        "Así que llegaron.", // 30
        "Como que llegamos? sabiaís que vendriamos?", // 31
        "Si", // 32
        "Lamento mucho haberlos asustado, estamos del mismo bando, pero dejen me presento.", // 33
        "Mi nombre es Hermes.", // 34
        "Yo soy el mensajero personal de los dioses en un momento.", // 35
        "Osea... despues de milenios finalmente aparecen?", // 36
        "Correcto, hemos estado presentes siempre pero no fisicamente... a exceptión de ahora...", // 37
        "Y... ya que eres un mensajero... Nos vienes a traer un mensaje?", // 38
        "No exactamente.", // 39
        "Desde los cielos vimos la ruptura del sellos de Magnus y me enviaron a revisar. Me mencionaron que dos humanos de corazón fuerte llegarían.", // 40
        "Y baje no hace mucho. Que hacen ustedes aquí.", // 41
        "Le explican todo... él se toman el tiempo de esuchar", // 42
        "Entiendo... Hades despetara... no creí que fuesen donde Magnus directamente y les contara de esta entrada.", // 43
        "Tienen suerte de que baje.", // 44
        "Porque es necesario que un ser de los cielos les de acceso a él.", // 45
        "Parece que la historia esta de nuestro lado chico.", // 46
        "Bueno vamos. No hay que perder el tiempo. Pero antes les tengo que decir algo.", // 47
        "Si necesitan la aprovación de un dios para ir al inframundo necesitan ir donde mi señor Hypnos.", // 48
        "Él entendera.", // 49
        "Bueno, que esperamos.", // 50
        "Marchando.", // 51
        "Se ponen en él centro de la habitación y solo ven una luz cegadora rodearles.", // 52
        "Al abrir los ojos no se lo creen...", // 53
        "Ay... enserio estoy soñando??", // 54
        "Que alguien me peñiste.", // 55
        "Hermes lo hace.", // 56
        "AY! Hablo metaforicamente.", // 57
        "Lo siento, bueno, bienvenidos al reino de Zeus.", // 58
        "Solo observan una enorme montaña entre las nubes... el lugar es hermoso", // 59
        "Bueno, dejene llevarles donde mi señor.", // 60
        "Los llevan volando y se dirigen a uno de los templos celestiales.", // 61
        "Bueno chico... almenos si morimos contra Hades ya lo habremos visto todo.", // 62
        "No tardan en llegar y estan en las puertas del Templo.", // 63
        "Hemos llegado, muchachos, mucho ojo, estaran en presencia de un dios... traten de ser lo más formales y neutrales posibles.", // 64
        "Entran y al fondo ven en un trono a una enorme figura majestuosa...", // 65
        "Caminan con cautela entre los pasillos.", // 66
        "Descuiden no los mordera.", // 67
        "Llegan finalmente", // 68
        "Mi señor... como ha estado su dia.", // 69

    //HYPNOS
        "Hermes puedes retirarte, se perfectamente las intenciones nuestros invitados.", // 70
        "Como gusto mi señor. Buena suerte, un gusto haberlos conocido.", // 71
        "Se larga", // 72
        "Estan muy tensos.", // 73
        "Bueno, dejenme me presento, soy Hypnos. Dios de los sueños.", // 74
        "Así que quieren llegar a Hades para frenarlo no es así.", // 75
        "Si señor.", // 76
        "Bien, puedo llevarlos directamente a los dominios de Hades.", // 77
        "Muchas g...", // 78
        "Pero. Antes pruebenme que son capaces de hacerle frente a tal calamidad.", // 79
        "Y como logramos eso.", // 80
        "Batallando conmigo.", // 81
        "!!!", // 82
        "No... no quiero ofenderlo pero... usted es un dios señor...", // 83
        "Y? si no pueden conmgigo como pretendes pelear con alguien más fuerte que yo?", // 84
        "Tiene un buen punto. Bien daremos nuestro mejor esfuerzo.", // 85
        "Que así sea.", // 86

        // batalla
        "Bien, ya me han demostrado sus capacidades. Tienen mi aprobación.", // 87
        "Muchas gracias sñeor.", // 88
        "Se que Hades anhela con todas sus fuerzas perturbar la paz de la tierra que se os otorgo.", // 89
        "Pero nosotros no podemos intervenir.", // 90
        "Dejare en sus manos una fracción de mi poder. Y detengan los planes de Hades.", // 91
        "Eso haremos...", // 92
        "Y tú humano, tienes una gran determinación.", // 93
        "Por si no lo sabías mi hermano Thanatos y yo notamos tu presencia cuando de niño en aquella la noche del asedio de Atenas. estabas en las últimas.", // 94
        "Espera estabas ahí tambien chico.??", // 95
        "Nos llamaste la atención... y ahora sabemos de tus capacidades.", // 96
        "Y me enorgullece saber que no tomaste un camino oscuro cuando tenias la capacidad.", // 97
        "Bueno salvadores. No pierdas más el tiempo, les dare mi bendición para cruzar el inframuendo y mi permiso para ir a los campos Éliseos.", // 98
        "Os deseo suerte.", // 99
        "De un chasquido pasaron del templo a un lugar oscuro y abisal... huele a muerto, azufre y sangre.", // 100
        "Hay que asco... y que rapido.", // 101
        "Con que este es el inframundo. Cuando dije que quise ir de aventuras contigo jamas pense en ver 2 lugares mitícos con mis propios ojos.", //102
        "Bien chico. No perdamos más él tiempo.", // 103
        "hey... nos mejoro nuestras armas. Bueno. Andando!", // 104
    };

    string Pla = "\033[3m";
    string Nai = "\033[31mNaika: \033[0m";
    string Her = "\033[34mHermes: \033[0m";
    string Hyp = "\033[33mHypnos: \033[0m";

    for (int i = 0; i < 70; i++){
        if (i == 0 || i == 2 || i == 3 || i >= 5 && i <= 7 || i == 11 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20
        || i == 21 || i == 24 || i == 25 || i == 27 || i == 29 || i == 42 || i == 52 || i == 53 || i == 56 || i == 59 || i == 61
        || i == 63 || i == 65 || i == 66 || i == 68 || i == 72 || i == 73){
            cout << Pla;
        } else {
            cout << (i == 30 || i >= 32 && i <= 34 || i == 35 || i == 37 || i == 39 || i == 40 || i == 41 || i >= 43 && i <= 45
                || i >= 47 && i <= 49 || i == 51 || i == 58 || i == 60 || i == 64 || i == 67 || i == 69 ? Her:Nai);
        }
        PrintWithPause_Sky(SkyKingdom[i], 20);
        LongPause_Sky(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
        if (i == 86) cout << endl;
    }

    for (int i = 70; i < 105; i++){
        if (i == 71){
            cout << Her;
        } else if (i == 72 || i == 73 || i == 100){
            cout << Pla;
        } else {
            cout << (i == 70 || i == 74 || i == 75 || i == 77 || i == 79 || i == 81 || i == 84 || i == 86 || i == 87
                || i == 89 || i == 90 || i == 91 || i == 93 || i == 94 || i >= 96 && i <= 99 ? Hyp:Nai);
        }
        PrintWithPause_Sky(SkyKingdom[i], 20);
        LongPause_Sky(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
        Clear();
        // if (i == 86) DHBattle(p, h);
    }
}