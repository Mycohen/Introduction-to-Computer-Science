
/*
Author: Moshe Jacob Cohen
Course: Computer science Introduction 150005
Exercise: 6.4
Description: The program picks up six positive decimal fractions different from each other
and creates a new array of 6-integers, in which the serial values of the array numbers respectively appear.
*/

#include<iostream> 
using namespace std;

namespace Exercises {
	/**
  * Sorts the indices of an array of positive decimal fractions in ascending order.
  * 
  * @param num The array of positive decimal fractions.
  * @param indc The array to store the sorted indices.
  */
	void sortedIndices(float num[], int indc[]) {
		int i, j, k = 0;
		bool flag1;
		for (i = 0; i < 6; i++) {
			flag1 = true;
			for (j = 0; j < 6; j++) {
				if (num[i] > num[j]) {
					flag1 = false;
					break;
				}
			}

			if (flag1 && num[i] != 1) {
				indc[k] = i;
				k++;
				num[i] = 1;
				i = -1;
			}
		}
	}

	/**
  * The main function.
  */
	void Ex_6_4_main() {
		cout << "Exercise 6.4" << endl;
		cout << "The program picks up six positive decimal fractions different from each other and creates a new array of 6-integers, in which the serial values of the array numbers respectively appear." << endl;
		float numbers[6];
		int indices[6];
		bool flag = true;
		cout << "enter  6 numbers between 0 and 1: ";
		for (int i = 0; i < 6; i++) {
			cin >> numbers[i];
			if (numbers[i] >= 1 || numbers[i] <= 0) {
				flag = false;
			}
		}
		if (!flag) {
			cout << "ERROR";
			for (int j = 0; j < 6; j++) {
				cin >> numbers[j];
			}
		}
		sortedIndices(numbers, indices);
		cout << endl;
		cout << "sorted indices:" << endl;
		for (int k : indices) {
			cout << k << ' ';
		}
	}
}
