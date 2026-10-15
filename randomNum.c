/**
* @file randomNum.c
* @brief Implements random number.
* 
*This module provides functions to initialize the random number generator
 * and generate random integers within a given range. The random generator
 * is seeded using the current system time to ensure variability.
*/
#include "randomNum.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/**
   * @brief Initialize the random number generator
   Seeds the random number generator using current time. 
 * This makes sure the random numbers are different each time the progrm runs
   * @return void
  */
void randomNumInit(void) {
    srand((unsigned int)time(NULL));
}
/**
 * @brief Generates a random integer between lower and upper
 * If lower is greater than upper, the values are swapped.
 * * @param lower The lower bound of the random number range.
 * @param upper The upper bound of the random number range.
 * @return int A random integer between lower and upper (inclusive).
 */
int WF1randomInt(int lower, int upper) {
    if (lower > upper) {// it swaps if needed
        int tmp = lower;
        lower = upper;
        upper = tmp;
    }
    //this line produces value in lower, upper
    return (rand() % (upper - lower + 1)) + lower;
}