/*
 * cardtest3.c - this will check that council_room correctly allows all players to draw cards
 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"

int main () {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	
	//printf ("Starting game.\n");
	initializeGame(2, k, 10, &G);
	printf("\n\t\tTesting council Room card().\n");
	printf("council_room should allow the player to get 4 cards from his deck and all other players get 1 from their decks.\n");
	printf("current stats for the cards affected by this function is.\n");
	int P1hand = G.handCount[0];
	int P1deck = G.deckCount[0];
	int P1discards = G.discardCount[0];
	int buys = G.numBuys;
	int P2hand = G.handCount[1];
	int P2deck = G.deckCount[1];
	int P2discards = G.discardCount[1];
	int coin_bonus = 0;
	printf("Current stats for P1 are \n\t# cards in hand = %d\n\t# cards in deck = %d\n\t# cards in discard pile = %d\n# of buys = %d\n", P1hand, P1deck, P1discards, buys);
	printf("Current stats for P2 are \n\t# cards in hand = %d\n\t# cards in deck = %d\n\t# cards in discard pile = %d\nSending coucil room through council_room()\n", P2hand, P2deck, P2discards);
	//int a = cardEffect(adventurer,0,0,0,&G,1,&coin_bonus);

	int council = cardEffect(council_room,-1,-1,-1,&G,1,&coin_bonus);
	
	printf("cardEffect returned %d\n", council);

	if(G.handCount[0] == 8)
	 	{ printf("PASSED - P1 has the correct # of cards in its hand - %d\n", G.handCount[0]); }
	else
		{ printf("FAILED - P1 has the incorrect # of cards in its hand - %d\n", G.handCount[0]); }

	if(G.deckCount[0] == 1)
		{ printf("PASSED - P1 has the correct # of cards in its deck - %d\n", G.deckCount[0]); }
	else
		{ printf("FAILED - P1 has the incorrect # of cards in its deck - %d\n", G.deckCount[0]); }
	
	if(G.discardCount[0] == 1)
		{ printf("PASSED - P1 has the correct # of cards in its discard pile  - %d\n", G.discardCount[0]); }
	else
		{ printf("FAILED - P1 has the incorrect # of cards in its discard pile  - %d\n", G.discardCount[0]); }
	
	if(G.numBuys == 1)
		{ printf("PASSED - P1 has the correct # of buys - %d\n", G.numBuys); }
	else
		{ printf("FAILED - P1 has the incorrect # of buys - %d\n", G.numBuys); }
	
	/*
	printf("This game does not draw cards till the start of the players turn so ");
	if(G.handCount[1] == 1)//this game does not draw cards till the start of the players turn
	{ printf("PASSED - P2 has the correct # of cards in its hand - %d\n", G.handCount[1]); }
	else
	{ printf("FAILED - P2 has the incorrect # of cards in its hand - %d\n", G.handCount[1]); }
	
	if(G.deckCount[1] == 9)
	{ printf("PASSED - P2 has the correct # of cards in its deck - %d\n", G.deckCount[1]); }
	else
	{ printf("FAILED - P2 has the incorrect # of cards in its deck - %d\n", G.deckCount[1]); }
	
	if(G.discardCount[1] == 0)
	{ printf("PASSED - P2 has the correct # of cards in its discard pile - %d\n", G.discardCount[1]); }
	else
	{ printf("FAILED - P2 has the incorrect # of cards in its discard pile - %d\n", G.discardCount[1]); }
	
	if(G.numBuys == 1)
	{ printf("PASSED - P2 has the correct # of buys - %d\n", G.numBuys); }
	else
	{ printf("FAILED - P2 has the incorrect # of buys - %d\n", G.numBuys); }
	 */
}//end main
