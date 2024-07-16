#include <iostream>
using namespace std;

namespace Exercises {

    // Function to swap elements at indices i and j
    void swap(int* arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Recursive function to reverse the array
    void reverse(int* arr, int size, int start = 0) {
        if (start >= size / 2) {
            // Base case: if we've reached the middle, stop
            return;
        }
        // Swap the start element with the corresponding end element
        swap(arr, start, size - start - 1);
        // Recursive call for the next pair
        reverse(arr, size, start + 1);
    }

    /**
     * Main function for Exercise 11.4
     */
    void Ex_11_4_main() {
		cout << "Exercise 11.4:\n";
		cout << "This program reverses an array of integers." << endl;
        int* arr;
        int num;
		cout << "Enter the size of the array: ";
        cin >> num;

        if (num <= 0) {
            cout << "ERROR: Number must be positive." << endl;
            
        }

        arr = new int[num];
        cout << "Enter array values: ";
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }

        cout << "Before: \n";
        for (int i = 0; i < num; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        reverse(arr, num);

        cout << "After: \n";
        for (int i = 0; i < num; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr; // Deallocate dynamic memory
      
    }
       
    
}