#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
	Write a program that opens a text file, reads it character-by-character to the end of
	the file, and reports the number of characters in the file.
*/

void task_08() // let it be kind a main func
{
	cout << "Enter a name of file to read: ";
	string sFileName;
	getline(cin, sFileName);

	ifstream inFile;
	inFile.open(sFileName.c_str());
	if (!inFile.is_open())
	{
		cout << "Could not open the file!" << endl;
		return;
	}

	int nCharacters = 0;
	while (inFile.get() != EOF)
		++nCharacters;

	cout << "The number of characters in the file (including unprintable) is " << nCharacters << endl;

	inFile.close();
}
