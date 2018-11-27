/*
 * cardTest4.c - this will check that outpost() correctly gave cards to players,
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
	//sets oupost flag and discards outpost.
	//check that outpostPlayed is incremented.
	
	printf("\n\t\tTesting outpost card().\n");
	printf("Outpost should allow the player to take another turn after playing this card.\n");
	//printf("current stats for the cards affected by this function is.\n");
	int P1hand = G.handCount[0];
	int P1deck = G.deckCount[0];
	int P1discards = G.discardCount[0];
	int disc = G.discard[0][0];
	int outpost = G.outpostPlayed;
	int coin_bonus = 0;


	printf("Current stats for P1 are \n\t# cards in hand = %d\n\t# cards in deck = %d\n\t# cards in discard pile = %d\n\toutpost played = %d\n\tfirst card in discard pile is = %d.\n", P1hand, P1deck, P1discards, outpost, disc);
	
	int council = cardEffect(23,-1,-1,-1,&G,0,&coin_bonus);
	
	printf("cardEffect returned %d\n", council);
	
	if(G.outpostPlayed == 1)
	{ printf("PASSED - Outpost played is correct - %d\n", G.outpostPlayed); }
	else
	{ printf("FAILED - There is the incorrect value for outpost played - %d\n", G.outpostPlayed); }
	
	if(G.discardCount[0] == 1)
	{ printf("PASSED - P1 has the correct # of cards in its discard pile - %d\n", G.discardCount[0]); }
	else
	{ printf("FAILED - P1 has the incorrect # of cards in its discard pile - %d\n", G.discardCount[0]); }
	
	if(G.discard[0][0] == outpost)
	{ printf("PASSED - outpost is in the discard pile.\n"); }
	else
	{ printf("FAILED - outpost is NOT in the discard pile.\n"); }
	
	
	
}//end main
