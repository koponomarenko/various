#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
	Write a function that takes a reference to a string object as its parameter and that converts
	the contents of the string to uppercase. Use the toupper() function described in Table 6.4 of
	Chapter 6. Write a program that uses a loop which allows you to test the function with different input.
	A sample run might look like this:
	Enter a string (q to quit): go away
	GO AWAY
	Next string (q to quit): good grief!
	GOOD GRIEF!
	Next string (q to quit): q
	Bye.
*/

inline void ConvertToUpper(string & sStr);

void task_03() // let it be kind a main func
{
	string sStr;

	cout << "Enter a string (q to quit):";
	while (true)
	{
		getline(cin, sStr);
		if (sStr.size() == 1 && sStr[0] == 'q' || sStr[0] == 'Q')
			break;

		ConvertToUpper(sStr);
		cout << sStr << endl;
		cout << "Next string (q to quit):";
	}

	cout << "Bye." << endl;
}


void ConvertToUpper(string & sStr)
{
	for (size_t i = 0; i < sStr.size(); ++i)
		sStr[i] = toupper(sStr[i]);
}