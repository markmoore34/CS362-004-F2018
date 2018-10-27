/*
 * unitTest2.c - this will check that scoreFor() correctly awards points to players.
 */


#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main ()
{
	struct gameState H;
	int k[10] = {adventurer, outpost, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};//cutpurse
	
	initializeGame(2, k, 10, &H);
	int score = scoreFor(0, &H);

	int j = 0;
	printf("\n\t\t\tTESTING scoreFor()\n\tP1 score at game start is %d.\n", score);

	if(scoreFor(0,&H) == 3)
		{ printf("PASSED! Score at start should be 3 and is %d.\n", scoreFor(0,&H)); }
	else { printf("Score at start should be 3 but it's %d.\n", scoreFor(0,&H)); }
	
	printf("Changing all cards in hand to Estate(+1).\n");
	for(j=0;j<H.handCount[0];j++)
	{
		H.hand[0][j] = estate;
	}
	printf("Score should have risen by max 5. Did it? \tScore == %d.\n", scoreFor(0,&H));
	
	printf("Changing all cards in deck to Estate(+1).\n");
	for(j=0;j<H.deckCount[0];j++)
	{
		H.hand[0][j] = estate;
	}
	
	if(scoreFor(0,&H)==10)
	{
		printf("Score is %d! The function - PASSED.\n", scoreFor(0,&H));
	}
	else  {printf("FAILED - Score should be 10 with all cards as estates.\tScore == %d.\n", scoreFor(0,&H));}
}//end main
