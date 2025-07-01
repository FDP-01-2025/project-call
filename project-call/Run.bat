@echo off
g++ -Isrc main.cpp ^
src/Dialogues/Prologue/Prologue.cpp ^
src/Dialogues/Training/Training.cpp ^
src/Battles/Tutorial/Tutorial.cpp ^
src/Data/PlayerData/PlayerData.cpp ^
-o Run.exe

pause