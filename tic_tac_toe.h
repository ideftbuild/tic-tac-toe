#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define ROWS 3
#define COLS 3

/* System headers */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int checkwin(char (*board)[COLS], char x_or_o);

bool checkrols(char (*board)[COLS], char x_or_o);

bool checkcols(char (*board)[COLS], char x_or_o);

bool checkdiagBackward(char (*board)[COLS], char x_or_o);

bool checkdiagForward(char (*board)[COLS], char x_or_o);

void table(char (*board)[COLS]);

void validate(bool valid, int rows, int cols);

char setX_OR_O();

int enterSquare(int *rows, int *cols);

char computer_ai(char (*board)[COLS], char human_value);

bool checkSquare(char (*board)[3], int rows, int cols);

void defaultBoard(char (*board)[3]);
#endif /* ifndef TIC-TAC-TOE_H */
