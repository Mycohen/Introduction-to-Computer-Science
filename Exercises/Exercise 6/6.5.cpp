#include<iostream> 
using namespace std;

namespace Exercises
{
	/**
  * Calculates the difference between two sets and stores the result in a new array.
  * 
  * @param setA The first set.
  * @param setB The second set.
  * @param difference The array to store the difference.
  */
	void Difference(int setA[], int setB[], int difference[])
	{
		bool flag;
		int k = 0;
		for (int i = 0; i < 6; i++)
		{
			flag = true;
			for (int j = 0; j < 6; j++)
			{
				if (setA[i] == setB[j])
				{
					flag = false;
					setA[i] = 0;
					break;
				}
			}
			if ((flag == true) & (setA[i] != 0))
			{
				difference[k] = setA[i];
				k++;
			}
		}
	}

	/**
  * Checks if an array is empty.
  * 
  * @param Array The array to check.
  * @return True if the array is not empty, false otherwise.
  */
	bool checkEmpty(int Array[])
	{
		for (int i = 0; i < 6; i++)
		{
			if (Array[i] != 0)
				return true;
		}
		return false;
	}

	/**
  * The main function to calculate the difference between two sets.
  */
	void Ex_6_5_main()
	{
		int set1[6], set2[6], difference[6] = { 0 };
		bool flag = false;
		cout << "enter first 6 numbers:" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> set1[i];
			while (set1[i] <= 0)
			{
				cout << "ERROR" << endl;
				cin >> set1[i];
			}
		}
		cout << "enter next 6 numbers:" << endl;
		for (int j = 0; j < 6; j++)
		{
			cin >> set2[j];
			while (set2[j] <= 0)
			{
				cout << "ERROR" << endl;
				cin >> set2[j];
			}
		}
		Difference(set1, set2, difference);

		if (checkEmpty(difference))
		{
			cout << "set difference is:" << endl;
			for (int nimaasLi = 0; nimaasLi < 6; nimaasLi++)
			{
				if (difference[nimaasLi] != 0)
					cout << difference[nimaasLi] << " ";
			}
		}
		else
			cout << "set difference is:" << endl << "empty" << endl;
	}
}
