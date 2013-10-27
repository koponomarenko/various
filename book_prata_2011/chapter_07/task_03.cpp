#include <iostream>
using namespace std;

/*
	Here is a structure declaration:
		structure box
		{
			char maker[40];
			float height;
			float width;
			float length;
			float volume;
		};
	a. Write a function that passes a box structure by value and that displays the
	value of each member.
	b. Write a function that passes the address of a box structure and that sets the
	volume member to the product of the other three dimensions.
	c. Write a simple program that uses these two functions.
*/

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void Display(box Box);
void CalcVolume(box * Box);


void task_03() // let it be kind a main func
{
	box Box;


	cout << "Enter maker: ";
	cin.getline(Box.maker, sizeof(Box.maker));
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());


	cout << "Enter height: ";
	while (!(cin >> Box.height))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input. Try again: ";
	}
	cin.get();


	cout << "Enter width: ";
	while (!(cin >> Box.width))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input. Try again: ";
	}
	cin.get();


	cout << "Enter length: ";
	while (!(cin >> Box.length))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input. Try again: ";
	}
	cin.get();


	CalcVolume(&Box);
	Display(Box);
}


void Display(box Box)
{
	cout << endl << endl;
	cout << "maker: " << Box.maker << endl;
	cout << "height: " << Box.height << endl;
	cout << "width: " << Box.width << endl;
	cout << "length: " << Box.length << endl;
	cout << "volume: " << Box.volume << endl;
	cout << endl;
}


void CalcVolume(box * Box)
{
	Box->volume = Box->height * Box->width * Box->length;
}