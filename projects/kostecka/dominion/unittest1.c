#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

	printf("Testing Compare function\n");
	int larger = 1;
	int smaller = -1;
	int max = 2147483647;
	int min = -2147483647;

	//compare a > b
	if ((compare(&larger, &smaller)) == 1)
		printf("Compare passed when a > b\n");
	else
		printf("Compare failed when a > b\n");

	//compare a < b
	if ((compare(&smaller, &larger)) == -1)
		printf("Compare passed when a < b\n");
	else
		printf("Compare failed when a < b\n");

	//compare a = b
	if ((compare(&larger, &larger)) == 0)
		printf("Compare passed when a = b\n");
	else
		printf("Compare failed when a = b\n");

	//a = min boundary
	if ((compare(&min, &smaller)) == -1)
		printf("Compare passed when a is minimum boundary\n");
	else
		printf("Compare failed when a is minimum boundary\n");

	//a = max boundary
	if ((compare(&max, &smaller)) == 1)
		printf("Compare passed when a is maximum boundary\n");
	else
		printf("Compare failed when a is maximum boundary\n");

	//b = min boundary
	if ((compare(&larger, &min)) == 1)
		printf("Compare passed when b is minimum boundary\n");
	else
		printf("Compare failed when b is minimum boundary\n");

	//b = max boundary
	if ((compare(&larger, &max)) == -1)
		printf("Compare passed when b is maximum boundary\n");
	else
		printf("Compare failed when b is maximum boundary\n");

	return 0;
}
