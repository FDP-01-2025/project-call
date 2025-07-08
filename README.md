[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# 📦 Ashes Of Olympus

## 🎮 Descripción del Proyecto

AshesOfOlympus es un RPG en consola ambientado en la mitología griega, donde enfrentas dioses y criaturas legendarias. Tendrás que elegir entre atacar, usar magia, hablar o mostrar piedad para derrotar a tus enemigos o perdonarlos.

## ⚙ Características Técnicas

- Lenguaje: **C++**
- Compilador: **MinGW / g++**
- Librerías utilizadas:
  - `<iostream>`
  - `<windows.h>`
  - `<ctime>`
  - `<fstream>`
  - `<algorithm>`
  - `<vector>`

## 🧩 Funcionalidades principales

- Sistema de combate por turnos (ataques, magia, defensa, piedad)
- Barra de vida y mana con colores
- Jefes con mecánicas únicas (como Hades, Cerbero, etc.)
- Checkpoint para reiniciar en caso de derrota
- diálogos para ambientar la historia 

## 🛠 Temas de programación aplicados

- **Variables y tipos de datos:**
  - Ejemplo: 
 ![Ejemplo de tipo de datos](/resources/Images/Variables%20.png)

- **Condicionales (if, else):**
  - Ejemplo: 
  ![Ejemplo de if, else](/resources/Images/If,%20else.png)

- **Bucles:**
  - Ejemplo: dibujar la barra de vida.
  ![Ejemplo de bucle](/resources/Images/For.png)

- **Funciones:**
  - Ejemplo: 
  ![Ejemplo de funciones](/resources/Images/Funcion.png)

- **Arrays / vectores:**
  - Ejemplo: guardar dialogos.
  ![Ejemplo de Array](/resources/Images/Array.png)


## 🖼 Mockups y ejemplo de pantallas

- Pantalla de combate con stats y comandos
![Ejemplo:](/resources/Images/Interfaz.jpg)
- Pantalla de "Game Over" con opción de continuar

## 📦 Requisitos mínimos

- **RAM:** 6 GB
- **Procesador:** Intel Pentium 400 MHz o superior
- **Espacio:** 200 MB

## ▶ Cómo compilar

```bash
cd ruta/al/proyecto
g++ -Isrc main.cpp src/Dialogues/Prologue/Prologue.cpp src/Dialogues/Training/Training.cpp src/Dialogues/Tutorial/Tutorial.cpp src/Data/PlayerData/PlayerData.cpp src/Data/NaikaData/Naika.cpp src/Data/NaikaDummy/NaikaDummy.cpp src/Battles/NaikaDummy/NaBattle.cpp src/Data/EliteSData/EliteSlime.cpp src/Battles/SlimeBattle/Sbattle.cpp src/Data/TrollData/Troll.cpp src/Battles/TrollBattle/TrollFight.cpp src/BattleUtils/BattleUtils.cpp src/Data/GolemData/Golem.cpp src/Battles/GolemBattle/GolemFight.cpp src/Data/NihilusData/Nihilus.cpp src/Battles/NihilusBattle/NihilusFight.cpp src/Data/KingMagnus/KingMagnus.cpp src/Battles/KMBattle/KMBattle.cpp src/Dialogues/DeepCave/Cave.cpp src/Dialogues/Forest/Forest.cpp src/Dialogues/AtenasCity/Atenas.cpp src/Data/HypnosData/Hypnos.cpp src/Battles/HypnosBattle/DHBattle.cpp src/Dialogues/Olympus/Olympus.cpp src/Dialogues/Sky/Sky.cpp src/Data/Hades_Data/Hades.cpp src//Battles/HadesBattle/HadesFight.cpp src/Dialogues/Underworld/Underw.cpp -o Run
```

> Sustituye `...` por los archivos `.cpp` del proyecto.

## 💾 Ejecución

```bash
.\'Run.exe'
```

## 🧑‍💻 Equipo

- **Nombre del equipo:** [Call of Coding]

### Integrantes del equipo

1. **Nombre completo:** [Ricardo Alexei Valle Avalos]  
   **Carnet:** [00080525]

2. **Nombre completo:** [Edgar Alejandro Ventura Zelaya]  
   **Carnet:** [00210925]

3. **Nombre completo:** [Carlos David Toledo Garcia]  
   **Carnet:** [00228725]

4. **Nombre completo:** [Herberth Ariel Tobar Sermeño]  
   **Carnet:** [00158525]


## 📂 Repositorio 

https://github.com/FDP-01-2025/project-call.git

## 🚀 Créditos y agradecimientos

Gracias al equipo por el esfuerzo, la inspiración de la mitología griega por hacer épico el proyecto.

---

> *AshesOfOlympus* — Proyecto académico para práctica de programación en C++.
