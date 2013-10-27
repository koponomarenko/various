#include <iostream>
#include <fstream>
#include <string>
#include "emp.h"
using namespace std;

/*

*/

const int SIZE = 10;

int fillFromFile(fstream & fin, employee ** pArr, int nSize);
int addNewEmployees(fstream & fout, employee ** pArr, int nSize);
void showStaff(employee ** pArr, int nSize);


int main(int argc, char * argv[])
{
	fstream fInOut;
	string sFileName;
	employee * empArr[SIZE] = {0};
	int nFilled = 0;

	if (argc > 1)
		sFileName = argv[1];
	else
	{
		cout << "Enter file name: ";
		getline(cin, sFileName);
	}

	try
	{
		fInOut.open(sFileName.c_str(), ios_base::in | ios_base::out);
		if (!fInOut.is_open())
			throw string("Error while opening file: ") + sFileName;
		
		if (fInOut.good())
			nFilled = fillFromFile(fInOut, empArr, SIZE); // from file
		
		showStaff(empArr, nFilled);
		nFilled = nFilled + addNewEmployees(fInOut, empArr + nFilled, SIZE - nFilled); // to file
		showStaff(empArr, nFilled);

		fInOut.close();
	}
	catch (string & ex)
	{
		cerr << ex << endl;
	}
	catch (bad_alloc & ex)
	{
		cerr << ex.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown exception" << endl;
	}

	for (int i = 0; i < nFilled; i++)
		delete empArr[i];

	cout << "Bye.\n";
	cin.ignore(cin.rdbuf()->in_avail()).get();
}


// return nabber of filled objects
int fillFromFile(fstream & fin, employee ** pArr, int nSize)
{
	int id;
	int i = 0;

	while (i < nSize && fin.good() && fin.peek() != EOF)
	{
		fin >> id;
		
		switch(id)
		{
		case abstr_emp::EMPLOYEE:
			pArr[i] = new employee;
			break;
		case abstr_emp::MANAGER:
			pArr[i] = new manager;
			break;
		case abstr_emp::FINK: 
			pArr[i] = new fink;
			break;
		case abstr_emp::HIGHFINK: 
			pArr[i] = new highfink;
			break;
		default:
			throw "Error while reading file";
		}
		fin.get(); // '\n'

		pArr[i]->GetAll(fin);
		i++;
	}

	fin.clear();
	return i;
}


int addNewEmployees(fstream & fout, employee ** pArr, int nSize)
{
	int i = 0;
	char choice;

	while (i < nSize && fout.good())
	{
		cout << "Wich character you want to create: \n"
			 << "1: employee	2: manager" << endl
			 << "3: fink		4: highfink" << endl
			 << "q: quit" << endl
			 << ">";
		cin >> choice;
		while (strchr("1234q", choice) == NULL)
		{
			cout << "Please enter 1, 2, 3, 4 or q: ";
			cin >> choice;
		}
		cin.ignore(cin.rdbuf()->in_avail());

		if (choice == 'q')
			break;

		switch(choice)
		{
		case '1': 
			pArr[i] = new employee;
			fout << abstr_emp::EMPLOYEE << endl; // mark obj type in file
			break;
		case '2': 
			pArr[i] = new manager;
			fout << abstr_emp::MANAGER << endl;
			break;
		case '3': 
			pArr[i] = new fink;
			fout << abstr_emp::FINK << endl;
			break;
		case '4': 
			pArr[i] = new highfink;
			fout << abstr_emp::HIGHFINK << endl;
			break;
		}
		
		pArr[i]->SetAll();
		pArr[i]->WriteAll(fout);
		cout << endl;
		i++;
	}
	return i;
}


void showStaff(employee ** pArr, int nSize)
{
	if (nSize)
		cout << endl << "Here is your staff:" << endl << endl;
	else
		cout << endl << "You don't have staff." << endl << endl;

	for (int i = 0; i < nSize; i++)
	{
		pArr[i]->ShowAll();
		cout << "-------------------------" << endl;
	}
}