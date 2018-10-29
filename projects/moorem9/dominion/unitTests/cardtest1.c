/*
 * cardtest1.c - this will check if funcSmithy() functions as expected.
 */

#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	
	//printf ("Starting game.\n");
	initializeGame(2, k, 10, &G);
	
	printf("\n\t\tTesting Smithy card().\n");
	
	//bug is to send hand position (not player#) into drawcard
	printf("In Smithy() there is a bug that sends the hand position instead of player number to the drawcard function.\n");
	printf("calling funcSmithy 4 times. Changing hand position each time.\nExpect a seg fault after hand position 1\n");
	printf("funcSmithy(0,&G, 0).\n");
	funcSmithy(0,&G, 0);
	printf("funcSmithy(0,&G, 1).\n");
	funcSmithy(0,&G, 1);
	printf("funcSmithy(0,&G, 2).\n");
	//funcSmithy(0,&G, 2);
	printf("funcSmithy(0,&G, 3).\n");
	//funcSmithy(0,&G, 3);
	printf("All tests with 0 or 1 card position successfull.\n");


	/**
	int i = numHandCards(&G);
	printf("the number of cards at the beginning of the game is - %d\n", i);
	printf("Manually changing handcount of P1 to 20\n");
	G.handCount[0] = 20;
	printf("The function numHandCards() now returns %d\n", numHandCards(&G));
	printf("Manually changing handcount of P1 to 12\n");
	G.handCount[0] = 12;
	printf("The function numHandCards() now returns %d\n", numHandCards(&G));
	printf("Now changing whoseTurn() to 1.\n");
	G.whoseTurn = 1;
	printf("Manually changing handcount of P2 to 15\n");
	G.handCount[1] = 15;
	printf("The function numHandCards() now returns %d\n", numHandCards(&G));
	printf("Manually changing handcount of P2 to 36\n");
	G.handCount[1] = 36;
	printf("The function numHandCards() now returns %d\n", numHandCards(&G));
	 **/
}

