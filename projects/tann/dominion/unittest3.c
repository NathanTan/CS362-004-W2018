#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFunction = "kingdomCards";    

    printf("----------------Testing: %s----------------\n", testFunction);

    /*----------------------Test 1----------------------*/
    int* array;
    array = kingdomCards(1,2,3,4,5,6,7,8,9,10);
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 4);
    assert(array[4] == 5);
    assert(array[5] == 6);
    assert(array[6] == 7);
    assert(array[7] == 8);
    assert(array[8] == 9);
    assert(array[9] == 10);

    printf("Test Passed\n");

    return 0;
}
