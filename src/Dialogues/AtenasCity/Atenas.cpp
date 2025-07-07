#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
#include "Battles/NihilusBattle/NihilusFight.h"
using namespace std;

void PrintWithPause_At(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(0); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_At(int MiliSeconds){
    Sleep(0); // 1000 para pausa larga.  // "MiliSeconds" to normal
}
void AtenasCity(Player& p, Nihilus& Nihi){
    string Atenas[] = {
        "Ves que no ha cambiado jucho todo", // 0
        "Vas pasando por las afueras de la ciudad antes de entrar en las murallas", // 1
        "Te topas con unos guardias de la muralla", // 2
        "Identifiquese", // 3
        "Le dices tu nombre", // 4
        "Aja veamos...", // 5
        "Revisa", // 6
        "Espera un minuto...", // 7
        "No eres el chico que desaparecio hace 3 meses?", // 8
        "Te preguntas.. 3 MESES?", // 9
        "Maldices al viejo", // 10
        "Oh chico... estas en graves problemas.", // 11
        "Vienes conmigo.", // 12
        "Sigues maldiciendo al viejo por tal acto", // 13
        "Te meten en una puesto de guarida", // 14
        "Espera a que la oficial llegue", // 15
        "Estas en muchos líos muchacho...", // 16
        "Te desapareciste sin motivo. Bueno, suerte con la oficial hehe", // 17
        "De pronto comienzas a escuchar pasos hacia tu dirección", // 18
    };

    string NaikaAlly[] = {
        "Cada vez se hacen más rapidos...", // 0
        "Cuando te das cuenta ya han derribado la puerta...", // 1
        " regresaste?!", // 2
        "Reconoces esa voz al instante", // 3
        "Me alegra que no te haya pasado nada", // 4
        "Te abraza... dile adios a tu columna...", // 5
        "Me alegra que estes ileso..", // 6
        "Que te paso?", // 7
        "No tienes heridas?", // 8
        "No...", // 9
        "Debo relajarme...", // 10
        "Ufff...", // 11
        "EN DONDE CARAJOS TE METISTE", // 12
        "Te agarra de los hombros y te sacude con fuerza", // 13
        "Sabes lo preocupada. No, sabes lo preocupados que estuvimos de tu desaparición?", // 14
        "Apenas llevabas un día de trabajo por Zeus.", // 15
        "Te secuestraron los persas acaso?", // 16
        "tratas de calmarla y le explicas la situación", // 17
        "...", // 18
        "Te perdiste?", // 19
        "Y que un brujo te teletransporto?", // 20
        "...", // 21
        "...", // 22
        "HAHAHAH", // 23
        "Por el amor de Urano te lavaron el cerebro amigo?", // 24
        "Magos, un bosque, y ahora estas aqui despues de 3 meses como si nada...", // 25
        "Me hiciste el día... ya enserio.", // 26
        "No sabes cuanto haz metido la pata verdad?.", // 27
        "Si no tienes justificación de porque faltaste tanto tiempo.", // 28
        "Te pueden llevar a una corte marcial.", // 29
        "Ademas de que ya estas fichado y tienes prohibido salir de la ciudad.", // 30
        "Lose una pena.", // 31
        "Pero... quizas pueda hacer algo por tí.", // 32
        "No creas que es barato.", // 33
        "Puedo hacer que te retiren los cargos si me ayudas con una misión, que me dices?", // 34
        "Para que te pregunto, estas obligado a ayudarme colega.", // 35
        "Verás te cuento sobre la situación...", // 36
        "Más al norte hay un pequeño pueblo que ha tenido un pequeñito problema...", // 37
        "Bueno que pequeño. Enorme problema.", // 38
        "Ultimamente hay bandidos que han estado saquenado la aldea frecuentemnete... Su líder... se llama Nihilus. Él famoso rey bandido que comenzo su reinado del terror hace solo 2 meses.", // 39
        "Y la pobre pues ya esta en las últimas luego de tantos saqueos.", // 40
        "Y pues como a nuestra reina le da un poco igual la situación si es algo que es ajeno a Atenas", // 41
        "Me gustaría poder ayudar a esa gente, y necesitare un colega que... sirva de cebo...", // 42
        "Lo siento pero nadie más se atrevio a cumplir mi petición.", // 43
        "No te queda de otra colega.", // 44
        "Bien, no perdamos el tiempo y vamos!", // 45
        "...", // 46
    };

    string NaikaNotAlly[] = {
        "Cada vez se hacen más rapidos...", // 0
        "Cuando te das cuenta ya estaba abriendo la puerta... Y la cierra con fuerza", // 1
        "Vaya vaya... miren quien tenemos aqui", // 2
        "Reconoces esa voz al instante", // 3
        "Me alegra que no te haya pasado nada eh", // 4
        "Nos volvemos a ver... rompe muñecas", // 5
        "Me sorprende que te apareces ahora sin estar ileso.", // 6
        "Que te paso? te peleaste con conejos? o solo perdiste tu tiempo mientas evadias tus remposabilidades?", // 7
        "No tienes heridas? hay que mal...", // 8
        "Saben tan siquiera donde carajos te has metido?", // 9
        "... no me responderas?", // 10
        "Te agarra de los hombros y te sacude con fuerza", // 11
        "Escuchame mocos no he perdido mi tiempo contigo entrenandote para que te esfumes del trabajo apenas en tu primer día quedo claro!", // 12
        "Almenos habian personas que se preocuparon por tí", // 13
        "Apenas llevabas un día de trabajo por dios.", // 14
        "Eres alguien muy irresponsable.", // 15
        "Te secuestraron los persas acaso?", // 16
        "tratas de calmarla y le explicas la situación", // 17
        "...", // 18
        "Te perdiste?", // 19
        "Y que un brujo te teletransporto?", // 20
        "...", // 21
        "...", // 22
        "Te desapareces y me sales con esas estupideces?", // 23
        "Por el amor de Urano te lavaron el cerebro amigo?", // 24
        "Magos, un bosque, y ahora estas aqui despues de 3 meses como si nada...", // 25
        "Me hiciste el día... ya enserio... pero solo lo has empeorado", // 26
        "No sabes cuanto haz metido la pata verdad?.", // 27
        "Si no tienes justificación de porque faltaste tanto tiempo.", // 28
        "Te pueden llevar a una corte marcial...", // 29
        "Ademas de que ya estas fichado y tienes prohibido salir de la ciudad.", // 30
        "Lose una total pena.", // 31
        "Pregunatas si hay algo que puedas hacer", // 32
        "Ademas de ir a prisión... sí, si la hay.", // 33
        "Puedo hacer que te retiren los cargos si me ayudas con una misión, no te obligare... si lo que quieres es la carcel.", // 34
        "Aceptas", // 35
        "Verás te cuento sobre la situación...", // 36
        "Más al norte hay un pequeño pueblo que ha tenido un pequeñito problema...", // 37
        "Bueno que pequeño. Enorme problema.", // 38
        "Ultimamente hay bandidos que han estado saquenado la aldea frecuentemneteSu líder... se llama Nihilus. Él famoso rey bandido que comenzo su reinado del terror hace solo 2 meses.", // 39
        "Y la pobre pues ya esta en las últimas luego de tantos saqueos.", // 40
        "Y pues como a nuestra reina le da un poco igual la situación si es algo que es ajeno a Atenas", // 41
        "Y pues me gustaría poder ayudar a esa gente, y necesitare a alguein que sirva de cebo.", // 42
        "Lo siento pero nadie más se atrevio a cumplir mi petición.", // 43
        "No te queda de otra que hacer hacerme caso si quieres salir de esta situación.", // 44
        "...", // 45
        "Y mira, vamos a tener que convivir para resolver esto.", // 46
        "Si colaboras.", // 47
        "Quizas pueda reconciliarme contigo.", // 48
        "Pero solo si no me terminas siendo un estorobo", // 49
        "A donde iremos nos enfrentaremos a alguien que representa el mismo peligro", // 50
        "Así que da todo de tí como verdadero ateniense.", // 51
        "Y si te mueres... pues es cosa tuya.", // 52
        "Bueno... dejemos de perder el tiempo y vayamos.", // 53
        "Te agarra de tu armadura y te arrastra a pie hasta la ciudad.", // 54
        "Lo siento tampoco le agradas a mi caballo.", // 55
        "Te tocara caminar.", // 56
    };

    string Nihilus[] = {
        "Logran llegar a la aldea vecina.", // 0
        "Vaya.. este lugar se ha vuelvo más... lúgubre.", // 1
        "La mayoria de los residentes se han ido... pero pues la reina no desea inmigrantes en Atenas.", // 2
        "Así que mataremos dos pajaros de un tio.", // 3
        "bueno tres si consideramos tu problemon.", // 4
        "Andando ya casi es media noche.", // 5
        "Te vestiremos de campesino, y te dare algunas joyas.", // 6
        "No te preocupes si te apuñalan.", // 7
        "Yo te cubro la espalda...", // 8
        "Perderías sangre pero podemos.", // 9
        "Anda en posición... usualmente asaltan a media noche.", // 10
        "No te queda más remedio que ser el espantapajaros de la misión", // 11
        "...", // 12
        "Estas esperando... y esperando...", // 13
        "Ya son pasadas la medianoche", // 14
        "Que raro... será que ya saben estoy presente?", // 15
        "Escuchan caballos a lo lejos", // 16
        "Escuchaste! a neutras posiciones!", // 17
        "HAHAAAY", // 18
        "Preparense muchachos... este pueblito hay que sacarle hasta la ultima gota", // 19
        "Nota tu presencia de lejos", // 20
        "¿Eh?", // 21
        "Quien es?", // 22
        "Hey chicos... parece que tenemos carne fresca esta noche", // 23
        "Avanzan y estan de frente a frente", // 24
        "Vay vaya, acaso eres una doncella que busca su anillo de matrimonio?", // 25
        "HAHAHAHAY", // 26
        "Bueno, ire al grano jovencito.", // 27
        "Dame todo lo que poseas y salras ileso.", // 28
        "Te lo contrario... nos veremos obligados a incendiar la aldea.", // 29
        "Ni siquiera saben hacer fuego te preguntas.", // 30
        "Bien, veo que tienes una mirada desafiante... Oh... y que hermosas Joyas por cierto...", // 31
        "Saca su espada", // 32
        "Que tal si me llevo algunas...", // 33
        "Se prepara para atacarte... es muy veloz...", // 34
        "...", // 35
        "Naika sale y bloquea el ataque del bandido", // 36
        "Aqui no pasara nada si estoy en guardia.", // 37
        "Vaya vaya, tenemos a una parejita aqui... que bien 2x1.", // 38
        "Supongo que... espera, tu te me haces familiar.", // 39
        "Sí, mi nombre es Naika, y aqui y ahora detendre el tormento que has estado generando... Nihilus...", // 40
        "Vaya vaya... la chica que siempre a frustado los planes a mis chicos...", // 41
        "Finalmente nos vemos cara a cara...", // 42
        "Sabía que si no habia alguien debíl para robarle no le tomarías importancia", // 43
        "De verdad crees poder detener mi imperio muchacha?", // 44
        "Si, si cortamos de raíz el problema.", // 45
        "Bueno... si van a morir me quiero que recuerden mi nombre antes de degollarlos...", // 46
        "Me conocen como Nihulus...", // 47
        "Pero mi sobrenombre es Nyx... el bandido de la luna creciente.", // 48
        "Y pocos han vivido para conocer mi nombre", // 49
        "Y nosotros seremos quien detengamos tus talones.", // 50
        "Bien, ustees contra mí solo sera eh.", // 51
        "De acuerdo, hagamos esto.", // 52
        "Si ustedes ganan me retiro como bandido... para siempre. Ademas de irme preso claro.", // 53
        "Pero y si perdemos...?", // 54
        "HA... facíl, no viviran para contarlo.", //55
        "Que así sea...", // 56

    // BATALLA

        "Ugh... como... es posible esto...", // 57
        "Bien hecho camarada.", // 58
        "Lo siento Nyx... pero tus días de gloria acabaron.", // 59
        "Mierda.", // 60
        "Uhhh... saben... mi sueño es que mi hijo fallecido estuviera orgulloso de lo fuerte que se volvio su padre...", // 61
        "Pero supongo que la avaricia me consumio... metí mucho la pata.", // 62
        "Sí pues una lastima, te llevaras una buena cadena perpetura.", // 63
        "Bueno... gracias por la darme una batalla que jamas recordare almenos.", // 64
        "Y chico, si me derrotaste se que puedes volverte más fuerte...", // 65
        "Todos regresan a Atenas", // 66
        "Paso un día", // 67
        "Bien chico, cumpli mi promesa.", // 68
        "Ya estas libre de líos, pero que no vuelva a suceder ok?", // 69
        "Donde tienes pensado ir ahora?", // 70
        "Le cuentas sobre el monte Olimpo", // 71

        "Interesante... oye", // 72
        "Bueno ire al grano.", // 73
        "MI TRABAJO APESTA", // 74
        "Es solo papeleo a cada rato", // 75
        "Y me aburro", // 76
        "Y pelear contigo me encedio mi chispa para pelear", // 77
        "Mis huesos ya se estaban acalambrando", // 78
        "Así que pienso unirme a tu equipo", // 79
        "Nose donde quieras ir.", // 80
        "O cuales son tus objetivos.", // 81
        "Pero si hay batallas de por medio, me gustaría disfrutas de esa adrenalina.", // 82
        "NAIKA SE UNIO A TU EQUIPO", // 83
        "Bien", // 84
        "Te agarra con fuerta nuevamente", // 85
        "Al monte olimpo!", // 86
    };

    // p.BadRelationNaika = true; // TEMPORAL
    string Pla = "\033[3m";
    string Gu = "\033[32mGuardia: \033[0m";
    string Nai = "\033[31mNaika: \033[0m";
    string Nih = "\033[35mNihilus: \033[0m";

    for (int i = 0; i < 19; i++){
        cout << (i == 3 || i == 5 || i == 7 || i == 8 || i == 11 || i == 12 || i == 15 || i == 16 || i == 17 ? Gu:Pla);
            PrintWithPause_At(Atenas[i], 20);
            LongPause_At(1000);
            cout << endl;
            cout << "\033[0m";
            PtC();
        Clear();
    }

    if (!p.BadRelationNaika){
        for (int i = 0; i < 47; i++){
        cout << (i == 0 || i == 1 || i == 3 || i == 5 || i == 13 || i == 17 ? Pla:Nai);
        if (i == 2) cout << "\033[34m" <<p.PlayerName << "\033[0m";
            PrintWithPause_At(NaikaAlly[i], 20);
            LongPause_At(1000);
            cout << endl;
            cout << "\033[0m";
            PtC();
        Clear();
        }
    } else {
        for (int i = 0; i < 57; i++){
        cout << (i == 0 || i == 1 || i == 3 || i == 11 ||i == 17 || i == 32 ||i == 35 ? Pla:Nai);
            PrintWithPause_At(NaikaNotAlly[i], 20);
            LongPause_At(1000);
            cout << endl;
            cout << "\033[0m";
            PtC();
        Clear();
        }
    }

    for (int i = 0; i < 57; i++){
        if (i == 0 || i == 13 || i == 14 || i == 16 || i == 20 || i == 24 || i == 30 || i == 32 || i >= 34 && i <= 36){
            cout << Pla;
        } else {
            cout << (i == 18 || i == 19 || i >= 21 && i <= 23 || i >= 25 && i <= 29 || i == 31 || i == 33 || i == 38 || i == 39 || i == 41 || i == 42 || i == 44 || i >= 46 && i <= 49 || i >= 51 && i <= 53 || i == 55 ? Nih:Nai);
        }
        PrintWithPause_At(Nihilus[i], 20);
        LongPause_At(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }
    NihilusBattle(p, Nihi);
    for (int i = 57; i < 87; i++){
        if (i == 66 || i == 67 || i == 71 || i == 83 || i == 85){
            cout << Pla;
        } else {
            cout << (i == 57 || i >= 60 && i <= 62 || i == 64 || i == 65 ? Nih:Nai);
        }
        PrintWithPause_At(Nihilus[i], 20);
        LongPause_At(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }
}