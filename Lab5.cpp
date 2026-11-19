//============================================================================
// Name        : Lab5.cpp
// Author      : Landon Anstey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Landon Anstey
// Lab 5, ECE 2161-001
// Compares execution times of six sorting algorithms.

#include <iostream>
#include <limits>
#include <ctime>
#include "myheaders.h"

using namespace std;

int main() {

    // Store the original data and a working copy.
    long data[MAXSIZE];
    long wData[MAXSIZE];

    int sz = -1;
    int choice;

    // Array containing the six sorting functions.
    typedef void (*SortFunction)(long[], int);

    SortFunction sorts[6] = {
        insertionSort,
        selectionSort,
        bubbleSort,
        quickSort,
        mergeSort,
        shellSort,
    };

    const char* names[6] = {
        "Insertion",
        "Selection",
        "Bubble",
        "Quick",
        "Merge",
        "Heap"
    };

    const char* outputFiles[6] = {
        "lab5_A_out.txt",
        "lab5_B_out.txt",
        "lab5_C_out.txt",
        "lab5_D_out.txt",
        "lab5_E_out.txt",
        "lab5_F_out.txt"
    };

    // Display the menu until the user exits.
    while (true) {

        printmenu();

        if (!(cin >> choice)) {

            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a number from 0 to 7.\n";
            continue;
        }

        // Option 0: Exit the program.
        if (choice == 0) {
            break;
        }

        // Option 1: Load data from the input file.
        if (choice == 1) {

            sz = readfile("lab5_input.txt", data);

            if (sz < 0) {
                cout << "ERROR: Cannot open lab5_input.txt\n";
            }
            else {
                cout << "Loaded " << sz << " numbers.\n";
            }
        }

        // Options 2 through 7: Run sorting algorithms.
        else if (choice >= 2 && choice <= 7) {

            if (sz < 0) {
                cout << "Load the input data first.\n";
                continue;
            }

            // Copy the original array before sorting.
            for (int i = 0; i < sz; i++) {
                wData[i] = data[i];
            }

            int index = choice - 2;

            // Start the CPU timer.
            clock_t begin_time = clock();

            // Run the selected sorting function.
            sorts[index](wData, sz);

            // Stop the CPU timer.
            clock_t end_time = clock();

            // Calculate execution time in seconds.
            double cpu_time_used =
                double(end_time - begin_time) / CLOCKS_PER_SEC;

            cout << names[index]
                 << " sort CPU time: "
                 << cpu_time_used
                 << " seconds.\n";

            // Verify that the array is sorted.
            bool sorted = true;

            for (int i = 1; i < sz; i++) {

                if (wData[i] < wData[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) {
                cout << "Ascending order check: PASS\n";
            }
            else {
                cout << "Ascending order check: FAIL\n";
            }

            // Write the sorted array to its output file.
            if (writefile(wData, sz, outputFiles[index]) == -1) {
                cout << "ERROR: Could not write output file.\n";
            }
            else {
                cout << "Saved " << outputFiles[index] << endl;
            }
        }

        else {
            cout << "Invalid choice. Select 0 through 7.\n";
        }
    }

    cout << "Goodbye!\n";

    return 0;
}

