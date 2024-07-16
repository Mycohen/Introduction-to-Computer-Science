#include<iostream> 
using namespace std;

namespace Exercises {
	/**
  * Performs a binary search on a sorted array to find the index of a given item.
  * 
  * @param vector The sorted array to search.
  * @param sizeOfArr The size of the array.
  * @param item The item to search for.
  * @return The index of the item if found, -1 otherwise.
  */
	int binarySearch(int vector[], int sizeOfArr, int item)
	{
		int result = -1;
		int low = 0, mid;
		int high = sizeOfArr - 1; // N - # of elements
		
		while (low <= high)
		{
			mid = (low + high) / 2;
			
			if (item == vector[mid])
			{
				result = mid;
				break;
			}
			else if (item > vector[mid])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		
		return result;
	}

	/**
  * Checks if an array is in increasing order.
  * 
  * @param vector The array to check.
  * @param size The size of the array.
  * @return True if the array is in increasing order, false otherwise.
  */
	bool increase(int vector[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (vector[i] >= vector[i + 1])
			{
				return false;
			}
		}
		
		return true;
	}

	/**
  * Main function for Exercise 7.1.
  * 
  * Prompts the user to enter 10 numbers, checks if they are in increasing order,
  * and performs a binary search on the array to find a given number.
  */
	void Ex_7_1_main()
	{
		int vector[10], sizeOfArr = 10, item, local;
		
		cout << "Enter 10 numbers: ";
		for (int i = 0; i < sizeOfArr; i++)
		{
			cin >> vector[i];
		}

		while (!increase(vector, sizeOfArr))
		{
			cout << "ERROR" << endl;
			for (int j = 0; j < sizeOfArr; j++)
			{
				cin >> vector[j];
			}
		}
		
		cout << endl;
		cout << "Enter 1 number: ";
		cin >> item;
		cout << endl;
		
		local = binarySearch(vector, sizeOfArr, item);
		
		if (local == -1)
		{
			cout << "Not found" << endl;
		}
		else
		{
			cout << "The number " << item << " was found at index " << local << endl;
		}
	}
}
