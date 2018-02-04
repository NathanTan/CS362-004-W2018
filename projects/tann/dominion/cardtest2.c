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
    char *testFunction = "Adventurer";
    int precount, postcount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 4;
    int card = smithy;
    int numPlayers = 3;
    int testPlayer = 0;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);
    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int currentPlayer = whoseTurn(&state);
    precount = state.handCount[currentPlayer];
    execute_adventurer(card, choice1, choice2, choice3, &state, handpos, &bonus);

    postcount = state.handCount[currentPlayer];

    printf("pre: %d\npost: %d\n", precount, postcount);
    assertIsTrue(precount + 2, postcount); 

    /*----------------------Test 2----------------------*/
    currentPlayer = whoseTurn(&state);
    precount = state.handCount[currentPlayer];
    execute_adventurer(card, choice1, choice2, choice3, &state, handpos, &bonus);

    postcount = state.handCount[currentPlayer];

    printf("pre: %d\npost: %d\n", precount, postcount);
    assertIsTrue(precount + 2, postcount); 

        return 0;
}
