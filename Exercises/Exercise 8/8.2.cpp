
#include <iostream>
using namespace std;
namespace Exercises {
    // Function prototypes
    void printAll(int* database, int database_size);
    void sort_database(int* database, int database_size);
    bool is_data_already_exist(int* database, int database_size, int new_data, int divider = 1);
    void newClass(int* database, int& database_size, int new_data);
    void delClass(int* database, int& database_size, int delete_data);
    void searchClass(int* database, int database_size, int num_search);
    void printCode(int* database, int database_size, int code_search);

    // Enum for menu options
    enum numbers
    {
        new_classroom = 0, delete_classroom, search_classroom, print_specific, print_all, exit_program
    };

    /**
     * @brief Main function for Exercise 8.2
     * 
     */
	void Ex_8_2_main()
    {
		cout << "Exercise 8.2:\n";
		cout << "Welcome to the classroom database!" << endl;
        // Declaring all the variables
        int database_size = 0;
        int database[50] = { 0 };
        int new_data, delete_data, search_num, code_search;
        bool flag = true;

        cout << "Enter 0 to add a new classroom." << endl;
        cout << "Enter 1 to delete a hybrid classroom." << endl;
        cout << "Enter 2 to search for a specific classroom." << endl;
        cout << "Enter 3 to print all the classrooms for a specific Machon." << endl;
        cout << "Enter 4 to print all the hybrid classrooms." << endl;
        cout << "Enter 5 to exit." << endl;
        cout << "Enter your choice: " << endl;

        while (flag)
        {
            int num;
            cin >> num;  // Read the user's choice

            switch (num)
            {
            case new_classroom:
                cout << "Enter the code of the classroom to add: ";
                cin >> new_data;
                newClass(database, database_size, new_data);
                break;
            case delete_classroom:
                cout << "Enter the code of the classroom to delete: ";
                cin >> delete_data;
                delClass(database, database_size, delete_data);
                break;
            case search_classroom:
                cout << "Enter the code of the classroom to search for: ";
                cin >> search_num;
                searchClass(database, database_size, search_num);
                break;
            case print_specific:
                cout << "Enter the code of the Machon: ";
                cin >> code_search;
                printCode(database, database_size, code_search);
                break;
            case print_all:
                printAll(database, database_size);
                break;
            case exit_program:
                flag = false;
                break;
            default:
                cout << "ERROR" << endl;
                break;
            }

            if (flag) {
                cout << "Enter your next choice: " << endl;
            }
        }
    }

    /**
     * @brief Function to print all data in the database
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     */
    void printAll(int* database, int database_size)
    {
        for (int i = 0; i < database_size; i++)
        {
            cout << database[i] << endl;
        }
        cout << endl;
    }

    /**
     * @brief Function to sort the database in ascending order
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     */
    void sort_database(int* database, int database_size)
    {
        for (int i = 0; i < database_size - 1; i++)
        {
            for (int j = i + 1; j < database_size; j++)
            {
                if (database[i] > database[j])
                {
                    int temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            }
        }
    }

    /**
     * @brief Function to check if data already exists in the database
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     * @param new_data The new data to check
     * @param divider The divider to use for checking
     * @return true if the data already exists, false otherwise
     */
    bool is_data_already_exist(int* database, int database_size, int new_data, int divider)
    {
        bool found = false;
        for (int i = 0; i < database_size; i++)
        {
            if ((database[i] / divider) == new_data)
            {
                if (divider == 1)
                {
                    return true;
                }
                else
                {
                    cout << database[i] << " ";
                    found = true;
                }
            }
        }
        return found;
    }

    /**
     * @brief Function to add a new class to the database
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     * @param new_data The new data to add
     */
    void newClass(int* database, int& database_size, int new_data)
    {
        while (new_data > 99999 || new_data < 10000)
        {
            cout << "ERROR" << endl;
            cin >> new_data;
        }

        if (!is_data_already_exist(database, database_size, new_data) && database_size < 50)
        {
            database[database_size] = new_data;
            database_size++;
            sort_database(database, database_size);
        }

        printAll(database, database_size);
    }

    /**
     * @brief Function to delete a class from the database
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     * @param delete_data The data to delete
     */
    void delClass(int* database, int& database_size, int delete_data)
    {
        bool found = false;
        for (int i = 0; i < database_size; i++)
        {
            if (database[i] == delete_data)
            {
                found = true;
                for (int j = i; j < database_size - 1; j++)
                {
                    database[j] = database[j + 1];
                }
                database_size--;
                break;
            }
        }

        if (!found)
        {
            cout << "Class not found in the database." << endl;
        }

        printAll(database, database_size);
    }

    /**
     * @brief Function to search for a class in the database
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     * @param num_search The number to search for
     */
    void searchClass(int* database, int database_size, int num_search)
    {
        if (is_data_already_exist(database, database_size, num_search))
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    /**
     * @brief Function to print classes for a specific Machon
     * 
     * @param database Pointer to the database array
     * @param database_size Size of the database array
     * @param code_search The code to search for
     */
    void printCode(int* database, int database_size, int code_search)
    {
        while (code_search > 99 || code_search < 10)
        {
            cout << "ERROR" << endl;
            cin >> code_search;
        }

        bool found = is_data_already_exist(database, database_size, code_search, 1000);
        if (!found)
        {
            cout << endl;
        }
    }
}
