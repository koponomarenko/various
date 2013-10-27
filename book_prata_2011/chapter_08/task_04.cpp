#include <iostream>
#include <cstring>
using namespace std;

/*
	The following is a program skeleton:
		#include <iostream>
		using namespace std;
		#include <cstring> // for strlen(), strcpy()
		struct stringy {
			char * str; // points to a string
			int ct; // length of string (not counting '\0')
		};
		// prototypes for set(), show(), and show() go here
		int main()
		{
			stringy beany;
			char testing[] = "Reality isn't what it used to be.";
			set(beany, testing); // first argument is a reference,
			// allocates space to hold copy of testing,
			// sets str member of beany to point to the
			// new block, copies testing to new block,
			// and sets ct member of beany
			show(beany); // prints member string once
			show(beany, 2); //prints member string twice
			testing[0] = 'D';
			testing[1] = 'u';
			show(testing); // prints testing string once
			show(testing, 3); // prints testing string thrice
			show("Done!");
			return 0;
		}

	Complete this skeleton by providing the described functions and prototypes. Note
	that there should be two show() functions, each using default arguments. Use
	const arguments when appropriate. Note that set() should use new to allocate
	sufficient space to hold the designated string. The techniques used here are similar
	to those used in designing and implementing classes. (You might have to alter the
	header filenames and delete the using directive, depending on your compiler.)
*/

struct stringy
{
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy & stStringy, const char * pszStr);
void show(const stringy & stStringy, int nPrintCopies = 1);
void show(const char * pszStr, int nPrintCopies = 1);

void task_04() // let it be kind a main func
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); //prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");

	delete [] beany.str;
}

void set(stringy & stStringy, const char * pszStr)
{
	stStringy.ct = strlen(pszStr);
	stStringy.str = new char [stStringy.ct + 1];
	strcpy(stStringy.str, pszStr);
}

void show(const stringy & stStringy, int nPrintCopies)
{
	for (int i = 0; i <nPrintCopies; ++i)
		cout << stStringy.str << endl;
}

void show(const char * pszStr, int nPrintCopies)
{
	for (int i = 0; i <nPrintCopies; ++i)
		cout << pszStr << endl;
}
