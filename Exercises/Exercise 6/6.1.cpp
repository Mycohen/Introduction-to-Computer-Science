#include<iostream> 
using namespace std;

namespace Exercises
{
	/**
  * @brief Checks if all the numbers in the range of 1 to 15 are present in the array.
  * 
  * @param arr The array of integers to be checked.
  * @return true if all numbers are present, false otherwise.
  */
	bool checkingArray(int arr[])
	{
		for (int i = 0; i < 15; i++)
		{
			if (arr[i] > 15 || arr[i] < 1)
				return false;
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (arr[j] == arr[i])
						return false;
				}
			}
		}
		return true;
	}

	/**
  * @brief Main function for Exercise 6.1.
  * 
  * Prompts the user to enter 15 numbers, stores them in an array, and checks if all numbers are present.
  * Prints "GOOD" if all numbers are present, otherwise prints "NOT GOOD".
  */
	void Ex_6_1_main()
	{
		cout << "Exercise 6.1" << endl;
		cout << "This program will check if all the numbers in the range of 1 to 15 are present in the array." << endl;
		cout << "enter 15 numbers: ";
		int arr[15] = { 0 };
		for (int i = 0; i < 15; i++)
		{
			cin >> arr[i];
		}
		if (checkingArray(arr))
			cout << "GOOD" << endl;
		else
			cout << "NOT GOOD" << endl;
	}
}
