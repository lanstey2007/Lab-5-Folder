#include "myheaders.h"


// Ava Rich
// Lab 5 ECE 2161, Section 001
// Sort A: Bubble Sort


// Bubble Sort: sorts data[0..size-1] in increasing order.
// Each pass scans from bottom of array up to position i.
// It swaps neighboring elements that are out of order.


void bubblesort(long data[], long size) {

	for (long i = 0; i < size - 1; ++i) {

		for (long j = size - 1; j > i; --j) {

			if (data[j] < data[j-1]) {
				swap(data[j], data[j-1]);
			}
		}
	}

	return;
}
