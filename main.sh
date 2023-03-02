#!/bin/sh

g++ -c *.cpp

g++ *.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system

bin/game
