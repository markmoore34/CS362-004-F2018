/*
 * randomCardTest1.c - this will check if funcSmithy() functions as expected.
 */

#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main ()
{
	printf("\n\t\tTEST TEST TEST().\n");
	struct gameState G;
	int coin_bonus = 0;
	int cardEffectResult = -10;
	//int getCostReturn = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	initializeGame(2, k, 10, &G);
	printf("\n\t\tTesting Smithy card()");
	printf("\tCalling smithyCard 20 times. Changing hand position each time.\n");
	//make random # gen to send into funcSmithy as the hand position.
	int c, n;
	printf("\tSending 20 random numbers(0-100) into smithyCard() as the player.\n");
	int failure = 0;
	for (c = 0; c <= 20; c++)
	{
		printf("\tstart of loop\n");
		n = rand() % 101;//get a random handPos
		cardEffectResult = cardEffect(smithy,0,0,0,&G,1,&coin_bonus);//13 is smithy card.
		if(cardEffectResult == 0)
			{printf("\tSUCCESS with %d\n\tTEST cardEffectResult = %d\n", n, cardEffectResult);}
		else{
			failure = 1;//if any of the fuunctions returned -1 it trickles out to here.
			printf("\tWARNING - FAILURE (after %d tests) with %d\n\tTEST cardEffectResult = %d\n",c, n, cardEffectResult);
		}
	 }
	if(failure==0)
		{printf("\t20 randomTestCard tests SUCCESSFUL\n ");}
	else{
		printf("\n\t20 randomTestCard tests FAILED\n ");
	}
}

