#include<iostream> 
using namespace std;

namespace Exercises {
	/**
  * Checks if the given vector is sorted in descending order.
  * 
  * @param vector The vector to be checked.
  * @param SIZE The size of the vector.
  * @return True if the vector is sorted in descending order, false otherwise.
  */
	bool descendingOrder(int vector[], int SIZE);

	/**
  * Receives values for the array and checks the integrity of the input.
  * 
  * @param SIZE The size of the array.
  * @param Arr The array to store the input values.
  * @param sizeOf The size of the input values.
  */
	void checkInputFunction(const int SIZE, int  Arr[], int& sizeOf);

	/**
  * Merges two arrays into a third array.
  * 
  * @param vectorA The first array to be merged.
  * @param vectorB The second array to be merged.
  * @param mergArray The array to store the merged values.
  * @param sizeA The size of the first array.
  * @param sizeB The size of the second array.
  */
	void mergingTwoArrays(int vectorA[], int vectorB[], int mergArray[], int sizeA, int sizeB);

	/**
  * Main function for Exercise 7.2.
  */
	void Ex_7_2_main()
	{
		const int MAXSIZE = 10;
		int firstArr[MAXSIZE], secondArr[MAXSIZE], thirdArr[MAXSIZE];
		int tempArr[MAXSIZE * 2], mergeArr[MAXSIZE * 3];
		int sizeArr1 = 0, sizeArr2 = 0, sizeArr3 = 0;
		cout << "Enter values for the first vector:" << endl;
		//Absorption of values into first array.
		checkInputFunction(MAXSIZE, firstArr, sizeArr1);
		cout << "Enter values for the second vector:" << endl;
		//Absorption of values into first array.
		checkInputFunction(MAXSIZE, secondArr, sizeArr2);
		cout << "Enter values for the third vector:" << endl;
		//Absorption of values into first array.
		checkInputFunction(MAXSIZE, thirdArr, sizeArr3);
		//Merger of first and second arrays into "temporary" array.
		mergingTwoArrays(firstArr, secondArr, tempArr, sizeArr1, sizeArr2);
		//Merger of "temporary" and third arrays into merge array.
		mergingTwoArrays(tempArr, thirdArr, mergeArr, sizeArr1 + sizeArr2, sizeArr3);
		//prints the values of merge array.
		cout << "Merged vector is:" << endl;
		for (int i = 0; i < sizeArr1 + sizeArr2 + sizeArr3; i++)
			cout << mergeArr[i] << ' ';
	}

	/**
  * Receives values for the array and checks the integrity of the input.
  * 
  * @param SIZE The size of the array.
  * @param Arr The array to store the input values.
  * @param sizeOf The size of the input values.
  */
	void checkInputFunction(const int SIZE, int  Arr[], int& sizeOf)
	{
		int i;
		for (i = 0; i < SIZE; i++)
		{
			cin >> Arr[i];
			if (Arr[i] == 0)
				break;
		}
		//If the values are not in ascending order, they are re-absorbed.
		while ((descendingOrder(Arr, SIZE)) == false)
		{
			cout << "ERROR" << endl;
			for (int j = 0; j < SIZE; j++)
			{
				cin >> Arr[j];
				if (Arr[j] == 0)
					break;
			}
		}
		if (i != SIZE)
			sizeOf = i;
	}

	/**
  * Checks if the given vector is sorted in descending order.
  * 
  * @param vector The vector to be checked.
  * @param SIZE The size of the vector.
  * @return True if the vector is sorted in descending order, false otherwise.
  */
	bool descendingOrder(int vector[], const int SIZE)
	{
		for (int i = 0; i < SIZE - 1 && vector[i] != 0; i++)
		{
			if (vector[i] <= vector[i + 1] || vector[i] < 0)
			{
				return false;
			}
		}
		return true;
	}

	/**
  * Merges two arrays into a third array.
  * 
  * @param vectorA The first array to be merged.
  * @param vectorB The second array to be merged.
  * @param mergArray The array to store the merged values.
  * @param sizeA The size of the first array.
  * @param sizeB The size of the second array.
  */
	void mergingTwoArrays(int vectorA[], int vectorB[], int mergArray[], int sizeA, int sizeB)
	{
		int pVecA = 0, pVecB = 0, pVecMerg = 0;
		while (pVecA < sizeA && pVecB < sizeB)
		{
			if (vectorA[pVecA] > vectorB[pVecB])
				mergArray[pVecMerg++] = vectorA[pVecA++];
			else
				mergArray[pVecMerg++] = vectorB[pVecB++];
		}
		while (pVecA < sizeA)
		{
			mergArray[pVecMerg++] = vectorA[pVecA++];
		}
		while (pVecB < sizeB)
		{
			mergArray[pVecMerg++] = vectorB[pVecB++];
		}
	}
}
