#include <iostream>

#include "clString.h"

using namespace std;

/*
	Enhance the clString class declaration (that is, upgrade string1.h to string2.h) by
	doing the following:
		a. Overload the + operator to allow you to join two strings into one.
		b. Provide a stringlow() member function that converts all alphabetic characters
		in a clString to lowercase. (Don’t forget the cctype family of character functions.)
		c. Provide a stringup() member function that converts all alphabetic characters
		in a clString to uppercase.
		d. Provide a member function that takes a char argument and returns the number
		of times the character appears in the clString.

	Test your work in the following program:
		// pe12_2.cpp
		#include <iostream>
		using namespace std;
		#include "string2.h"
		int main()
		{
			clString s1(" and I am a C++ student.");
			clString s2 = "Please enter your name: ";
			clString s3;
			cout << s2; // overloaded << operator
			cin >> s3; // overloaded >> operator
			s2 = "My name is " + s3; // overloaded =, + operators
			cout << s2 << ".\n";
			s2 = s2 + s1;
			s2.stringup(); // converts clString to uppercase
			cout << "The clString\n" << s2 << "\ncontains " << s2.has('A')
				 << " 'A' characters in it.\n";
			s1 = "red"; // clString(const char *),
			// then clString & operator=(const clString&)
			clString rgb[3] = { clString(s1), clString("green"), clString("blue")};
			cout << "Enter the name of a primary color for mixing light: ";
			clString ans;
			bool success = false;
			while (cin >> ans)
			{
				ans.stringlow(); // converts clString to lowercase
				for (int i = 0; i < 3; i++)
				{
					if (ans == rgb[i]) // overloaded == operator
					{
						cout << "That's right!\n";
						success = true;
						break;
					}
				}
				if (success)
					break;
				else
					cout << "Try again!\n";
			}
			cout << "Bye\n";
			return 0;
		}

	Your output should look like this sample run:

		Please enter your name: Fretta Farbo
		My name is Fretta Farbo.
		The clString
		MY NAME IS FRETTA FARBO AND I AM A C++ STUDENT.
		contains 6 'A' characters in it.
		Enter the name of a primary color for mixing light: yellow
		Try again!
		BLUE
		That's right!
		Bye
*/

void task_02() // let it be kind a main func
{
	clString s1(" and I am a C++ student.");
	clString s2 = "Please enter your name: ";
	clString s3;
	cout << s2; // overloaded << operator
	cin >> s3; // overloaded >> operator
	s2 = "My name is " + s3; // overloaded =, + operators
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup(); // converts clString to uppercase
	cout << "The clString\n" << s2 << "\ncontains " << s2.has('A')
		 << " 'A' characters in it.\n";
	s1 = "red"; // clString(const char *),
	// then clString & operator=(const clString&)
	clString rgb[3] = { clString(s1), clString("green"), clString("blue")};
	cout << "Enter the name of a primary color for mixing light: ";
	clString ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow(); // converts clString to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
}