#ifndef ARRAY_H
#define ARRAY_H
#include "randomNum.h"
/**
* @file array.h
* @brief Declarations for array manipulation functions.
**/

/** Function prototypes for Working Functions(WF2–WF8, WF15)
* */
void WF2fillFromKeyboard(int arr[], int capacity);
void WF3_fillRandom(int arr[], int size, int capacity, int min, int max);
void WF4_clearArray(int arr[], int capacity);
void WF5_sortArray(int arr[], int capacity);
void WF6_randomizeArray(int arr[], int capacity);
void WF7_printUsed(const int arr[], int capacity);
void WF8_printAll(const int arr[], int capacity);
int  WF15_countUsed(const int arr[], int capacity);
#endif