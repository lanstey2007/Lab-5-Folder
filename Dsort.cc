/*
 * Dsort.cc
 * Sort used: Quick Sort
 *  Created on: Nov 12, 2026
 *      Author: lanstey2007
 */

// Quick sort
// Separates numbers into groups that are smaller, equal to, or lager
// than the pivot

#include "myheaders.h"

static void quickSortRange(long data[], int left, int right) {
	while (left < right) {
		long pivot = data[left + (right-left) / 2];

		int less = left;
		int i = left;
		int greater = right;
		while (i <= greater) {
			if (data[i] < pivot) {
				swap(data[less], data[i]);
				less++;
				i++;
			}
			else if (data[i] > pivot) {
				swap(data[i], data[greater]);
				greater--;
			}
			else{
				i++;
			}
		}
	if (less - left < right - greater) {
		quickSortRange(data, left, less - 1);
		left = greater + 1;
	}
	else {
		quickSortRange(data, greater + 1, right);
		right = less - 1;
		}
	}
}

void quickSort(long data[], int n) {
	if (n > 1) {
		quickSortRange(data,0, n-1);
	}
}
