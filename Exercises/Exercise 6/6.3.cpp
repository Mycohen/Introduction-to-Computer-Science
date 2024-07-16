/*
Author: Moshe Jacob Cohen
Course:Computer science Introduction 150005
Exercise:6.3
Description: The program picks up numbers (until 100 numbers) and creates a new array that updates the array
so that each number in it appears only once
*/

#include<iostream> 
using namespace std;
namespace Exercises {
	/**
  * Creates a new array that updates the input array so that each number appears only once.
  * 
  * @param arr The input array.
  * @param sizeOfArr The size of the input array.
  * @param counter A reference to an integer that will store the number of elements in the new array.
  */
	void newArray(int arr[], const int sizeOfArr, int& counter)//First function that creates the new array
	{

		for (int i = 0; i < sizeOfArr; i++)//aloop that compares the first number to the rest of the numbers.
		{
			for (int j = i + 1; j < sizeOfArr; j++)
			{
				if (arr[i] == arr[j])//If there is an element that appears more than one times, we will replace in this number by a 0. 
				{
					arr[j] = 0;
				}
			}
			if (arr[i] != 0)//Printing the new vector (if the element isn't equal to 0)
			{
				cout << arr[i] << " ";
				counter++;
			}

		}

	}


	/**
  * The main function that prompts the user to enter up to 100 values and creates the new array.
  */
	void Ex_6_3_main()//The main function
	{
		cout << "Exercise 6.3" << endl;
		cout << "The program picks up numbers (until 100 numbers) and creates a new array that updates the array so that each number in it appears only once" << endl;
		int sizeOfArray, i, arr[100] = { 0 }, counter = 0;
		cout << "enter up to 100  values, to stop enter 0:" << endl;
		for (i = 0; i < 100; i++)
		{
			cin >> arr[i];
			if (arr[i] == 0)
			{
				break;//The condition to stop the input.
			}
		}
		sizeOfArray = i;
		cout << "the new vector is: " << endl;
		newArray(arr, sizeOfArray, counter);
		cout << endl << "number of elements: " << counter << endl;
		
	}
}
