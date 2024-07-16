#include <iostream>
using namespace std;
namespace Exercises {
    // Function to swap elements at indices i and j
    void swap(int* arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Recursive function to find the index of the smallest element in the array
    int smallest(int* arr, int size, int start = 0) {
        if (size == 1) {
            return start;
        }
        int minIndex = smallest(arr, size - 1, start + 1);
        return (arr[start] < arr[minIndex]) ? start : minIndex;
    }

    // Recursive function to sort the array using selection sort principle
    void sort(int* arr, int size, int start = 0) {
        if (start >= size - 1) {
            return;
        }
        int minIndex = smallest(arr, size - start, start);
        swap(arr, start, minIndex);
        sort(arr, size, start + 1);
    }

    /**
     * Main function to execute the program.
     */
    void Ex_11_3_main() {
		cout << "Exercise 11.3:\n";
		cout << "This program sorts an array of integers using selection sort." << endl;
        int* arr;
        int num;
        do {
            cout << "Enter the size of the array: ";
            cin >> num;
            if (num <= 0)
                cout << "ERROR: Number must be positive." << endl;
        } while (num <= 0);

        arr = new int[num];
        cout << "Enter array values: ";
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        cout << "Before: \n";
        for (int i = 0; i < num; i++)
            cout << arr[i] << " ";
        cout << endl;

        sort(arr, num);

        cout << "After: \n";
        for (int i = 0; i < num; i++)
            cout << arr[i] << " ";
        cout << endl;

        delete[] arr; // Deallocate dynamic memory
     
    }
}
