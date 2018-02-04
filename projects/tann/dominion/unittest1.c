#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFunction = "isGameOver";
    int seed = 4;
    int numPlayers = 3;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);

    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int gg = -1;
    gg = isGameOver(&state);
    printf("%d\n", gg);

    //Zero means game not over
    assert(gg == 0);

    /*----------------------Test 2----------------------*/
    //Set the providence count to 0, thus ending the game
    state.supplyCount[3] = 0;

    gg = isGameOver(&state);
    printf("%d\n", gg);

    //One means game over
    assert(gg == 1);

    return 0;
}
