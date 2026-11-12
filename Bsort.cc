#include "myheaders.h"

// Ava Rich
// Lab 5 ECE 2161, Section 001
// Sort B: Merge Sort


// Merge Sort: sorts data[first..last] in increasing order.
// Splits array in half, sorts each half recursively, then merges the two sorted halves.
// Stops splitting when a piece has fewer than two elements.

void mergesort(long data[], long first, long last) {

	if (first < last) {  // i.e. the piece has two or more elements

		long mid = (first + last) / 2;

		mergesort(data, first, mid);
		mergesort(data, mid + 1, last);

		merge(data, first, last);
	}

	return;
}


// Merge: merges the sorted halves data[first..mid] and data[mid+1..last] into one sorted piece.
// The merged values are built in a temporary array and then copied back.

void merge(long data[], long first, long last) {

	long mid = (first + last) / 2;
	long i1 = 0;			                    // next free slot in tmp[]
	long i2 = first;		                    // next unused element of the left half
	long i3 = mid + 1;	                        // next unused element of the right half
	long* tmp = new long[last - first + 1];

	// While both halves still have elements, take the smaller front value
	while ((i2 <= mid) && (i3 <= last)) {

		if (data[i2] < data[i3]){
			tmp[i1++] = data[i2++];
		}

		else{
			tmp[i1++] = data[i3++];
		}
	}

	// One half is now empty, copy the leftovers of the other half.
	while (i2 <= mid){
		tmp[i1++] = data[i2++];
	}

	while (i3 <= last){
		tmp[i1++] = data[i3++];
	}

	// Copy the merged result back into data[]
	for (i1 = 0; i1 < (last - first + 1); ++i1){
		data[first + i1] = tmp[i1];
	}

	delete [] tmp;

	return;
}

