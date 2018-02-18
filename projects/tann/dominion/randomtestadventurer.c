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
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    int i = 0;
    srand(4);

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);

    printf("----------------Random Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    printf("Player: %d\n", testPlayer);

    int randd = rand() % 50;
    // Give the player a random amount of cards.
    for (i = 0; i < randd; i++)
    {
        drawCard(testPlayer, state);
    }

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
    while (handpos < randd) {
        execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    }

    postcount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    assertIsTrue(precount + (2 * number_of_smithys), postcount);

    // /*----------------------Test 2----------------------*/

    // printf("Player: %d\n", testPlayer);

    // //Smithy is card 13
    // //Set the player 1's first card to smithy
    // state.hand[testPlayer][handpos] = 13;

    // precount = state.handCount[testPlayer];
    // printf("handcount: %d\n", state.handCount[testPlayer]);

    // execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    // postcount = state.handCount[testPlayer];
    // printf("handcount: %d\n", state.handCount[testPlayer]);

    // printf("This test should fail:   ");

    // assertIsTrue(precount + 2, postcount);

    // /*----------------------Test 1----------------------*/
    // endTurn(&state);
    // testPlayer = whoseTurn(&state);

    // //Smithy is card 13
    // //Set the player 1's first card to smithy
    // state.hand[testPlayer][handpos] = 13;

    // precount = state.handCount[testPlayer];
    // printf("handcount: %d\n", state.handCount[testPlayer]);

    // execute_smithy(card, choice1, choice2, choice3, &state, handpos, &bonus);
    // postcount = state.handCount[testPlayer];
    // printf("handcount: %d\n", state.handCount[testPlayer]);

    // assertIsTrue(precount + 2, postcount);

    return 0;
}