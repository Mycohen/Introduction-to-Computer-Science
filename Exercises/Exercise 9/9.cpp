#include<iostream> 
using namespace std;
namespace Exercises {

	void newClass(int*& ptrToDataBase, int& sizeODB, int classCode)
	{
		if (sizeODB == 0)
		{
			ptrToDataBase = new int[sizeODB];
		}
		bool flag = true;
		for (size_t i = 0; i < sizeODB; i++)
		{
			if (ptrToDataBase[i] == classCode)
				flag = false;
		}
		if (flag)
		{
			int newSizeODB = sizeODB + 1;
			int* help = new int[newSizeODB];
			int i;
			for (i = 0; i < sizeODB; i++)
			{
				help[i] = ptrToDataBase[i];
			}
			help[i] = classCode;
			delete[]  ptrToDataBase;
			ptrToDataBase = help;
			sizeODB = newSizeODB;
			if (sizeODB > 1)
			{
				for (int j = 1; j < sizeODB; j++)
				{
					for (int k = 0; k < sizeODB - j; k++)
					{
						if (ptrToDataBase[k] > ptrToDataBase[k + 1])
						{
							int temp = ptrToDataBase[k];
							ptrToDataBase[k] = ptrToDataBase[k + 1];
							ptrToDataBase[k + 1] = temp;
						}
					}
				}

			}
		}
	}
	void delClass(int*& ptrToDataBase, int& sizeODB, int classCode)
	{
		bool flag = false;
		for (size_t i = 0; i < sizeODB; i++)
		{
			if (ptrToDataBase[i] == classCode)
				flag = true;
		}
		if (flag)
		{
			int newSizeODB = sizeODB - 1;
			int* help = new int[newSizeODB];
			int i = 0;
			int m = 0;
			while (ptrToDataBase[i] < classCode)
			{
				help[m++] = ptrToDataBase[i++];
			}
			i++;
			while (ptrToDataBase[i] > classCode && i < sizeODB)
			{
				help[m++] = ptrToDataBase[i++];
			}
			delete[]  ptrToDataBase;
			ptrToDataBase = help;
			sizeODB = newSizeODB;
		}
	}
	void printAll(int* dataBase, int sizeODB)
	{
		for (size_t i = 0; i < sizeODB; i++)
		{
			cout << dataBase[i] << ' ';
		}
	}
	int* searchClass(int* dataBase, int sizeODB, int classCode)
	{
		int result = -1;
		int low = 0;
		int mid;
		int high = sizeODB - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (classCode == dataBase[mid])
			{
				result = mid;
				break;
			}
			else if (classCode > dataBase[mid])
			{
				low = mid + 1;
			}
			else { high = mid - 1; }
		}
		if (result != -1)
			return dataBase + mid;
		else
			return NULL;
	}
	void printCode(int* dataBase, int sizeODB, int machonCode)
	{
		for (size_t i = 0; i < sizeODB; i++)
		{
			if (*(dataBase + i) / 1000 == machonCode)
			{
				cout << *(dataBase + i) << ' ';
			}
		}
	}
	void Ex_9_main()
	{
		cout << "Exercise 9\n";
		cout << "This program manages a database of classrooms.\n";
		int* dataBase = NULL;
		int num = 0, sizeODB = 0, machonCode;
		cout << "Enter 0 to add a new classroom." << endl;
		cout << "Enter 1 to delete a hybrid classroom." << endl;
		cout << "Enter 2 to search for a specific classroom." << endl;
		cout << "Enter 3 to print all the classrooms for a specific Machon." << endl;
		cout << "Enter 4 to print all the hybrid classrooms." << endl;
		cout << "Enter 5 to exit." << endl;
		cout << "Enter your choice: ";
		enum choice { NEWCLASS = 0, DELCLASS, SEARCHCLASS, PRINTCODE, PRINTALL };
		cin >> num;
		while (num < 0 || num>5)
		{
			cout << "ERROR" << endl;
			cin >> num;
		}
		while (num != 5)
		{
			switch (num)
			{
			case NEWCLASS: cout << "Enter the code of the classroom to add: ";
				int classCode; cin >> classCode;
				while (classCode < 10000 || classCode>99999)
				{
					cout << "ERROR\n";
					cin >> classCode;
				}
				newClass(dataBase, sizeODB, classCode);
				printAll(dataBase, sizeODB); cout << endl;
				break;
			case DELCLASS:cout << "Enter the code of the classroom to delete: ";
				cin >> classCode;
				while (classCode < 10000 || classCode>99999)
				{
					cout << "ERROR\n";
					cin >> classCode;
				}
				delClass(dataBase, sizeODB, classCode);
				printAll(dataBase, sizeODB); cout << endl;
				break;
			case SEARCHCLASS:cout << "Enter the code of the classroom to search for: ";
				cin >> classCode;
				if (searchClass(dataBase, sizeODB, classCode) == NULL)
					cout << "Not found" << endl;
				else cout << "Found" << endl;
				break;
			case PRINTCODE:cout << "Enter the code of the Machon: ";
				cin >> machonCode;
				while (machonCode < 10 || machonCode>99)
				{
					cout << "ERROR\n";
					cin >> machonCode;
				}
				printCode(dataBase, sizeODB, machonCode);
				cout << endl;
				break;
			case PRINTALL:printAll(dataBase, sizeODB);
				cout << endl;
				break;
			}
			cout << "Enter your next choice: ";
			cin >> num;
			while (num < 0 || num>5)
			{
				cout << "ERROR" << endl;
				cin >> num;
			}
		}
		
	}
}