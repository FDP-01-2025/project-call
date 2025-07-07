#include <iostream>
#include <windows.h>
#include <time.h>
#include "Data/PlayerData/PlayerData.h"
#include "Data/NaikaData/Naika.h"
#include "Battles/NaikaDummy/NaBattle.h"
#include "BattleUtils/BattleUtils.h"
using namespace std;

void LevelUp(Player& p){
    p.Level = 5; // sube de nvl + Stats
    p.MAX_HP += 50;
    p.HP += 50;
    p.DEFENSE += 5;
    p.MAX_MANA += 25;
    p.MANA += 25;
    p.MONEY += 25;
    p.PotionsHP += 1;
    p.PotionsMANA += 1;
}
void PrintWithPause_Tu(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(Pause); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_Tu(int MiliSeconds){
    Sleep(MiliSeconds); // 0 para lectura instantanea.  // "MiliSeconds" to normal
}
void Tutorial(Player& p, Naika Na, NaikaDummy& Ndum){
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
    "\033[3mArma de entrenamiento muy rigida, hecha de madera muy robusta fabricada unicamente para aporrear munecos de prueba.\nFue hecha por una carpintera (profesional?)...\nEsas astillas te doleran mas a ti que al enemigo...\033[0m", //20
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
    bool CancelDialogue = false;
    int Option = 0, option_kill = 0, option_view = 0, option_Naika = 0, option_consolation = 0;

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

    string Pacifist[] = {
        "Muñeco de Naika te hace una reverencia en tu honor por brindarle tal batalla.", // 0
        "Oye vienes a pelear, no perdonar... bueno, no estoy decepcionada, lo dejaré pasar por esta vez.", // 1
        "Ha sido un deleite para mi vista esta pelea.", // 2
        "Tienes potencial muchacho.", // 3
        "Qué dices, vamos con tus compañeros por banquete y vino?", // 4
        "Eres menor? no me importa! JAJA, yo invito" // 5
    };

    string Genocide[] = {
        "Ves lo que queda del muñeco... apenas puede levantarse pero hace una reverencia en tu honor por brindarle tal batalla... lista para lo que prosigue.", // 0
        // POSE DE VICTORIA
        "¡Felicidades, pasaste el entrenamiento, y con estilo!", // 1
        "Lo abraza", // 2
        "Ejem* lo siento, soy muy expresiva.", // 3
        "Ha sido un deleite para mi vista esta pelea.", // 4
        "Tienes mucho potencial muchacho.", // 5
        // DESTRUIR
        "Sueltas tu espada y te abalanzas con el muñeco", // 6
        "Con tus puños empiezas a destruir al muñeco con un odio incandescente", // 7
        "El pobre muñeco, sin alma ni voz, no puede siquiera expresar su agonía.", // 8
        "\033[31mNaika\033[0m\033[3m te aparta\033[0m", // 9
        "hey chico para! para! el muñeco no te hizo nada más.", // 10
        "Somos griegos... no monstruos.", // 11
        "Hice con amor este muñeco...", // 12
        "...", // 13
        "Haces como si me odiaras... o es asi?", // 14
        "...", // 15
        "Bien, pasaste la prueba...", // 16
        "Pero lárgate, tus compañeros deben estar esperándote... no?", // 17
    };

for (int i = 0; i < 11; i++) {
    if (i == 6) {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[6], 20);
        cout << endl << endl;
        PrintWithPause_Tu(Tutorial[7], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
        i++;
    } else if (i == 10) {
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[10], 20);
        cout << "\033[0m";
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
    } else {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
    }
}

Clear();
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
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            Disobey = true;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            break;
        }
    } while (Option != 1);

Clear();
    for (int i = 11; i < 31; i++){
        if (i == 22){
            cout << "Opcion: " << endl;
            cout << "\033[31m1. ATTACK\033[0m\n2. MAGIC\n3. ACTION\n4. ITEM\n5. MERCY\n" << endl;
            PtC();
        Clear();
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
        Clear();
            PrintWithPause_Tu(Tutorial[i+1], 20);
            LongPause_Tu(1000); cout << endl;
            cout << "\033[0m";
            PtC();
        i++;
        Clear();
        } else if (i == 20){
            cout << "\033[33mEspada de madera\033[0m: ";
            PrintWithPause_Tu(Tutorial[i], 20);
            cout << "\033[0m";
            LongPause_Tu(1000); cout << endl;
            PtC();
        Clear();
        } else if (i == 19){
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 20); cout << endl;
            LongPause_Tu(1000);
            PtC();
        Clear();
        } else if (i == 11){
            cout << "\033[3m";
            PrintWithPause_Tu(Tutorial[i], 20); cout << endl;
            Sleep(1000);
            PrintWithPause_Tu(Tutorial[i+1], 20);
            cout << "\033[0m";
            LongPause_Tu(1000); cout << endl;
            PtC();
            i++;
        Clear();
        } else {
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
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
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            Disobey2 = true;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            break;
        }
    } while (true);
    
Clear();
    for (int i = 31; i < 50; i++){
    if (i == 49){
        cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        if (Disobey == true && Disobey2 == true){
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Conditionals[9], 20); cout << endl;
        }
        PtC();
        Clear();
    } else if (i <= 35 || i >= 39 && i <= 43 || i == 47){
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        cout << "\033[0m";
        Clear();
    } else if (i <= 38 || i >= 44 && i <= 46 || i >= 48 && i <= 49){
        cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
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
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            break;
        default:
            cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(20);
        }
            Sleep(1000);
            cout << endl;
            PtC();
            Clear();
            cout << endl;
            break;
        }
    } while (true);

Clear();
    for (int i = 50; i < 53; i++){
        if (i == 50){
            cout << "Opciones de accion: " << endl;
            PrintWithPause_Tu(Tutorial[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
        Clear();
        } else {
            cout << "\033[31mNaika: \033[0m"; PrintWithPause_Tu(Tutorial[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
        Clear();
        }
    }
    ShowStats(p);
    for (int i = 53; i < 62; i++){
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
    }

    bool Close = false;
    cout << "Que stats deseas ver?\n1. \033[31mNaika: \033[0m\n2. Muneco de entrenamiento" << endl;
    do{
    cin >> Option;

Clear();
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
        PrintWithPause_Tu(Conditionals[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        cout << "\033[0m";
        Clear();
        }
        Close = true;
        break;
    default:
        cout << "\033[31mNaika: \033[0m";
            for (char c : Conditionals[0]){
            cout << c;
            Sleep(20);
        }
        break;
        }
    } while (Close != true);
    

    for (int i = 62; i < 87; i++){
        if (i == 79 || i == 83 || i == 86){
        cout << "\033[3m";
        PrintWithPause_Tu(Tutorial[i], 20);
        cout << "\033[0m";
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
        } else if (i == 65){
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Conditionals[13], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
        } else {
        cout << "\033[31mNaika: \033[0m";
        PrintWithPause_Tu(Tutorial[i], 20);
        LongPause_Tu(1000); cout << endl;
        PtC();
        Clear();
        }
    }

string NaikaPostBattle[] = {
    "horas después", // 0
    "Bien chicos, estoy bastante contenta de su progreso en este día.", // 1
    "Muchos han demostrado su potencial.", // 2
    "Y como recompensa por su arduo labor os invito a una cena.", // 3
    "Conozcanse entre ustedes, convivirán por mucho tiempo.", // 4
    "Así mantengamos buenas relaciones ok?", // 5
    "Sin más que decir buenas noches y disfruten!", // 6
    "Disfrutas de la comida y la buena vibra", // 7
    "Observas que Naika salio al balcon", // 8
    // BadRelation = true
    "Te da igual y sigues con tu noche", // 9
    // BadRelation = false;
    "Te pica la curiosidad", // 10
    // SI

    "Sales a revisar", //11
    "Encuentras a Naika en el Balcón pensativa", //12
    "noto tu presencia", //13
    "Hey hola chico... ¿buscabas algo? o me buscabas a mi?", //14
    "Bromeo, ¿qué necesitas?", //15
// NADA

    "Nada eh", // 16
    "Te pego fuerte mi muñeco o porque tan apagado? haha.", //17
    "Bueno, ten mi copa de vino si quieres.", //18
    "no me viene mal que me acompañen a ver las estrellas.", //19
    "¿Que si me sucede algo?...", //20
// sucede algo?

    "Nah...", //21
    "Simplemente miro las estrellas...", //22
    "...", //23
    "Ok me atrapaste...", //24
    "Este cargo de oficial... no es tan gloriosa como parece.", //25
    "Tienes prestigio sí... pero muchos esperan altas expectativas...", //26
    "El papeleo.", //27
    "Entrenar tropas...", //28
    "Y dirigir vidas como si fueran piezas en un tablero.", //29
    "Es... mucha responsabilidad, sabes?", //30
    "Yo... suelo beber mucho por eso.", //31
    "Y a veces, temo no regresar del campo... ", //32
    "Pero eso no es lo que más me aterra.", //33
    "A comparación de otros tutores...", //34
    "Yo le agarro cariño a mis tropas...", //35
    "Recuerdo sus nombres. Sus voces. Las bromas tontas. Sus sueños.", //36
    "verlos dar sus primeros pasos como soldados...", //37
    "Son más que soldados. Son parte de mí.", //38
    "Cada momento es guardado con amor.", //39
    "El tiempo que le dedico a cada uno.", //40
    "Todo lo que pasamos.", //41
    "De un día para otro pueden ser solo viles recuerdos...", //42
    "Doy todo de mí para evitar eso.", //43
    "Arriesgó demasiado y doy todo de mi para tener la menor cantidad de bajas posibles.", //44
    "Sangre, sudor, todo por verlos vivos. Para verlos crecer y convertirse en soldados honorables.", //45
    "No por nada dedico sangre y sudor, seguir aspirando a ser más fuerte", // 46
    "Porque no quiero..", //47
    "No quiero recibir esa carta que dice que uno de ellos cayó.", // 48
    "Que ya no volverán...", //49
    "Me cuesta... soportarlo...", // 50
    "Me destruye por dentro.", //51
    "Aunque me hayas visto a mi decir que grecia es muerte... solo finjo esa cara para cumplir con las expectativas de mis superiores...", // 52
    "\033[3mla voz se le quiebra\033[0m", // 53
    "Soy consciente... que... no es ni será la última vez que suceda...", // 54
    "Cada pérdida... es como perder a alguien de mi familia...", //55
    "\033[3maprieta los puños para no temblar\033[0m", // 56
    "Yo... No se si pueda seguir con esto...", //57
    "Yo... \033[3mexplota en lágrimas\033[0m", // 58
// Consolar NO
    "...", //59
    "Lo siento si me ves en esta situación...", //60
    "\033[3mse seca las lágrimas\033[0m", //61
    "Lamento que me veas en este estado tan deplorado...", //62
    "Se que no es profesional...", //63
    "Ni es de cerca mi carácter...", //64
    "...", //65
    "Eres algo callado.", //66
    "Me recuerdas a... un viejo amigo...", //67
    "Bueno anda...", //68
    "Tus amigos deben estarse preguntando que hacemos los 2 aquí afuera.", //69
    "No queremos que se esparzan rumores o si?", //70
    "Toma.", //71
    "\033[3mTe regala la copa de vino\033[0m", //72
    "Pronto los alcanzo...", //73
    "Te despides y vuelves con tus compañeros.", //74
// Consolar SI
    "\033[3mLe das un fuerte abrazo a Naika\033[0m", //75
    "\033[3mSe siente conmovida y te devuelve el abrazo\033[0m", //76
    "\033[3mQue tierno pero casi te saca los órganos con su fuerza...\033[0m", //77
    "Gracias", //78
    "\033[3mse seca las lágrimas\033[0m", //79
    "Lo necesitaba...", //80
    "Lo siento si me ves en esta situación...", // 81
    "Lamento que me veas en este estado tan deplorado...", //82
    "Se que no es nada profesional...", //83
    "Nadie me ha visto llorar... ni siquiera ellos...", //84
    "He estado sola en esta situación...", //85
    "Y por eso aprecio mucho tu gesto ", //86
    "Me haces recordar mucho a un viejo amigo.", //87
    "Recuerdo que cuando comenzamos nuestro entrenamiento no teníamos ni los 14 cumplidos.", //88
    "No tenía experiencia en nada.", //89
    "Yo era una niña que perdió a sus padres al inicio de la guerra de sucesión.", //90
    "Y tenía 2 opciones, o ir a un orfanato... o ser reclutada en el ejército.", //91
    "Opte por la segunda opción...", //92
    "Si tenía que morir... que sea luchando y evitando que otros niños tengan mi mismo destino.", //93
    "Y si moría... Al menos podría ver a mis padres.", //94
    "Y bueno, en mi entrenamiento fue cuando lo conocí.", //95
    "Se llamaba Leo.", //96
    "Y mejor nombre no le quedaba.", //97
    "Era fuerte, valiente y empático, era una persona increíble.", //98
    "Cuando coincidimos en un ejercicio en conjunto me contó que también perdió a sus padres.", //99
    "Y fue ahí donde comenzó nuestra fuerte amistad.", //100
    "No éramos solo camaradas. Éramos amigos muy cercanos.", //101
    "Nos apoyamos incondicionalmente", //102
    "Hasta que de un momento a otro nos dieron una fuerte noticia...", //103
    "Todos nosotros...", //104
    "Que Aún éramos sólo cadetes...", //105
    "Nos dieron la orden directa de enfrentarnos a las guerrillas rebeldes.", //106
    "No pasó ni una semana cuando ya comenzábamos a matar rebeldes.", //107
    "Todavía era una inutil que no entendía el peso de la guerra.", //108
    "Si no fuera por él... Ya habría muerto.", //109
    "Me salvó la vida innumerables veces.", //110
    "Pero de él aprendí mucho.", //111
    "Se tomaba la molestia de ser mi instructor.", //112
    "En horas de paz nos enfrentamos uno contra uno y me enseñaba cómo pelear.", //113
    "Note un progreso, me sentía cada vez más útil.", //114
    "Pero para ese momento no sabía usar nada de magia... como tú. ", //115
    "Y es una roca en el zapato si estás en la guerra.", //116
    "Pero él enseñó técnicas novedosas para ese momento.", //117
    "Era un estratega nato.", //118
    "Y un día de estos durante nuestra práctica...", //119
    "Ello... durante la noche.. lanzaron una de las mayores ofensivas hechas en la guerra...",  //120
    "Esa noche... fue una lluvia de sangre...",  //121
    "Hicieron una evacuación a gran escala. ",  // 122
    "Llamaron a cada soldado...",  //123 
    "Leo y yo salimos disparados hacia la entrada de la capital...", //124
    "No iban a tardar en derribar las murallas...", //125
    "Porque traían nuevas armas de asedio, jamás vistas...", //126
    "Se especula que trabajaron en conjunto con los persas y espartanos para fabricar tales armas...", //127 
    "a estos últimos se les acusó... pero ellos lo niegan... Por eso actualmente se rompieron relaciones diplomáticas los espartanos...", //128
    "La situación era muy crítica... y estaba en nuestra contra...", //129
    "Allí se iba a decidir qué bando ganaría... todos dieron todo de sí... incluyendome...", //130
    "Estábamos acorralados... pero no teníamos miedo... era todo o nada.", //131
    "Y entre las murallas lograron romper algunas puertas... y se abrieron varios frentes en la ciudad...", //132
    "Leo era del primer batallón... y yo del segundo...", //133
    "Tenía un nudo en la garganta... Íbamos a pelear en diferentes zonas...", //134
    "Pero antes de partir...", //135
    "Él me abrazó...", //136
    "Me dijo que sea fuerte, nos tenemos el uno al otro y que esta batalla no nos separara.", //137
    "Y que sin importar lo que pase, siempre estaríamos juntos.", //138
    "No contuve las lágrimas... No quería perder a quien se había convertido en mi familia.", //139
    "Pero...", //140
    "No era el momento...", //141
    "Me soltó... Tomó su arma y lo ví desaparecer entre los escombros...", //142
    "Me sequé las lágrimas y tomé mi arma para dirigirme a mi batallón...", //143
    "Y entre en combate...", //144
    "Gracias a él pude valerme por cuenta propia...", //145
    "No niego que también entre camaradas cubrimos nuestras espaldas...", //146
    "Casi muero varias veces... pero resistí como pude...", //147
    "horas de batalla... mis músculos no daban para más...", //148
    "Llegaban ordas y ordas de soldados... no imaginé que muchos buscaban derrocar a la reina...", //149
    "Di todo pero... el arma se me resbaló...", //150
    "Y en ese momento... solo vi a un ateniense alzar su arma y preparado para cortarme el cuelo...", //151
    "Yo solo... me rendí... y esperar lo peor...", //152
    "Derrame lágrimas... No por morir... si no porque no volveré a ver a quien consideraba mi hermano mayor...", //153
    "Y con mi perdida no quería que él sufriera... Pero no habia nada que pudiera hacer ya...", //154
    "Solo cerré los ojos... vi pasar mi vida... todo iba a cámara lenta...", //155
    "Pero justo cuando sentía el filo de la espada en el cuello.", //156
    "Escuche su voz... y lo ví.", //157
    "Estaba muy herido y con sangre... agotado como yo...", //158
    "Gritó mi nombre y con arrojó su arma contra mi agresor...", //159
    "Logro desarmarlo y lo noqueo...", //160 
    "Hizo lo imposible por salvarme...", //161
    "Me abrazó con todas sus fuerzas", //162
    "Y me dijo que si yo hubiese muerto...", //163
    "Él no se lo hubiera perdonado...", //164
    "Pero al vernos nos llenamos de determinación y no nos detendremos hasta acabar con esto... muriendo o salvando nuestro reino...", //165
    "Tomamos nuestras armas y volvimos al frente...", //166
    "Solo vi que peleamos codo a codo...", //167
    "Asesinando sin piedad a cada rebelde...", //168
    "Pero...", //169
    "Los rebeldes viéndose frenados...", //170
    "Comenzaron a hacer uso de sus nuevos juguetes...", //171
    "Y para peor escuchamos que batallones de personas se dirigen aquí para sumarse al asedio.", //172
    "Pero estaban siendo frenados por un reino aliado...", //173
    "Pero más temprano que tarde llegarán...", //174
    "Se nos agotaba el tiempo y los recursos de poco en poco...", //175
    "No nos dieron otra orden más que pelear...", //176
    "La retirada no era posible... estábamos en una península rodeados de mar...", //177
    "No contábamos con muchos barcos para escapar...", //178
    "Antes de pensar en una nueva estrategía...", //179
    "Escuchamos explosiones...", //180
    "Ellos... ya empezaron el asedio con sus nuevas armas...", //181
    "Catapultas... Helepolis... Balistas...", //182
    "No pasó ni el día y nuestras bajas se dispararon...", //183
    "Ya estábamos peleando bajo escombros cuando tomé consciencia de la situación...",//184
    "Polvo... sangre... escombros... media ciudad ya estaba en ruinas...", //185
    "Mire a los ojos a Leo...", //186
    "Nuestras miradas ya esperaban lo peor...", //187
    "Pero no teníamos más opciones más que pelear...", //188
    "En mi cabeza ya solo veía los cuerpos de mis ex compañeros...", //189
    "Mis heridas... El olor a sangre.. compañeros perdidos... no se como no colapse en ese momento...", //190
    "Leo solo me tomó de la mano y me dijo que todo estaría bien mientras siguiéramos juntos...", //191
    "Yo estuve a punto de estallar en lágrimas... balbuceando que moriríamos...", //192
    "Pero Leo solo se calmó... y me abrazó.", //193
    "Él me dijo que todo estaría bien... y que si moríamos o sobrevivíamos... lo haríamos juntos.", //194
    "Logró calmarme y me dijo que era una ateniense... que Thanatos no nos visitara hoy...", //195
    "La sangre de Magnus corre por nuestras venas de guerreros...", //196
    "Y nuevamente me levante... me secó las lágrimas... y yo asenté con la cabeza...", //197
    "De nuevo tenía ganas de volver al frente...", //198
    "Pero cuando mis ganas de luchar volvieron...", //199
    "Escuchamos un grito... y volteamos...", //200
    "Los rebeldes lanzaron una nueva ofensiva...", //201
    "Piedras de catapultas llenaron el cielo...", //202
    "Pero... No directo contra nosotros...", //203
    "Si no contra los civiles...", //204
    "A todos se nos salió el alma...", //205
    "Nos llenó de coraje... como esos bastardos apuntaron contra los de su misma nación...", //206
    "Y resultó ser... que un batallón de persas ya se encontraba en el asedio...", //207
    "No fue de esperar las reacciones de ambos bandos...", //208
    "Los rebeldes no querían esto... los traicionaron...", //209
    "Se dieron cuenta que solo fueron usados muy tarde...", //210
    "Usaron nuestros conflictos a su favor... y ellos vendrán solo para rematarnos...", //211
    "Rápidamente se hizo un cese al fuego y los rebeldes se encargaron de ese batallón persas... ", //212
    "Que los muy estúpidos abrieron fuego muy temprano...", //213
    "Si no fuese por ese milagro... solo seríamos un títere persa...", //214
    "Pero...", //215
    "Pese al alto al fuego.", //216
    "Los persas ya estaban por llegar...", //217
    "Rápidamente tanto nosotros como el bando contrario formamos un solo ejército...", //218
    "Sus líderes acordaron una alianza temporal...", //219
    "pero... aún así no igualamos ni numérica ni tecnológicamente a los persas...", //220
    "Ya estaba amaneciendo... la moral estaba muy baja por el desgaste.", //221
    "Pase junto a Leo con una fogata apenas... hablando que no teníamos ya a donde ir... podíamos huir... pero nuestros líderes...", //222
    "Necios... dijeron que no podían perder Atenas... Nuestra capital.", //223
    "Que formaba parte de nosotros... y era nuestro deber protegerla a toda costa...", //224
    "Abandonar la ciudad era considerado traición... y sentencia de muerte...", //225
    "Algunos hicieron el intento... los ejecutaron...", // 236
    "Y otros nadaron... Para peor el mar estaba violento esa semana...", // 237
    "Y como te imaginaras... se ahogaron...", // 238
    "No habíamos dormido... Y el sol ya comenzaba a salir... cuando...", // 239
    "Una gran sombra sobrevoló Atenas... esperamos lo peor... y así sucedió...", // 230
    "Una enorme piedra del tamaño de una casa cayó cerca del templo de la reina... destrozando la mitad de este... fallaron por suerte...", // 231
    "Y eso solo significaba una cosa...", // 232
    "Los persas...... estaban aquí...", // 233
    "En el horizonte... miles de persas estaban llegando del horizonte...", // 234
    "No solo vimos sus innumerables filas... ", // 235
    "Traían consigo un Trabuquete del tamaño de una montaña...", // 236
    "Un arma tan poderosa... que hizo añicos la mitad del gran Templo de la reina...", // 237
    "Que se decía que era muy resistente...", // 238
    "Todos tragaron saliva… tuvimos piel de gallina… nuestro miedo se apoderó de nosotros...", // 239
    "Llegó la batalla decisiva...", // 240
    "Los persas estaban recargando el trabuquete… esperando las órdenes de iniciar el asedio...", // 241
    "Nosotros también cargamos nuestras armas de asedio... gracias a los rebeldes.", // 242
    "Pero no era suficiente...", // 243
    "y... a las 7 de la mañana...", // 244
    "Comenzó el infierno...", // 245
    "Con las murallas rotas.. los persas tenían vía libre para ir al centro de la capital... barriendo edificios con su juguete...", // 246
    "Apenas montamos defensas provisionales...", // 247
    "Ellos iban a acabar con nosotros...", // 248
    "De un momento a otro ya estábamos peleando con persas...", // 249
    "Y estábamos en medio de una lluvia de piedras...", // 250
    "Intercambiamos fuego cada segundo...", // 251
    "Pero...", // 252
    "Su trabuquete tenía tal potencia que podía disparar a 1km de distancia...", // 253
    "No podemos alcanzarla y destruirla por medios convencionales...", // 254
    "Y nadie tenía tal magia para lanzarle algo o potenciar alguna máquina…...", // 255
    "Solo nos quedaba ver y resistir... mientras su trabuquete destruía de poco en poco nuestras armas de asedio...", // 256
    "Ya no había esperanzas...", // 257
    "Y habían pasado ya 3 días de asedio seguido...", // 258
    "Atenas ya estaba en las últimas...", // 259
    "Dormimos apenas 2 horas.. o lo intentábamos… Había mucho ruido con el asedio y gritos... sin mencionar el potente olor a sangre...", // 259
    "Pero un día después… Leo y yo embarcamos a los persas que lograron entrar… Logramos derrotarlos...", // 260
    "Pero en ese momento justo cuando íbamos a festejar esa pequeña victoria...", // 261
    "Comenzó una nueva oleada de fuego enemigo.", // 262
    "Nos resguardamos... ya era normal a esas alturas...", // 263
    "pero... algo no...", // 264
    "Leo tvo un mal presagio...", // 265
    "Y cuando volteo...", // 266
    "Había 2 niñas pequeñas escapando del miedo...", // 267
    "No sabíamos donde estaban sus padres...", // 268
    "Pero de un momento a otro una piedra derrumbó un edificio cercano...", // 269
    "Estaban por caerle grandes escombros...", // 270
    "Y de ahí Leo salió corriendo tras ellas...", // 271
    "Logró agarrarlas y me las lanzó… las atrape...", // 272
    "Pero tras ese enorme esfuerzo… y el desgaste.", // 273
    "Vi que su pierna... se partió en 2...", // 274
    ".....", // 275
    "Se cayó al suelo...", // 276
    "Grite su nombre y trate de alcanzarlo...", // 277
    "Solo vi su dolor... me miro a los ojos con lágrimas... y me dijo perdóname...", // 278
    "y solo llegue a ver...", // 279
    "Como el escombro lo aplastó totalmente...", // 280
    "Me quede congelada...", // 281
    "Como pude haber permitido eso me dije varias veces...", // 282
    "Explote nuevamente en lágrimas...", // 283
    "Las niñas trataron de calmarme.", // 284
    "No las escuche...", // 285
    "Mi enojo era tal que apreté a una de ellas...", // 286
    "Yo... no... no era mi intención...", // 287
    "La rabia... me cegó… mi odio… crece...", // 288
    "En ese momento vi la vida de las niñas apagarse...", // 289
    "Y me quede helada… que estoy haciendo...?", // 290
    "Ellas no tienen que pagar mis errores...", // 291
    "Iba a terminar con las vidas que mi prometido salvó...", // 292
    "Su... su sacrificio iba a ser en vano...", // 293
    "En ese momento no lo había notado...", // 294
    "Pero descubrí una nueva forma de magia...", // 295
    "El arrebatamiento del alma.", // 296
    "Solo unos pocos usuarios son capaces de arrebatar el alma de un ser y potencial su propia magia.", // 297
    "Tal magia se potencia con los sentimientos... si tienes muchos… su poder es exponencial...", // 298
    "Si la persona tiene pocos o es incapaz de sentir... ya no será capaz de usar magia...", // 299
    "Y pasó lo primero...", // 300
    "Estallé y libera una enorme energía… saque a volar todo lo que estaba a mi alrededor...", // 301
    "Experimente un poder... tan fuerte que quemaba mis venas... absorbí el alma de esas 2 niñas...", // 302
    "Mi armadura... arma... apariencia... ojos... cambiaron... todo...", // 303
    "Con esa nueva transformación.", // 304
    "Me entró una idea...", // 305
    "No sabía que pasaba pero lo intente...", // 306
    "Me dirigí a las niñas... no respiraban...", // 307
    "Así que me concentre y rece a Zeus para ver si mi idea funcionaba...", // 308
    "Si puedo arrebatarme el alma... ¿Puedo hacer lo contrario? me dije...", // 309
    "Así que me tomo varios minutos concentrandome...", // 310
    "No podía llorar por la muerte de mi prometido ahora...", // 311
    "Pasaron varios minutos hasta que...", // 312
    "Tosieron... estaban débiles... pero con vida...", // 313
    "Apenas podían moverse...", // 314
    "Así que tomé una decisión difícil...", // 315
    "Tomar prestadas sus almas.", // 316
    "Tenía poder pero… a costa de otras vidas...", // 317
    "Así que empuñe el arma y no perdí el tiempo.", // 318
    "Estaba en contrarreloj...", // 319
    "Terminaré esta guerra de una vez por todas...", // 320
    "Ya no estaba agotada... me sentía liviana... experimenté este creciente poder...", // 321
    "Volvieron a caer piedras... pero use mi magia... con un enorme esfuerzo logré redirigirlas... acabando con medio batallón a la lejanía.", // 322
    "Era un progreso.", // 323
    "No perdí el tiempo y fui directo al frente de la guerra...", // 324
    "Yo cambie el rumbo de la guerra.", // 325
    "En cuestión de un día frene su avance... empezaron a retroceder...", // 326
    "Lidere las tropas y logre subir su moral...", // 327
    "Nadie sabía quién era... pero estaban felices de estar en su bando... y los persas… aterrados...", // 328
    "La gota que derramó el vaso fue cuando concentré todo mi mana en una roca del trabuquete que tomó la decisión de apuntarme...", // 329
    "Grave error...", // 330
    "para ellos...", // 331
    "Con odio les redirige la piedra... y logre atinarle a su juguete...", // 332
    "Se me grabó su cara de horror cuando vieron que su arma estrella estaba en ruinas...", // 333
    "La retirada fue pronta...", // 334
    "Ganamos...", // 335
    "Llegue a ver el atardecer con sangre en mis manos... feliz de poner fin a esto...", // 336
    "pero… estaba vacía...", // 337
    "Mientras me idolatraban...", // 338
    "Yo solo caí de espaldas... me desplomé y lloré... alce mi reino a la victoria... pero con una promesa rota...", // 339
    "No era tiempo para llorar... tenía asuntos pendientes...", // 340
    "Fui directo donde magnus... y lo asesiné a sangre fría...", // 341
    "Evite que continuara la guerra... pero fue una pésima decisión como heroína...", // 342
    "En un solo día entre en los libros de historia... interferí en 2 eventos históricos que tuvieron que terminar de maneras diferentes.", // 343
    "Fui declarada Héroe de guerra de esa forma... pese a que no sabían quién era... y hasta el momento nadie sabe de mi paradero... claro en esa forma.", // 344
    "Atenas siguió soberana y con la Dinastía Aira vencedora...", // 345
    "La reina y otros pocos compañeros que sobrevivieron tomamos puestos importantes en el ejército.", // 346
    "De hecho tú actual general es un veterano también.", // 347
    "Pero tiene un puesto más alto que él mío al ser cercano a la familia real.", // 348
    "Pero al final solo me importa una cosa...", // 349
    "Regrese con las niñas... con hambre... frío... y sed...", // 350
    "Les regrese la totalidad de sus almas... o eso creía...", // 351
    "Perdí mi transformación... pero es lo de menos...", // 352
    "Les di abrigo... comida y agua... iba a llevarlas para que las sanaran...", // 353
    "Pero una de ellas... estaba más débil que la otra...", // 354
    "No controle bien mi poder... y gaste más el alma de una que de la otra...", // 355
    "El precio que pagué fue caro...", // 356
    "La abracé y entre lágrimas le imploré perdón...", // 357
    "El sacrificio de Leo... fue en vano...", // 358
    "Ella... solo miró... y me llamó madre...", // 359
    "Éllas están agradecidas por ser la única que se preocupó por ellas... no tenía la culpa.", // 360
    "Ambas me calmaron.. la hermana mayor no tuvo ningún rencor conmigo...", // 361
    "Era muy madura... sabía que estábamos en una situación crítica...", // 362
    "Pero no contuvo las lágrimas de ver la vida de su hermana menor apagándose...", // 363
    "Se dieron un último abrazo...", // 364
    "Y... falleció... entre los brazos de su hermana...", // 365
    ".....", // 366
    "Esa misma noche la enterramos afuera de Atenas...", // 367
    "Se me acercó y me dijo...", // 368
    "Madre... no te preocupes... diste tu mejor esfuerzo... te amo...", // 369
    "No contuve las lágrimas y la abracé... ella actuaba exactamente como Leo...", // 370
    "También en ese momento me entregó algo...", // 371
    "Era una pequeña fracción del alma de su hermana...", // 372
    "Me mencionó que antes de fallecer su hermana... le dijo que cuando muera no dejen ir su alma... que desearía estar con ellos.", // 373
    "Y que si se desata nuevamente una crisis similar...", // 374
    "Que al menos ella me acompañaría... indirectamente me prestó un poder devastador... y yo... podré evitar que otros niños pasen por algo similar a lo que vivimos...", // 375
    "Acepté...", // 376
    "Y bueno...", // 377
    "\033[3mAbre su puño y le muestra su alma\033[0m", // 378
    "Tengo acceso nuevamente a tal poder... pero... no quisiera usarlo nunca...", // 379
    "Sería como usar a mi hija como arma...", // 380
    "Y si tuviera que usarlo... sería en una situación de extrema importancia.", // 381
    "Así que para mí... aún es como si la mantuviese con vida...", // 382
    "Y en cambio su hermana... la llevé a un orfanato... No permití que viviera lo mismo que yo...", // 383
    "Y actualmente dirige ese mismo orfanato... y es una gran madre para muchos niños...", // 384
    "Incluso aprendió a hornear deliciosa comida...", // 385
    "Te digo que la comida que estabas comiendo tú y ellos.", // 386
    "La preparó ella para ustedes, hecha con todo su amor.", // 387
    "Así que no la desperdicies si no quieres quedarte sin cabeza Eh...", // 388
    "\033[3mSe seca las lágrimas\033[0m", // 389
    "Te agradezco mucho que me haya desahogado contigo...", // 390
    "Enserio gracias...", // 391
    "Y dime...", // 392
    "¿Te gustó mi historia?", // 393
    "Lo siento si te hice perder el tiempo...", // 394
    "Vaya paso casi la hora...", // 395
    "Tus compañeros ya se deben estar preguntando que hacemos aqui tanto tiempo...", // 396
    "Pero... antes de que regresemos", // 397
    "No... no le digas nada a ellos... vale?", // 398
    "No quiero que se preocupen de más por mi", // 399
    "Me verían como una figura materna... sabes que si les sucede algo a ellos...", // 400
    "Me afectaría mucho... y peor.", // 401
    "Bueno en fin, anda chico.", // 402
    "Tus amigos deben estarse preguntando que hacemos los 2 aquí afuera.", // 403
    "No queremos que se esparzan rumores o si?", // 404
    "Toma.", // 405
    "\033[3mTe regala la copa de vino\033[0m", // 406
    "Pronto os alcanzo...", // 407
    "Cuídate mucho, y gracias por escucharme.", // 408
    "\033[3mSe despide con una sonrisa\033[0m", // 409
    "Disfruta, la aún noche es joven.", // 410
    "Y oye, ten cuidado... por alguna razón presiento que una gran tormenta se aproxima...", // 411
    "Y apenas se estan formando las nubes...", // 412
    "...Bueno, ya no te interrumpo más, anda ve con tus amigos.", // 413
    "Nos vemos pronto en el campo de entrenamiento mañana.", // 414
    /// 3 YEARS LATER
    "3 AÑOS DESPUES", // 415
    "\033[3mLograste cumplir tu entrenamiento y te graduaras con honores.\033[0m", // 416
    "\033[3mLlegas a tu ceremonia de graduación, donde te esperan tus compañeros, Naika y el General.\033[0m", // 417
    "Hoy, es un día especial cadetes.", // 418
    "Hoy celebramos un momento decisivo en la vida de cada uno de ustedes, donde ya no sera considerados cadetes.", // 419
    "Si no hoy ya se volveran soldados de pleno derecho del ejercito ateniense.", // 420
    "Han superado pruebas duras, que no cualquiera podría soportar.", // 421
    "Han demostrado su valentía, fuerza y determinación.", // 422
    "Llegaron aquí siendo niños, y ahora parten como hombres forjados en la adversidad.", // 423
    "La guerra no perdona, pero ha templado su espíritu y su cuerpo.", // 424
    "Cada uno de ustedes es un pilar de esta nación, un escudo contra la oscuridad que amenaza nuestra tierra.", // 425
    "Recuerden siempre que el verdadero valor no está en la fuerza, sino en la lealtad, el honor y la voluntad de proteger a los suyos.", // 426
    "Salgan con la frente en alto, porque de ustedes depende el futuro de nuestro pueblo.", // 427
    "Bien hecho muchachos.", // 428
    "Fue un completo honor y orgullo haber sido su tutora.", // 429
    "Compartimos muchos momentos especiales.", // 430
    "Realmente espero que se vuelvan grandes soldados de prestigio.", // 431
    "Cuídense entre ustedes y rompanse una pierna.", // 432
    "Y recuerden, siempre estaré aquí para apoyarlos en lo que necesiten.", // 433
    // Badrelation = false
    "Y tú ", // 434
    "\033[3mTe mira con una sonrisa\033[0m.", // 435
    "¿Cómo te sientes ahora que te graduas?.", // 436
    "¿Estás emocionado por lo que viene?.", // 437
    "Has crecido mucho desde cruzamos miradas.", // 438
    "Cuídate mucho en serio.", // 439
    "Anhelo el momento en que nos volvamos a ver.", // 440
    // FIN
    "Se lanzan una última sonrisa y se retiran, comienza tu nueva aventura...", // 441
    "Bien soldados, como nos encontramos en tiempo de paz, su trabajo de hoy es solo guardia, siendo ustedes el rango más bajo del ejercito de momento, pero se que aspiraran a más, sin más que decir os deseo suerte.", // 442
    "Yuju que divertida es esta aventura... almenos te diero nuevo equipamiento...", // 443
    "Te trasladaron a la ciudad de Calcis, donde te asignaron como un guardia menor de la puerta este de la ciudad.", // 445
    "Ya comenzaste a patrullar la ciudad más temprano de lo que esperabas, pero al menos te asignaron un compañero.", // 446
    "Olvidalo, es algo molesto.", // 447
    "Solo se la pasa hablando de como su esposa le fue infiel... y que ahora él vive con su amante.", // 448
    "Que surrealista es esto, pero al menos te pagan...", // 449
    "Te quedaste medio dormido y ya acabo tu turno, te despides de tu compañero y te vas a casa finalmente despues de tu paga de 50 monedas...", // 450
    "Llegas a tu casa y te preparas para dormir, mañana será un día largo... nuevamente.", // 451
    "Supones que no habra mucha acción en tu vida desde ahora... o eso creíste.", // 452
    "Esa misma medianoche algo te despierta... un sonido algo peculiar.", // 453
    "Apenas es de madrugada... estás muy cansado pero aún así decides investigar.", // 453
    "A lo lejos observas una manada de slimes ir hacia un bosque... Lo dejas pasar... si no fuera porque te diste cuenta de un detalle.", // 454
    "Eso que llevan... no es un cuerpo???", // 455
    "Abandonas tu casa rápido y agarras tu arma para seguirlos.", // 456
    "Te diriges al bosque lo más rápidamente.", // 457
    };

    p.WEAPON = "Espada de madera"; // void NaikaDummyBattle(Player p, NaikaDummy Ndum); no cometer esta estupidez de declarar en vez de llamar
    NaikaDummyBattle(p, Ndum); // funcion de batalla
    LevelUp(p); // sube de nivel al jugador
    Sleep(2000);
    Clear();
    if (!p.KilledNaikaDummy){ // ruta pacifista
        for (int i = 0; i < 6; i++){
            if (i != 0){
                cout << "\033[31mNaika: \033[0m";}
            PrintWithPause_Tu(Pacifist[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
        }

    } else { // ruta neutral/genocida
        for (int i = 0; i < 1; i++){
            cout << "\033[3m";
            PrintWithPause_Tu(Genocide[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
            cout << "\033[0m";
        }

        while (option_kill != 1 && option_kill != 2){
                cout << "Que prosigue?\n1. Pose de victoria\n2. Destruir" << endl;
                cin >> option_kill;
            if (option_kill < 1 || option_kill > 2){
                DefaultError();
            }
        }

    Clear();
        switch (option_kill){
        case 1:
            for (int i = 1; i < 6; i++){
                cout << (i != 2 ? "\033[31mNaika: \033[0m":"\033[3m");
            PrintWithPause_Tu(Genocide[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
            cout << "\033[0m";
                }
            for (int i = 4; i < 6; i++){
                cout << "\033[31mNaika: \033[0m";
                PrintWithPause_Tu(Pacifist[i], 20);
                LongPause_Tu(1000); cout << endl;
                PtC();
                Clear();
                cout << "\033[0m";
            }
            break;
        case 2:
        p.BadRelationNaika = true;
            for (int i = 6; i < 18; i++){
                cout << (i > 9 ? "\033[31mNaika: \033[0m":"\033[3m");
            PrintWithPause_Tu(Genocide[i], 20);
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
            cout << "\033[0m";
                }
            break;
        default:
            DefaultError();
            break;
        }
    }

    for (int i = 0; i < 9; i++){
        cout << (i == 0 || i == 7 || i== 8 ? "\033[3m":"\033[31mNaika: \033[0m");
        PrintWithPause_Tu(NaikaPostBattle[i], 20);
        LongPause_Tu(1000);
        cout << endl;
        PtC();
        Clear();
    };

    if (p.BadRelationNaika){
        cout << "\033[3m";
        for (char c : NaikaPostBattle[9]){
            cout << c;
        }
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
        cout << "\033[0m";
// si mataste a dummy

    } else {
        cout << "\033[3m";
        for (char c : NaikaPostBattle[10]){
            cout << c;
        }
            LongPause_Tu(1000); cout << endl;
            PtC();
            Clear();
        cout << "\033[0m";

        while (option_view != 1 && option_view != 2){
            cout << "Vas ir a verla?\n1. Si\n2. No\n";
            cin >> option_view;
            if (option_view < 1 || option_view > 2){
                DefaultError();
            }
        }

        switch (option_view){
        case 1:
        Clear();
            for (int i = 11; i < 16; i++){
                cout << (i < 14 ? "\033[3m":"\033[31mNaika: \033[0m");
                PrintWithPause_Tu(NaikaPostBattle[i], 20);
                LongPause_Tu(1000);
                cout << endl;
                PtC();
                Clear();
            };
            break;
        case 2:
        Clear();
            cout << "\033[3m" << NaikaPostBattle[9] << "\033[0m" << endl;
            Sleep(1000);
            PtC();
            CancelDialogue = true;
            Clear();
            break;
        default:
            DefaultError();
            break;
        }

        if (!CancelDialogue){ // si no se cancela el dialogo
            while (option_Naika != 1 && option_Naika != 2){
            cout << "1. Nada\n2. ¿Sucede algo?\n";
            cin >> option_Naika;
            if (option_Naika < 1 || option_Naika > 2){
                DefaultError();
            }
        }

        Clear();
            switch (option_Naika){
            case 1:
                for (int i = 16; i < 21; i++){
                    cout << "\033[31mNaika: \033[0m";
                    PrintWithPause_Tu(NaikaPostBattle[i], 20);
                    LongPause_Tu(1000);
                    cout << endl;
                    PtC();
                Clear();
                };
                break;
            case 2:
                cout << "";
                break;
            default:
                DefaultError();
                break;
            }

            for (int i = 21; i < 59; i++){
                cout << "\033[31mNaika: \033[0m";
                PrintWithPause_Tu(NaikaPostBattle[i], 20);
                LongPause_Tu(1000);
                cout << endl;
                PtC();
            Clear();
            }
            
            while (option_consolation != 1 && option_consolation != 2){
            cout << "Consolarla?\n1. Si\n2. No\n";
            cin >> option_consolation;
            if (option_consolation < 1 || option_consolation > 2){
                DefaultError();
            }
        }

        Clear();
            switch (option_consolation){
            case 1:
                for (int i = 75; i < 414; i++){
                cout << ( i < 78 ? "\033[3m":"\033[31mNaika: \033[0m");
                PrintWithPause_Tu(NaikaPostBattle[i], 20);
                    if (i == 86) cout << "\033[34m" << p.PlayerName << "\033[0m";
                LongPause_Tu(1000);
                cout << endl;
                PtC();
            Clear();
                    }
                break;
            case 2:
                for (int i = 59; i < 75; i++){
                cout << ( i != 74 ? "\033[31mNaika: \033[0m":"\033[3m");
                PrintWithPause_Tu(NaikaPostBattle[i], 20);
                LongPause_Tu(1000);
                cout << endl;
                PtC();
            Clear();
                    }
                break;
            default:
                DefaultError();
                break;
            }
        } // si no se cancela el dialogo
    }

Clear();
    cout << "\033[3m" << NaikaPostBattle[415] << "\033[0m" << endl;
    LongPause_Tu(2000);
    PtC();
    Clear();
        for (int i = 416; i < 434; i++){
            if (i > 417) cout << (i <= 428 ? "\033[32mGeneral: \033[0m":"\033[31mNaika: \033[0m");
            PrintWithPause_Tu(NaikaPostBattle[i], 20);
            LongPause_Tu(1000);
            cout << endl;
            PtC();
        Clear();
        }

    if(!p.BadRelationNaika){
        for (int i = 434; i < 442; i++){
            cout << "\033[31mNaika: \033[0m";
            PrintWithPause_Tu(NaikaPostBattle[i], 20);
            if (i == 435) cout << "\033[34m" << p.PlayerName << "\033[0m";
            LongPause_Tu(1000);
            cout << endl;
            PtC();
        Clear();
        }
        for(int i = 442; i < 459; i++){
            cout << "\033[3m";
            if(i == 443) cout << "\033[32mGeneral: \033[0m";
            PrintWithPause_Tu(NaikaPostBattle[i], 20);
            LongPause_Tu(1000);
            cout << endl;
            PtC();
        Clear();
        }
    }
    p.WEAPON = "Espada de soldado;"; // nuevo equipo
    p.ATTACK += 10;
    p.ARMOR = "Cota de hierro";
    p.DEFENSE += 5;
    p.MONEY += 50;
}