/*
 * myheaders3.h
 *
 *  Created on: Oct 29, 2026
 *      Author: pierina-melo
 */

#ifndef MYHEADERS3_H_
#define MYHEADERS3_H_

// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!


#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int	    readfile(string infilename, long data[]);
int	    writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);

void selectionSort(long int arr[], long n);
void shellSort(long int arr[], long n);



#endif /* MYHEADERS3_H_ */
