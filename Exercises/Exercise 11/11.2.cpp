#include <iostream>
using namespace std;
namespace Exercises {

    /**
     * Recursive function to find the index of the smallest element in the array.
     *
     * @param arr The array of integers.
     * @param size The size of the array.
     * @param index The current index being checked.
     * @param minIndex The index of the current smallest element.
     * @return The index of the smallest element in the array.
     */
    int smallest(int arr[], int size, int index = 0, int minIndex = 0) {
        if (index == size) return minIndex; // Base case: if we've checked all elements, return the minIndex
        if (arr[index] < arr[minIndex]) minIndex = index; // Update minIndex if a smaller element is found
        return smallest(arr, size, index + 1, minIndex); // Recursive call to check the next element
    }
    // Prototype of the recursive function
    

   void Ex_11_2_main() {
        int* arr;
        int number;
		cout << "Exercise 11.2:\n";
		cout << "This program finds the smallest element in an array of integers." << endl;

        // Prompt the user to enter a positive number
        do {
            cout << "Enter the size of the array: ";
            cin >> number;
            if (number <= 0) cout << "ERROR" << endl;
        } while (number <= 0);

        // Allocate memory for the array
        arr = new int[number];

        // Prompt the user to enter the array values
        cout << "Enter array values: ";
        for (int i = 0; i < number; i++) {
            cin >> arr[i];
        }

        // Find the smallest element in the array
        cout << "The smallest is: " << arr[smallest(arr, number)] << endl;

        // Free the allocated memory
        delete[] arr;
       
    }

}
