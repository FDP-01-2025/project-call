#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <BattleUtils.h>
#include "LibraryPrologue.h"
using namespace std;

void PrintWithPause_P(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(Pause); // 0 para lectura rapida.  // "Pause" to normal
    }
}
void LongPause_P(int MiliSeconds){
    Sleep(MiliSeconds); // 0 para lectura rapida.  // "MiliSeconds" to normal
}
void Prologue(){
    string x;
    string prologue[] = {
        "\033[1;3;4mAnciente Greece. Atenas. 487 A. Magnus",
        "La lluvia golpea con insistencia los restos de una ciudad agonizante en plena guerra.",
        "El cuerpo de un nino yace inconsciente entre los escombros.",
        "Mas sin embargo...",
        "Su mente no esta en silencio pacifico... logras escuchar \033[31m2\033[0m voces."
    };

    string MysteriousVoice1[] = {
        "Hey...", // 0
        "Despierta...", // 1
        "...", // 2
        "Me sorprende que aun respire luego de lo sucedido.", // 3
        "Quizas.", // 4
        "Pero yo solo cumplo con mi trabajo.", // 5
        "Crees que \033[31mEllos\033[0m hayan abandonado a los humanos a su suerte?.", // 6
        "Y sin embargo... algo en este nino te inquieta.", // 7
        "Sucede algo?.", // 8
        "Porque lo mencionas?.", // 9
        "Y esas ocasiones sucedieron hace siglos.", // 10
        "Y sabemos como terminaron.", // 11
        "Mientras respire no, no tenemos ninguna autoridad para intervenir.", // 12
        "Aunque... sobrevive?.", // 13
        "Tal vez...", // 14
        "Lo tendre en mira.", // 15
        "No bromees.", // 16
        "Nadie me arrebatara lo que se me encomendo.", // 17
        "Sea lo que sea, no somos nosotros quienes pagaremos las consecuencias.", // 18
        "Sera mejor que nos retiremos.", // 19
        "Siento varias presencias, se dirigen hacia nuestra direccion.", // 20
        "Sabes que no es tan simple.", // 21
        "En estos tiempos se exige mi presencia en muchos lugares.", // 22
        "Nos veremos otra vez... cuando el equinoccio de Acuario traiga consigo la ultima sombra.", //23
        "No es el momento para profecias vacias.", // 24
        "No me hagas seguir perdiendo el tiempo.", // 25
    };

    string MysteriousVoice2[] = {
        "Crees que es demasiado joven para cruzar la frontera del sueno eterno?", // 0
        "Que efimera es la existencia humana.", // 1
        "Los mas poderosos codician tanto, sin entender lo breve de su llama.", // 2
        "Y los mas debiles se hunden en el silencio.", // 3
        "Tal vez... no fueron mas que un simple experimento.", // 4
        "Como arrojar ratones en un bosque repleto de bestias.", // 5
        "Mientras que \033[31mNosotros\033[0m solo observamos y cumplimos nuestros roles.", // 6
        "Lo observo.", // 7
        "Su futuro se despliega ante mi... pero no logro descifrarlo.", // 8
        "Es incierto... difuso... no soy capaz de predecir con exactitud que sucedera con el.", // 9
        "Es ambiguo, raras fueron las ocasiones que veo estas anomalias en humanos.", // 10
        "No... este es diferente.", // 11
        "Este nino no tiene un destino... Tiene muchos.", // 12
        "Como ramas que crecen en direcciones opuestas.", // 13
        "Algunas grises como si no tuvieran vida...", // 14
        "Otras claras y puras, como la primera luz del dia...", // 15
        "Y unas tan oscuras como la noche pura...", // 16
        "Deberiamos de intervenir?", // 17
        "No estoy seguro... su futuro me intriga, es como un arbol.", // 18
        "No logro ver mas alla del tronco.", // 19
        "le daras un tiempo?", //20
        "Este tipo de anomalia, no debemos ignorarla.", //21
        "Las veces que lo has mencionado se te salio de las manos y nos dieron ordenes directas de intervenir.", // 22
        "Solo no te confies esta vez.", // 23
        "Puede convertirse en un angel salvador para su gente...", // 24
        "O en el verdugo que termine sumiendo a todos a la oscuridad...", // 25
        "Puede que te quite el trabajo.", // 26
        "bromeaba, solo era una idea... o tal vez no.", // 27
        "Hay algo dentro de el que grita poder. Algo que aun no despierta.", // 28
        "No hagas la vista gorda.", // 29
        "Nunca envaines tu arma en un camino con niebla.", // 30
        "Bajar la guardia alimentara a la sombra que tomara tu cuerpo.", // 31
        "Ya estuvimos mas tiempo de lo previsto, hermano.", // 32
        "De todas maneras no son capaces de vernos.", // 33
        "Cuando tu senor reclame lo que considera suyo...?", // 34
        "Como quieras.", // 35
        "Adios...", // 36
        "Th...a...n..." // 37
    };

    string You[] = {
        "Te despiertas bruscamente.", // 0
        "Toses...", // 1
        "Solo observas escombros y fuego a tu alrededor de lo que parece una ciudad.", // 2
        "No pareces recordar como llegaste aqui.", // 3
        "Estas muy debil como para caminar e ir a un lugar seguro.", // 4
        "Estas sangrando, no crees sobrevivir por mucho tiempo en estas condiciones.", // 5
        "Pero logras escuchar voces y pasos acercandose a tu direccion.", // 6
        "Te sientes mareado... por la perdida de sangre.", // 7
        "...", // 8
    };

    string Soldiers[] = {
        "Hey! hay un sobreviviente en este sitio!.", // 0
        "Vaya es muy joven, que hacia en este lugar.", // 1
        "Sea cual sea la situacion envialo a el y el resto de supervivientes al campamento.", // 2
        "De acuerdo, tengan cuidado, aun hay rebeldes por estas zonas.", // 3
        "Vas a estar bien chico...", // 4
        "\033[3mDe un momento a otro te desmayas nuevamente...\033[0m" // 5
    };

    string V1 = "Voz misteriosa 1";
    string V2 = "Voz misteriosa 2";
    string H1 = "Hoplita 1";
    string H2 = "Hoplita 2";
    string Black = "\033[30m";
    string Yellow = "\033[33m";
    string Green = "\033[32m";

    string colors[] = {
    Black, Black, Black, Black, Yellow, Black, Black, Yellow, Yellow, Yellow, Black, Yellow, Yellow, Yellow,
    Black, Black, Yellow, Yellow, Yellow, Black, Yellow, Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow,
    Yellow, Yellow, Black, Black, Yellow, Yellow, Yellow, Black, Yellow, Black, Yellow, Yellow, Yellow, Yellow,
    Yellow, Black, Black, Yellow, Yellow, Black, Yellow, Yellow, Yellow, Black, Black, Yellow, Yellow, Black,
    Black, Black, Yellow, Black, Black, Yellow, Yellow, Yellow
    };

    string ColorsH[] = {
        Green, Yellow, Yellow, Green, Yellow, Black
    };

    string prefixes[] = {
    V1, V1, V1, V1, V2, V1, V1, V2, V2, V2, V1, V2, V2, V2, V1, V1, V2, V2, V2, V1, V2, V1, V1, V2, V2, V2, V2,
    V2, V2, V2, V1, V1, V2, V2, V2, V1, V2, V1, V2, V2, V2, V2, V2, V1, V1, V2, V2, V1, V2, V2, V2, V1, V1, V2,
    V2, V1, V1, V1, V2, V1, V1, V2, V2, V2
    };

    string prefixesH[] = {
        H1, H2, H2, H1, H2, ""
    };

    string texts[] = {
        MysteriousVoice1[0],
        MysteriousVoice1[1],
        MysteriousVoice1[2],
        MysteriousVoice1[3],
        MysteriousVoice2[0],
        MysteriousVoice1[4],
        MysteriousVoice1[5],
        MysteriousVoice2[1],
        MysteriousVoice2[2],
        MysteriousVoice2[3],
        MysteriousVoice1[6],
        MysteriousVoice2[4],
        MysteriousVoice2[5],
        MysteriousVoice2[6],
        MysteriousVoice1[7],
        MysteriousVoice1[8],
        MysteriousVoice2[7],
        MysteriousVoice2[8],
        MysteriousVoice2[9],
        MysteriousVoice1[9],
        MysteriousVoice2[10],
        MysteriousVoice1[10],
        MysteriousVoice1[11],
        MysteriousVoice2[11],
        MysteriousVoice2[12],
        MysteriousVoice2[13],
        MysteriousVoice2[14],
        MysteriousVoice2[15],
        MysteriousVoice2[16],
        MysteriousVoice2[17],
        MysteriousVoice1[12],
        MysteriousVoice1[13],
        MysteriousVoice2[18],
        MysteriousVoice2[19],
        MysteriousVoice2[20],
        MysteriousVoice1[14],
        MysteriousVoice2[21],
        MysteriousVoice1[15],
        MysteriousVoice2[22],
        MysteriousVoice2[23],
        MysteriousVoice2[24],
        MysteriousVoice2[25],
        MysteriousVoice2[26],
        MysteriousVoice1[16],
        MysteriousVoice1[17],
        MysteriousVoice2[27],
        MysteriousVoice2[28],
        MysteriousVoice1[18],
        MysteriousVoice2[29],
        MysteriousVoice2[30],
        MysteriousVoice2[31],
        MysteriousVoice1[19],
        MysteriousVoice1[20],
        MysteriousVoice2[32],
        MysteriousVoice2[33],
        MysteriousVoice1[21],
        MysteriousVoice1[22],
        MysteriousVoice1[23],
        MysteriousVoice2[34],
        MysteriousVoice1[24],
        MysteriousVoice1[25],
        MysteriousVoice2[35],
        MysteriousVoice2[36],
        MysteriousVoice2[37],
    };

    system("cls");
    for (int i = 0; i < 5; i++){
        cout << "\033[3m";
        PrintWithPause_P(prologue[i], 30);
        LongPause_P(1000); cout << endl;
            if (i == 0){
                cout << "Enter any letter to continue" << endl;
            }
        PtC();
        cout << "\033[0m";
        Clear();
    }

    for (int i = 0; i < 64; i++){
        if (i == 63){
            cout << colors[i] << prefixes[i] << "\033[0m" << ": ";
            PrintWithPause_P(texts[i], 500);
            SleepMS(1000); cout << endl;
            PtC();
            Clear();
        } else {
            cout << colors[i] << prefixes[i] << "\033[0m" << ": ";
            PrintWithPause_P(texts[i], 30);
            SleepMS(1000); cout << endl;
            PtC();
            Clear();
        }
    }
        

    for (int i = 0; i < 9; i++){
        cout << "\033[3m";
        PrintWithPause_P(You[i], 30);
        SleepMS(1000); cout << endl;
        PtC();
        Clear();
    } 

    for (int i = 0; i < 6; i++){
        if (i == 5){
        PrintWithPause_P(Soldiers[i], 30);
        SleepMS(1000); cout << endl;
        PtC();
        Clear();
        } else {
        cout << ColorsH[i] << prefixesH[i] << "\033[0m" << ": ";
        PrintWithPause_P(Soldiers[i], 30);
        SleepMS(1000); cout << endl;
        PtC();
        Clear();
        }
    }
}