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
	int temphand[MAX_HAND];// moved above the if statement
	
	initializeGame(2, k, 10, &G);
	int hand = G.handCount[0];//put the number of the hand in the hand into hand.
	int deck = G.deckCount[0];//put the number of the cards in the deck into hand.
	int discards = G.discardCount[0];//
	
	printf("\n\t\tTesting Adventurer card().\n");
	
	printf("Adventurer should reveal cards until 2 treasures are found, then add the treasure to the players hand and discard the other revealed cards.\n");
	printf("Current stats are:\n\t cards in hand = %d\n\tcards in deck = %d\n\tcards in discard pile = %d\n", hand, deck, discards);
	//printf("Changing the players deck to have treasure in the first 2 spots(top 2 cards)\n");
	//G.hand[0][0] = 4;//4 is the number for treasure
	//G.hand[0][1] = 4;//4 is the number for treasure
	printf("I introduced a bug into funcAdventurer that reversed the comparison or treasures drawn from 'drawntreasure<2' to 'drawntreasure>2'\n This will cause the while statement to never excecute unless more than 2 is sent in for the drawn treasure.\n\tTEST#1 - send 0 as treasure drawn\n");
	
	printf("Sending 20 random numbers(0-10) into funcAdventurer as the # of drawnTreasure.\n");
	int c=0;
	int DT=0;
	
	for (c = 1; c <= 20; c++)
	{
		printf("c is %d\n", c);
		DT = rand() % 11;
		printf("funcAdventurer(7, &G,0,temphand,%d,-1,0).\n", DT);
		int a = funcAdventurer(7, &G,0,temphand,DT,-1,0);
			if(a==-1)
				{ printf("ERROR in funcAdventurer() - returned -1.\n"); }

	}
	printf("funcAdventurer() is dependent on the correct comparison between the number of treasures drawn and 2.\n Nothing else can be tested if that comparison is wrong.\n I have it inserted if's statements that returned negative one if the values that are out of bounds are sent into the associated functions");

}
	/**
	int adventure = funcAdventurer(7, &G,0,temphand,0,-1,0);//sending with 0 as treasure drawn(3rd from last)
	if(adventure == 0){
		printf("funcAdventurer returned 0\n");}
	else
		printf("funcAdventurer returned something other than 0.\n");
	
	printf("Current stats are:\n\t cards in hand = %d\n\tcards in deck = %d\n\tcards in discard pile = %d\n", G.handCount[0], G.deckCount[0], G.discardCount[0]);

	printf("sending 1 as treasure drawn\n");
	adventure = funcAdventurer(7, &G,0,temphand,1,-1,0);//sending with 0 as treasure drawn
	if(adventure == 0){
		printf("funcAdventurer returned 0\n");}
	else
		printf("funcAdventurer returned something other than 0.\n");

	printf("Current stats are:\n\t cards in hand = %d\n\tcards in deck = %d\n\tcards in discard pile = %d\n", G.handCount[0], G.deckCount[0], G.discardCount[0]);


}
**/
