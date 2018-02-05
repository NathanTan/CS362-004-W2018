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
    char *testFunction = "Smithy";
    int precount, postcount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 4;
    int result;
    int numPlayers = 3;
    int testPlayer = 0;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);

    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    printf("Player: %d\n", testPlayer);
    //Smithy is card 13
    //Set the player 1's first card to smithy
    state.hand[testPlayer][handpos] = 13;

    int card = 13;
    precount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    postcount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    assertIsTrue(precount + 2, postcount);

    /*----------------------Test 2----------------------*/

    printf("Player: %d\n", testPlayer);

    //Smithy is card 13
    //Set the player 1's first card to smithy
    state.hand[testPlayer][handpos] = 13;

    precount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    postcount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    printf("This test should fail:   ");

    assertIsTrue(precount + 2, postcount);

    /*----------------------Test 1----------------------*/
    endTurn(&state);
    testPlayer = whoseTurn(&state);

    //Smithy is card 13
    //Set the player 1's first card to smithy
    state.hand[testPlayer][handpos] = 13;

    precount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    postcount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    assertIsTrue(precount + 2, postcount);

    return 0;
}
