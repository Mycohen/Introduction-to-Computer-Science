# include <iostream>
using namespace std;
/*
* Program that calculates the area of a rectangle and a circle.
*
*/
namespace Exercises
{
	int area(int a, int b)
	{
		int rectangleArea = a * b; // Calculating the square area.
		return rectangleArea;
	}
	
	float area(int r) // Calculating the circle area.
	{
		const float PI = 3.14159;
		float circleArea = PI * r * r;
		return circleArea;
	}

	void Ex_5_1_main()
	{
		cout << "Exercise 5.1" << endl;
		cout << "This program calculates the area of a rectangle and a circle." << endl;
		int length, width, rectangleArea;
		cout << "Enter length and width of the rectangle:" << endl;
		cin >> length >> width; // Receiving the length and width.
		
		while (length <= 0 || width <= 0) // Checking that the inputs are positive integers.
		{
			cout << "ERROR" << endl;
			cin >> length >> width;
		}
		
		cout << endl;
		rectangleArea = area(length, width);
		cout << rectangleArea << endl; // Printing the square area.

		int radius;
		float circleArea;

		cout << "Enter radius of the circle:" << endl;
		cin >> radius; // Receiving the radius.
		cout << endl;

		while (radius <= 0) // Checking that the radius is positive.
		{
			cout << "ERROR" << endl;
			cin >> radius;
		}

		circleArea = area(radius);
		cout << circleArea << endl;
	}
}