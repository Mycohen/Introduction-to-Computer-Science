/*
Author: Moshe Jacob Cohen, ID:324692680
Course:Computer science Introduction 150005
Exercise:12
Description: The program is a store management system that allows the user 
to add items to the store, find the price of an item, order items that are below the minimum amount, 
update the amount of an item that has been sold, and print the details of each item in the store.
*/
# include <iostream>
# include<cstring>
# include<string>
#pragma warning (disable:4996)
using namespace std;
namespace Exercises {
	struct Item
	{
		int code;
		char name[21];
		int amount;
		int min;
		float price;
	};
	/**
  * @brief Prints the details of each item in the store.
  * 
  * @param store Pointer to the array of items in the store.
  * @param numItems The number of items in the store.
  */
	void print(Item* store, int numItems)
	{
		for (int i = 0; i < numItems; i++)
		{
			cout << "name: " << store[i].name << endl;

			cout << "code: " << store[i].code << endl;
			cout << "amount: " << store[i].amount << endl;
			cout << "minimum amount: " << store[i].min << endl;
			cout << "price: " << store[i].price << endl;

		}
	}
	/**
  * @brief Finds the price of an item based on its code.
  * 
  * @param store Pointer to the array of items in the store.
  * @param numItems The number of items in the store.
  */
	void findPrice(Item* store, int numItems)
	{
		cout << "enter code: ";
		int codeToSearch;
		cin >> codeToSearch;
		bool flag = false;
		for (int i = 0; i < numItems; i++)
		{
			if (store[i].code == codeToSearch)
			{
				cout << "price: " << store[i].price << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "ERROR" << endl;
		}
	}
	/**
  * @brief Orders items that have an amount below the minimum.
  * 
  * @param store Pointer to the array of items in the store.
  * @param numItems The number of items in the store.
  */
	void order(Item* store, int numItems)
	{
		int amountTO;
		for (int i = 0; i < numItems; i++)
		{
			if (store[i].amount < store[i].min)
			{
				amountTO = (store[i].min - store[i].amount) + 5;

				cout << "item name: " << store[i].name << endl;
				cout << "code: " << store[i].code << endl;
				cout << "amount to order: " << amountTO << endl;

			}
		}
	}
	/**
  * @brief Updates the amount of an item that has been sold.
  * 
  * @param store Pointer to the array of items in the store.
  * @param numItems The number of items in the store.
  */
	void sold(Item*& store, int numItems)
	{
		cout << "enter code:" << endl;
		int itemCode, amount;
		cin >> itemCode;
		cout << "enter amount:" << endl;
		cin >> amount;
		bool flag = true;
		for (int i = 0; i < numItems; i++)
		{
			if (store[i].code == itemCode)
			{
				flag = false;
				if (amount - store[i].amount < 0)
				{
					store[i].amount = 0;
					break;
				}
				else
				{
					store[i].amount -= itemCode;
					break;
				}
			}

		}
		if (flag)
		{
			cout << "ERROR";
		}
	}
	/**
  * @brief Adds a new item to the store.
  * 
  * @param store Pointer to the array of items in the store.
  * @param maxSize The maximum number of items that can be stored.
  * @param numItems The current number of items in the store.
  */
	void addItem(Item*& store, int maxSize, int& numItems)
	{

		int newcode, newAmount, minAmount; float newPrice;
		char newName[21];
		cout << "enter code:" << endl;
		cin >> newcode;
		cout << "enter name: " << endl;
		cin >> newName;

		cout << "enter amount:" << endl;
		cin >> newAmount;

		cout << "enter minimum amount:" << endl;
		cin >> minAmount;

		cout << "enter price:" << endl;
		cin >> newPrice;


		if (numItems == maxSize)
		{
			cout << "ERROR" << endl;

		}
		else if (newcode == store[numItems].code && newName != store[numItems].name)
		{
			cout << "ERROR" << endl;

		}
		else
		{
			if (newcode == store[numItems].code && newName == store[numItems].name)
			{
				store[numItems].amount = newAmount;
			}
			else
			{

				store[numItems].amount = newAmount;
				/*cout << store[numItems].amount << endl;*/
				store[numItems].code = newcode;
				/*cout << store[numItems].code << endl;*/
				store[numItems].min = minAmount;
				/*cout << store[numItems].min << endl;*/
				strcpy(store[numItems].name, newName);
				/*cout << store[numItems].name << endl;*/
				store[numItems].price = newPrice;
				/*cout << store[numItems].min << endl;*/

			}
		}
		numItems++;



	}
	enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT };
	/**
  * @brief Main function to run the program.
  * 
  */
	void Ex_12_main()
	{
		cout << "Exersice 12" << endl;
		cout << "Store management system" << endl << "In this program you can add items to the store, find the price of an item, order items that are below the minimum amount, update the amount of an item that has been sold, and print the details of each item in the store." << endl;
		Item* store;
		int maxItems;
		int numItems = 0;
		int choice;
		cout << "enter max number of items: " << endl;
		cin >> maxItems;
		store = new Item[maxItems];

		do {
			cout << "enter 0-5:\n";

			cin >> choice;

			switch (choice) {
			case EXIT:	break;

			case ADD:	addItem(store, maxItems, numItems);
				break;

			case FIND: 	findPrice(store, numItems);
				break;

			case SOLD:	sold(store, numItems);
				break;

			case ORDER:	order(store, numItems);
				break;

			case PRINT: 	print(store, numItems);
				break;

			default: 	cout << "ERROR" << endl;
			}
		} while (choice != 0);
		
	}
}