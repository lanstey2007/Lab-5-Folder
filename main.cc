#include <iostream>
#include <ctime>
#include "myheaders.h"

using namespace std;

// Global array to avoid stack overflow
long numbers[MAXSIZE];

int main()
{
    int choice;
    int size = 0;

    string inputFile = "lab5input.txt";

    do
    {
        printmenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // Read data from input file
            case 1:
            {
                size = readfile(inputFile, numbers);

                if (size == -1)
                {
                    cout << "Error opening input file." << endl;
                }
                else
                {
                    cout << "Successfully loaded " << size
                         << " numbers." << endl;
                }

                break;
            }

            // Bubble Sort
            case 2:
            {
                size = readfile(inputFile, numbers);

                if (size == -1)
                {
                    cout << "Error opening input file." << endl;
                    break;
                }

                clock_t start_time = clock();

                bubblesort(numbers, size);

                clock_t end_time = clock();

                double elapsed_time =
                    double(end_time - start_time) / CLOCKS_PER_SEC;

                cout << "Bubble Sort completed." << endl;
                cout << "Time: " << elapsed_time << " seconds." << endl;

                writefile(numbers, size, "lab5_bubblesort_out.txt");

                cout << "Output saved to lab5_bubblesort_out.txt"
                     << endl;

                break;
            }

            // Merge Sort
            case 3:
            {
                size = readfile(inputFile, numbers);

                if (size == -1)
                {
                    cout << "Error opening input file." << endl;
                    break;
                }

                clock_t start_time = clock();

                mergesort(numbers, 0, size - 1);

                clock_t end_time = clock();

                double elapsed_time =
                    double(end_time - start_time) / CLOCKS_PER_SEC;

                cout << "Merge Sort completed." << endl;
                cout << "Time: " << elapsed_time << " seconds." << endl;

                writefile(numbers, size, "lab5_mergesort_out.txt");

                cout << "Output saved to lab5_mergesort_out.txt"
                     << endl;

                break;
            }

            // Remaining sorting algorithms
            case 4:
            case 5:
            case 6:
            case 7:
            {
                cout << "This sorting algorithm has not been implemented yet."
                     << endl;
                break;
            }

            // Exit
            case 0:
            {
                cout << "Exiting program." << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}
