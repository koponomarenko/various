#include <iostream>
#include <string>
using namespace std;

/*
	Redo Listing 9.9, replacing the character array with a string object. The program
	should no longer have to check whether the input string fits, and it can compare
	the input string to "" to check for an empty line.
*/

// function prototype
void strcount(const string & str);

void task_02() // let it be kind a main func
{
	string sInput;

	cout << "Enter a line:\n";
	while (getline(cin, sInput) && sInput != "")
	{
		strcount(sInput);
		cout << "Enter next line (empty line to quit):\n";
	}

	cout << "Bye\n";
}


void strcount(const string & sStr)
{
	static int total = 0; // static local variable
	int count = 0; // automatic local variable

	cout << "\"" << sStr <<"\" contains ";
	count = sStr.size(); // go to end of string

	total += count;

	cout << count << " characters\n";
	cout << total << " characters total\n";
}