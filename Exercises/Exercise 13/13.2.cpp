#include <iostream>
#include <fstream>
using namespace std;

namespace Exercises {
    /**
     * Counts the occurrences of a given string in a file.
     * 
     * @param file The input file stream.
     * @param searchStr The string to search for.
     * @return The number of occurrences of the search string in the file.
     */
    int countOccurrences(ifstream& file, const string& searchStr) {
        string word;
        int count = 0;

        // Read words from the file and count occurrences of searchStr
        while (file >> word) {
            if (word == searchStr) {
                count++;
            }
        }

        return count;
    }

    /**
     * Main function to count occurrences of a string in a file.
     */
    void Ex_13_2_main() {
		cout << "Exercise 13.2" << endl;
        ifstream file("file.txt");

        // Check if the file is opened successfully
        if (!file.is_open()) {
            cout << "The file file.txt could not be opened" << endl;
            
        }

        // Get the string to search from the user
        string searchStr;
        cout << "Enter the string to search for: ";
        cin >> searchStr;

        // Count occurrences of the string in the file
        int count = countOccurrences(file, searchStr);

        // Print the result
        cout << "The string " << searchStr << " was found " << count << " times in the file." << endl;

        // Close the file
        file.close();
    }
}