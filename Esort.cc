/*
 * Esort.cc
 *
 *  Created on: Nov 5, 2026
 *  Author: pierina-melo
 */
#include <iostream>

/*
 * Sorts an array of signed long integers in increasing order using Selection Sort.
 * arr Pointer to the array of long ints.
 * Number of elements in the array.
 */
void selectionSort(long int arr[], long n) {
    // Move the boundary of the unsorted subarray one by one
    for (long i = 0; i < n - 1; i++) {
        long minIndex = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (long j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            long int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
