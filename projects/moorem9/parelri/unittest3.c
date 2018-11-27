/*
 * unitTest3.c - this will check that shuffle() shuffles cards with sufficient irregularity.
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

	printf("\n\t\tTesting shuffle().\n");
	int i;
	int arr1[30];
	int arr2[30];//arr2 is not needed, as it turns out....
	//create a a deck of 30 with 10 different cards.
	for(i=0;i<30;i++)
	{
		if(i/3==1){
			arr1[i] = adventurer;
			arr2[i] = adventurer;//arr2 is not needed, as it turns out....
		}
		if(i/3==2){
			arr1[i] = council_room;
			arr2[i] = council_room;
		}
		if(i/3==3){
			arr1[i] = feast;
			arr2[i] = feast;
		}
		if(i/3==4){
			arr1[i] = gardens;
			arr2[i] = gardens;
		}
		if(i/3==5){
			arr1[i] = mine;
			arr2[i] = mine;
		}
		if(i/3==6){
			arr1[i] = remodel;
			arr2[i] = remodel;
		}
		if(i/3==7){
			arr1[i] = smithy;
			arr2[i] = smithy;
		}
		if(i/3==8){
			arr1[i] = village;
			arr2[i] = village;
		}
		if(i/3==9){
			arr1[i] = baron;
			arr2[i] = baron;
		}
		if(i/3==0){
			arr1[i] = great_hall;
			arr2[i] = great_hall;
		}
	}
	for(i=0;i<30;i++){	//copy arr1 into P1 deck.
		G.deck[0][i] = arr1[i];
	}
	int m = 0;
	printf(" \tThere are 3 of each of 10 different cards. \n\tThe percent of cards the same should be about 10 percent.\n");
	printf("\tIf it is more than 20 percent the shuffle fails.\n");
	G.deckCount[0] = 30;//reset P1 deck count

	for(m=0;m<30;m++){
		printf("G.deck[%d] = %d - %d = arr1[%d]\n", m, G.deck[0][m], arr1[m], m);
	}

	int a=0;			//shuffle number counter
	for(a=0;a<3;a++){
		int samecard = 0;	//to count how many cards are the same
		shuffle(0,&G);	//send to shuffle
		for(m=0;m<30;m++){
			printf("G.deck[%d] shuffled = %d - %d = arr1[%d]\n", m, G.deck[0][m], arr1[m], m);
			if(G.deck[0][m] == arr1[m])
				samecard++;
		}
		printf("%d cards are the same.\n", samecard);
		if((samecard/30)*100>20){
			printf("Shuffle #%d FAILED. More than 20 percent of the cards are the same.\n", a+1);
		}
		else{
			printf("Shuffle #%d PASSED - Less than 20 percent of the cards are the same.\n", a+1);
		}
		
		for(i=0;i<30;i++){//copy shuffled deck into arr1 for comparison in next loop.
			arr1[i] = G.deck[0][i];
		}

	}
	
	printf("If the players deck is <1, shuffle should return -1. Lets test it!\n");
	G.deckCount[0] = 0;//reset P1 deck count
	//int retShuff = shuffle(0,&G);	//send to shuffle
	if(shuffle(0,&G) == -1){
		printf("PASSED - After changing G.deckCount[0] to 0, suffle() returned -1\n");
	}
	else
		printf("FAILED - After changing G.deckCount[0] to 0, suffle() returned something other than -1\n");
}
