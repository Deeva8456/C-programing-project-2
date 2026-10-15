/**
* @file array.c
* @brief Implements array manipulation of functions(WF2–WF8, WF15).
*/
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Fill array from user
 * Recieve an array and its capacity it reads the integer values from the user
 * and stores them in array if a negative value is entered it stops storing values and the
 * @param arr Integer array to fill.
 * @param capacity Maximum number of elements that can be stored in the array.
 * remaining elements are filled with UNUSED_MARKER.
 */
void WF2fillFromKeyboard(int arr[], int capacity) {
	int value, i = 0;
	printf("Enter numbers (negative to stop):\n");// Read numbers until a negative is entered or array is full
	while (i < capacity) {
		scanf_s("%d", &value);

		if (value < 0)
			break;

		arr[i++] = value;//Store the entered value
	}
	// fill remaining elements with UNUSED_MARKER -1
	while (i < capacity)
		arr[i++] = UNUSED_MARKER;
}

/**
* @brief Fills the first 'size' elements with random values.
* and the marked UNUSED_MARKER. Uses WF1randInt() from randomNum.c.
* @param arr Integer array to fill.
 * @param size Number of elements to fill with random values.
 * @param capacity Total size of the array.
 * @param min Minimum random value (inclusive).
 * @param max Maximum random value (inclusive).
*/
void WF3_fillRandom(int arr[], int size, int capacity, int min, int max) {
	if (size > capacity) {// this prevents overflow
		size = capacity;
	}
	for (int i = 0; i < size; i++)// Fill first 'size' elements with random values
		arr[i] = WF1randomInt(min, max);

	for (int i = size; i < capacity; ++i)// Mark remaining elements as unused
		arr[i] = UNUSED_MARKER;

}

/** @brief Clear all elements by marking them unused.
 * @param arr Array to clear.
 * @param capacity Size of the array.
*/
void WF4_clearArray(int arr[], int capacity) {
	for (int i = 0; i < capacity; i++)
		arr[i] = UNUSED_MARKER;
}

/** @brief Count number of used elements in an array
* *
 * Used elements are those that are not equal to UNUSED_MARKER.
 * Counting stops at the first UNUSED_MARKER.
 *
 * @param arr Input array.
 * @param capacity Size of the array.
 * @return int Number of used elements.
*/
int WF15_countUsed(const int arr[], int capacity) {
	int count = 0;
	for (int i = 0; i < capacity; i++) {
		if (arr[i] == UNUSED_MARKER)
			break;// stopes at first unused
		count++;
	}
	return count;
}

/** @brief bubble sort is used to sortt elements in ascending order using bubbnle sort
* Unused elements remain at the end of the array.
 * @param arr Array to sort.
 * @param capacity Total capacity of the array.
 */


void WF5_sortArray(int arr[], int capacity) {
	int n = WF15_countUsed(arr, capacity);

	// Simple bubble sort for the used elements
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// marks the rest with UNUSED_MARKER
	for (int i = n; i < capacity; i++) {
		arr[i] = UNUSED_MARKER;
	}
}


/** @brief Randomize used elements order.
 * Unused elements remain at the end.
 * * @param arr Array to randomize.
 * @param capacity Total capacity of the array.
*/
void WF6_randomizeArray(int arr[], int capacity) {
	int n = WF15_countUsed(arr, capacity);// count used element

	for (int i = n - 1; i > 0; i--) {// shuffle used element
		int j = WF1randomInt(0, i);// pick a dadom iindex
		// swaps elements
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;// swamp elements
	}
	// marks the rest with UNUSED_MARKER
	for (int i = n; i < capacity; ++i)
		arr[i] = UNUSED_MARKER;
}
/** @brief Print only used elements in { } form.
 *
 * @param arr Array to print.
 * @param capacity Total capacity of the array.
*/
void WF7_printUsed(const int arr[], int capacity) {
	int n = WF15_countUsed(arr, capacity);
	printf("{");
	for (int i = 0; i < n;i++) {
		printf("%d", arr[i]);
		if (i < n - 1)
			printf(", ");// it prints comma between numbers
	}
	printf("}\n");
}
/** @brief Print all elements (including UNUSED_MARKER). 
 * Displays elements inside curly braces `{}` separated by commas.
 * @param arr Array to print.
 * @param capacity Total capacity of the array.
*/
void WF8_printAll(const int arr[], int capacity) {
	printf("{");
	for (int i = 0; i < capacity; i++) {
		printf("%d", arr[i]);
		if (i < capacity - 1)
			printf(", ");
	}
	printf("}\n");
}