# include <iostream>
using namespace std;

namespace Exercises
{
    /**
     * Checks if a given number is prime.
     * 
     * @param n The number to check.
     * @return True if the number is prime, false otherwise.
     */
    bool isPrime(int n)
    {
        for (int i = 2; i < n; i++)//i should be greater than 1 because 1 is not a prime number.
        {
            if (n % i == 0)//That is - the number is not a prime number
                return false;

        }
        return true;
    }

    /**
     * Prints the nearest prime number to the given number.
     * 
     * @param number The number for which to find the nearest prime.
     */
    void findPrime(int number)//A function that prints the nearest prime number.
    {
        if (isPrime(number) == true)//If the number received is prime we will print the number
            cout << number << " ";
        else//We will need to print the nearest greater prime number.
        {
            for (int i = 1; i < number; i++)
            {
                if (isPrime(number + i) == true)//Printingthe nearest greater prime number. 
                {
                    cout << number + i << " ";
                    break;
                }
            }
        }
    }

    /**
     * Main function for Exercise 5.4.
     */
    void Ex_5_4_main()
    {
        srand((unsigned)time(NULL));
        int num;
        cout << "Enter number of values: ";
        cin >> num;
        if (num > 0)//Printing the nearest greater prime number (or the number himself if he is a prime number).
        {
            cout << "Table size: ";
            findPrime(num);
        }
        else
        {
            num = rand() % 91 + 10;//The number range given in the exercise.
            cout << "Table size: ";
            findPrime(num);
        }
        cout << endl;
    }
}