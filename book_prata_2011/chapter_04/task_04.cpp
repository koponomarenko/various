#include <iostream>
#include <string>
using namespace std;

/*
	Write a program that asks the user to enter his or her first name and then last
	name,and that then constructs,stores,and displays a third string consisting of the
	user’s last name followed by a comma,a space,and first name.Use string objects
	and methods from the string header file. A sample run could look like this:
	Enter your first name: Flip
	Enter your last name: Fleming
	Here is the information in a single string: Fleming, Flip
*/

void task_04() // let it be kind a main func
{
	string sTmp;

	cout<<"Enter your first name: ";
	string sFirstName;
	getline(cin, sFirstName);

	cout<<"Enter your last name: ";
	string sLastName;
	getline(cin, sLastName);

	string sFullName = sLastName + ", " + sFirstName;
	cout<<"Here is the information in a single string: "<<sFullName<<endl;
}