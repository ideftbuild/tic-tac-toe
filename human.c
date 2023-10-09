#include "tic_tac_toe.h"

char setX_OR_O()
{
	char x; 

	printf("X or O: ? ");
	scanf("%c", &x);
	
	return(x);
}


int enterSquare(int *rows, int *cols)
{
	printf("\nenter the rols and cols\n");
	return(scanf("%d %d", rows, cols));
}

