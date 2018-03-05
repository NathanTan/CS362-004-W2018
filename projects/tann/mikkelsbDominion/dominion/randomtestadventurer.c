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
    char *testFunction = "Adventurer";
    int precount, postcount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 4;
    int card = adventurer;
    int numPlayers = 3;
    int testPlayer = 0;
    int drawntreasure = 0;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    int temphand[MAX_HAND];// moved above the if statement
    int z = 0;// this is the counter for the temp hand


    srand(40);

    // initialize a game state
    initializeGame(numPlayers, k, seed, &state);
    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int currentPlayer = whoseTurn(&state);

    // Lets pump the player's deck full with a random amount of cards.
    int randd = ((rand() + 40 ) % 100) + 40; // The deck max is 500
    printf("Random integer: %d\n", randd);

    int deckCount = state.deckCount[currentPlayer];
    int cardsAdded = 0;
    while (cardsAdded < randd) {
        deckCount = state.deckCount[currentPlayer];
        state.deck[currentPlayer][deckCount] = rand() % 26; // Add a random card.
        state.deckCount[currentPlayer]++;
        cardsAdded++;
    }

    printf("Deck size: %d\n", deckCount);


    precount = state.handCount[currentPlayer];
    adventurerCardEffect(&drawntreasure, &state, &currentPlayer, temphand, &z, &card);

    postcount = state.handCount[currentPlayer];

    printf("pre: %d\npost: %d\n", precount, postcount);
    assertIsTrue(precount + 2, postcount); 


    //Make sure we get full branch coverage
    endTurn(&state);
    currentPlayer = whoseTurn(&state);
    
    //Emptying the deck will trigger a shuffle of the discard into the new deck.
    state.deckCount[currentPlayer] = 0;
    precount = state.handCount[currentPlayer];
    
    adventurerCardEffect(&drawntreasure, &state, &currentPlayer, temphand, &z, &card);
    postcount = state.handCount[currentPlayer];

    printf("pre: %d\npost: %d\n", precount, postcount);
    assertIsTrue(precount + 2, postcount); 

    return 0;
}