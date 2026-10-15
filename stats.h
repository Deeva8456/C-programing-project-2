#ifndef STATS_H
#define STATS_H
/**
 * @file stats.h
 * @brief Statistical functions (min, max, avg, median, variance, stddev).
 * Provides functions to compute basic statistics on integer arrays,
 */
/**
 * @brief Finds the minimum element in an array.
 * @param arr The array of integers.
 * @param capacity The capacity of the array.
 * @return int The minimum value in the array.
 */
int WF9_minElement(const int arr[], int capacity);
/**
 * @brief Finds the maximum element in an array.
 * @param arr The array of integers.
 * @param capacity The capacity of the array.
 * @return int The maximum value in the array.
 */
int    WF10_maxElement(const int arr[], int capacity);
/**
 * @brief Computes the average of elements in an array.
 * @param[in] arr The array of integers.
 * @param[in] capacity The capacity of the array.
 * @return double The average of the elements.
 */
double WF11_average(const int arr[], int capacity);
/**
 * @brief Computes the median of elements in an array.
 * @param arr The array of integers.
 * @param capacity The capacity of the array.
 * @return double The median value.
 */

double WF12_median(const int arr[], int capacity);
/**
 * @brief Computes the variance of elements in an array.
 * @param arr The array of integers.
 * @param capacity The capacity of the array.
 * @return double The variance value.
 */
double WF13_variance(const int arr[], int capacity);
/**
 * @brief Computes the standard deviation of elements in an array.
 * @param arr The array of integers.
 * @param capacity The capacity of the array.
 * @return double The standard deviation value.
 */
double WF14_stddev(const int arr[], int capacity);
#endif