#include <iostream>
#include <cstring>
using namespace std;
namespace Exercises {// Function to reverse each word in the sentence string
    /**
     * Reverses each word in the given sentence.
     * 
     * @param sentence The sentence to be reversed.
     */
    void reverse(char sentence[]) {
        int length = strlen(sentence);
        int start = 0;

        for (int i = 0; i <= length; ++i) {
            // When a space or end of string is found, reverse the word
            if (sentence[i] == ' ' || sentence[i] == '\0') {
                int end = i - 1;

                // Reverse the characters of the word
                while (start < end) {
                    char temp = sentence[start];
                    sentence[start] = sentence[end];
                    sentence[end] = temp;
                    ++start;
                    --end;
                }

                // Move to the start of the next word
                start = i + 1;
            }
        }
    }

    void Ex_10_2_main() {
		cout << "Exercise 10.2:\n";
		cout << "This program reverses each word in a sentence." << endl;
        char sentence[81];
        cout << "Enter a string: " << endl;
        cin.getline(sentence, 81);

        reverse(sentence);

        cout << "After reverse: " << sentence << endl;

      
    }
}
