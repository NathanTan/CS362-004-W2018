#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFunction = "getCost";
    int seed = 4;
    int numPlayers = 3;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);

    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int card = curse;
    assert(0 == getCost(card));

    /*----------------------Test 2----------------------*/
    card = copper;
    assert(0 == getCost(card));

    /*----------------------Test 3----------------------*/
    card = silver;
    assert(3 == getCost(card));

    /*----------------------Test 4----------------------*/
    card = gold;
    assert(6 == getCost(card));

    /*----------------------Test 5----------------------*/
    card = smithy;
    assert(4 == getCost(card));

    /*----------------------Test 6----------------------*/
    card = 100; //Not a card
    assert(-1 == getCost(card));

    return 0;
}
