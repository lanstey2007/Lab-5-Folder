/*
 * Helper_fns2.cc
 * Helper Functions
 *  Created on: Nov 12, 2026
 *      Author: lanstey2007
 */
#include <iostream>
#include <fstream>
#include "myheaders.h"
#include "Helper_fns2.cc"

using namespace std;

// Displays the program's main menu.
void printmenu() {

    cout << "\n1: Read input file\n";
    cout << "2: Insertion sort\n";
    cout << "3: Selection sort\n";
    cout << "4: Bubble sort\n";
    cout << "5: Quicksort\n";
    cout << "6: Mergesort\n";
    cout << "7: Shell sort\n";
    cout << "0: Exit\n";
    cout << "Choice: ";
}

// Prints the array to the terminal.
void printarray(long data[], long size) {

    for (long i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

// Reads numbers from the input file.
// Returns the number of values read.
// Returns -1 if the file cannot be opened.
int readfile(string infilename, long data[]) {

    ifstream infile(infilename.c_str());

    if (!infile.is_open()) {
        return -1;
    }

    long value;
    int size = 0;

    while (size < MAXSIZE && infile >> value) {
        data[size] = value;
        size++;
    }

    if (!infile.eof() && infile.fail()) {
        cerr << "Warning: Input stopped before end of file.\n";
    }

    infile.close();

    return size;
}

// Writes the sorted array to an output file.
// Returns 0 if successful, -1 if unsuccessful.
int writefile(long data[], long size, string outfilename) {

    ofstream outfile(outfilename.c_str());

    if (!outfile.is_open()) {
        return -1;
    }

    for (long i = 0; i < size; i++) {
        outfile << data[i] << endl;
    }

    bool success = outfile.good();

    outfile.close();

    return success ? 0 : -1;
}

// Swaps two numbers using pass-by-reference.
void swap(long& x, long& y) {

    long temp = x;
    x = y;
    y = temp;
}




