#include <iostream>
#include <cstring>
using namespace std;

/*
	Write a program that asks the user to enter his or her first name and then last
	name,and that then constructs,stores,and displays a third string,consisting of the
	user’s last name followed by a comma,a space,and first name.Use chararrays and
	functions from the cstring header file. A sample run could look like this:
	Enter your first name: Flip
	Enter your last name: Fleming
	Here is the information in a single string: Fleming, Flip
*/

void task_03() // let it be kind a main func
{
	cout<<"Enter your first name: ";
	char szFirstName[35] = {0};
	cin.getline(szFirstName, sizeof(szFirstName));
	if (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	cout<<"Enter your last name: ";
	char szLastName[55] = {0};
	cin.getline(szLastName, sizeof(szLastName));
	if (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	char szFullName[sizeof(szFirstName) + sizeof(szLastName)];
	strcat(strcat(strcpy(szFullName, szLastName), ", "), szFirstName);
	cout<<"Here is the information in a single string: "<<szFullName<<endl;
}