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
    char *testFunction = "Council Room";
    int precount, postcount;
    int preBuyCount, postBuyCount;
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
    precount = state.handCount[testPlayer];
    prePlayer2HandCount = state.handCount[testPlayer + 1];
    preBuyCount = state.numBuys;

    execute_council_room(card, choice1, choice2, choice3, &state, handpos, bonus);

    postcount = state.handCount[testPlayer];
    postPlayer2HandCount = state.handCount[testPlayer + 1];    
    postBuyCount = state.numBuys;
    

    assertIsTrue(precount + 3, postcount);
    assertIsTrue(preBuyCount + 1, postBuyCount);

    return 0;
}
