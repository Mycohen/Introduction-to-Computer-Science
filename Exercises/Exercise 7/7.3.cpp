#include<iostream> 
using namespace std;

namespace Exercises {
	/**
  * Corrects the input values in the given 2D array.
  * 
  * @param arr The 2D array to correct the input values.
  */
	void correctInput(int arr[][10])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cin >> arr[i][j];
				while (arr[i][j] < 0)
				{
					cout << "ERROR" << endl;
					cin >> arr[i][j];
				}
			}
		}
	}

	/**
  * Prints the given matrix.
  * 
  * @param matrix The matrix to print.
  */
	void printMatrix(int matrix[][10])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}

	/**
  * Sorts the given vector using the insertion sort algorithm.
  * 
  * @param vec The vector to sort.
  * @param size The size of the vector.
  */
	void insertSort(int* vec, int size)
	{
		int first, i;
		for (first = 1; first < size; first++)
		{
			int tmp = vec[first];
			for (i = first; i > 0 && tmp < vec[i - 1]; i--)
				vec[i] = vec[i - 1];
			vec[i] = tmp;
		}
	}

	/**
  * Sorts the upper triangle of the given matrix in ascending order.
  * 
  * @param matrix The matrix to sort.
  * @param tempVec The temporary vector used for sorting.
  * @param UPPER The size of the upper triangle.
  */
	void upperTriangle(int matrix[][10], int tempVec[], const int UPPER)
	{
		int k = 0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j < 10 - i; j++)
			{
				tempVec[k] = matrix[i][j + i];
				k++;
			}
		}
		k = 0;
		insertSort(tempVec, UPPER);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j < 10 - i; j++)
			{
				matrix[i][j + i] = tempVec[k];
				k++;
			}
		}
	}

	/**
  * Sorts the bottom triangle of the given matrix in ascending order.
  * 
  * @param matrix The matrix to sort.
  * @param tempVec The temporary vector used for sorting.
  * @param BOTTOM The size of the bottom triangle.
  */
	void bottomTriangle(int matrix[][10], int tempVec[], const int BOTTOM)
	{
		int k = 0;
		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < i; j++)
			{
				tempVec[k] = matrix[i][j];
				k++;
			}
		}
		k = 0;
		insertSort(tempVec, BOTTOM);
		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < i; j++)
			{
				matrix[i][j] = tempVec[k];
				k++;
			}
		}
	}

	/**
  * Main function for exercise 7.3.
  */
	void Ex_7_3_main()
	{
		cout << "Exercise 7.3: \n";
		cout << "This program sorts the upper and lower triangles of a 10x10 matrix in ascending order.\n\n";
		int matrix[10][10];
		cout << "Enter the values:" << endl;
		correctInput(matrix);
		cout << "\n" << "Before sorted:\n";
		printMatrix(matrix);
		cout << endl;
		const int UPPERTRIANGLE = 45, BOTTOMTRIANGLE = 45;
		int tempVec[UPPERTRIANGLE];
		upperTriangle(matrix, tempVec, UPPERTRIANGLE);
		bottomTriangle(matrix, tempVec, BOTTOMTRIANGLE);
		cout << "Sorted matrix:\n";
		printMatrix(matrix);
		cout << endl;
	}
}
