#include<iostream> 
using namespace std;

namespace Exercises {
	/**
  * Takes user input for a 2D character array.
  * @param arr The 2D character array to store the input.
  */
	void Input(char arr[][5])
	{
		cout << "Enter 10 words:" << endl;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> arr[i][j];
			}
		}
	}

	/**
  * Prints the sorted 2D character array.
  * @param matrix The 2D character array to print.
  */
	void printMatrix(char matrix[][5])
	{
		cout << "After sorting:\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << matrix[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}

	/**
  * Checks if the input in the 2D character array is valid.
  * @param matrix The 2D character array to check.
  * @return True if the input is valid, false otherwise.
  */
	bool checkInput(char matrix[][5])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (matrix[i][j] < 'a' || matrix[i][j] > 'z')
					return false;
			}
		}
		return true;
	}

	/**
  * Sorts the 2D character array using bubble sort algorithm.
  * @param matrix The 2D character array to sort.
  */
	void bubbleSort(char matrix[][5])
	{
		for (int i = 1; i < 10; i++)
		{
			int k = 0;
			char temp[5];
			for (int j = 0; j < 10 - i; j++)
			{
				k = 0;
				while (matrix[j][k] == matrix[j + 1][k] && k < 5)
				{
					k++;
					if (matrix[j][k] > matrix[j + 1][k])
					{
						for (int t = 0; t < 5; t++)
						{
							temp[t] = matrix[j][t];
							matrix[j][t] = matrix[j + 1][t];
							matrix[j + 1][t] = temp[t];
						}
					}
				}
				if (matrix[j][k] > matrix[j + 1][k])
				{
					for (int t = 0; t < 5; t++)
					{
						temp[t] = matrix[j][t];
						matrix[j][t] = matrix[j + 1][t];
						matrix[j + 1][t] = temp[t];
					}
				}
			}
		}
	}

	/**
  * Main function for exercise 7.4.
  * Reads user input, checks its validity, sorts the input, and prints the sorted result.
  */
	void Ex_7_4_main()
	{
		char matrix[10][5];
		Input(matrix);
		if (checkInput(matrix) == false)
		{
			cout << "ERROR\n";
		}

		bubbleSort(matrix);

		printMatrix(matrix);
	}
}
