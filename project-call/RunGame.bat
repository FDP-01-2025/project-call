@echo off
echo Compilando...

g++ -Isrc main.cpp ^
src/Dialogues/Prologue/Prologue.cpp ^
src/Dialogues/Training/Training.cpp ^
src/Battles/Tutorial/Tutorial.cpp ^
src/Data/PlayerData/PlayerData.cpp ^
src/Data/NaikaData/Naika.cpp ^
src/Data/NaikaDummy/NaikaDummy.cpp ^
src/Battles/NaikaDummy/NaBatlle.cpp ^
-o Run.exe

if %errorlevel% neq 0 (
    echo Error al compilar. Verifica el código.
    pause
    exit /b
)

echo Compilación exitosa. Ejecutando el juego...
Run.exe

pause