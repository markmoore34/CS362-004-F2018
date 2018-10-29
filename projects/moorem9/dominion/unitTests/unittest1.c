/*
 * unitTest1.c - this will check that initializeGame() correctly gave cards to players,
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
	//check that each player has 7 coppers and 3 kingdom cards at start of game.
	int i=0;
	int j=0;
	for(i=0; i<1; i++)//steps through player 1
	{
		int coppr = 0;
		int estte = 0;
		for(j=0; j<numHandCards(&G); j++)//steps through HAND of that player
		{
			if(G.hand[i][j] == copper)//should be 7 copper in all
				{ coppr++; }
			else if(G.hand[i][j] == estate)
				{ estte++; }
		}
		for(j=0; j<G.deckCount[i]; j++)//steps through DECK of that player
		{
			if(G.deck[i][j] == copper)//should be 7 copper in all
				{ coppr++; }
			else if(G.deck[i][j] == estate)
				{ estte++; }
		}
		printf("\n\tTest 1. Players have the correct # of copper and kingdom cards to start the game,\n\tTest 2. There are 8 Gardens and Great Hall cards with 2 players.\n");
		if(coppr == 7 && estte == 3)
			{ printf("PASSED - There are 3 Kingdom cards and 7 copper in player %d's hand\n", i+1); }
		else
		{	printf("coppers = %d\nestates = %d\n", coppr, estte);
			printf("FAILED - Incorrect number of cards in player %d's hand\n", i+1);}
	}

	if(G.supplyCount[great_hall] == 8 && G.supplyCount[gardens] == 8)
	   { printf("PASSED - There are 8 Great hall and 8 Gardens cards\n"); }
}//end main
