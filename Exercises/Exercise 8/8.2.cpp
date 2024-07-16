#include <iostream>
using namespace std;
namespace Exercises {
    //prototypes of the functions
    void printAll(int* database, int* database_size);
    void sort_database(int* database, int* database_size);
    bool is_data_already_exist(int* database, int* database_size, int* new_data, int divider = 1);
    void newClass(int* database, int* database_size, int* new_data);
    void delClass(int* database, int* database_size, int* delete_data);
    void searchClass(int* database, int* database_size, int* num_search);
    void printCode(int* database, int* database_size, int* code_search);

    //declaring an enum 
    enum numbers
    {
        new_classroom = 0, delete_classroom, search_classroom, print_specific, print_all, exit_program
    };

	void Ex_8_2_main()
    {
        //delcaring all the variables
        int database_size = 0;
        int database[50] = { 0 };
        int new_data, delete_data, search_num, code_search;
        bool flag = true;

        cout << "Enter 0 to add a new classroom." << endl;
        cout << "Enter 1 to delete a hybrid classroom." << endl;
        cout << "Enter 2 to search for a specific classroom." << endl;
        cout << "Enter 3 to print all the classsrooms for a specific Machon." << endl;
        cout << "Enter 4 to print all the hybrid classrooms." << endl;
        cout << "Enter 5 to exit." << endl;
        cout << "Enter your choice: " << endl;

        while (flag)
        {
            int num;
            cin >> num;                                                                 //read what the user want to do

            switch (num)
            {
            case new_classroom:                                                         //if the user want to add a class             
                cout << "Enter the code of the classroom to add: ";
                cin >> new_data;
                newClass(database, &database_size, &new_data);
                cout << "Enter your next choice: " << endl;
                break;

            case delete_classroom:                                                      //if the user want to remove a class
                cout << "Enter the code of the classroom to delete: ";
                cin >> delete_data;
                delClass(database, &database_size, &delete_data);
                cout << "Enter your next choice: " << endl;
                break;

            case search_classroom:                                                      //if the user want to search a class
                cout << "Enter the code of the classroom to search for: ";
                cin >> search_num;
                searchClass(database, &database_size, &search_num);
                cout << "Enter your next choice: " << endl;
                break;

            case print_specific:                                                        //if the user want to see specific classes
                cout << "Enter the code of the Machon: ";
                cin >> code_search;
                printCode(database, &database_size, &code_search);
                cout << "Enter your next choice: " << endl;
                break;

            case print_all:                                                             //if the user want to see all the classes
                printAll(database, &database_size);
                cout << "Enter your next choice: " << endl;
                break;

            case exit_program:                                                          //if the user want to exit the program
                flag = false;
                break;

            default:
                cout << "ERROR" << endl;
                break;
            }
        }

       
    }

    // Function to print all data in the database
    void printAll(int* database, int* database_size)
    {
        for (int i = 0; i < *database_size; i++)
        {
            cout << *(database + i) << " ";
        }
        cout << endl;
    }

    // Function to sort the database in increasing order
    void sort_database(int* database, int* database_size)
    {
        int temp = 0;
        for (int j = 0; j < *database_size; j++)
        {
            for (int i = 0; i < *database_size - 1; i++)
            {
                if (*(database + i) > *(database + i + 1))
                {
                    temp = *(database + i + 1);
                    *(database + i + 1) = *(database + i);
                    *(database + i) = temp;
                }
            }
        }
    }

    // Function to check if data already exists in the database
    bool is_data_already_exist(int* database, int* database_size, int* new_data, int divider)
    {
        for (int i = 0; i < *database_size; i++)
        {
            if ((*(database + i) / divider) == *new_data)
            {
                return true;
            }
        }
        return false;
    }

    // Function to add a new class to the database
    void newClass(int* database, int* database_size, int* new_data)
    {
        while (*new_data > 99999 || *new_data < 10000)
        {
            cout << "ERROR" << endl;
            cin >> *new_data;
        }

        if (!is_data_already_exist(database, database_size, new_data) && *database_size < 50)
        {
            *(database + *(database_size)) = *new_data;
            *database_size = *database_size + 1;
            sort_database(database, database_size);
        }

        printAll(database, database_size);
    }

    // Function to delete a class from the database
    void delClass(int* database, int* database_size, int* delete_data)
    {
        int num = -1;
        for (int i = 0; i < *database_size; i++)
        {
            if (*(database + i) == *delete_data)
            {
                num = i;
                break;
            }
        }

        if (num != -1)
        {
            *(database + num) = 999999;
            sort_database(database, database_size);
            *database_size = *database_size - 1;
        }

        printAll(database, database_size);
    }

    // Function to search for a class in the database
    void searchClass(int* database, int* database_size, int* num_search)
    {
        bool found = false;
        for (int i = 0; i < *database_size; i++)
        {
            if (*(database + i) == *num_search)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    // Function to print all classes with a specific code
    void printCode(int* database, int* database_size, int* code_search)
    {
        while (*code_search > 99 || *code_search < 10)
        {
            cout << "ERROR" << endl;
            cin >> *code_search;
        }

        for (int i = 0; i < *database_size; i++)
        {
            if (*(database + i) / 100 == *code_search)
            {
                cout << *(database + i) << " ";
            }
        }
        cout << endl;
    }
}