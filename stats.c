/**
 * @file stats.c
 * @brief Implements statistical calculations on arrays.
 */
#include "stats.h"
#include "array.h"
#include "randomNum.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

 /** @brief Return smallest used element in the array or UNUSED_MARKER if array is empty.
 *  Uses the first n elements as "used", where n is determined by WF15_countUsed.
 * @param  Array of integers.
  * @param capacity Size of the array.
  * @return int The minimum element found UNUSED_MARKER if none are used.
   */

int WF9_minElement(const int arr[], int capacity) {
    int n = WF15_countUsed(arr, capacity);// counts how many elements are used
    if (!n) return UNUSED_MARKER;//returns unused marker(-1) if no elements are used
    int min = arr[0];
    for (int i = 1;i < n;++i) {// loop through used elements
        if (arr[i] < min) {
            min = arr[i];// Update minimum if smaller value found
        }
    }
    return min;
}

/** @brief Return largest used element or UNUSED_MARKER if empty.
* Uses the first n elements as "used", where n is determined by WF15_countUsed.
* @param arr Array of integers.
 * @param capacity Size of the array
 * return int The maximum element found.
*/
int WF10_maxElement(const int arr[], int capacity) {
    int n = WF15_countUsed(arr, capacity);
    if (!n) return UNUSED_MARKER;

    int max = arr[0];// startrs with first element as max
    for (int i = 1;i < n;i++) {
        max = MAX2(max, arr[i]);// the macro i defined in randomNum.h its used here

    }
    return max;
}

/** @brief Compute the average (mean) of used elements in the array
 * @param arr Array of integers.
 * @param capacity Total capacity of the array.
 * @return double Average value of used elements, or 0.0 if empty.
 */

double WF11_average(const int arr[], int capacity) {
    int n = WF15_countUsed(arr, capacity);// Count used elements
    if (n == 0) return 0.0;//Return 0 if none used
    double sum = 0.0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];// gets the sum of total
    }
    return sum / n; // calculate the average
}
/**
 * @brief Compute median of used elements using bubble sort.
 * Copies used elements into a temporary array, sorts them,and computes the median.
 * The median is the middle value in a data set after sorting from lowest to highest.
 * - If the number of used elements is odd, the median is the single middle number.
 * - If the number of used elements is even, the median is the average of the two middle numbers.
* @param arr Input integer array
 * @param capacity Size of the array
 * @return Median value as a double or 0.0 if array is empty.
 */
double WF12_median(const int arr[], int capacity) {
    int n = WF15_countUsed(arr, capacity);  // Count used elements
    if (arr == NULL || capacity <= 0 || n <= 0) return 0.0; // Return 0 if array is empty
    if (n > capacity) n = capacity;        // Clamp n for safety
    // If only one element, just return it — avoids bubble sort with n=1
    if (n == 1) return arr[0];

    // Allocate temporary array for sorting
    int* temp = malloc((size_t)n * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed in WF12_median\n");
        return 0.0;
    }

    // Copy used elements
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    // Sort using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j + 1 < n - i; j++) {// ensures temp[j + 1] is always valid
            assert(j + 1 < n); // to guarantee valid access for analyzers
            if (temp[j] > temp[j + 1]) {//  store current element
                int tmp = temp[j];// move next element into current position
                temp[j] = temp[j + 1];//place original element into next position
                temp[j + 1] = tmp;
            }
        }
    }

    // Calculate median
    double median;
    if (n % 2 == 1) {
        median = temp[n / 2];  // Odd: middle element
    }
    else {
        median = (temp[n / 2 - 1] + temp[n / 2]) / 2.0; // Even: average of middle two
    }

    free(temp); // Free allocated memory
    return median;
}

/** @brief Compute population variance of used elements.
 * Variance measures how far data points are spread from the mean.
 * @param arr Array of integers.
 * @param capacity Total capacity of the array.
* @return The variance as a double or 0.0 if empty.
*/
double WF13_variance(const int arr[], int capacity) {
    int n = WF15_countUsed(arr, capacity);
    if (n == 0) return 0.0;
    double avg = WF11_average(arr, capacity),// get average
        sum = 0.0;
    for (int i = 0;i < n;i++) {// loop through used elements
        double d = arr[i] - avg;
        sum += d * d;// sum of squared differences
    }
    return sum / n;// population variance
}

/** @brief Compute population standard deviation of used elements.
* @param arr Array of integers.
 * @param capacity Total capacity of the array.
 * @return The standard deviation as a double.
*/
double WF14_stddev(const int arr[], int capacity) {
    return sqrt(WF13_variance(arr, capacity));
}
