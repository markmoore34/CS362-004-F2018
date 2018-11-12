/*
 * randomCardTest1.c - this will check if funcSmithy() functions as expected.
 */

#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



int main () {
	printf("\n\t\tTEST TEST TEST().\n");
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	
	//printf ("Starting game.\n");
	initializeGame(2, k, 10, &G);
	printf("\n\t\tTesting Smithy card().\n");
	
	//bug is to send hand position (not player#) into drawcard
	//make a random number genrerator to input numbers 0 to 10
	//make sure it doesn't seg fault with assert comments in the function??
	
	
	
	printf("In Smithy() there is a bug that sends the hand position instead of player number to the drawcard function.\n");
	printf("Calling funcSmithy 20 times. Changing hand position each time.\nExpect a seg fault after hand position 1\n");
	
	//make random # gen to send into funcSmithy as the hand position.
	int c, n;
	printf("Sending 20 random numbers(0-100) into funcSmithy as the player.\n");
	for (c = 1; c <= 20; c++) {
		n = rand() % 100 + 1;
		printf("funcSmithy(0,&G, %d).\n", n);
		funcSmithy(0,&G, n);
		//This is where the error will print.
		
		
	}
	
	//printf("funcSmithy(0,&G, 0).\n");
	//funcSmithy(0,&G, 0);
	//printf("funcSmithy(0,&G, 1).\n");
	//funcSmithy(0,&G, 1);
	//printf("funcSmithy(0,&G, 2).\n");
	//funcSmithy(0,&G, 2);
	//printf("funcSmithy(0,&G, 3).\n");
	//funcSmithy(0,&G, 3);
	//printf("All tests with 0 or 1 card position successfull.\n");

}

