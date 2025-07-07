#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
#include "Battles/KMBattle/KMBattle.h"
using namespace std;

void PrintWithPause_Oly(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(0); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_Oly(int MiliSeconds){
    Sleep(0); // 1000 para pausa larga.  // "MiliSeconds" to normal
}
void MountOlympus(Player& p, KingMagnus& Km){
    string Olympus[] = {
        "...", // 0
        "Luego de varíos días de viaje", // 1
        "Coño... no pense que este jodido monte fuese tan difícil de escalar...", // 2
        "Nose si me arrepenti de acompañarme... o de elogiarte por llevarme a ver estas vistas con tal adrenalina.", // 3
        "Bueno... no me has dicho por que la estamos escalando en primer lugar.", // 4
        "O si hay algún arma legendaria.", // 5
        "Sea lo que sea casi llegamos a la cima.", // 6
        "Tú sigue, descansare un rato.", // 7
        "La acompañas y toman un descanso", // 8
        "Despues de dos horas llegan a la cima.", // 9
        "Ufff... l-logramos... bien.. y que hay aqu....", // 10
        "De repente se dieron cuenta de una enorme puerta frente suyo.", // 11
        "Espera... este no es?...", // 12
        "Él sello del Gran Magnus?.", // 13
        "Para que vinimos a verlo?", // 14
        "Te acercas a la puerta", // 15
        "Oye chico nose si es peligroso. Imagine que solo vinimos a contemplarla.", // 16
        "Observas el sello... por alguna razón sientes que tienes una conexión con el sello...", // 17
        "Tengo un mal presentimiento...", // 18
        "Tocas la puerta.", // 19
        "Una gran cantidad de simbolos la rodean.", // 20
        "...", // 21
        "Ehhh... chico... creo que...", // 22
        "La puerta reaccióna a tu presencia.", // 23
        "La puerta se ilumima y desaparece.", // 24
        "!!!", // 25
        "Oye como?", // 26
        "Haz roto el sello?!?", // 27
        "Observas que hay a travez del sello.", // 28
        "Chico no deberías ser tan confi...", // 29
        "...", // 30
        "De repente una enorme arma intenta rebanarlos.", // 31
        "CHICO!", // 32
        "Naika logra bloquear el ataque apenas.", // 33
        "Te aleja del area por los pelos", // 34
        "Esto no esta bien esto no esta bien.", // 35
        "Sera posible...?", // 36
        "Que él... siga vivo?", // 37
        "Esuchan pasos que llegan.", // 38
        "Y ven a una figura hermosa saliendo.", // 39
        "Se tapa los ojos por el brillo del sol.", // 40
        "...", // 41
        "Ustedes...", // 42
        "Me liberaron...", // 43
        "Si...", // 44
        "Esto me huele muy mal chico.", // 45
        "... Cuando fue la última vez que senti el sol tocar mi piel...", // 46
        "Ustedes... que año es?", // 47
        "Eh.. es el... año 500 d.M", // 48
        "Hum... interesante.", // 49
        "Yo...", // 50
        "Entonces... estuve encerrado por mil años...", // 51
        "pero.. no recuerdo nada...", // 52
        "Oye... de casualida t... te llamas...", // 53
        "Magnus.", // 54
        "Sí... soy el mismismo que puso a Grecia de rodillas...", // 55
        "Pero... me siento tan debíl ahora.", // 56
        "Oye chico... como y porque lo liberaste?", // 57
        "Le explicas", // 58
        "...", // 59
        "¿Que?", // 60
        "Otra vez con esa historia?", // 61
        "Crees que él sepa como llegar a los campos Éliseos para derrotar... al dios Hades?.", // 62
        "De primera como piensas derrotar a un dios?", // 63
        "...Aunque...", // 64
        "Viendo los patrones...", // 65
        "Espera...", // 66
        "Sí estuve teniendo pesadillas...", // 67
        "Hades regresa cada 500 años...", // 68
        "Y un huamno capa de hacerle frente...", // 69
        "El sello de Magnus fue roto...", // 70
        "Y tu... no tienes dificultades al pelear...", // 71
        "Será que tu eres...", // 72
        "...", // 73
        "Él tercer gran huamno?.", // 74
        "Hay Zeus... como me metí en este lio...", // 75
        "Como paso todo esto?", // 76
        "Hades... Hades esta por despertar???", // 77
        "Oh... nononono...", // 78
        "Tratas de calmara", // 79
        "Oigan... que tanto parlotean allá?", // 80
        "Cierto. No es momento de perder la compostura.", // 81
        "Oye Magnus... tu derrotaste a Hades una vez no es asi?", // 82
        "Sí, porque lo dices", // 83
        "Pues sorpresa... él esta por regresar.", // 84
        "...", // 85
        "...", // 86
        "Y piensas que yo lo detenga en estas condiciones? mi armadura me abandono hace años...", // 87
        "Yo no les sere útil ahora. La humanidad se condeno.", // 88
        "Espera.", // 89
        "Este chico que tienes en frente.", // 90
        "És un gran humano.", // 91
        "!!", // 92
        "Acaso escuche lo que creo que escuche?", // 93
        "Sí... ademas de ser él quien abrio tu sello.", // 94
        "No me hagas reír... de verdad crees que él, con esa apariencia patetica sea capaz de salvarnos de un dios?", // 95
        "Si nos vamos a morir prefiero pudrire en mi sello antes de darle una oportunidad a ese idiota.", // 96
        "Sigues siendo tan arrogante como lo dicen los libros.", // 97
        "Y lo llamas patetico a él?", // 98
        "...!!", // 99
        "Me estas desafiando? a una figura legendaria como yo?", // 100
        "Te probare que este chico es digno de portar el mismo titulo que tú.", // 101
        "Aunque eso nos cueste caro.", // 102
        "Bien... resolvamos esto luchando.", // 103
        "Sí me logran derrotar... lo reconocere como mi sucesor... y os ayudare.", // 104
        "De lo contrario. Me llevare sus vidas. Absorvere sus almas para volver a mi plenitud...", // 105
        "Tambien eres capaz de usar tal magia...", // 106
        "Ya veo... por eso te volviste tan fuerte...", // 107
        "Sacan las armas", // 108
        "Si pasas sobre nosotros... no seremos los unicos a los que les absorvas el alma... no es así?", // 109
        "Me sorprende que sepas eso... no me digas... tambien eres otra portadora de tal fuente de poder...", // 110
        "Que importa si lo soy! Estas usando vidas a tu favor! crees que lo voy a permitir!", // 111
        "Haha... pues eso veo.", // 112
        "No perdamos más el tiempo y termienmos esto de una vez.", // 113

    // batalla
        "Ugh... como... es posible que yo... haya perdido.", // 114
        "Le apuntan el arma al cuello.", // 115
        "Lo siento. Pero sabes que tus días de gloria acabaron...", // 116
        "Ha... me recuerdas la vez que mi propio hijo derroto...", // 117
        "Bien... ustedes ganaron justamente.", // 118
        "Que necesitan de mí.", // 119
        "Necesitamos saber como pararle los pies a Hades... directamente en los campos Éliseos...", // 120
        "Esto según el chico... supongo que mata evitar que Hades haga de las suyas antes.", // 121
        "Los campos éliseos eh...", // 122
        "Bueno... primero deberan ir al infierno claro esta. Pero si no has sido bondadoso no podras pasar a dichos campos... a menos que desafíes a los jueces del inframundo.", // 123
        "O tengas el visto bueno de otro dios...", // 124
        "Si no has matado no necesitas de la segunda opcion. Pero tambien para ir al infierno tienes que morir o que un dios te lleve.", // 125
        "Y sabes... cuando estuve vivo. Se que Zeus nos abandono.", // 126
        "Pero su reino sigue intacto en el cielo.", // 127
        "Si logras encontrar la manera de ir... puede que te encuentres a un dios.", // 128
        "Y como llegamos allá?", // 129
        "En Atenas... conocen el palacio blanco?", // 130
        "Sí... dicho lugar donde antes residian los Magnus", // 131
        "En cierta sección hay una conexión directamente con él cielo...", // 132
        "Nose porque... se dice que un mago a escondidas hablaba con los dioses olimpicos... pero no sabemos para que.", // 133
        "Bueno... eso es todo lo que les puedo decir.", // 134
        "Gracias enserio señor.", // 135
        "Yo seguire en esta montaña... si saben que estoy vivo no se de lo que mis leales u opositores sean capaces de hacer.", // 136
        "Si... hubo una guerra civil por ello. Y las chispas revivirian si saben que estas vivo.", // 137
        "Ya veo... bueno. Vivire aqui hasta el fin de mis días... Yo ya estuve el tiempo suficiente en los libros de historia.", // 138
        "Y bueno, para derrotar a Hades chico, como eres un gran humano ya tendrias la capacidad de hacerlo... pero necesitas tener mucha determinación.", // 139
        "Antes de partir, le dejare parte de mi fuerza", // 140
        "Un fragmento de armadura balnca. Que es lo unico que me queda de ella.", // 141
        "Mi arma, la Maxima", // 142
        "y mi magia... Explosion", // 143
        "Gracias por todo...\033[3m\nTu ataque y defensa se incrementaron\nTambien desbloqueatse un nuevo tipo de magia.\033[0m", // 144
        "De nada... Y buena suerte.", // 145
        "Que Zeus... os acompañe...", // 146
        "Se marchan dejando todo atras...", // 147
        "Hacia el palacio blanco chico... nos depara una amenaza muy grande...", // 148
    };

    string Pla = "\033[3m";
    string Nai = "\033[31mNaika: \033[0m";
    string KMag = "\033[33mMagnus: \033[0m";

    for (int i = 0; i < 114; i++){
        if (i == 0 || i == 1 || i == 8 || i == 9 || i == 11 || i == 15 || i == 17 || i == 19 || i == 20 || i == 21
        || i == 23 || i == 24 || i == 28 || i == 31 || i == 33 || i == 34 || i >= 38 && i <= 40 || i == 58 || i == 79 || i == 108){
            cout << Pla;
        } else {
            cout << (i >= 41 && i <= 43 || i == 46 || i == 47 || i >= 49 && i <= 52 || i >= 54 && i <= 56 || i == 80
                || i == 83 || i == 85 || i == 87 || i == 88 || i == 92 || i == 93 || i == 95 || i == 96 || i == 99
                || i == 100 || i >= 103 && i <= 105 || i == 110 || i == 112 || i == 113 ? KMag:Nai);
        }
        PrintWithPause_Oly(Olympus[i], 20);
        LongPause_Oly(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }

    KingMagnusBattle(p, Km);
    Sleep(2000);

Clear();
    for (int i = 114; i < 149; i++){
        if (i == 115 || i == 147){
            cout << Pla;
        } else {
            cout << (i == 114 || i >= 117 && i <= 119 || i >= 122 && i <= 128 || i == 130 || i >= 132 && i <= 134 || i == 136 || i >= 138 && i <= 143 || i == 145 || i == 146 ? KMag:Nai);
        }
        PrintWithPause_Oly(Olympus[i], 20);
        LongPause_Oly(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }
}