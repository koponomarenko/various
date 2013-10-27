#include <iostream>
#include <cstring>
using namespace std;

/*
	Begin with the following structure declaration:
		struct chaff
		{
			char dross[20];
			int slag;
		};
	Write a program that uses placement new to place an array of two such structures in
	a buffer. Then assign values to the structure members (remembering to use
	strcpy() for the char array) and use a loop to display the contents. Option 1 is to
	use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular
	new to allocate the buffer.
*/

struct chaff
{
	char dross[20];
	int slag;
};

void FillChaff(chaff & Chaff);
inline void DisplayChaff(chaff & Chaff);


void task_03() // let it be kind a main func
{
	static char Buffer[128];
	chaff * paChaff = NULL;
	bool bUseHeapMem = false;

	try
	{
		cout << "Enter size of array: ";
		int nSize = 0;
		while (!(cin >> nSize) || nSize <= 0)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}
		cin.get();
	

		if (nSize * sizeof(chaff) <= sizeof(Buffer))
		{
			paChaff = new (Buffer) chaff[nSize]; // static memoty
		}
		else
		{
			bUseHeapMem = true;
			paChaff = new chaff[nSize]; // heap memory
		}


		for (int i = 0; i < nSize; ++i)
			FillChaff(paChaff[i]);

		cout << endl;
		cout << "Your entered Chaffs: " << endl << endl;
		for (int i = 0; i < nSize; ++i)
			DisplayChaff(paChaff[i]);
	}
	catch (bad_alloc &)
	{
		cout << "bad_alloc exception!" << endl;
		return;
	}
	catch (...)
	{
		cout << "Unknown exception!" << endl;
	}

	if (bUseHeapMem)
		delete [] paChaff;
}



void FillChaff(chaff & Chaff)
{
	// just in case, clear the input buffer
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	cout << "Enter a Chaff.dross: ";
	cin.getline(Chaff.dross, sizeof(Chaff.dross));

	// just in case, clear the input buffer
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());


	cout << "Enter a Chaff.slag: ";
	while (!(cin >> Chaff.slag))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();
}

void DisplayChaff(chaff & Chaff)
{
	cout << "Chaff.dross: " << Chaff.dross << endl;
	cout << "Chaff.slag: " << Chaff.slag << endl;
}