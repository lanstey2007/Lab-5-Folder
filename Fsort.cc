/*
 * Fsort.cc
 *
 *  Created on: Nov 5, 2026
 *  Author: pierina-melo
 */

#include <iostream>

/**
 * Sorts an array of signed long integers in increasing order using Shell Sort.
 * arr Pointer to the array of long ints.
 * n Number of elements in the array.
 */
void shellSort(long int arr[], long n) {
    // Start with a large gap, then reduce the gap by half in each iteration
    for (long gap = n / 2; gap > 0; gap /= 2) {

        // Gap insertion sort for the current gap size
        for (long i = gap; i < n; i++) {
            long int temp = arr[i];
            long j;

            // Shift earlier gap-sorted elements up until the correct location for temp is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Place temp into its correct position
            arr[j] = temp;
        }
    }
}
