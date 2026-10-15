/**
 * @file menufunc.c
 * @brief Implements menu test routines MF1–MF3.
 *  
 * MF1 demonstrates random filling, clearing, sorting, and min/max display.
 * MF2 tests sorting and randomization functions.
 * MF3 collects user input, prints statistics, and demonstrates array functions.
 */
#include "menufunc.h"
#include "array.h"
#include "stats.h"
#include "randomNum.h"
#include <stdio.h>
#include <stdlib.h>
 /**
  * @brief MF1: Demonstrates random filling, clearing, sorting, and min/max display.
  * * - Fills an array with random numbers.
 * - Prints only used elements and all elements.
 * - Clears the array and prints it again.
 * - Refills, sorts, prints, and displays min/max values.
  */

void MF1(void) {
    printf("\n\n");
    int arr[10];// declare array of capacity 10
    // using WF3 fills array with 7 random numbers in the range 10 to 20
    WF3_fillRandom(arr, 7, 10, 10, 20); 
    WF7_printUsed(arr, 10);//print only used elements
    WF8_printAll(arr, 10);// print all elements.
    WF4_clearArray(arr, 10); //clears array
    WF7_printUsed(arr, 10); 
    WF8_printAll(arr, 10);
    WF3_fillRandom(arr, 5, 10, 20, 30);//refill arry
    WF5_sortArray(arr, 10);  // sorts array
    WF8_printAll(arr, 10);// prints all elements
    // prints min and max
    printf("Min:%d\nMax:%d\n", WF9_minElement(arr, 10), WF10_maxElement(arr, 10));
    printf("\n\n");
}
/**
 * @brief MF2 Tests sorting and randomization functions.
 *  - Fills an array with random numbers.
 * - Prints, sorts, randomizes, and prints again.
 */
void MF2(void) {
    printf("\n\n");
    int arr[20];// array with capacty of 20
    //fill array with 15 random numbers in range 10 to 20.
    WF3_fillRandom(arr, 15, 20, 10, 20);
    WF8_printAll(arr, 20);//print all elements.
    WF5_sortArray(arr, 20);//
    WF8_printAll(arr, 20);
    WF6_randomizeArray(arr, 20);// randomize array.
    WF8_printAll(arr, 20);
    printf("\n\n");
}
/**
 * @brief MF3: Collects user input and prints array statistics.
 *
 * - Accepts up to 100 numbers from the keyboard.
 * - Prints used elements.
 * - Computes and displays min, max, average, median, variance, and standard deviation.
 */
void MF3(void) {
    printf("\n\n");
    int arr[100];// array eith capacity 100
    WF2fillFromKeyboard(arr, 100);// fills array from keyboard input
    WF7_printUsed(arr, 100);// prints used elements
    printf("Min:%d\nMax:%d\n", WF9_minElement(arr, 100), WF10_maxElement(arr, 100));// prints min and max
    printf(" Arrray has Average value:%.2f and Median:%.2f\n", WF11_average(arr, 100), WF12_median(arr, 100));// prints average and median
	printf("Used:%d Variance:%.2f StdDev:%.2f\n", WF15_countUsed(arr, 100), WF13_variance(arr, 100), WF14_stddev(arr, 100));// prints used count, variance and stddev
    printf("\n\n");
}
