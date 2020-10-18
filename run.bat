#!/bin/bash

clear
set mypath=%cd%
rm -f *.o projeto
gcc -c jogo_da_velha.c
gcc -c main.c
gcc main.o jogo_da_velha.o -o jogodavelha
START  %mypath%\jogodavelha.exe