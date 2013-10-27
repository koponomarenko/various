#include <iostream>
#include <cctype>
using namespace std;

/*
	Write a program that reads keyboard input to the @ symbol and that echoes the
	input except for digits, converting each uppercase character to lowercase, and vice
	versa. (Don’t forget the cctype family.)
*/

void task_01() // let it be kind a main func
{
	char ch = 0;

	cout << "Write something (write \"@\" to finish entering):" << endl;
	while (cin.get(ch) && ch != '@')
	{
		if (!isdigit(ch))
		{
			cout<< char (isupper(ch) ? tolower(ch) : toupper(ch));
		}
	}

	cout << endl;
}