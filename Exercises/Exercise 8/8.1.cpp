#include<iostream> 

using namespace std;
namespace Exercises {
	/**
  * @brief Calculates the size of the jump between two arrays when an equality is found.
  * 
  * @param ptr1 Pointer to the first array.
  * @param big[] The first array.
  * @param ptr2 Pointer to the second array.
  * @param small[] The second array.
  * @param size1 The size of the first array.
  * @param size2 The size of the second array.
  * @return The size of the jump if a constant difference is found, otherwise returns 770.
  */
	int jump(int* ptr1, int big[], int* ptr2, int small[], const int size1, const int size2)
	{
		ptr1 += 1;
		bool flag = true;
		int counter = 0;
		if (size2 == 1)
			return 0;
		while (ptr1 < big + size1)
		{
			if (*ptr1 == *(ptr2 + 1))
				break;
			else
			{
				counter++;
			}

			ptr1++;
		}
		ptr2 += 2;

		ptr1 = ptr1 + counter + 1;
		while (ptr2 < small + size2)
		{
			if (*(ptr1) != *ptr2)
			{
				flag = false;
			}
			if (counter == 0)
			{
				ptr1++;
			}
			else
				ptr1 = ptr1 + counter + 1;
			ptr2++;

		}
		if (flag == true)
		{
			return counter;
		}
		else
		{
			return 	770;
		}
	}

	/**
  * @brief Checks for equality between elements in two arrays and finds the minimum jump size.
  * 
  * @param big[] The first array.
  * @param small[] The second array.
  * @param size1 The size of the first array.
  * @param size2 The size of the second array.
  * @return The minimum jump size if an equality is found, otherwise returns -1.
  */
	int checkequality(int big[], int small[], const int size1, const int size2)
	{
		int min = 770, counter = 0;
		int* ptr1 = big, * ptr2 = small;
		while (ptr1 < big + size1)
		{
			if (*ptr2 == *ptr1)
			{
				counter = jump(ptr1, big, ptr2, small, size1, size2);
				if (counter < min)
				{
					min = counter;
				}
			}
			ptr1++;
		}
		if (min == 770)
		{
			return -1;
		}
		else
		{
			return min;
		}
	}

	/**
  * @brief Takes input for two arrays and calculates the minimum jump size.
  * 
  * @param big Pointer to the first array.
  * @param small Pointer to the second array.
  * @param size1 Reference to the size of the first array.
  * @param size2 Reference to the size of the second array.
  */
	void input(int* big, int* small, int& size1, int& size2)
	{
		cout << "Enter the size of big:\n";
		cin >> size1;
		while (size1 <= 0 || size1 > 80)
		{
			cout << "ERROR\n"; cin >> size1;
		}
		cout << "Enter " << size1 << " numbers:\n";
		for (int i = 0; i < size1; i++)
		{
			cin >> *(i + big);
		}
		cout << "Enter the size of small:\n";
		cin >> size2;
		while (size2 <= 0 || size2 > 80)
		{
			cout << "ERROR\n"; cin >> size2;
		}
		cout << "Enter " << size2 << " numbers:\n";

		for (int i = 0; i < size2; i++)
		{
			cin >> *(i + small);
		}
	}

	/**
  * @brief Main function to calculate the minimum jump size between two arrays.
  */
	void Ex_8_1_main()
	{
		cout << "Exercise 8.1\n";
		cout << "This program calculates the size of the jump between two arrays when an equality is found.\n"
		int big[80] = { 0 }, small[80] = { 0 }, size1 = 0, size2 = 0;
		input(big, small, size1, size2);
		cout << "Size of jump:\n" << checkequality(big, small, size1, size2) << endl;
	}
}
