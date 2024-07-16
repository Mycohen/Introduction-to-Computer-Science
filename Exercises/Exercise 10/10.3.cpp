/*
Author:Moshe Jacob Cohen
ID:324692680
Course:Computer science Introduction 150005
Exercise: 10.3
Description:Computerized dictionary.
*/
#include<iostream> 
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
namespace Exercises {
	/**
  * Adds a new word to the lexicon if it doesn't already exist.
  * @param lex The lexicon array.
  * @param sizeOL The size of the lexicon array.
  * @param new_word The new word to be added.
  */
	void newStr(char**& lex, int& sizeOL, char new_word[])
	{
		// If the lexicon is empty, create a new array with the new word
		if (sizeOL == 0)
		{
			lex = new char* [1];
			lex[0] = new char[strlen(new_word) + 1];
			strcpy(lex[0], new_word);
			sizeOL += 1;
		}
		else
		{
			bool flag = true;
			// Check if the new word already exists in the lexicon
			for (size_t i = 0; i < sizeOL; i++)
			{
				if (strcmp(lex[i], new_word) == 0)
					flag = false;
			}
			// If the new word doesn't exist, add it to the lexicon
			if (flag)
			{
				int newSizeOL = sizeOL + 1;
				char** help = new char* [newSizeOL];
				int i;
				for (i = 0; i < sizeOL; i++)
				{
					help[i] = new char[strlen(lex[i]) + 1];
					strcpy(help[i], lex[i]);
				}
				help[i] = new char[strlen(new_word) + 1];
				strcpy(help[i], new_word);
				for (size_t i = 0; i < sizeOL; i++)
				{
					delete[]lex[i];
				}
				delete[]lex;
				lex = help;
				sizeOL = newSizeOL;
				// Sort the lexicon in alphabetical order
				for (int j = 1; j < sizeOL; j++)
				{
					for (int k = 0; k < sizeOL - j; k++)
					{
						if (strcmp(lex[k], lex[k + 1]) > 0)
						{
							char* tempPtrChar = new char[strlen(lex[k]) + 1];
							strcpy(tempPtrChar, lex[k]);
							strcpy(lex[k], lex[k + 1]);
							strcpy(lex[k + 1], tempPtrChar);
							delete[]tempPtrChar;
						}
					}
				}
			}
		}
	}

	/**
  * Deletes a word from the lexicon if it exists.
  * @param lex The lexicon array.
  * @param sizeOL The size of the lexicon array.
  * @param wordToD The word to be deleted.
  */
	void deleteStr(char**& lex, int& sizeOL, char* wordToD)
	{
		bool flag = false;
		// Check if the word to be deleted exists in the lexicon
		for (size_t i = 0; i < sizeOL; i++)
		{
			if (strcmp(lex[i], wordToD) == 0)
				flag = true;
		}
		// If the word exists, delete it from the lexicon
		if (flag)
		{
			int newSizeODB = sizeOL - 1;
			char** help = new char* [newSizeODB];
			int i = 0;
			int m = 0;
			// Copy the words before the word to be deleted
			while (strcmp(lex[i], wordToD) < 0)
			{
				help[m] = new char[strlen(lex[m]) + 1];
				strcpy(help[m++], lex[i++]);
			}
			i++;
			// Copy the words after the word to be deleted
			while (i < sizeOL && strcmp(lex[i], wordToD) > 0)
			{
				help[m] = new char[strlen(lex[m]) + 1];
				strcpy(help[m++], lex[i++]);
			}
			for (size_t i = 0; i < sizeOL; i++)
			{
				delete[]lex[i];
			}
			delete[]lex;
			lex = help;
			sizeOL = newSizeODB;
		}
	}

	/**
  * Prints all the words in the lexicon.
  * @param lex The lexicon array.
  * @param sizeOL The size of the lexicon array.
  */
	void printAll(char** lex, int sizeOL)
	{
		for (size_t i = 0; i < sizeOL; i++)
		{
			cout << lex[i] << ' ';
		}
	}

	/**
  * Searches for a word in the lexicon.
  * @param lex The lexicon array.
  * @param sizeOL The size of the lexicon array.
  * @param wordToS The word to search for.
  * @return The found word if it exists, otherwise NULL.
  */
	char* searchStr(char** lex, int sizeOL, char* wordToS)
	{
		int result = -1;
		int low = 0;
		int mid;
		int high = sizeOL - 1;
		// Binary search for the word in the lexicon
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (strcmp(wordToS, lex[mid]) == 0)
			{
				result = mid;
				break;
			}
			else if (strcmp(wordToS, lex[mid]) > 0)
			{
				low = mid + 1;
			}
			else { high = mid - 1; }
		}
		// Return the found word or NULL if not found
		if (result != -1)
			return lex[mid];
		else
			return NULL;
	}

	/**
  * Prints all the words in the lexicon that start with a specific letter.
  * @param lex The lexicon array.
  * @param sizeOL The size of the lexicon array.
  * @param aLetter The letter to filter the words by.
  */
	void printChar(char** lex, int sizeOL, char aLetter)
	{
		for (size_t i = 0; i < sizeOL; i++)
		{
			if (lex[i][0] == aLetter)
			{
				cout << lex[i] << ' ';
			}
		}
		cout << '\n';
	}

	/**
  * Main function for Exercise 10.3 - Computerized dictionary.
  */
	void Ex_10_3_main()
	{
		cout << "Exercise 10.3:\n";
		cout << "Computerized dictionary." << endl << "In this program you can add, delete, search, and print words in a computerized dictionary." << endl;
		char** lexicon = nullptr;
		int num = 0, sizeOL = 0;
		cout << "Enter 0-5:" << endl;
		enum choice { NEWSTR, DELSTR, SEARCHSTR, PRINTCHAR, PRINTALL };
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
			case NEWSTR: cout << "Enter the word:\n";
				char  newWord[80]; cin >> newWord;
				newStr(lexicon, sizeOL, newWord);
				printAll(lexicon, sizeOL); cout << endl;
				break;
			case DELSTR:cout << "Enter the word to delete:\n";
				cin >> newWord;
				deleteStr(lexicon, sizeOL, newWord);
				printAll(lexicon, sizeOL); cout << endl;
				break;
			case SEARCHSTR:cout << "Enter the word to search for:\n";
				cin >> newWord;
				if (searchStr(lexicon, sizeOL, newWord) == NULL)
					cout << "Not found" << endl;
				else cout << "Found" << endl;
				break;
			case PRINTCHAR:cout << "Enter the char:\n";
				char aLetter;
				cin >> aLetter;
				printChar(lexicon, sizeOL, aLetter);
				break;
			case PRINTALL:printAll(lexicon, sizeOL);
				cout << endl;
				break;
			}
			cout << "Enter 0-5:\n";
			cin >> num;
			while (num < 0 || num>5)
			{
				cout << "ERROR" << endl;
				cin >> num;
			}
		}
		for (size_t i = 0; i < sizeOL; i++)
		{
			delete[]lexicon[i];
		}
		delete[]lexicon;
	}
}