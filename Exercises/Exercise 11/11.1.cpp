#include <iostream>
using namespace std;

namespace Exercises {
    /**
     * Recursively prints 'a' n times if n is positive.
     * Prints 'b' n times if n is zero.
     * 
     * @param n The number of times to print 'a' or 'b'.
     */
    void printABs(int n) {
        if (n > 0) {
            cout << 'a';
            printABs(n - 1);
        }
        else if (n == 0) {
            int i = 0;
            while (i < n) {
                cout << 'b';
                i++;
            }
        }
    }

    /**
     * Prints 'a' n times using the printABs function,
     * followed by printing 'b' n times using a loop.
     * 
     * @param n The number of times to print 'a' and 'b'.
     */
    void printABsWrapper(int n) {
        printABs(n);
        for (int i = 0; i < n; ++i) {
            cout << 'b';
        }
    }

    /**
     * Main function for Exercise 11.1.
     * Prompts the user to enter a number,
     * then calls the printABsWrapper function with the entered number.
     */
    void Ex_11_1_main() {
		cout << "Exercise 11.1:\n";
		cout << "In this program you will enter a number and the program will print 'a' n times and 'b' n times." << endl;
        int number;
        cout << "Enter a number:" << endl;
        cin >> number;
        printABsWrapper(number);
    }
}
