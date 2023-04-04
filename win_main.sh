#!/bin/sh

x86_64-w64-mingw32-g++ -c *.cpp -DSFML_STATIC

x86_64-w64-mingw32-g++ *.o -o bin/game.exe -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -static-libgcc -static-libstdc++

#bin/game

powershell.exe Start bin/game.exe
