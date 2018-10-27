#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
int funcAdventurer(int card, struct gameState *state,int currentPlayer,int *temphand,int drawntreasure,int cardDrawn,int z);
int funcSmithy(int currentPlayer, struct gameState *state, int handPos);
int funcMine(int j,struct gameState *state,int currentPlayer,int choice1,int choice2, int handPos);
int funcTribute(struct gameState *state,int *tributeRevealedCards,int nextPlayer, int currentPlayer);
int funcTreasureMap(int index,struct gameState *state,int currentPlayer,int handPos);

#endif
