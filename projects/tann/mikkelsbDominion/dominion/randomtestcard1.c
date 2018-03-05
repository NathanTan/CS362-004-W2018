#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    int numPlayers = 3;
    int testPlayer = 0;
    int deckStartSize = 0;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    srand(4);

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);
    testPlayer = whoseTurn(&state);

    printf("----------------Random Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    printf("Player: %d\n", testPlayer);

    int randd = rand() % 50;

    deckStartSize = state.deckCount[testPlayer];
    printf("Deck start size: %d\n", state.deckCount[testPlayer]);

    int hand_count = state.handCount[testPlayer];
    randd = rand() % hand_count;
    int number_of_smithys = 0;


    // Make a random about of cards in the player's hand smithy.
    while (handpos < randd) {
        //Smithy is card 13
        //Set the player 1's first card to smithy
        state.hand[testPlayer][handpos] = 13;
        handpos++;
        number_of_smithys++;
    }


    int card = 13; // Smithy is 13
    precount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    handpos = 0;
    // Execute all the smithys!
    //while (handpos < randd) {
    {
        printf("Executing smithy!\n");
        smithyCardEffect(&state, &testPlayer, &handpos);
        handpos++;
    }

    postcount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    // Hand count should end up at 7 when the seed is 4 because this
    // early in the game, the player runs out of cards to draw, but
    // still loses cards when executing smithy.
    assertIsTrue(7, postcount);

   
    return 0;
}