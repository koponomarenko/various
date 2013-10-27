#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void mergFiles(const string & sNameIn1, const string & sNameIn2);

int main(int argc, char *argv[])
{
	string sNameIn1, sNameIn2;

	if (argc == 3)
	{
		sNameIn1 = argv[1];
		sNameIn2 = argv[2];
	}
	else
	{
		cout << "Enter name of the first file: ";
		getline(cin, sNameIn1);
		cout << "Enter name of the second file: ";
		getline(cin, sNameIn2);
	}

	try
	{
		mergFiles(sNameIn1, sNameIn2);

		cout << "Files " << sNameIn1 << " and " << sNameIn2 << " merged successfully." << endl;
		cout << "Output file: \"out.txt\"" << endl;
	}
	catch (string & ex)
	{
		cerr << ex << endl;
	}
	catch (...)
	{
		cerr << "Unknown exception" << endl;
	}

	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}

void mergFiles(const string & sNameIn1, const string & sNameIn2)
{
	ifstream fin1, fin2;
	fin1.open(sNameIn1.c_str());
	if (!fin1.is_open())
		throw string ("Error while opening file: ") + sNameIn1;

	fin2.open(sNameIn2.c_str());
	if (!fin2.is_open())
		throw string ("Error while opening file: ") + sNameIn2;

	ofstream fout;
	fout.open("out.txt");

	string sWord;

	while (fin1 || fin2)
	{
		char ch = 0;
		unsigned char uch = 0;
			
		/* copy string from 1st file  */
		while (fin1)
		{
			if (fin1.peek() != '\n' && fin1.peek() != EOF) // чтобы поток стал eof(), этот символ надо вычитать его с потока.
			{
				if (sWord.size())
					fout << ' ';
				fin1 >> sWord;
				fout << sWord;
			}
			else
			{
				fin1.get();
				break;
			}
		}
		
		/* copy string from 2nd file */
		while (fin2)
		{
			if (fin2.peek() != '\n' && fin2.peek() != EOF)
			{
				if (sWord.size())
					fout << ' ';
				fin2 >> sWord;
				fout << sWord;
			}
			else
			{
				fin2.get();
				break;
			}
		}

		sWord.clear();
		if (fin1 || fin2)
			fout << endl; // '\n'
	}
}
