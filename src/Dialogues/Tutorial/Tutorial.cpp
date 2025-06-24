#include <iostream>
#include <windows.h>
#include <time.h>
#include "Data/PlayerData/PlayerData.h"
#include "Data/NaikaData/Naika.h"
#include "Battles/NaikaDummy/NaBattle.h"
using namespace std;

void PrintWithPause_Tu(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(Pause); // 0 para lectura rapida.  // "Pause" to normal
    }
}
void LongPause_Tu(int MiliSeconds){
    Sleep(0); // 0 para lectura rapida.  // "MiliSeconds" to normal
}
void Tutorial(Player& p, Naika Na, NaikaDummy& Ndum){
    string x;
    string Tutorial[] = {
    "Bien soldado, bienvenido a tu entrenamiento.", //0
    "Por generaciones hemos entrenado arduamente a nuestros batallones.", //1
    "Cada uno ha sido bendecido por Zeus.", //2
    "Puede que ya no estemos en nuestra mejor epoca.", //3
    "Pero no significa que no tengamos \033[31mdeterminacion.\033[0m", //4
    "Ejem, Comenzaremos con lo basico.", //5
    "Al iniciar en una batalla se te desplegara un menu como este:", //6
    "1. ATTACK\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n", // 7
    "Vez ese muneco de por ahi? APORREALO.", //8
    "Ejem usa el boton \033[31mATTACK\033[0m.", //9
    "*Entraste en una batalla con el muneco de entrenamiento*", // 10
    "El muneco de entrenamiento ha sido aporreado.", //11
    "Recibio 1 de dano.", //12
    "Asi se hace!.", //13
    "Aunque claro, no te vas a romper la madre con el enemigo a puno limpio.", //14
    "Te harian papilla!",//15
    "Por eso, les entregaremos espadas...", //16
    "De madera.", //17
    "Hechas por mi!.", //18
    "\033[31mNaika\033[0m te entrega: \033[33mEspada de madera\033[0m", //19
    "\033[3mArma de entrenamiento muy rigida, hecha de madera muy robusta hecha unicamente para aporrear munecos de prueba.\nFue hecha por una carpintera (profesional?)...\nEsas astillas te doleran mas a ti que al enemigo...\033[0m", //20
    "Bien pruebalo.", //21
    "Independientemente de lo que hayas hecho la espada de madera ya se ha roto casi de inmediato.", //22
    "Pones cara de asco.", //23
    "Se rompio tu espada... he...", //24
    "...", //25
    "No preguntes o terminaras como esa espada.", //26
    "Bueno sigamos con tu entrenamiento...", //27
    "Ahora el siguiente boton de tu menu es la magia.", //28
    "No sabes usar magia? No me importa.", //29
    "Vamos! prueba el boton \033[34mMAGIC\033[0m. Por cierto.\nLa magia usa \033[34mMANA\033[0m, Y es un recuros muy importante. Pero si se te acaba solo espera y se te regenera de poco en poco.\nAh! y al usar magia no puedes fallar! la magia es util para asegurar un 100% de daño!", //30
    "Intentas usar magia", //31
    "Usas todas tus fuerzas y te pones rojo", //32
    "Logras crear una mini rafaga de aire hacia el muneco de entrenamiento", //33
    "No le mueves ni un pelo", //34
    "...", //35
    "No te preocupes.", //36
    "Puedes llegar a ser tan fuerte como yo! con practica claro.", //37
    "Mira y aprende.", //38
    "\033[31mNaika\033[0m se truena el cuello y suspira.", //39
    "con su magia expulsa un ventaval.", //40
    "Se sale de control.", //41
    "No solo manda a volar el muneco de entrenamiento...", //42
    "Saca a volar medio cuartel", //43
    "...", //44
    "Me van a descontar esto...", //45
    "En fin... traere otro muneco...", //46
    "10 minutos despues", //47
    "Bien, al menos con mi vendaval tienes una mejor vista!, no hay que ser pesimistas!", //48
    "Ahora veamos el boton \033[33mACTION\033[0m", //49
    "1. MY STATS\n2. ENEMY DESCRIPTION\n3. EXCHANGE MAGIC\n4. ACTION 1\n5. ACTION 2\n6. ACTION 3\n7. DEFEND\n8. RETURN\n", //50
    "Dentro de \033[33mACTION\033[0m puedes hacer varias acciones como puedes ver, Te hare un resumen rapido.", //51
    "usa \033[33mMY STATS\033[0m muestra tus stats actuales. miremos los tuyos.", //52
    "Ahora eres un debilucho.", //53
    "Pero si tienes curiosidad...", //54
    "Ah! y no consume tu turno. Puedes presumirle de tus stats a tus enemigos tanto como quieras!", //55
    "La cara de bobo que les veras a tus enemigos!", //56
    "sigamos.", //57
    "\033[33mENEMY DESCRIPTION\033[0m: usarlo para ver que tan debil es tu enemigo y reirte de el...", //58
    "Si es que no es mas fuerte que tu claro, y no te haga papilla!", //59
    "COMO YO!", //60
    "bien, usa \033[33mENEMY DESCRIPTION\033[0m conmigo! o... usa ese apestoso muneco... \033[3m(No soy tu enemiga pero bah)\033[0m.", //61
    "Aqui en \033[33mEXCHANGE MAGIC\033[0m es util si tienes mas de un tipo de magia puedes intercambiarlos en una pelea!", //62
    "Es util para cambiar de estrategia!", //63
    "Luego tienes los \033[33mACTIONS 1, 2 y 3\033[0m Son botones para que realices diferentes acciones en una batalla si no deseas pelear,\ncomo terminar una batalla pacificamente y bla...bla...bla.", //64
    "Pero aqui estamos en Grecia! aqui es muerte!", //65
    "Y de ultimo tienes el \033[33mRETURN\033[0m, eh, sirve si cambias de opinion y quieres liarte a palos con tu enemigo de ya.", //66
    "Para mi es un 50/50, no te sirve... a menos que seas un indeciso.", //67
    "Pero eso es de gallinas!", //68
    "Luego tenemos \033[33mITEM\033[0m basicamente te sirve para usar objetos que hayas tenido en el camino, no te dare mas explicaciones.", // 69
    "y de ultimo tenemos \033[33mMERCY\033[0m", //70
    "...", //71
    "Siempre me pregunto por que de este este inutil boton.", //72
    "Basicamente si tienes suficientes \033[34mpuntos de piedad\033[0m puedes perdonar a tu enemigo.", //73
    "O si eres un \033[31mbondadoso\033[0m bajale el HP a tu enemigo hasta casi matarlo y se rendira.", //74
    "Somos griegos...", //75
    "no mounstros...", //76
    "puedes perdonar a uno que otro plebeyo por ahi.", //77
    "Bien muchacho, Ahora toma esta otra espada de madera y...", //78
    "Neika saca un muneco de prueba con su forma", //79
    "Usa todo lo aprendido para luchar conmigo!", //80
    "Claro... use magia para que pelee por mi.", //81
    "Aun no estais en forma para enfrentarme!. ",//82
    "Te empuja", //83
    "Buena suerte! estare atras observando!", //84
    "Ah si! cuidado, puedes fallar tus golpes!", //85
    "Muneco con forma de Neika aparecio", //86
    };

    bool Disobey = false;
    bool Disobey2 = false;
    srand(time(NULL));
    int Option;

    string Conditionals[] = {
        "No te hagas el listo, usa las \033[31mOPCIONES\033[0m que te muestra el menu!.", // 0
        "Necio! ese no es.", // 1
        "Attack! Attack!.", // 2
        "Hablo en Persa o que? usa Attack.", // 3 
        "NO es ese boton! Si Zeus te estuviera entrenando ya te hubiera lanzado un rayo!.", // 4
        "No me importa si no usas magia usa el bendito... BOTON.", // 5
        "Magic! Magic!.", // 6
        "Hablo en Sumerio o que? usa Magic.", // 7
        "NO es ese boton! Si Poseidon te estuviera entrenando ya hubiera inundado tu casa!.", // 8
        "Y me asegurare de que tu mocoso no le des a otros botones como si no hubiera un manana.", // 9
        "Ni me molestare en reganarte.", // 10
        "No tienes nada que ver... es solo un apestoso muneco.", // 11
        "Por alguna razon tiene consciencia. Le caes mal...", //12
        "Luego tenemos \033[33mDEFEND\033[0m, hace que recibas menos dano y recargues mas \033[34mMANA\033[0m, si deseas usar mayormente magia claro." // 13
    };

    /*
for (int i = 0; i < 11; i++) {
    if (i == 6) {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[6], 30);
        cout << endl << endl;
        PrintWithPause_Tu(Tutorial[7], 20);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        i++;
    } else if (i == 10) {
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[10], 30);
        cout << "\033[0m";
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
    } else {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
    }
}

system("cls");
    do{
        int Index = rand() % 4+1;
        cout << "Opcion: " << endl;
        cout << "\033[31m1. ATTACK\033[0m\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n";
        cin >> Option;
    
        switch (Option){
        case 1:
            break;
        case 5:
        case 4:
        case 3:
        case 2:
            cout << "\033[31mNaika: \033[0m"; 
            for (char c : Conditionals[Index]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            Disobey = true;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            break;
        }
    } while (Option != 1);

system("cls");
    for (int i = 11; i < 31; i++){
        if (i == 22){
            cout << "Opcion: " << endl;
            cout << "\033[31m1. ATTACK\033[0m\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n" << endl;
            cin >> x;
        system("cls");
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 30);
            LongPause_Tu(1000); cout << endl;
            cin >> x;
        system("cls");
            PrintWithPause_Tu(Tutorial[i+1], 30);
            LongPause_Tu(1000); cout << endl;
            cout << "\033[0m";
            cin >> x;
        i++;
        system("cls");
        } else if (i == 20){
            cout << "\033[33mEspada de madera\033[0m: ";
            PrintWithPause_Tu(Tutorial[i], 30);
            cout << "\033[0m";
            LongPause_Tu(1000); cout << endl;
            cin >> x;
        system("cls");
        } else if (i == 19){
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 30); cout << endl;
            LongPause_Tu(1000);
            cin >> x;
        system("cls");
        } else if (i == 11){
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 30); cout << endl;
            Sleep(1000);
            PrintWithPause_Tu(Tutorial[i+1], 30);
            cout << "\033[0m";
            LongPause_Tu(1000); cout << endl;
            cin >> x;
            i++;
        system("cls");
        } else {
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 30);
            LongPause_Tu(1000); cout << endl;
            cin >> x;
            system("cls");
        }
    }

    do{
        int Index_2 = rand() % 4+5;
        cout << "Opcion: " << endl;
        cout << "1. ATTACK\n\033[34m2. MAGIC\033[0m\n3. ACTION\n4. ITEM\n5. MERCY\n";
        cin >> Option;
        if (Option == 2) break;

        switch (Option){
        case 5:
        case 4:
        case 3:
        case 1:
            cout << "\033[31mNaika: \033[0m"; 
            for (char c : Conditionals[10]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            Disobey2 = true;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            break;
        }
    } while (true);
    
system("cls");
    for (int i = 31; i < 50; i++){
    if (i == 49){
        cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        if (Disobey == true && Disobey2 == true){
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Conditionals[9], 30); cout << endl;
        }
        cin >> x;
        system("cls");
    } else if (i <= 35 || i >= 39 && i <= 43 || i == 47){
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        cout << "\033[0m";
        system("cls");
    } else if (i <= 38 || i >= 44 && i <= 46 || i >= 48 && i <= 49){
        cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        }
    }


    do{
        cout << "Opcion: " << endl;
        cout << "1. ATTACK\n2. MAGIC\n\033[33m3. ACTION\033[0m\n4. ITEM\n5. MERCY\n";
        cin >> Option;
        if (Option == 3) break;

        switch (Option){
        case 5:
        case 4:
        case 2:
        case 1:
        cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[10]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(30);
        }
            Sleep(1000);
            cout << endl;
            cin >> x;
            system("cls");
            cout << endl;
            break;
        }
    } while (true);

system("cls");
    for (int i = 50; i < 53; i++){
        if (i == 50){
            cout << "Opciones de accion: " << endl;
            PrintWithPause_Tu(Tutorial[i], 30);
            LongPause_Tu(1000); cout << endl;
            cin >> x;
        system("cls");
        } else {
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 30);
            LongPause_Tu(1000); cout << endl;
            cin >> x;
        system("cls");
        }
    }
    ShowStats(p);
    for (int i = 53; i < 62; i++){
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
    }

    bool Close = false;
    cout << "Que stats deseas ver?\n1. \033[31mNaika: \033[0m\n2. Muneco de entrenamiento" << endl;
    do{
    cin >> Option;

system("cls");
    switch (Option){
    case 1:
        ShowStats(Na);
        cout << endl;
        cout << "Descripcion: Joven oficial del ejercito Ateniennse.\nNaika es una guerrera experimentada, tiene un temperamento algo explosivo, pero tambien tiene un corazon bondadoso.\nUsara todos los recursos necesarios para salvar a quienes lo necesiten.";
        cout << endl << endl;
        Close = true;
        break;
    case 2:
        for (int i = 11; i < 13; i++){
        cout << "\033[3m";
        PrintWithPause_Tu(Conditionals[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        cout << "\033[0m";
        system("cls");
        }
        Close = true;
        break;
    default:
        cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(30);
        }
        break;
        }
    } while (Close != true);
    

    for (int i = 62; i < 87; i++){
        if (i == 79 || i == 83 || i == 86){
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[i], 30);
        cout << "\033[0m";
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        } else if (i == 65){
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Conditionals[13], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        } else {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 30);
        LongPause_Tu(1000); cout << endl;
        cin >> x;
        system("cls");
        }
    }
    */
    p.WEAPON = "Espada de madera";
    NaikaDummyBattle(p, Ndum);
    // void NaikaDummyBattle(Player p, NaikaDummy Ndum); no cometer esta estupidez de declarar en vez de llamar
}