#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFunction = "fullDeckCount";
    int seed = 4;
    int numPlayers = 3;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);

    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int testPlayer = 0;
    int card = copper; 
    int deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 7); //Player starts with 7 copper cards.
    
    /*----------------------Test 2----------------------*/
    testPlayer = 0;
    card = silver; 
    deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 0); //Player starts with 0 silver cards.

    /*----------------------Test 2----------------------*/
    testPlayer = 0;
    card = curse; 
    deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 0); //Player starts with 0 curse cards.
    


    return 0;
}
