/*
 * Csort.cc
 * Landon Anstey
 * Sort used: Insertion Sort
 *  Created on: Nov 12, 2026
 *  Author: lanstey2007
 */

// Insertion Sort - shifts larger numbers to the right and inserts the
// current number into its correct position
#include "myheaders.h"

void insertionSort(long data[], int n) {
	for (int i = 1; i < n; i++) {
		long key = data[i];
						int j = i - 1;

		while (j >= 0 && data [j] > key) {
			data[j + 1] = data [j];
			j--;
		}
		data[j+1] = key;
	}
}




