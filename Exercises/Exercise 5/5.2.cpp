#include<iostream> 
using namespace std;
namespace Exercises {
    bool perfect(int num)//A function that recognizes perfect numbers
    {
        int i = 1, sum = 0;
        while (i < num)//The function goes through all the divisions of the number
        {
            if (num % i == 0)
                sum += i;//The sum of the divisors of the number
            i++;
        }
        if (sum == num)//Check that it's a perfect number
            return true;
        else
            return false;
    }


    void printPerfects(int n = 500)//A function that prints the perfect numbers
    {
        if (n > 6)//The minmale perfect number. There is a default value of 500 for printing all the perfefect numbers til 5000

        {
            bool isItPerfect;
            for (int i = 1; i < n; i++)
            {
                isItPerfect = perfect(i);//Sending i to the first function 
                if (isItPerfect)//If is it perfect, the number will be printed
                    cout << i << ' ';
            }
            cout << endl;
        }
        else
            cout << endl;

    }
    void Ex_5_2_main()
    {
        int num;
        cout << "Enter a number: " << endl;//Accepting the number
        cin >> num;
        while (num <= 0)//Checking that is a positive number
        {
            cout << "ERROR" << endl;
            cin >> num;
        }
        printPerfects(num);//Print the perfect numbers up to the value of N
        printPerfects();//Print the perfect numbers up to the value of 500

    }
}

