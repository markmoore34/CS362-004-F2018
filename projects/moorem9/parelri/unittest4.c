/*
 * unitTest4.c - this will check that numHandCards() returns the correct # of cards for each player.
 */

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

	printf("\n\t\tTesting numHandCards().\n");
	int i = numHandCards(&G);
	printf("the number of cards at the beginning of the game is - %d\n", i);
	
	printf("Manually changing handcount of P1 to 20\n");
	G.handCount[0] = 20;
	if(numHandCards(&G) == 20)  { printf("PASSED - The function numHandCards() now returns %d\n", numHandCards(&G));}
	else { printf("Failed - The function numHandCards() now returns %d\n", numHandCards(&G));}

	printf("Manually changing handcount of P1 to 12\n");
	G.handCount[0] = 12;
	if(numHandCards(&G) == 12)  { printf("PASSED - The function numHandCards() now returns %d\n", numHandCards(&G)); }
	else { printf("Failed - The function numHandCards() now returns %d\n", numHandCards(&G));}

	printf("Now changing whoseTurn() to 1.\n");
	G.whoseTurn = 1;
	
	printf("Manually changing handcount of P2 to 15\n");
	G.handCount[1] = 15;//also need to change whosTurn() to P2
	G.whoseTurn = 1;
	if(numHandCards(&G) == 15)  { printf("PASSED - The function numHandCards() now returns %d\n", numHandCards(&G));}
	else  { printf("Failed - The function numHandCards() now returns %d\n", numHandCards(&G)); }
	
	printf("Manually changing handcount of P2 to 36\n");
	G.handCount[1] = 36;//also need to change whosTurn() to P2
	if(numHandCards(&G) == 36)  { printf("PASSED - The function numHandCards() now returns %d\n", numHandCards(&G));}
	else  { printf("Failed - The function numHandCards() now returns %d\n", numHandCards(&G)); }
}

