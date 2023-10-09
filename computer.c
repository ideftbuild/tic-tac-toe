#include "tic_tac_toe.h"

char computer_ai(char (*board)[COLS], char human_value)
{
	int i, j;
	char computer_value;

	computer_value = (human_value == 'x') ? 'o' : 'x';

	i = 0;
	while(i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = computer_value;
				return (computer_value); /* Success */
			}
			j++;
		}
		i++;
	}

	return (computer_value - '0');
}
