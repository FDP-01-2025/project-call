#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "BattleUtils/BattleUtils.h"
#include "Data/EliteSData/EliteSlime.h"
#include "Battles/SlimeBattle/Sbattle.h"
#include "Data/TrollData/Troll.h"
#include "Battles/TrollBattle/TrollFight.h"
using namespace std;

void PrintWithPause_F(const string& Text, int Pause) {
    for (char c : Text) {
        cout << c;
        Sleep(0);
    }
}
void LongPause_F(int MiliSeconds) {
    Sleep(0);
}
void Forest(Player& p, EliteS& S, Troll& Tr) {
    string forestIntro[] = {
        "Cruzas entre árboles y arbustos", //0
        "El bosque es más denso de lo que imaginabas.", //1
        "Por la hora la visibilidad es poca pero te acercas cada vez más.", //2
        "Los encontrastes.", //3
        "Los slimes se ponen a la defensiva, aunque miras que se están comunicando entre ellos.", //4
        "Por lo visto se ponen de acuerdo en algo...", //5
        "Luego observamos a un slime más grande acercándose.", //6
        "El resto de slimes huyen...", //7
        "No tienes otra alternativa más que hacerle frente.", //8
    };

    string BattleES [] = {
    //Dead
        "Asestas el último golpe y derrotas al slime", //0
        "Subes de nivel", //1
        "Los otros slimes salen huyendo con el cuerpo", //2
        "Corres lo máximo posible y los acorralados...", //3
        "N-nos rendimos!", //4
        "los apuntas con tu espada a cada uno", //5
        "Ok ok! tu ganas!", //6
        "Los slimes sueltan el cuerpo", //7
        "p-podemos explicarte...pero no nos mates por favor...", //8
        "Guardas tu arma... de momento", //9

    //Mercy
        "El slime de Élite se conmovió por que lo dejaras vivir", //10
        "Llamó a sus compañeros", //11
        "H-hola! humano!", //12
        "Eres de los pocos que se atreven a entrar al bosque...", //13
        "Y el primero que se atreve a perdonarnos...",  //14
        "Somos visto como plagas...", //15
        "\033[3mLe cuentas sobre el cuerpo\033[0m", //16
        "ah! si..." //17

    //SEGUIR
        "Eh! quien encendio la luz...", //18
        "Que hago en medio del bosque?", //19
        "Y que hacen todo estos slimes alrededor mio???", //20
        "PORQUE estoy atada!.", //21
        "eso...", //22
        "\033[3mle apuntas con el arma\033[0m", //23
        "Ok! ok! lo confesamos...", //24
        "Bueno... comencemos con el principio...", //25
        "Hace tiempo los slimes vivíamos en armonía junto a otras especies...", //26
        "Hasta que la nación de los trolls atacó", //27
        "Todas las especies dieron todo de sí....", //28
        "Y salimos victoriosos...", //29
        "Pero las bajas salieron caras...", //30
        "Sabes... nosotros completamente hechos de mana...", //31
        "Y un troll al enterarse de eso... se aprovecho de nuestra debilidad...", //32
        "cerro la fuente principal que le da Mana al bosque...", //33
        "Y entonces... se desató el caos económico.", //34
        "Todo lo que antes podíamos comprar con maná... perdió completamente su valor.", //35
        "Claro... porque aquí, el maná era la moneda. Literalmente. Estamos hechos de dinero, en nuestros términos.", //36
        "continuando...", //37
        "Los precios comenzaron a caer en picada.", //38
        "Caimos en recesión economica...", //39
        "Y que todo baje no es nada bueno... busca deflación en google si quieres.", //40
        "continuando.", //41
        "No solo la hiperdeflación estaba subiendo a un ritmo alarmante...", //42
        "Hubo una caída brutal del consumo.", //43
        "Despidos masivos.. desempleo desenfrenado...", //44
        "Y nuestras vidas se agotaban para peor...", //45
        "Y no podíamos volver a tomar las armas en esas condiciones con un Troll que cada vez se hace más fuerte...", //46
        "Así que recurrimos a un último recurso...", //47
        "Él secuestro...", //48
        "Sabes... Cada día, lidiamos con los vuestros...", //49
        "Lidiamos que los humanos nos utilicen como tutoriales... no solo en los Isekai.", //50
        "Si no has usado uno como tutorial ya te amamos...", //51
        "Así que se nos ocurrió que para equilibrar eso...", //52
        "Empezamos a secuestrar...", //53
        "Ahora que lo digo yo si se oye mal... pero no tenemos alternativa...", //54
        "Secuestramos seres con un alto valor de mana y lo robamos.", //55
        "No lo matamos... drenamos... pero si lo dejamos más seco que palo en el desierto.", //56
        "¿Por qué tanto alboroto?", //57
        "O-oh querido rey... lamento mucho pero solo...", //58
        "Callate, no tenemos que dar explicaciones.", //59
        "Hacemos lo que podemos para sobrevivir y no cambiaremos de opinión", //60
        "oigan me van a desatar o...", //61
        "También te callas.", //62
        "Tienes el maná para que nuestra especie subsista unos meses más.", //63
        "No! No! oye tú sea como te llames por favor ayudame!", //64
        "Si me quedo sin mana yo me quedaré sin trabajo de maga por meses!", //65
        "Y su manera de robar mana es muy... muy...", //66
        "Ugh entran por donde no deben como Pedro por su casa!", //67
        "y me dan asco!!", //68
        "¿Tú alguna vez has sentido a un slime... drenandoté por el ombligo?", //69
        "¿¡NO!? ¡Pues no lo recomiendo!", //70
        "Sin permiso esto es una grave violación a los acuerdos de Magia de Ginebra, ¡en serio!.", //71
        "...", //72
        "...", //73
        "{Player} ...", //74
        "Dejala.. ejem...", //75
        "Sea lo que sea nos la llevamos.", //76
        "\033[3mLos desafías con tu arma\033[0m", //77
        "Me desafías? así será...", //78
        "Espere rey... no es una buena idea, derrotó a uno de élite!", //79
        "Que? bueno... es un humano... no deberíamos subestimar los...", //80
        "Bien... hagamos esto para detener los secuestros...",  //81
        "Si derrotas al Troll que nos atormenta cesamos nuestro modo mexicano y liberamos a la chamana y otros rehenes.", //82
        "De lo contrario, si no nos ayudaras... lárgate inmediatamente. Tú decides.", //83

        //ignora el problema 
        "\033[3mTe das media vuelta y esto ya no es tu asunto\033[0m", //84
        "Hum... como imagine.. chicos a trabajar", //85
        "S-si señor... espereme.", //86
        "NO! NO hey regresa! HEY! Ayúdame! por favor! puedo conceder una nueva magia...", //87
        "POR FAVOR!", //88
        "No sé si soportaré lo que me deparará!!", //89
        "Ya no los escuchas", //90
        "Vas caminando de regreso a tu hogar", //91
        };

        //Genocida
        string Genocide[] = { 
        "\033[3mEl Slime Rey te observa con cautela.\033[0m", //0
        "\033[3mLa Chamana contiene la respiración.\033[0m",  //1
        "O-Oye chico... porque tu mirada cambio tan... tan... \033[3mtraga saliva\033[0m", //2
        "Por favor... si tienes un mínimo de humanidad... no los provoques...", //3
        "\033[3mSusurra al Rey.\033[0m", //4
        "Majestad... no me gusta cómo nos mira...", //5
        "Tranquilo. solo todavía no ha decidido el entrometido.",  //6
        "Por favor...", //7
        "Tú... no tienes que hacer esto.", //8
        "Puedes... simplemente irte, o ayudarnos.", //9
        "...", //10
        "Sé perfectamente tus intenciones... {Player}.", //11
        "No son tus enemigos.", //12
        "\033[3mSiente un mal presagio, pero su voz es firme como un verdadero rey\033[0m", //13
        "Chico, no pienso dar ni un paso atrás si el futuro de mi gente pende de un hilo.", //14
        "Y no busco la guerra. Pero si amenazas a los míos... no me queda más alternativa que responder fuego con fuego...", //15
        "S-señor... su espada... no la ha bajado en ningún momento.", //16
        "¿Por qué sigues empuñando eso... humano?", //17
        "Imagine que mi propuesta te estaba gustando.", //18
        "\033[3mTus dedos aprietan más fuerte la empuñadura.\033[0m", //19
        "S-señor...  tengo miedo.", //20
        "\033[3men voz baja\033[0m", //21
        "No sabemos que pretende.", //22
        "Empieza a evacuar y llama a todas las unidades posibles...", //23
        "Debemos ser precavidos...", //24
        "Esta situación...no me gusta nada.", //25
        "Es exactamente igual cuando inicio la guerra con los Trolls...", //26
        "Apenas logramos sobrevivir...", //27
        "Pero no creo que contemos con la misma suerte ahora.", //28
        "C-como ordene señor.", //39
        "\033[3msale disparado\033[0m", //30
        "\033[3mLo notas y tratas de alcanzarlo\033[0m", //31
        "\033[3mBloquean inmediatamente tu paso\033[0m", //32
        "Chico te lo advertí.", //33
        "\033[3mTe rodean y te apuntan con lo que tienen\033[0m", //34
        "Si tocas a mis chicos sera una declaración de guerra.", //35
        "Y abriremos fuego.", //36
        "No, por favor... solo está en shock... ¿verdad?", //37
        "Pero señor... le prometió a su esposa que no lastimaría más ningún humano!", //38
        "Después de que unos salvaran a sus padres en la guerra contra los Trolls!", //39
        "\033[3mLe salen lagrimas\033[0m", //40
        "Pues lo siento... por situaciones como esta es que nunca hago promesas...", //41
        "Chico, quiero que te largues del bosque inmediatamente.", //42
        "O por las buenas...", //43
        "\033[3mRecargan sus armas\033[0m", //44
        "O por la fuerza...", //45
        "Este es mi ultimatum.", //46
        "\033[3mLa situación es crítica\033[0m", //47
        "Por favor... Desatenme!! No saben con lo que se meten!!", //48
        "Puedo ayudar!! puedo... puedo...", //49
        "por favor... {Playername}", //50
        "Todo listo señor.", //51
        "No nos hagas abrir fuego chico.", //52
        "Da un solo paso más...", //53
        "Y...", //54
        "Te juro que no te gustará lo que viene.", //55
    
        //retirarte 
        "\033[3mBajas tu arma y te rindes\033[0m",  //56
        "\033[3mSolo das media vuelta... este ya no es asunto tuyo\033[0m", //57
        "\033[3mTe das media vuelta y esto ya no es tu asunto\033[0m",  //58
        "\033[3mNo estas en condiciones para una larga pelea\033[0m", //59
        "Gracias.", //60
        "Sabía que entenderías.", //61
        "Pero desde hoy quedas exiliado de este bosque.", //62
        "Y a partir de hoy decreto que todo los humano que entre en él será considerado nuestro enemigo.", //63
        "Señor, ya estamos abortando la evacuación.", //64
        "Gracias... {name}", //65
        "Gracias por no... proceder...", //66
        "No te preocupes por mí...", //67
        "Podré soportar lo que me deparará a mí...", //68
        "Adiós.", //69
        "\033[3mYa no los escuchas\033[0m", //70
        "\033[3mVas caminando de regreso a tu hogar... con sentimeintos agridulces... ¿que estuviste a punto de hacer?\033[0m", //71

        //proceder
        "\033[3mDesobedeces\033[0m", //72
        "...", //73
        "Eso veo.", //74
        "Lo siento esposa mía.," //75
        "Espero que me perdones por romper tu promesa...",  //76
        "Me aseguraré de que no quede ni una molécula de tu ser por perturbar este bosque.", //77
        "Y que tu cuerpo se pudra en el Tártaro.", //78
        "\033[3mTe pones en posición defensiva\033[0m", //79
        "\033[3mTe lanzan una lluvia de piedra y magma\033[0m", //80
        "\033[3mPor alguna razón... te sientes más liviano\033[0m", //81
        "\033[3mComo si se hubiese ido tu alma...\033[0m", //82
        "\033[3mPero gracias a eso esquivar sin muchas dificultades todo\033[0m", //83
        "\033[3mTodos están desconcertados... de esta situación...\033[0m", //84
        "\033[3mEstá muy nervioso\033[0m", //85
        "S-señor... acaso... como lo hizo?", //86
        "\033[3mTraga saliva\033[0m", //87
        "Ningún humano hubiese tenido esos reflejos...", //88
        "Acaso...", //89
        "Él... es... el Tercer Gran Humano?", //90
        "Eso solo significa también otra cosa... \033[31mÉl\033[0m está muy cerca de despertar...", //91
        "Gran... Humano??? Será... que tiene relación... con Él Legendario Magnus!?", //92
        "Señor llegó la infantería está aquí!!", //93
        "\033[3mTe rodean miles de soldados\033[0m", //94
        "Justo a tiempo.", //95
        "Bueno chaval, se acabo tu tiempo.", //96
        "Gran humano o no...", //97
        "Me asegurare de que mueras.", //98
        "INICIEN EL ASALTO!", //99
        "A sus ordenes!", //100
        "Sobre Él!!!!", //101
        "NOOOO!", //102
        "\033[3mTodos los slimes saltan sobre tí!!!\033[0m", //103
        "...", //104
        "...", //105
        "...", //106
        "\033[3mLevantas tu arma\033[0m", //107
        "...", //108
        "\033[3mSolo se escucha el rebanamiento de varios cuerpos de un solo tajo\033[0m", //109
        "!!!", //110
        "!!!", //111
        "Oh... no... no.. nonono...", //112
        "HUYAN!!", //113
        "No... NO!", //114
        "Si mataras a mi pueblo!!", //115
        "Que sea sobre mi cadáver!!", //116
        "\033[3mSlime Rey revela su verdadera forma gloriosa\033[0m", //117
        "\033[3mTodas sus stats suben exponencialmente\033[0m", //118
        "No use esta forma desde que asesinaron a mi esposa...", //119
        "Y me obligaste a hacerlo.", //120
        "Mi gente... murió por proteger mi vida... y la de sus familias...", //121
        "Mi cuerpo... será lo último que deleitara tu vista!", //122
        "Sin más tiempo que perder... moriras...", //123
        "\033[3mCon gran velocidad se abalanza sobre tí\033[0m", //124

    // BATALLA
        "\033[3mEs derrotado de un solo golpe\033[0m", //125
        "...",  //126
        "SEÑOR!!", //127
        "NOO!!", //128
        "M-maldita sea...", //129
        "Incluso con este poder...", //130
        "De un solo golpe... yo...", //131
        "Ugh...", //132
        "No creí que fueras un peligro total...", //133
        "Si pasas ahora... sobre mí...", //134
        "Como deje que esto pasara...", //135
        "Irás por todos... ¿no es así?", //136
        "Esposa mía... hijos... mi gente... yo...", //137
        "Os he fallado.", //138
        "\033[3mEl cadaver del Slime Rey se esparce en el piso\033[0m", //139
        "\033[3mLos restos del Gran Rey, antes símbolo de gloria, se esparcen como lodo tibio en la tierra que juró proteger.\033[0m", //140
        "\033[3mLa corona cae de su cabeza y rueda hasta quedar a tus pies.\033[0m", //141
        "\033[3mSu cuerpo, ya sin forma, se esparce como un charco sin alma sobre el suelo frío.\033[0m", //142
        "\033[3mvomita\033[0m", //143
        "R-r-r-r-e-e...y", //144
        "REYYYY! el rey ha muerto no puede ser!", //145
        "\033[3mHay panico total\033[0m", //146
        "\033[3msolo ignoras los gritos\033[0m", //147
        "\033[3mApenas reaccionas\033[0m", //148
        "\033[3mdecides poner fin a esto de una vez\033[0m", //149
        "\033[3mEl único sonido que escuchas es el metálico canto de tu espada resolviendo la situación.\033[0m", //150
        "\033[3mLa sensación fría del acero, la sangre fría, el eco sordo de la muerte.\033[0m", //151
        "\033[3mAcabarás con el problema de una vez\033[0m", //152
        "\033[3mTerminaste el trabajo\033[0m", //153
        "\033[3mUn vacío helado te inunda el pecho...\033[0m", //154
        "\033[3mPero... algo en tu interior se siente perversamente satisfecho. Tanta experiencia acumulada, tanta destrucción consumada.\033[0m", //155
        "\033[3mTu cuerpo está manchado con la sangre viscosa de los slimes.\033[0m", //156
        "\033[3men shock, su voz es un susurro quebrado, casi un lamento.\033[0m", //157
        "Porque...", //158
        "PORQUE FUE NECESARIO ESO!", //159
        "¡RESPONDE!", //160
        "\033[3mBlandes el arma lentamente, sin una palabra.\033[0m", //161
        "\033[3mcierra los ojos esperando lo peor\033[0m", //162
        "\033[3mSolo se escucha un corte en esto...\033[0m", //163
        "\033[3mLa liberas de su atadura\033[0m", //164
        "\033[3msus manos temblorosas rozan la libertad.\033[0m", //165
        "eres libre.", //166
        "\033[3mla voz rota, traspasada por el dolor y la incredulidad\033[0m", //167
        "Porque...", //168
        "Ellos solo buscaban su supervivencia...", //169
        "Ni siquiera mataban...", //170
        "Solo trataban... trataban de subsistir con lo que podían...", //171
        "¿Qué eres?", //172
        "¿Quién eres?", //173
        "Acaso eres humano??", //174 
        "Que justifico ese genocidio...", //175
        "QUE TE HICIERON?", //176
        "eres libre.", //177
        "RESPONDE MI P.TA PREGUNTA!", //178 
        "Resolvi el problema.", //179
        "¿Problema? Sí, mataste el problema... y a todos los inocentes con él.", //180
        "Me ayudaste... sí... a convertirme en testigo del horror absoluto.", //181
        "\033[3mRompe en llanto\033[0m", //182
        "... solo buscaban vivir... y tenías la capacidad de ayudarlos...", //183
        "Algo “externo” te impulsó a hacer esto?", //184
        "¿Acaso simplemente disfrutaste de la destrucción del fruto de una curiosidad morbosa?", //185
        "Me das asco...", //186
        "Mejor dicho...", //187
        "Me dan...", //188
        "...", //189
        ".. ¿terminaste?", //190
        "Si... ni creas que olvidaré esto.", //191
        "estás de su lado?", //192
        "\033[3mlanzas una mirada fría\033[0m", //193
        "\033[3mtraga saliva\033[0m", //194
        "N-No...", //195
        "{Player}: eso quería escuchar...", //196
        "\033[3mLa chamana solo observa como te vas tranquilo después de tal matanza\033[0m", //197
        "\033[3mSabes que no lo olvidará\033[0m", //198
        "\033[3mSolo se escucha el goteo viscoso del maná evaporándose en el suelo.\033[0m", //199
        "\033[3mDejas atrás un enorme vacío de poder... y especies pudrirse en vida poco a poco\033[0m", //200
        "\033[3mSin que nadie más cambie la situación...\033[0m", //201
        "\033[3mVas caminando de regreso a tu hogar... vacío\033[0m", //202
        "\033[3mDejando pudrirse un bosque sin salvación\033[0m", //203
    };

    string Pacifist[] = {
        //Ayudarles
        "Espléndido!", //0
        "De acuerdo, resuelve lo del troll y cumplimos nuestra palabra", //1
        "Bien muchacho, te daremos un pequeño equipo y provisiones para que te prepares para lo peor.", //2
        "Preparado? sigue rio arriba y no deberías tardar mucho en toparse con el centro del bosque...", //3
        "La fuente que le da vida al bosque... Buena suerte...", //4
        "\033[3mLuego de una intensa caminata llegas a un lugar hermoso\033[0m", //5
        "\033[3mNunca habías visto tanto mana en un solo lugar\033[0m", //6
        "\033[3my detrás de una lianas de mana ahí se encontraba\033[0m", //7
        "\033[3mUn enorme troll azul que se estaba comiendo directamente todo lo que tenia mana\033[0m", //8
        "\033[3mY como todo en el bosque está conectado\033[0m", //9
        "\033[3mSupo de inmediato tu existencia\033[0m", //10
        "Vaya vaya vaya... que tenemos aquí", //11
        "No ha sido suficiente que hayan erradicado a mi especie?", //12
        "Y vienen a pararme los pies ahora un debilucho humano?", //13
        "HAHAHA, dime, esos estúpidos slimes pidieron ayuda externa?", //14
        "HAHAHA", //15
        "¿Qué piensas hacer ahora que me has despertado un pequeño humano?", //17
        "¿Me contaras un cuento? ¿O me deportas a México?", //18
        "JAJAJA, qué ingenuo...", //19
        "\033[3mLe lanzas una baya\033[0m", //20
        "...", //21
        "Quieres hacerme enojar?", //22
        "Nosotros los trolls arreglamos nuestras diferencias peleando uno a uno.", //23
        "Que estas nervioso de pelear con un gigante?", //24
        "Terminemos con este asunto de una vez... aquí voy!", //25
        "\033[3mTroll apareció y te desafío\033[0m", //26
    //BATTLE

    //Kill troll
        "Uhhhhh... Me.. me has ganado?", //27
        "...",  //28
        "Bueno... tienes mis respetos...",  //29
        "Sabes... duele ser el último de tu especie...",  //30
        "Dejare de existir...",  //31
        "Pero me diste una gloriosa batalla...",  //32
        "Y podré ver a mis hermanos...",  //33
        "Que por mucho tiempo fuimos... discriminados...",  //34
        "Mi vida se agota... adiós...",  //35
        "Humano...",  //36
        "\033[3mEl troll fallece con una pose de victoria\033[0m",  //37
        "\033[3mTe salen lagrimas\033[0m",  //38
        "\033[3mAprendiste que no todos los monstruos nacen siéndolo. Algunos lo son porque el mundo los empujó.\033[0m",  //39
        "\033[3mSolo abres la fuente de mana y vuelves con los slimes\033[0m",  //40
        "Vaya... lo lograste...",  //41
        "El mana ha regresado y nos sentimos vivos nuevamente...",  //42
        "Debería inclinarte a tí por tal acción...",  //43
        "Ese apestoso troll ya no nos molestara.",  //44
        "\033[3mSolo pides soltar a la chamana entre lágrimas\033[0m",  //45
        "\033[3mY terminar con los secuestros\033[0m",  //46
        "Bien, palabra es palabra.",  //47
        "Voy señor!",  //48
        "\033[3mSueltan a la chamana\033[0m",  //49
        "muchas gracias muchacho...",  //50
        "Ya me estaban aburriendo...",  //51
        "Me obligaban a escuchar sus estúpidas historias heroicas de una tal guerra que sucedió aquí...",  //52
        "Y viendo tu expresión... ellos no son los héroes...",  //53
        "Bueno... como agradecimiento te otorgare este obsequio.",  //54
    // OPCION
        "Elige bien:",  //55
        "Bien.. que así sea.", //56
        "Cierra sus ojos y...", //57
        "Ω, θεοί του Ολύμπου, ακούστε τις προσευχές μου... Ω, ευλογημένος Δίας, δώσε στον γιο σου το δώρο που λαχταρά και λούστε τον στη θεϊκή σου πληρότητα.", //58
        "Un aura comienza a rodearte y te sientes lleno de vigor", //59
        "Aceptas el regalo", //60
        "Bueno... tu misión en este bosque la cumpliste...", //61
        "Pero... Solo hiciste tu trabajo, No te culpes.", //62
        "Se que el troll murió con gloria.", //63
        "Ya está atardeciendo... deberías volver...", //64
        "Puede que la recompensa no fue grande.", //65
        "Pero demostraste ser una gran persona.", //66
        "Adiós... soldado.", //67
        "Te despides de la chamana", //68
        "Solo te volteas atrás y vuelves a tu hogar", //69
        "Pero con un sentimiento de culpa", //70

        //Mercy troll
        "Tú bajas tu arma lentamente. El troll se queda inmóvil, desconcertado.", //71
        "Porque... me has perdonado...",  //72
        "¿No vas a acabar conmigo?",  //73
        "Te acercas y dejas caer una segunda baya a sus pies.",  //74
        "...",  //75
        "la recoge con torpeza, como si nunca hubiera visto un gesto así en siglos",  //76
        "¿esto es una ofrenda?",  //77
        "¿Para mí?",  //78
        "¿Tú... de verdad crees que algo como yo merece vivir?",  //79
        "se sienta lentamente, mirando la baya como si fuera un recuerdo olvidado",  //80
        "Cuando era pequeño...",  //81
        "Éramos una comunidad muy unida...",  //82
        "Pero fuimos muy discriminados por otras especies...",  //83
        "Según ellos, éramos un peligro potencial.",  //84
        "Yo solo era un trollcito inocente que solo buscaba jugar...",  //85
        "No éramos una tribu bélica...",  //86
        "Pero con el paso del tiempo fuimos forzados a serlos...",  //87
        "Estalló una guerra... dimos el primer movimiento... grave error...",  //88
        "Pocos se unieron a nuestro bando...",  //89
        "Y éramos nosotros contra el bosque entero...",  //90
        "Era pequeño y no era consciente de la situación.. solo recuerdo que mi madre hizo hasta lo imposible por escondernos...",  //91
        "Y cuando terminó la guerra... fue una masacre en ambos bandos...",  //92
        "Y de mí especie quedaos muy pocos...",  //93
        "Pero poco a poco nos cazaban por rencor...",  //94
        "Así que tomé la decisión de atacar el talón de Aquiles de este bosque...",  //95
        "El mana... si me arrebataron todo... porque yo no a ellos?",  //96
        "Supongo que... ahora están pagando las consecuencias de mis acciones...",  //97
        "Pero tú... me has hecho dudar...",  //98
        "¿Y si todavía queda algo en mí que valga la pena?",  //99
        "El troll se pone de pie lentamente, y por primera vez no parece una amenaza, sino... un soldado cansado.",  //100
        "...",  //101
        "Muy bien, humano.",  //102
        "No te lo diré dos veces...",  //103
        "Tienes mi respeto.",  //104
        "Y mi promesa.",  //105
        "Ya no consumiré más mana.",  //106
        "Y si el resto de especies aceptan mi perdón...",  //107
        "Seré yo quien vele por la seguridad del bosque ahora...",  //108
        "He hecho mucho daño, tanto yo como mis ancestros...",  //109
        "Y aunque nosotros solo nos defendimos...",  //110
        "Tomamos pésimas decisiones que nos llevaron a la extinción...",  //111
        "Y casi nos llevamos al bosque con nosotros...",  //112
        "Y... si no me perdonan...",  //113
        "Lo aceptaré... y me marcharé del bosque...",  //114
        "Bien humano...",  //115
        "Se da la vuelta, y empieza a abrir unas lianas de mana.",  //116
        "No se si esto te ayude... ",  //117
        "Le otorga 2 frutos",  //118
        "Las últimas reliquias de mi familia...",  //119
        "Como símbolo de que es posible un nuevo comienzo, te entregaré una de ellas...",  //120
        "Una fruta que potenciará el límite de tu HP...",  //121
        "Otra que potenciará tu capacidad de MANA...",  //122
        "Una pierza para armadura de Troll reforzada... es algo grande pero puedo encogerla.",  //123
        "Y un arma Troll... es pesada pero tu fuerza será imparable...",  //124
        "Tu decides...",  //125
    //OPCION
        "Que así sea...", //126
        "Bien... ahora humano... llevame con aquellos seres", //127
        "Y conviértete en el mediador que lleve a la reconciliación del bosque.", //128
        "Y traiga una nueva era de paz...", //129
        "Sin más preámbulos... vamos... conozco un atajo...", //140
        "Se adentran en unas lianas huecas...", //141
        "No tardaran en llegar al punto de encuentro...", //142
        "Te sientes orgulloso de aprender el camino de la paz", //143
        "Aprendiste que la empatía puede romper ciclos de odio. El perdón es un riesgo... pero a veces es el primer paso hacia un futuro mejor.", //144
        "Te reencuentras con los slimes", //145
        "Vaya... lo lograste...", //146
        "El MANA ha regresado y nos sentimos vivos nuevamen...", //147
        "Un sentimiento de disforia lo llena", //148
        "Cree estar soñando pero mira de pies a cabeza al troll", //149
        "¿Qué hace él aquí??", //150
        "Porque traes a nuestro enemigo?", //151
        "Eh... yo solo vine a...", //152
        "Calla!", //153
        "Nos has atormentado por generaciones!", //154
        "Y te deberíamos creer que vienes pacificado?", //155
        "TE PIDO QUE TE LAR...", //156
        "Lo amenazas y lo detienes", //157
        "Q-Que crees que haces?", //158
        "¿Estas de su lado?", //159
        "Escucha pedazo de baba, estoy buscando las paces.", //160
        "El bosque no puede seguir dividido a estas alturas...", //161
        "Y... aprendí las acciones y mis consecuencias...", //162
        "Yo... tomé conciencia por las mala de la situación que les hice pasar...", //163
        "Y vine aqui de rodillas a importarles perdón...", //164
        "...", //165
        "Si realmente vamos a discutir esto.", //166
        "Y tu perdón es sincero...", //167
        "Podemos llegar a un acuerdo...", //168
        "Hagamoslo en privado.", //169
        "Solo si él es el mediador.", //170
        "... como quieras.", //171
        "Ustedes 3 entran en una sala privada", //172
        "Todos esperan con ansias finalmente un tratado de paz", //173
        "Pasó la hora y finalmente llegaron a un acuerdo", //174
        "Bien escuchen...", //175
        "Hoy... es un día especial.", //176
        "Nuestros antepasados han dividido al bosque en facciones por mucho tiempo.", //177
        "Y nosotros pagamos esas consecuencias...", //178
        "No estoy contento de esta decisión... pero si es por el bien de ustedes.", //179
        "Hoy declaro la paz y la unidad completa del bosque.", //180
        "Cada especie dentro de este bosque compartiremos un mismo territorio.", //181
        "Y se les reconocerán sus derechos.", //182
        "Y quien perturbe la paz... Nuestro nuevo aliado será quien tome las riendas del destino y vele por la paz del bosque.", //183
        "Hoy troll lo declaró oficialmente guardián del bosque.", //184
        "un antiguo enemigo... que logró redimirse y convertirse en un potencial aliado.", //185
        "Yo juro lealtad a este bosque bendito.", //186
        "Y maldito sea quien perturbe sus aguas.", //187
        "Que provoque el despertar del protector de este santuario.", //188
        "Y todo eso fue gracias a ese chico.", //189
        "Te mereces nuestro respeto.", //190
        "Sin tu ayuda... esto hubiese seguido por generaciones...", //191
        "Hasta que alguno de los dos hubiese caído rendido.", //192
        "Y gracias a tí también y al troll, por abrir la fuente y llenar nuevamente de vida al bosque...", //193
        "Que antes solo era un sueño lúcido volver a verlo en su esplendor...", //194
        "Sin ninguna otra palabra más que decir... vivan con energía esta nueva etapa en sus vidas...", //195
        "Todos celebran y van a comer", //196
        "Gracias chico... me diste una nueva oportunidad de ver la vida...", //197
        "Estaba muy solo... y el rencor me cegó esta luz.", //198
        "Bien... debo volver a mi puesto. Esperaré con ansias el día en que nuestros caminos se crucen de nuevo.", //199
        "Se despiden y chocan codos como hermanos", //200
        "Mientras te alejas te topas con la chamana", //201
        "Hey chico... les has hecho un enorme favor.", //202
        "Me imagino que no quieres respetos y títulos honorarios como recompensa final eh?", //203
        "Así que yo misma quiero recompensarte.", //204
        "No solo por rescatarme... sino porque salvaste y cambiaste el destino de muchas vidas incondicionalmente.", //205
        "¿Será porque lo hiciste por voluntad propia?", //206
        "O... porque alguien externo de buen corazón busco tu felicidad y la de otros?", //207
        "O porque...", //208
        "Ese alguien busca solo busca primero ver el final feliz...", //209
        "Para luego...", //210
        "Tener la curiosidad morbosa de que hubiera pasado si tomabas la decisión incorrecta...", //211
        "Enserio crees tener el control total de tus hilos... {Playername}?", //212
        "...", //213
        "...", //214
        "...", //215
        "HAHAH bromeaba.", //216
        "¡Tuviste que ver tu cara de perplejo!", //217
        "hay espera que recobre el aliento...", //218
        "Ufff...", //219
        "Bueno.. hablando enserio...", //220
        "¿Cómo quieres que te recompense?" //221
    
        // OPCION

        //beso
        "!!!", //222
        "EH???", //223
        "...", //224
        "HAHAHAH...", //225
        "Soy chamana, pero no tuve que usar ningún hechizo para que caigas en mis encantos??", //226
        "Anda..", //227
        "Se acerca lentamente y le da un beso en la mejilla", //228
        "Para que no tengas cara de pringao.", //229
        "Si nos conocemos mejor, quizás te dé una oportunidad... si es que esas son tus intenciones.", //230
        "...", //231
        "O acaso alguien movió sus hilos para saber qué respondería {Playernae}??", //232
        "...", //233
        "Solo bromeaba de nuevo tonturro.", //234
        "Bien... oye tampoco quiero que te vayas con las manos vacías.", //235
        "Toma.", //236
        "Te dan 3 bananas" // 237
        "No se porque las guardo... o porque las tengo... espero que te sean útiles.", //238
        "eso creo... espero nos sienta ese olor raro", //239
    
        //magia
        "Bien, como agradecimiento acepta uno de mis obsequios.", //240
        "Elige bien:" //241

    // OPCION

        "Bien.. que así sea.", //242
        "Cierra sus ojos y...", //243
        "Ω, θεοί του Ολύμπου, ακούστε τις προσευχές μου... Ω, ευλογημένος Δίας, δώσε στον γιο σου το δώρο που λαχταρά και λούστε τον στη θεϊκή σου πληρότητα.", //244
        "Un aura comienza a rodearte y te sientes lleno de vigor", //245
        "Aceptas el regalo" //246

    // OPCION
        "Y bien, no tienes un lugar  donde ir?", //247
        "O quieres ir a mi casa?", //248
        "Ni lo sueñes.", //249
        "No es que quiera.", //250
        "Bien podría invitarme a tomar té.", //251
        "Pero... literalmente vivo en un arbusto.", //252
        "La inflación está muy fuerte estos días...", //253
        "Tampoco creas que por ser chamana debería crear dinero...", //254
        "Eso es ilegal sabes...", //255
        "En fin... deberías volver.", //256
        "Este juego ya necesita más acción que charla.", //257
        "Y no hablo de esa hacer esa acción pillo.", //258
        "¿Quieres que te convierta en rana?", //259
        "No sentir remordimiento", //260
        "Anda cariño, tenemos trabajo que hacer.", //261
        "Haz hecho mucho por nosotros hoy...", //262
        "Y se notará tu ausencia...", //263
        "Pero... espero que nos volvamos a reencontrar.", //264
        "Te agarra de la mano", //265
        "Y... ten cuidado por favor con desafiar a los que están en la cima.", //266
        "Hay signos de que un cataclismo se avecina...", //267
        "No debes provocar a aquellos capaces de sumir este mundo en la oscuridad eterna.", //268
        "Creo... No... Sé que eres capaz de todo.", //269
        "Pero sé precavido ok?", //270
        "No nos gustaría perderte...", //271
        "En especial yo...", //272
        "Y... por favor... sigue el buen camino.", //273
        "Yo soy y seré consciente de cada acción que tomes...", //274
        "Si te desvías... yo... no sé si pueda vivir para presenciar en lo que te puedas convertir.", //275
        "Pero confío en ti...", //276
        "No quiero perder esta versión de ti.", //277
        "Y dime, ¿extrañarás?", //278
        "Espero que no te apegues mucho a esa tal Naika, vale?", //279
        "Sepa Zeus como sabe de su existencia", //280
        "suelta tu mano", //281
        "Te das cuenta que todos te empezaron a rodear", //282
        "Cuidate, tienes una misión que cumplir.", //283
        "estás algo confundido de qué misión habla", //284
        "Adiós... {Player name}", //285
        "Adios hermano.", //286
        "¡Visítanos pronto!", //287
        "Te recibiré en mi palacio con los brazos abiertos.", //288
        "s-señor... aún no tiene palacio...", //289
        "Oh- B-bueno... mi futuro palacio.", //290
        "Te despides de cada uno", //291
        "Solo te volteas atrás y vuelves a tu hogar con la vista de frente", //292
        "Pero con un sentimiento de... felicidad pura.", //293
        "De camino a casa... no recuerdas el camino", //294
        "Notas un sendero y decides seguirlo", //295
        "Pero en cuanto lo pisas... se rompe en pedazos...", //296
        "Caes en su agujero muy profundo", //297
        "Te golpeas y pierdes la conciencia" //298
    };

    int option_route = 0, option_geno = 0; // quemar numero para evitar que en switch se añada un valor basura
    bool Help = false, Kill = false, Return = false, Proceed = false;

    string Py = "\033[3m";
    string Es = "\033[36mSlime:\033[0m"; // color ansi cian
    string KS = "\033[33mRey Slime:\033[0m"; // amarillo
    string Cm = "\033[35mChamana:\033[0m"; // magenta
    string Tro = "\033[32mTroll: \033[0m"; // verde

    for (int i = 0; i < 9; i++){
        cout << Py;
            PrintWithPause_F(forestIntro[i], 20);
            LongPause_F(1000);
            cout << endl;
            PtC();
            cout << "\033[0m";
        Clear();
    }
    EliteSBattle(p, S);
}