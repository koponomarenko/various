#include <iostream>
#include <string>
using namespace std;

/*
	Design a structure called carthat holds the following information about an auto-
	mobile:its make,as a string in a character array or in a string object,and the year
	it was built,as an integer.Write a program that asks the user how many cars to cata-
	log. The program should then use new to create a dynamic array of that many car
	structures. Next, it should prompt the user to input the make (which might consist
	of more than one word) and year information for each structure. Note that this
	requires some care because it alternates reading strings with numeric data (see Chapter 4).
	Finally,it should display the contents of each structure. A sample run
	should look something like the following:
	How many cars do you wish to catalog? 2
	Car #1:
	Please enter the make: Hudson Hornet
	Please enter the year made: 1952
	Car #2:
	Please enter the make: Kaiser
	Please enter the year made: 1951
	Here is your collection:
	1952 Hudson Hornet
	1951 Kaiser
*/

void task_07() // let it be kind a main func
{
	struct Car
	{
		string sMake;
		int nYearMade;
	};

	cout<<"How many cars do you wish to catalog? ";
	int nCars = 0;
	cin>>nCars;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input. Try again: ";
		cin>>nCars;
	}
	cin.get(); // peek the '\n' from stream after Enter-key

	Car * pstCars = new Car[nCars];
	

	/* fill the cars info */
	for (int i = 0; i < nCars; ++i)
	{
		cout<<"Car #"<<i + 1<<':'<<endl;

		cout<<"Please enter the make: ";
		getline(cin, pstCars[i].sMake);

		cout<<"Please enter the year made: ";
		cin>>pstCars[i].nYearMade;
		while (!cin)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout<<"Incorrect input. Try again: ";
			cin>>pstCars[i].nYearMade;
		}
		cin.get(); // peek the '\n' from stream after Enter-key
	}


	/* show the cars info */
	cout<<endl;
	cout<<"Here is your collection:"<<endl;
	for (int i = 0; i < nCars; ++i)
	{
		cout<<pstCars[i].nYearMade<<' '<<pstCars[i].sMake<<endl;
	}
	cout<<endl;
	
	delete [] pstCars;
}
