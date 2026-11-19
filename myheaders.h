/*
 * myheaders.h
 * Landon Anstey
 *  Created on: Nov 12, 2026
 *  Author: lanstey2007
 */

#ifndef MYHEADERS_H
#define MYHEADERS_H
#include <string>
#define MAXSIZE 2100000

void printmenu();
void printarray(long data[], long size);

int readfile(std::string infilename, long data[]);
int writefile(long data[], long size, std::string outfilename);

void swap(long& x, long& y);

void insertionSort(long data[], int n);
void bubbleSort(long data[], int n);
void mergeSort(long data[], int n);
void quickSort(long data[], int n);
void selectionSort(long data[], int n);
void shellSort(long data[], int n);

#endif /* MYHEADERS_H_ */
