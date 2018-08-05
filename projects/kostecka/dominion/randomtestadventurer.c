#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int main() {

	srand(time(NULL));
	int thisPlayer = 0;
	int seed = 1000;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int xtraCoins = 0;
	int newCards = 0;
	int discarded = 0;
	int shuffledCards = 0;
	int extraBuys = 0;
	int extraActions = 0;

	int i;
	for(i = 0; i<5; i++){

	choice1 = rand() %2;
	choice2 = rand() %2;
	choice3 = rand() %2;
	handPos = rand() %2;
	bonus = rand() %2;

	struct gameState G, testG;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };


	initializeGame(2, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));
	
	if(i==0){
	testG.deckCount[thisPlayer] = 0;
	testG.hand[thisPlayer][testG.handCount[thisPlayer]-1] = copper;
	}

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	printf("Testing Card: Adventurer\n");

	newCards = 1;
	xtraCoins = 1;
	discarded = 1;

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	printf("number of buys = %d, expected = %d\n", testG.numBuys, G.numBuys + extraBuys);
	printf("number of actions = %d, expected = %d\n\n", testG.numActions, G.numActions + extraActions);
	}

	return 0;
}