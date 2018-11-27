/*
 * randomtestadventurer.c - this will check if funcAdventurer() functions as expected.
 */

#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define NUM_SECS 1.0f // delay period

int main ()
{
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy};//cutpurse
	//int temphand[MAX_HAND];// moved above the if statement
	int coin_bonus = 0;

	initializeGame(2, k, 10, &G);
	int hand = G.handCount[0];//put the number of the hand in the hand into hand.
	int deck = G.deckCount[0];//put the number of the cards in the deck into hand.
	int discards = G.discardCount[0];//
	
	printf("\n\t\tTesting Adventurer card().\n");
	printf("Adventurer should reveal cards until 2 treasures are found, then add the treasure to the players hand and discard the other revealed cards.\n");
	printf("Current stats are:\n\t cards in hand = %d\n\tcards in deck = %d\n\tcards in discard pile = %d\n", hand, deck, discards);
	printf("there is a bug in adventurerCard that changes the comparison of treasures drawn from 'drawntreasure<2' to 'drawntreasure<=2'\n This will cause the player to draw three treasure cards instead of two.\n");
	printf("Sending 20 random numbers(0-10) into funcAdventurer as the # of drawnTreasure.\n");
	int c=0;
	int DT=0;
	int a;
	for (c = 1; c <= 20; c++)
	{
		printf("loop # is %d\n", c);
		DT = rand() % 11;//Drawn Treasure
		printf("cardEffect(adventurer,0,0,0,&G,1,&coin_bonus).\n");
		a = cardEffect(adventurer,0,0,0,&G,1,&coin_bonus);
		if(a==-1)
			{ printf("ERROR in funcAdventurer() - returned -1.\n"); }
		else
			{  printf("\tSUCCESS with %d\n\tTEST cardEffectResult = %d\n", c, a);  }
	}
}

