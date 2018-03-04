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

/* Draws and plays a random amount of the village card */
int main()
{
    char *testFunction = "Village";
    int precount, postcount, pre_action_count, post_action_count;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 4;
    int result;
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

    printf("Player: %d\n", testPlayer);

    int randd = rand() % 50;

    deckStartSize = state.deckCount[testPlayer];
    printf("Deck start size: %d\n", state.deckCount[testPlayer]);

    int hand_count = state.handCount[testPlayer];
    randd = rand() % hand_count;
    int number_of_villages = 0;
    int card = village;


    // Make a random about of cards in the player's hand smithy.
    while (handpos < randd) {
        //Smithy is card 13
        //Set the player 1's first card to smithy
        state.hand[testPlayer][handpos] = card;
        handpos++;
        number_of_villages++;
    }


    precount = state.handCount[testPlayer];
    printf("handcount: %d\n", state.handCount[testPlayer]);

    pre_action_count = state.numActions;
    printf("Num actions: %d\n(Should be 1)\n", pre_action_count);

    handpos = 0;
    // Execute all the villages!
    while (handpos < randd) {
        //printf("Executing village!\n");
        result = cardEffect(card, choice1, choice2, choice3, &state, handpos, &bonus);
        handpos++;
    }

    postcount = state.handCount[testPlayer];
    // printf("new handcount: %d\n", postcount);
    // printf("old handcount: %d\n\n", precount);

    post_action_count = state.numActions;

    // printf("new action count: %d\n", post_action_count);
    // printf("old action count: %d\n\n", pre_action_count);
    // printf("Hand pos: %d\n", handpos);

    // Hand count shouldn't change from 5.
    assertIsTrue(precount, postcount);

    assertIsTrue(pre_action_count, post_action_count + (handpos * 2));
   
    return 0;
}