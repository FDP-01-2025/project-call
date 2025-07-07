#include <iostream>
#include <windows.h>
#include "BattleUtils/BattleUtils.h"
#include "Data/PlayerData/PlayerData.h"
#include "Battles/GolemBattle/GolemFight.h"
using namespace std;

void PrintWithPause_Cv(const string& Text, int Pause){
    for (char c : Text) {
        cout << c;
        Sleep(0); // 0 para lectura instantanea.  // "Pause" to normal
    }
}
void LongPause_Cv(int MiliSeconds){
    Sleep(0); // 1000 para pausa larga.  // "MiliSeconds" to normal
}
void CaveDialogue(Player& p, Golem& Gol){
    string CaveDialogue[] = {
        //DESPERTAR
        "Cobras consciencia...", // 0
        "Despiertas algo herido...", // 1
        "Apenas recobraste la consciencia, te encuentras en un lugar oscuro y frío, con un dolor agudo en todo el cuerpo.", // 2
        "Tomas conciencia de tu entorno, te encuentras en una cueva profunda y oscura.", // 3
        "Cómo pasaste de un lugar con vida... hasta este lugar de penumbras?", // 4
        "Te levantas como puedes y no tienes otra opción más que avanzar*.", // 5
        "Por suerte descubres que tu mana es bioluminiscente y haces uso de él para iluminar el camino.", // 6
        "Caminas y descubres un camino.", // 7
        "Te adentras en la cueva, el camino es largo y peligroso, pero no tienes otra opción más que avanzar.", // 8
        "Vez piedra caliza por toda la cueva.", // 9
        "Excelente material para reforzar armas.", // 10
        "Lo usas y tu daño aumenta, +10 ATTACK.", // 11
        "Avanzas y notas algo...", // 12
        "El suelo comienza a temblar...", // 13
        "Las rocas se mueven...", // 14
        "Piensas que la cueva colapsara...", // 15
        "Corres pero de pronto una gran muralla de piedra bloquea tu salida.", // 16
        "Y detrás tuya se engendra un poderoso golem de piedra.", // 17
        "Y con una potente voz gruesa solo dice...", // 18
        "Intruso.", // 19
        "Yo proteger maestro.", // 20
        "Quedarte sin mana es una sentencia de muerte ahora.", // 21
        "Pero no tienes más remedio que luchar...", // 22

        /// BATALLA CON GOLEM
        "Tu pasar prueba.", // 23
        "Estas desconcertado de porque te mostro piedad.", // 24
        "Y escuchas una voz al fondo y pasos venir hacia tu dirección.", // 25
        "Te pones en guardia.", // 26
        "Y logras ver a una figura muy anciana y con una larga barba blanca.", // 27
        "Hey pequeño demonio de piedra otra vez estas peleando con escarabaj...", // 28
        "Noto tu presencia.", // 29
        "Oh, estoy soñando?", // 30
        "No, tu despierto maestro.", // 31
        "Humano pasar prueba.", // 32
        "Oh... así que nos volvemos a ver después de 500 años amigo mio.", // 33
        "500... años dijo?", // 34
        "Oh lo siento, no nos presentamos.", // 35
        "Mi nombre es Alkeos.", // 36
        "Y creo que ya conoces a mi amigo.", // 37
        "Hola.", // 38
        "No se como llegaste hasta este punto chico.", // 39
        "Pero no sabes lo feliz que estoy de volver a vernos.", // 40
        "Debes estar muy confundido ahorita misma, ven pasa pasa deja que te explique todo.", // 41
        "Te prepara un té y te recuestas en lo que parece una silla de piedra, pero muy cómoda.", // 42
        "Bien, dime de donde eres.", // 43
        "Le cuentas toda tú historia.", // 44
        "Ya veo... has pasado por mucho chico.", // 45
        "Y por lo visto aún no has despertado el poder que corre por tus venas.", // 46
        "Veo que sigues confundido, no se si piensas que estás inconsciente aún por la caída.", // 47
        "Dejame presentarme nuevamente.", // 48
        "Como mencione soy Alkeos, un antiguo Caballero Blanco de hace 5 siglos.", // 49
        "No te suena? Bueno chico acomodate porque estaremos aquí un buen rato.", // 50





        //DORMIRTE
        "Solo cierras los ojos del sueño.", // 51
        "Te despiertas.", // 52

        //ESCUCHAR
        "Sabes, niño... aún no te has preguntado cómo se creó el mundo en el que estás parado", // 53
        "¿verdad?.", // 54
        "Si conoces la historia, quizás ya sepas parte de la verdad.", // 55
        "Pero lo que voy a contarte... es mucho más antiguo que cualquier libro.", // 56
        "Cuenta la leyenda... que el mundo nació de un caos primordial, un vacío eterno sin forma ni nombre.", // 57
        "Y de ese caos... surgió Gea, la Tierra, la madre de todo lo que existe.", // 58
        "Gea no fue creada. Simplemente... despertó.", // 59
        "Y al abrir sus ojos, la existencia comenzó a tomar forma.", // 60
        "Ella es considerada la deidad primordial de la vida, la materia y la fertilidad.", // 61
        "Fue Gea quien dio origen a los primeros dioses... y más adelante, a los humanos.", // 62
        "Pero Gea no estaba sola por mucho tiempo.", // 63
        "De su esencia nació Urano, el vasto cielo estrellado... y se convirtió en su esposo.", // 64
        "Juntos, Gea y Urano engendraron a la primera generación de seres colosales.", // 65
        "Los Titanes, los Cíclopes y los Hecatónquiros.", // 66
        "Cada uno de estos hijos fue forjando parte del mundo tal como lo conoces.", // 67
        "Fuego, mar, montaña, tiempo... poder.", // 68
        " Pero los Titanes, liderados por Cronos, se rebelaron contra su padre Urano al ser estos maltratados por él.", // 69
        "Lo destronaron... y así, comenzó el ciclo de los dioses que devoran a los dioses.", // 70
        "Eventualmente, uno de los hijos de Cronos... Zeus... se alzó contra él.", // 71
        "Y tras una guerra divina, los dioses del Olimpo tomaron el poder.", // 72
        "Zeus... el rey de los cielos, el relámpago encarnado.", // 73
        "La máxima deidad entre todos los dioses.", // 74
        "Junto a su esposa Hera, la diosa del matrimonio. Se alzó como el soberano supremo... y desde lo alto, gobernó los cielos.", // 75
        "A sus hermanos también se les concedieron dominios.", // 76
        "Cada uno con un poder igual en magnitud... pero distinto en esencia.", // 77
        "Poseidón, señor de las tormentas marinas, recibió el control de los siete mares.", // 78
        "Dueño de las profundidades, temido por navegantes y bestias del océano.", // 79
        "Y luego está Hades... el dios de los muertos y gobernante del inframundo.", // 80
        "El más temido de los tres.", // 81
        "El que aceptó reinar donde ningún otro se atrevía, pero con rencor.", // 82
        "Hades, guardián del inframundo, señor de los muertos.", // 83
        "Gobierna en las sombras, donde las almas van a rendir cuentas.", // 84
        "Todo estaba en orden.", // 85
        "Y durante milenios la humanidad progresaba a su manera, era el entretenimiento y experimento de los dioses.", // 86
        "Cada uno de los 3 dioses aceptó su rol... o al menos por un tiempo.", // 87
        "Tanto Poseidón como Hades envidiaban la tierra tan vasta y rica que Zeus les dio a seres tan inferiores.", // 88
        "Hades no está solo en el Inframundo, sino aislado, temido y olvidado por los humanos.", // 89
        "La envidia no es solo por la tierra, sino por el amor y la devoción que los humanos dan a Zeus.", // 90
        "Mientras que Poseidón, aunque es venerado por marinos, ve su dominio como un reino inestable, furioso, inabarcable, y lleno de muerte.", // 91
        "Desea y quiere experimentar el poder de crear y ser adorado en tierra firme.", // 92
        "Mientras que Hades y Poseidón tienen dominios que no crecen ni cambian. ", // 93
        "Los cielos y la tierra, en cambio, progresan, florecen y evolucionan con los humanos.", // 94
        "Y entre susurros antiguos... se decía que quien dominara la tierra, dictaría el destino del Olimpo.", // 95
        "En ese tiempo todos anhelaban poder.", // 96
        "Estos no solo eso fueron los factores para la envidia de sus hermanos.", // 96
        "Con el tiempo, Zeus se volvió más distante, incluso arrogante.", // 97
        "Así que un día fueron a reclamar lo que creían justo.", // 98
        "Pero Zeus los despreció con una sonrisa. -Ya tienen sus dominios-, dijo.", // 99
        "Como si fueran bestias a las que se les lanza un hueso.", // 100
        "Aquella respuesta no los enfureció de inmediato...", // 101
        "Pero lo que quebró todo fue cómo Zeus los trataba desde entonces.", // 102
        "No como hermanos... sino como simples extraños.", // 103
        "Esa fue la chispa que incendió su odio.", // 104
        "Y si Zeus no iba a ceder por las buenas...", // 105
        "Entonces lo harían por las malas.", // 106
        "Cada uno lideró un ejército. Y los cielos, los mares y la tierra se tiñeron de sangre.", // 107
        "A ese cataclismo... se le llamó la Gran Guerra Santa.", // 108
        "Y bueno, como era de esperarse Zeus se alzó con la victoria.", // 109
        "Logró sellar a sus propios hermanos. Fue una victoria agridulce.", // 110
        "Pero la guerra dejó cicatrices profundas en el mundo.", // 111
        "Y quienes se llevaron la peor parte fueron los humanos.", // 112
        "Ante tal evento estuvimos al borde de la extinción.", // 113
        "Y como si todo aquello no bastara... Zeus desapareció.", // 114
        "Abandonó este plano sin explicación. Sin advertencia.", // 115
        "Algunos dicen que se cansó del mundo... otros, que teme lo que él mismo desató.", // 116
        "Nos dejó a nuestra suerte.", // 117
        "Y así, los humanos quedaron solos, sin guía, sin protección.", // 118
        "Los humanos de aquel entonces estaban en un estado muy vulnerable.", // 119
        "Era sobrevivir o morir.", // 120
        "Así que Zeus antes de abandonar este plano nos regaló unas reliquias de invaluable valor...", // 121
        "Las armaduras blancas.", // 122
        "Armaduras hechas en los mismos cielos con la energía del sol.", // 123
        "Eran de un color Blanco puro.", // 124
        "Con estar cerca de ellas el sentimiento de paz era instantáneo.", // 125
        "Pero... Solo los de corazón noble y con una alta determinación tenían la capacidad de portarlas.", // 126
        "Y fue así como se fundó la orden de los caballeros blancos.", // 127
        "Una orden donde solo unos pocos fueron elegidos para proteger a la humanidad.", // 128
        "Y solo pasaron unos milenios para se empezaran a resquebrajar los sellos de los dioses caídos.", // 129
        "El primero en despertar fue Poseidón, el dios del mar.", // 130
        "Pero a diferencia de Hades, él fue precavido, era consciente del poder de los humanos ahora. Y decidió esperar.", // 131
        "Pero Hades... él no fue tan paciente.", // 132
        "Iba a hacer hasta lo imposibe por luchar por lo que el consideraba justo.", // 133
        "Cuando su sello fue roto los cielos se tornaron de oscuridad.", // 134
        "Y de las profundidades del inframundo surgió un ejército de muertos y espectros liderados por dicho dios.", // 135
        "Pero la humanidad ya estaba preparada para cualquier desafío.", // 136
        "Hades era poderoso.", // 137
        "Nos estábamos enfrentando a un dios.", // 138
        "Pero no creas que Zeus nos dio únicamente las armaduras blancas.", // 139
        "Su nombre... era Magnus.", // 140
        "Ese mismo magnus que ustedes lo han idolatrado y aparece en cada libro de historia.", // 141
        "El mismo Magnus que creo un imperio tan vasto que abarcaba desde toda grecia hasta la india.", // 142
        "Y Magnus no estaba solo, tenía a su lado a la generación de caballeros blancos más poderosos que jamas haya pisado la tierra...", // 143
        "Juntos, formaron un ejército imparable que desafió a Hades y su oscuro dominio.", // 144
        "con un líder nato a la cabeza fuimos capaces de sellar a Hades... por segunda vez.", // 145
        "Lo logramos...", // 146
        "No solo salvamos a la humanidad.", // 147
        "Logramos algo que cambio por completo el curso de la historia.", // 148
        "Le arrebatamos su arma divina. \033[31mÉl Devoraalmas\033[0m.", // 149
        "Un arma tal que tiene la capacidad de asesinar dioses.", // 150
        "Pero aunque nos hicimos con ella...", // 151
        "Nadie fue capaz de blandirla. Ni siquiera moverla.", // 152
        "Se dice que su densidad es capaz de rivalizar con la de una estrella.", // 153
        "Pues al contrario de las armaduras blancas.", // 154
        "Solo seres con un corazón tan vacío y oscuro como el de \033[35mNyx\033[0m, diosa primordial de la noche, podrían empuñarla.", // 155
        "Incluso entre los dioses, solo Ares... y el mismísimo Hades... fueron capaces de dominarla en su totalidad.", // 156
        "Para que un humano pueda alzarla... tendría que abandonar todo rastro de su humanidad.", // 157
        "Pero...", // 158
        "No pasó ni la hora y tal arma mítica se esfumó sin motivo aparente...", // 159
        "No dejó ni un rastro de su majestuosa presencia.", // 160
        "como si ya no perteneciera a este plano.", // 161
        "Y no había ninguna posibilidad que alguien la robara siquiera...", // 162
        "Algunos se preguntan por qué Hades no ha logrado llamarla...", // 163
        "Pero las armas divinas, chico... tienen voluntad propia.", // 164
        "La Devoraalmas no busca simplemente a un dios... busca a quien tenga el poder para destruir sin pestañear.", // 165
        "Y parece que... dicha arma podría tener ya un candidato en mira... un ser más destructivo que el mismo Hades?. Nadie lo sabe.", // 166
        "Pero al menos sin tal arma Hades ya no estará en su máximo esplendor.", // 167
        "Lo tendríamos más fácil.", // 168
        "O eso creíamos.", // 169
        "Aún está la gran incertidumbre del paradero del Devoraalmas.", // 170
        "Siquiera sabemos si aún existe...", // 171
        "Hades es una amenaza latente...  el regreso del nuevo portador de la Devoraalmas será quien sentencie nuestra especie.", // 172
        "Como derrotaremos a un ser que ni siquiera sabemos como se llama, o donde se encuentra?", // 173
        "Pero en ese entonces poco importaba.", // 174
        "al menos de momento lograron sellar a Hades...", // 175
        "Pero solo su cuerpo...", // 176
        "No lograron hacerse con su alma inmortal.", // 177
        "Hades si bien nos subestimó. Él estaba más preparado de lo que creíamos.", // 178
        "Como los humanos somos fruto del poder de un dios... también éramos vulnerables a ser controlados por estos.", // 179
        "Y como magnus era un recipiente único con tales habilidades.", // 180
        "Fue objetivo esencial de Hades.", // 181
        "Magnus poco a poco fue cayendo en la influencia del Hades.", // 182
        "Hades moldeaba la mente de Magnus, lo hacía con tal cautela que cuando sus efectos comenzaban a aparecer se creía que padecía de una enfermedad", // 183
        "Hades no lo corrompió de un día para otro, fue un veneno lento.", // 184
        "Cada día se volvía más agresivo, arrogante, orgulloso, narcisista y ambicioso.", // 185
        "Y era el objetivo de Hades.", // 186
        "Usar una figura de tal poder político para destruir a la humanidad desde dentro.", // 187
        "Destruir su sociedad.", // 188
        "Hay que admitir que Hades era inteligente.", // 189
        "Buscaba debilitarnos para que en su próxima guerra fuese capaz de lograr sus objetivos.", // 190
        "Y bueno, no hace falta decir que le deparo a a Magnus.", // 191
        "Al ya no ser un alma bondadosa... su armadura ya no lo iba a considerar digno.", // 192
        "Aunque no detectan el cambio de alma de inmediato.", // 193
        "Esta se volvió muy pesada progresivamente.", // 194
        "Y cuando su alma dejó de ser bondadosa... la armadura lo abandonó.", // 195
        "Así que Magnus ya era exponencialmente más débil ahora.", // 196
        "Y sumándole su mala fama que formó.", // 197
        "Fue la oportunidad perfecta para sellarlo.", // 198
        "Su hijo Magnus II, que ya no toleraba la tiranía de su padre.", // 199
        "Lideró a los caballeros blancos para derrocarlo y usurpar el trono.", // 200
        "Actualmente Magnus esta sellado", // 201
        "Pero al no ser un dios jamás escapará de su prisión.", // 202
        "Los magos responsables de sellarlo, lograron también descifrar que Hades aún siendo contenido por el sello, aún era capaz de influir en la mente.", // 203
        "Y desde entonces han ido monitoreando a humanos potencialmente fuertes.", // 204
        "Y bueno, su hijo fue coronado y su Dinastía persiste por años.", // 205
        "Es increíble el legado que dejaron ambos...", // 206
        "También la humanidad vio patrones, ciclos de Retorno, tanto de Hades como del nacimiento de un nuevo Gran humano vuelven en periodos de 500 años.", // 207
        "Pasaron 5 siglos y preambulos y señales ya daban indicios de que Hades estaba a punto de despertar.", // 208
        "Y como era de esperarse, un gran humano nació nuevamente.", // 209
        "Pero claro, no sabían quien podria serlo.", // 210
        "Pero la humanidad ya desconfiaba de su presencia.", // 211
        "Con el pasar de los años ya comenzaban a sospechar de posibles candidatos.", // 212
        "En especial de uno... Ese humano se llamaba Azael.", // 213
        "Con 15 años ya era un prodigio de la espada, con una fuerza y velocidad sobrehumana.", // 214
        "Consiguió mucho prestigio... pero ya estaba en la mira tanto de Hades como de los magos.", // 215
        "Se volvió un general Ateniense a muy corta edad.", // 216
        "Y cuando despertó Hades por segunda vez, fue sellado nuevamente.", // 217
        "Y bueno... como ya dije fuí un caballero blanco... luche junto a él", // 218
        "Pero ya sabemos qué pasó con Magnus.", // 219
        "Temía que le sucediese lo peor...", // 220
        "Y me encomendaron de su supervisión.", // 221
        "Era un chico muy gentil, amable y empatico con las personas...", // 222
        "Incluso se iba a casar con una hermosa mujer.", // 223
        "éramos grandes amigos.", // 224
        "Ó lo fuimos...", // 225
        "Hasta que comenzó a cambiar progresivamente." // 226
        "Azael ya comenzó a sentir pesada la armadura... primera advertencia.", // 227
        "Cuando su actitud amable y empática cambió a una morbosa y fría... fue una segunda advertencia.", // 228
        "Y cuando descubrió que le encantaba torturar prisioneros de guerra.", // 229
        "Ordenamos su ejecución... antes que sea demasiado tarde...", // 230
        "Me costo ver como decapitaban... a mi mejor... amigo.", // 231
        "Pero teniamos que poner en primer plano la vida de las personas.", // 232
        "Años después de la muerte de Azael decidí retirarme como caballero y me mude a este bosque.", // 233
        "Deje atrás a mis compañeros y mi armadura.", // 234
        "Sin imaginar que sería la última vez que los vería...", // 235
        "Por libros solo se que ocurrieron varios eventos que dieron por disuelta la orden.", // 236
        "Ya nadie sabe del paradero de ninguna armadura.", // 237
        "Pero... a mi es lo que menos me importaba.", // 238
        "Este tiempo estaba en armonía y viví mi retiro con el ambiente y es en lo que más pensaba.", // 239
        "Llegue a presenciar slimes muchas generaciones de slimes, trolls y otras especies.", // 240
        "Me dedicaba a estudiarlos.", // 241
        "Y bueno... un día de estos caí en esta cueva...", // 242
        "Si bien tenía una gran capacidad de mana mi cuerpo ya no estaba en condiciones para subir la cueva...", // 243
        "Mi muerte estaba sentenciada.", // 244
        "Hasta que explore la cueva y me tope con mi amigo golem...", // 245
        "Me ataco y pues fue una batalla muy ardua.", // 246
        "Pero logré derribar sus piernas.", // 247
        "Dijo que era digno.", // 248
        "Pero de que?", // 249
        "Segui con la cueva y encontré lo que parecía ser un pequeño charco de sangre.", // 250
        "No tardé en identificar que era porque estudiaba.", // 251
        "Era sangre de Titán.", // 252
        "Que como mencione fueron engendrados por Gea y Urano.", // 253
        "Los Titanes, seres majestuosos que alguna vez lucharon para tener el control del olimpo.", // 254
        "La guerra llamada la titanomaquia, que luego de su derrota. Fueron encerrados al tártaro junto a su líder Cronos.", // 255
        "Pero se sabía que en la lucha tanto la sangre de dioses como de los titanes se derramó sobre la tierra.", // 256
        "Y quien lo tome tendría la inmortalidad. ", // 257
        "Pero la sangre derramaba se filtraba muy rápido en la tierra.", // 258
        "Y por lo que estudie, dicha sangre tiene voluntad propia.", // 259
        "Y tal sangre creo este golem para proteger dicha fuente.", // 261
        "Pero para mi infortunio era morir en esta cueva o vivir por milenios con este cuerpo.", // 262
        "Y soy un apasionado por el estudio.", // 262
        "Me dije que si moría iba a perder toda la historia que podía seguir creándose.", // 263
        "Así que la tome.", // 264
        "Fue horrible, me desmayé del dolor que provoco eso... desperté con tal habilidad.", // 265
        "Y bueno te preguntaras porque no salí de esta cueva?", // 266
        "Bueno... la inmortalidad no es una bendición si el mundo allá afuera ya no te necesita.", // 267
        "Aquí tengo libros, paz, y a mi amigo Golem.", // 268
        "Y sabes... a veces es mejor estudiar la historia... que seguir escribiéndola.", // 269
        "Pero esto no quiere decir que haya intentado salir.", // 270
        "Después de varios años y mejorando mis técnicas de maná junto al Golem logre crear una magia primitiva de teletransportación.", // 271
        "Pero el problema es que tal magia tiene 2 grandes defectos.", // 272
        "Primero no puedo elegir el destino.", // 273
        "Apareces donde la magia decida enviarte o al menos en cierto radio del punto de destino. Es algo atemporal esto.", // 274
        "Y segundo... no es instantánea.", // 275
        "Puedes desaparecer en un segundo... y reaparecer en tu destino dentro de días, semanas o meses...", // 276
        "Con semejante incertidumbre... preferí quedarme aquí.", // 277
        "Gracias a la magia de teletransportación puedo tomar prestados, no robados, libros para no aburrirme.", // 278
        "Osea tardan mucho pero siempre aparecen cuando duermo.", // 279
        "Las veces que me cae uno mientras duermo y despierto por ello.", // 280
        "Y tengo compañía, no necesito dormir, ni comer, ni beber...", // 281

        //SIGUE AQUI
        "Pero en tu caso...", // 282
        "No quieres el mismo destino...", // 283
        "Pero descuida. puedo sacarte de aquí, si aceptas el riesgo...", // 284
        "Bueno muchacho tienes suerte de que Hades no sepa de tu ubicación.", // 285
        "Pero sabe de tu existencia.", // 286
        "No vayas por favor por el mal camino o te encontrarás muy fácil.", // 287
        "Hades regresará muy pronto.", // 288
        "Y romperá el sello.", // 289
        "Pero eso traería consecuencias devastadoras...", // 290
        "Por eso... tendrás que ir a los Campos Elíseos para acabar con él frente a frente...", // 291
        "¿Que cómo lo harás?", // 292
        "No lo sé, pero quizás alguien sí...", // 293
        "¿Recuerdas el sello de magnus?", // 294
        "Su sello está en el Monte Olimpo, al Suroeste de la ciudad de Salónica.", // 295
        "Nadie que no sea un Dios, un caballero blanco o un gran humano es capaz de romper un sello de tal poder...", // 296
        "Pero tú... podrás intentarlo...", // 297
        "Aunque lo mejor será que estés preparado.", // 298
        "No sabemos si aún está bajo la influencia de Hades...", // 299
        "O si se habrá debilitado...", // 300
        "Pero si logras apaciguarlo... pondrías sabes como ponerle fin al retorno de Hades.", // 301
        "Y chico... se una buena persona.", // 302
        "Mientras más oscuras sean tus acciones... más fácil será para Hades encontrarte.", // 303
        "Magnus y Azael mataron por proteger a los suyos... pero ese derramamiento de sangre los marcó.", // 304
        "Hades no necesita tu permiso... solo necesita verte, y poco a poco hará el resto.", // 305
        "Pero tú... aún estás a salvo. Tu alma sigue limpia.", // 306
        "Espero que nos volvamos a ver...", // 307
        "Bueno, este es el adios...", // 308
        "Fuiste una buena compañía por al menos una hora.", // 309
        "Pero tiene una misión por cumplir chico.", // 310
        "Ahora te teletransportarse a Atenas, o lo más cercano a ella...", // 311
        "Bien, no perdamos más el tiempo.", // 312
        "El mundo te necesita chico...", // 313
        "\033[3mEmpieza hacer el conjuro\033[0m", // 314

        //SALIR
        "Solo sientes como tu cuerpo se estira en el espacio tiempo", // 315
        "Es algo doloroso pero sientes que vas muy rápido a tu destino", // 316
        "Reapareces pero... estás en el aire?", // 317
        "Esto dolerá", // 318
        "Caes en picada...", // 319
        "...", // 320
        "Logras caer en un cúmulo de fardo al lado de una playa", // 321
        "Que... suerte?", // 322
        "Lo que importa es que estas bien...", // 323
        "Y tu problema es ahora donde estas...", // 324
        "Pero... lo reconoces... estas en Atenas nuevamente!", // 325
    };

    int option_sleep;
    bool Sleep = false;

    for (int i = 0; i < 23; i++){
        cout << (i == 19 || i == 20 ? "\033[35mGolemn: \033[0m":"\033[3m");
        PrintWithPause_Cv(CaveDialogue[i], 20);
        LongPause_Cv(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }

    p.ATTACK += 10; // sube 10 de ataque al aplicar piedra caliza.
    GolemBattle(p, Gol);

Clear();
    for (int i = 23; i < 51; i++){
        if (i >= 24 && i <= 29 || i == 24 || i == 34 ||i == 44){
            cout << "\033[3m";
        } else {
            cout << (i == 23 || i == 31 || i == 32 ||i == 38 ? "\033[35mGolem: \033[0m":"\033[34mViejo: \033[0m");
        }
        PrintWithPause_Cv(CaveDialogue[i], 20);
        LongPause_Cv(1000);
        cout << endl;
        cout << "\033[0m";
        PtC();
    Clear();
    }

    while (option_sleep != 1 && option_sleep != 2){
                cout << "Deseas mejor saltar su conversación?\n1. Dormirte\n2. Escuchar" << endl;
                cin >> option_sleep;
            if (option_sleep < 1 || option_sleep > 2){
                DefaultError();
        }
    }

Clear();
    switch (option_sleep){
    case 1:
        Sleep = true;
        break;
    case 2:
        Sleep = false;
        break;
    default:
        DefaultError();
        break;
    }

    if (!Sleep){
        for (int i = 53; i < 282; i++){
            cout << "\033[34mViejo: \033[0m";
            PrintWithPause_Cv(CaveDialogue[i], 20);
            LongPause_Cv(1000);
            cout << endl;
            cout << "\033[0m";
            PtC();
        Clear();
        }
    } else {
        cout << "\033[3m";
        for (int i = 51; i < 53; i++){
            PrintWithPause_Cv(CaveDialogue[i], 20);
            LongPause_Cv(1000);
            cout << endl;
            PtC();
        Clear();
        }
        cout << "\033[0m";
    }

    for (int i = 282; i < 315; i++){
            cout << "\033[34mViejo: \033[0m";
            PrintWithPause_Cv(CaveDialogue[i], 20);
            LongPause_Cv(1000);
            cout << endl;
            cout << "\033[0m";
            PtC();
        Clear();
        }
    cout << "\033[3m";
        for (int i = 315; i < 326; i++){
            PrintWithPause_Cv(CaveDialogue[i], 20);
            LongPause_Cv(1000);
            cout << endl;
            PtC();
        Clear();
        }
    cout << "\033[0m";
}