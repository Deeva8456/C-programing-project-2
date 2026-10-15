#ifndef RANDOMNUM_H
#define RANDOMNUM_H
/**
* @file randomNum.h
/**  it marks for unused array element. */
#define UNUSED_MARKER (-1)
/**@brief returns maximum of a and b. 
* @param a First value
 * @param b Second value
 * @return The greater of a and b
 */

#define MAX2(a,b) (((a) > (b)) ? (a) : (b))
/**
* @brief Initialize the random number generator.
uses curent time
*/
void randomNumInit(void);
/**
* @brief Return a random integer in [lower, upper].
*@param lower Lower bound and upper bound
* * @return Random integer between lower and upper.
 */

int WF1randomInt(int lower, int upper);

#endif