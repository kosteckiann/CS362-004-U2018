#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

	printf("Testing updateCoins()\n");

	int thisPlayer = 0;
	struct gameState G, testG;
	int seed = 1000;
	int bonus = 0;
	int copper = 0;
	int silver = 0;
	int gold = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	initializeGame(2, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));

	

//negative bonus
	G.coins = 0;
	testG.coins = 0;
	bonus = -5;
	G.hand[thisPlayer][0] = copper;
	G.hand[thisPlayer][1] = silver;
	G.hand[thisPlayer][2] = gold;
	updateCoins(thisPlayer, &G, -5);

	printf("number of coins = %d, expected = %d\n", G.coins, testG.coins + 1 + 2 + 3 + bonus);


//1 of each card
	G.coins = 0;
	testG.coins = 0;
	bonus = 0;
	G.hand[thisPlayer][0] = copper;
	G.hand[thisPlayer][1] = silver;
	G.hand[thisPlayer][2] = gold;
	updateCoins(thisPlayer, &G, 0);

	printf("number of coins = %d, expected = %d\n", G.coins, testG.coins + 1 + 2 + 3 + bonus);


//0, 0, 1
	G.coins = 0;
	testG.coins = 0;
	bonus = 0;
	G.hand[thisPlayer][0] = gold;
	updateCoins(thisPlayer, &G, 0);

	printf("number of coins = %d, expected = %d\n", G.coins, testG.coins + 3 + bonus);


//0, 0 , 0
	G.coins = 0;
	testG.coins = 0;
	bonus = 0;
	updateCoins(thisPlayer, &G, 0);

	printf("number of coins = %d, expected = %d\n", G.coins, testG.coins + bonus);

	return 0;
}
