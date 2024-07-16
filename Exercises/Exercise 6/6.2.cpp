# include <iostream>
using namespace std;
namespace Exercises {

	/**
  * Compares two vectors and counts the number of times the second vector appears as a subsequence in the first vector.
  * 
  * @param vecA The first vector.
  * @param sizeA The size of the first vector.
  * @param vecB The second vector.
  * @param sizeB The size of the second vector.
  * @return The number of times the second vector appears as a subsequence in the first vector.
  */
	int ComparesVectors(int vecA[], int sizeA, int vecB[], int sizeB)
	{
		int i, j = 0, count = 0;
		if (sizeA < sizeB)
			return 0;
		for (i = 0; i < sizeA; i++)//A for that will run on all the elements of the first array
		{
			while (vecA[i + j] == vecB[j] && j < sizeB)//While the array of i+j (j is allways =0 apart from there is an equaity)
			{
				j++;//Advancing the array
			}
			if (j == sizeB)//The condition that a sereies was completed
			{
				count++;
			}
			j = 0;                 //Reseting the elements in the second array
		}
		return count;
	}

	/**
  * Main function for Exercise 6.2.
  */
	void Ex_6_2_main()
	{
		cout << "Exercise 6.2" << endl;
		cout << "This program compares two vectors and counts the number of times the second vector appears as a subsequence in the first vector." << endl;
		int sizeV1, sizeV2;
		cout << "enter size of first array: ";
		cin >> sizeV1;
		int vector1[500] = { 0 }, vector2[100] = { 0 };


		while (sizeV1 < 1 || sizeV1>500)        //Checking that the input is corect
		{
			cout << "ERROR";
			cin >> sizeV1;
		}
		cout << "enter first array values: ";
		for (int i = 0; i < sizeV1; i++)
			cin >> vector1[i];
		cout << "enter size of second array: ";

		cin >> sizeV2;
		while (sizeV2 < 1 || sizeV1>100)//Checking that the input is corect
		{
			cout << "ERROR";
			cin >> sizeV2;
		}

		cout << "enter second array values: ";
		for (int j = 0; j < sizeV2; j++)
			cin >> vector2[j];
		cout << "result: " << ComparesVectors(vector1, sizeV1, vector2, sizeV2) << " times";  //Sending the information to the function

	

	}

}