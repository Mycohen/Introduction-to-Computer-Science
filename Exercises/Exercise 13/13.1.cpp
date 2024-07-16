#include <iostream>
#include <fstream>
using namespace std;
/*
* The program calculates the average of numbers in two files and compares their averages.
*
*/
namespace Exercises {

    /**
     * Calculates the average of numbers in a file.
     * 
     * @param file The input file stream.
     * @return The average of the numbers in the file.
     */
    double calculateAverage(ifstream& file) {
        double sum = 0;
        int count = 0;
        double number;

        // Read numbers from the file and calculate sum and count
        while (file >> number) {
            sum += number;
            count++;
        }

        // Return the average if count is not zero
        if (count == 0) {
            return 0;
        }

        return sum / count;
    }

    /**
     * Main function to calculate the average of numbers in two files and compare their averages.
     */
    void Ex_13_1_main() {
		cout << "Exercise 13.1" << endl;
        ifstream file1("grade1.txt");
        ifstream file2("grade2.txt");

        // Check if files are opened successfully
        if (!file1.is_open()) {
            cout << "The file grade1.txt could not be opened" << endl;

        }

        if (!file2.is_open()) {
            cout << "The file grade2.txt could not be opened" << endl;

        }

        // Calculate averages
        double avg1 = calculateAverage(file1);
        double avg2 = calculateAverage(file2);

        // Compare and print which file has the highest average
        if (avg1 > avg2) {
            cout << "highest average found in file 1" << endl;
        }
        else {
            cout << "highest average found in file 2" << endl;
        }

        // Close the files
        file1.close();
        file2.close();


    }
}
