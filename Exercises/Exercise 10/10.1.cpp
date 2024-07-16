#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
namespace Exercises{
    /**
 * Encrypts a string by replacing each character with its corresponding character from the opposite end of the alphabet.
 * Only alphabetic characters are encrypted, while non-alphabetic characters remain unchanged.
 *
 * @param string The string to be encrypted.
 */
    void crypto(char string[])
    {
        for (int i = 0; i < 80; i++)
        {
            if (string[i] == '\0')
                break;

            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = 'z' - (string[i] - 'a');
            }
            else if (string[i] >= 'A' && string[i] <= 'Z')
            {
                string[i] = 'Z' - (string[i] - 'A');
            }
        }
    }

    /**
     * Main function to demonstrate the encryption of a string.
     */
    void Ex_10_1_main()
	{
		cout << "Exercise 10.1\n";
		cout << "Welcome to the encryption program!\n" << "This program encrypts a string by replacing each character with its corresponding character from the opposite end of the alphabet.\n";
        char string[81];
        cout << "Enter a string (max 80 characters):\n";
        cin.getline(string, 81);
        crypto(string);
        cout << "After encryption:\n" << string << endl;
    }
}
