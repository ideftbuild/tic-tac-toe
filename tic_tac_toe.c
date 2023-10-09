#include "tic_tac_toe.h"
#include <stdio.h>

/**
* table - Shows the board of tic tac toe game
*
* @board: The board array
*
* Return: void (Nothing)
*/
void table(char (*board)[COLS])
{
	int i, j;

	printf("\n\n");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (j == 0)
				printf("%d", i);

			printf("   %c    ", board[i][j]);

			if (j != (COLS - 1))
			{
				putchar('|');
			}
		}
		putchar('\n');
		if (i != (ROWS - 1))
			printf("   ------|--------|-------\n");
	}
	printf("\n\n");
}

/**
 * program - The UI, that calls other functions
 *
 * @board: the board array
 *
 * Return: void (Nothing)
 */
void program(char (*board)[COLS])
{
	bool valid;
	int rows, cols;
	char choice, human_value, computer_value, playerName[50];

	printf("Enter your name\n");
	fgets(playerName, 50, stdin);

	printf("x or o: ");
	scanf(" %c", &human_value);
	/* Use the opposite of what player or human wants */
	computer_value = (human_value == 'x') ? 'o' : 'x';
	do {

	valid = enterSquare(&rows, &cols);

	validate(valid, rows, cols);
	if (checkSquare(board, rows, cols))
		continue;
	else 
		board[rows][cols] = human_value;


	if(checkwin(board, human_value))
	{
			printf("%s wins!!\n", playerName);
			break;
	}

	computer_value = computer_ai(board, human_value);
	if(checkwin(board, computer_value))
	{
		printf("Computer wins!!\n");
		break;
	}

	table(board);

	} while (true);

	table(board);

		printf("Do you want to play again: ");
		scanf(" %c", &choice);
		switch (choice)
		{
			case 'y':
				defaultBoard(board);
				program(board);
				break;
			case 'n':
				printf("Thank you for having time for this lovely game, hope to see you next time\n");
				exit(0);
		}

}

/**
 * validate - check if the number entered is a valid
 *
 * @valid: Return value from scanf, 0 means it is false, 1 mean true
 * @rows: The rows that the user wants to play
 * @cols: The cols that the user wants to play
 *
 * Return: void (Nothing)
 */
void validate(bool valid, int rows, int cols)
{
	if (valid == 0)
	{
		printf("Not a number\nExiting.........\n");
		exit(-1);
	}
	if (( rows < 0 || rows > 2) || (cols < 0 || cols > 2)) 
		printf("\nNumber is greater or less\n");
}

/**
 * checkSquare - check if the squared selected, is empty for a new one
 *
 * @rows: The rows that the user wants to play
 * @cols: The cols that the user wants to play
 *
 * Return: true if it is not valid, and false if it is
 */
bool checkSquare(char (*board)[3], int rows, int cols)
{
	if (board[rows][cols] != ' ')
	{
		printf("Not a valid square, Enter another square\n");
		return (true);
	}
	else 
	{
		return (false);
	}
}

/**
 * defaultBoard - The default board, of no element in it, just spaces
 *
 * @board: The board grid
 *
 * Return: void (Nothing)
 */
void defaultBoard(char (*board)[3])
{
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			board[i][j] = ' ';
	}
}

/**
 * main - Starts the program 
 *
 * Return: 0, (Success)
 */
int main(void)
{
	printf("Heyyy, it a game of tic tac toe\n");
	printf("In this game, you can challenge, the ai bot, as it grows it knowledge\n");
	printf("To limitless possibities\n");
	printf("\t\t\t\t\tMAKER: akan-SWE");

	char board[ROWS][COLS] = {{' ',' ',' '}, {' ',' ',' '},{' ',' ',' '}};

	table(board);
	program(board);

	return (0);
}
