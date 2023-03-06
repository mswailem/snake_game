#!/bin/sh

g++ -c *.cpp

mv *.o bin

g++ bin/*.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system

bin/game
