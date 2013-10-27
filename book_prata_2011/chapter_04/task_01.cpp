#include <iostream>
#include <string>
using namespace std;

/*
	Write a C++ program that requests and displays information as shown in the fol-
	lowing example of output:
	What is your first name? Betty Sue
	What is your last name? Yewe
	What letter grade do you deserve? B
	What is your age? 22
	Name: Yewe, Betty Sue
	Grade: C
	Age: 22
	Note that the program should be able to accept first names that comprise more
	than one word. Also note that the program adjusts the grade downward—that is,up
	one letter. Assume that the user requests an A,a B,or a C so that you don’t have to
	worry about the gap between a D and an F.
*/

void task_01() // let it be kind a main func
{
	string sTmp;

	cout<<"What is your first name? ";
	string sFirstName;
	do {
		cin>>sTmp;
		sFirstName += sTmp;
		if(cin.peek() != '\n')
			sFirstName += cin.peek();
	} while (cin.get() != '\n');

	cout<<"What is your last name? ";
	string sLastName;
	do {
		cin>>sTmp;
		sLastName += sTmp;
		if(cin.peek() != '\n')
			sLastName += cin.peek();
	} while (cin.get() != '\n');

	cout<<"What letter grade do you deserve? ";
	char chGrade;
	cin>>chGrade;

	cout<<"What is your age? ";
	int nAge = 0;
	cin>>nAge;


	cout<<"Name: "<<sLastName<<", "<<sFirstName<<endl;
	cout<<"Grade: "<<chGrade<<endl;
	cout<<"Age: "<<nAge<<endl;
}