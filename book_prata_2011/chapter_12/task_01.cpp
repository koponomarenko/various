#include <iostream>

#include "clCow.h"

using namespace std;

/*
	Consider the following class declaration:
		class Cow {
			char name[20];
			char * hobby;
			double weight;
		public:
			Cow();
			Cow(const char * nm, const char * ho, double wt);
			Cow(const Cow c&);
			~Cow();
			Cow & operator=(const Cow & c);
			void ShowCow() const; // display all cow data
		};
	Provide the implementation for this class and write a short program that uses all the
	member functions.
*/

void task_01() // let it be kind a main func
{
	clCow Cow1;
	cout << "Cow1: clCow Cow1;" << endl;
	Cow1.ShowCow();
	cout << endl;

	clCow Cow2("Name", "Hobby", 55);
	cout << "Cow2: clCow Cow2(\"Name\", \"Hobby\", 55);" << endl;
	Cow2.ShowCow();
	cout << endl;

	clCow Cow3 = Cow2;
	cout << "Cow3: clCow Cow3 = Cow2;" << endl;
	Cow3.ShowCow();
	cout << endl;

	Cow1 = Cow3;
	cout << "Cow3: Cow1 = Cow3;" << endl;
	Cow1.ShowCow();
}