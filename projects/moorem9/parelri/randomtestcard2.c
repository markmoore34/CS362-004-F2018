/*
 * randomCardTest2.c - this will check that outpost() correctly gave cards to players,
 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"

int main () {
	struct gameState G;
	int k[10] = {adventurer, gardens, outpost, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	
	initializeGame(2, k, 10, &G);

	printf("\n\t\tTesting outpost card().\n");
	int coin_bonus = 0;
	int c, n, a, hndPos;
	a=0;
	int counter = 0;
	int playedCardCt = 0;
	int fakeCard = 100;
	int handCt =0;
	int discrded = 0;

	printf("Sending 20 random numbers(0-100) into outpost as the handPosition 1 to 5.\n");
	for (c = 0; c <= 20; c++)
	{
		n = rand() % 5;//only 5 cards to draw bc the player only has 5 cards to start with.
		if(G.hand[0][n]==-1){//if the card ha alreqadxy been played, put a traceable value in to that element.
			G.hand[0][n] = fakeCard;
			fakeCard++;
		}
		hndPos = G.hand[0][n];//store what was in that hand position
		handCt= G.handCount[0];//record the hand count
		counter = G.outpostPlayed;//store what is in G.outpostPlayed
		playedCardCt = G.playedCardCount;//store how many cards have been played
		discrded = G.discardCount[0];//lets see if discard count is incremented somewhere?
	int outpost = cardEffect(23,-1,-1,-1,&G,n,&coin_bonus);
		printf("\toutpost returned %d.\n", outpost);
		
		if(G.playedCards[playedCardCt] == hndPos)
		   {
			   printf("PASSED - Card recorded in G.playedCards - %d - is equal to the card sent in. - %d\n", G.playedCards[playedCardCt], hndPos);
		   }

		if(G.outpostPlayed == counter+1)//check if outPost played has been incremented
			{ printf("PASSED - G.outpostPlayed has been incremented.\n"); }
		else{ printf("FAILED - There is the incorrect value for outpost played - %d\n", G.outpostPlayed); }
		
		
		if(G.handCount[0] == handCt-1)//check if outPost played has been incremented
		{
			printf("PASSED - handcount was decrimented from - %d - to - %d -.\n", handCt, G.handCount[0]);
			G.handCount[0]++;//reset the number of cards in the hand.
		}
		else
			{ printf("FAILED - There is the incorrect value for the G.handCount - %d\n", G.handCount[0]); }
		
		if(G.playedCards[G.playedCardCount-1] == hndPos)//check that G.playedCards is the same as sent in.
			{ printf("PASSED - the chosen number - %d - is in the discard pile.\n", G.playedCards[G.playedCardCount-1]); }
		else
			{ printf("FAILED - outpost is NOT in the discard pile.\n"); }
	}
}//end main
