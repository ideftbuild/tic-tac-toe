#!/bin/bash


# Compile 
gcc checkwin.c computer.c human.c tic_tac_toe.c -o run

# run
./run

# delete the executable file 
rm run
