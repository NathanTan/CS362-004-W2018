#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

void assertIsTrue(int a, int b)
{
    if (a == b)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");
    return;
}

int main()
{
    char *testFunction = "Embargo";
    int precount, postcount;
    int preBuyCount, postBuyCount;
    int preCoins, postCoins;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 4;
    int card = council_room;
    int numPlayers = 2;
    int testPlayer = 0;
    int prePlayer2HandCount, postPlayer2HandCount;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);
    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    preCoins = state.coins;
    precount = state.handCount[testPlayer];

    int results = execute_embargo(card, choice1, choice2, choice3, &state, handpos, bonus);
    postCoins = state.coins;
    postcount = state.handCount[testPlayer];    
    assertIsTrue(preCoins + 2, postCoins);
    assertIsTrue(precount - 1, postcount);

    return 0;
}
