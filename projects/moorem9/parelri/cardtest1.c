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
	initializeGame(2, k, 10, &G);
	int cardEffectResult = 0;
	int coin_bonus= 0;
	printf("\n\t\tTesting Smithy card().\n");
	//bug is to send hand position (not player#) into drawcard
	//printf("In Smithy() there is a bug that sends the hand position instead of player number to the drawcard function.\n");
	printf("Calling funcSmithy 4 times. Changing hand position each time.\n");

	printf("cardEffect(smithy,0,0,0,&G,0,&coin_bonus)\n");
	cardEffectResult = cardEffect(smithy,0,0,0,&G,1,&coin_bonus);//13 is smithy card.
	if(cardEffectResult == 0 && G.discardCount[0] == 1)  { printf("Passed - discard count is 1\n");}
	else  { printf("FAILED - discard count does not equal 1\n"); }

	cardEffectResult = cardEffect(smithy,0,0,0,&G,1,&coin_bonus);//13 is smithy card.
	if(cardEffectResult == 0 && G.discardCount[0] == 2)  { printf("Passed - discard count is 2\n");}
	else  { printf("FAILED - discard count does not equal 2\n"); }

	cardEffectResult = cardEffect(smithy,0,0,0,&G,2,&coin_bonus);//13 is smithy card.
	if(cardEffectResult == 0 && G.discardCount[0] == 3)  { printf("Passed - discard count is 3\n");}
	else  { printf("FAILED - discard count does not equal 3\n"); }

	cardEffectResult = cardEffect(smithy,0,0,0,&G,3,&coin_bonus);//13 is smithy card.
	if(cardEffectResult == 0 && G.discardCount[0] == 4)  { printf("Passed - discard count is 4\n");}
	else  { printf("FAILED - discard count does not equal 4\n"); }
	
	//printf("All tests with 0 or 1 card position successfull.\n");
	/**
*/
}

