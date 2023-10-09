#include "tic_tac_toe.h"

int checkwin(char (*board)[COLS], char x_or_o)
{
	if(checkcols(board, x_or_o))
	{
		printf("\nWin on colums by %c \"|\"\n", x_or_o);
		return (1);
	}
	else if (checkrols(board, x_or_o))
	{
		printf("\nWin on rows by %c \"---\"\n", x_or_o);
		return (1);
	}
	else if (checkdiagBackward(board, x_or_o))
	{
		printf("\nWin on backward diagonal by %c \"\\\"\n", x_or_o);
		return (1);
	}
	else if(checkdiagForward(board, x_or_o))
	{
		printf("\nWin on forward diagonal by %c \"/\"\n", x_or_o);
		return (1);
	}

	return (0);
}

bool checkrols(char (*random)[COLS], char x_or_o)
{
	int i, j;
	bool match;

	match = true;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS ; j++) 
		{
			if (random[i][j] == x_or_o && random[i][j + 1] == x_or_o
				&& random[i][j + 2] == x_or_o)
				return (match);
			else
				break;
		}
	}

	return (!match);
}

bool checkcols(char (*board)[3], char x_or_o)
{
	int i, j;
	bool match;

	for (i = 0; i < COLS; i++)
	{
		match = true;

		for (j = 0; j < ROWS; j++)
		{
			if(board[j][i] != x_or_o) 
			{
			/* Go to the next cols when there is no match */
				match = false;
				break;
			}
			/* hence go to the next rols if there is a match */
		} 
		/* only executes when j equals ROWS or inner loop executes successfully */
		if(match)
			return (1);
	}

	return (0);
}

bool checkdiagBackward(char (*board)[3], char x_or_o)
{
	int i, j;

	bool match;

	match = true;

	for (i = 0; i < ROWS; i++)
	{
		for (j = i; j < COLS; j++)
		{
			if (board[i][j] == x_or_o)
				break;
			else
				return (!match);
		}
	}
	return (match);
}

bool checkdiagForward(char (*board)[3], char x_or_o)
{
	int i, j;
	bool match;

	match = true;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 2 - i; j < COLS; j++)
		{
			if (board[i][j] == x_or_o)
				break;
			else
				return (!match);
		}
	}
	
	return (match);
}
