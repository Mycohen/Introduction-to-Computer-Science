# include <iostream>
using namespace std;

namespace Exercises
{
	/**
  * Calculates the sum of the digits in a given number.
  * 
  * @param n The number for which to calculate the sum of digits.
  * @return The sum of the digits in the given number.
  */
	long sumDigits(long n)
	{
		int sumOfdigit = 0, a = 0;
		while (n > 0)
		{
			a = n % 10; // a is the last digit of the number.
			n /= 10;
			sumOfdigit = sumOfdigit + a; // Calculates the sum of the digit.
		}
		return sumOfdigit;
	}

	/**
  * Calculates the last digit ID for a given number.
  * 
  * @param num The number for which to calculate the last digit ID.
  * @return The last digit ID for the given number.
  */
	long lastDigitID(long num)
	{
		int sum = 0, i, lastDigitID = 0, oneDigitId;
		for (i = 0; num > 0; i++)
		{
			oneDigitId = num % 10; // The last digit ID.
			if (i % 2 == 0) // If the location number is even, the program multiplies by two (the formula given).
				oneDigitId *= 2;
			sum = sum + sumDigits(oneDigitId); // Calculates the sum.
			num /= 10;
		}
		if (sum % 10 == 0) // If the sum % 10 is equal to 0, the last digit ID is 0.
		{
			return 0;
		}
		lastDigitID = 10 - (sum % 10); // The last digit ID.
		return lastDigitID;
	}

	/**
  * Main function for Exercise 5.3.
  * Prompts the user to enter an ID number and calculates the full ID by appending the last digit ID.
  */
	void Ex_5_3_main()
	{
		cout << "Exercise 5.3" << endl;
		cout << "This program will calculate the full ID by appending the last digit ID." << endl;
		long num;
		const long minID = 10000000, maxID = 99999999; // Checking that the ID number is correct.
		cout << "Enter your ID:";
		cin >> num;
		while (num < minID || num > maxID) // Checking that the ID number is correct.
		{
			cout << "ERROR" << endl;
			cin >> num;
		}
		cout << "Your full ID is:" << num << lastDigitID(num) << endl; // Prints the complete ID.
	}
}