#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
	Do Programming Exercise 6 but modify it to get information from a file. The first
	item in the file should be the number of contributors,and the rest of the file should
	consist of pairs of lines,with the first line of each pair being a contributor’s name
	and the second line being a contribution.That is,the file should look like this:
	4
	Sam Stone
	2000
	Freida Flass
	100500
	Tammy Tubbs
	5000
	Rich Raptor
	55000
*/

struct ContribInfo
{
	string sName;
	double nContribution;
};

bool FileToArray(ifstream &inFile, ContribInfo * pContributors, int nSize);
void DisplayContributors(ContribInfo * pContributors, int nSize);


void task_09() // let it be kind a main func
{	
	cout << "This program will take info from file." << endl
		 << "The first item in the file should be the number of contributors," << endl
		 << "and the rest of the file should consist of pairs of lines," << endl
		 << "with the first line of each pair being a contributor’s name" << endl
		 << "and the second line being a contribution" << endl << endl;


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


	int nSize = 0;
	if (!(inFile >> nSize)) // "the number of contributors: "
	{
		cout << "File is corrupt!" << endl;
		return;
	}
	inFile.get();


	ContribInfo * pContributors = new ContribInfo[nSize];

	if (FileToArray(inFile, pContributors, nSize))
		DisplayContributors(pContributors, nSize);
	else
		cout << "File is corrupt!" << endl;


	delete [] pContributors;
}



bool FileToArray(ifstream &inFile, ContribInfo * pContributors, int nSize)
{
	int i = 0;

	while (i < nSize && inFile)
	{
		getline(inFile, pContributors[i].sName); // "Enter a name of contributor: "
		if (!(inFile >> pContributors[i].nContribution)) // "Enter a contribution: "
			return false;
		inFile.get();

		++i;
	}

	return (i == nSize);
}



void DisplayContributors(ContribInfo * pContributors, int nSize)
{
	/* display Grand Patrons */
	bool bFlag = false;
	cout << endl;
	cout << "Grand Patrons" << endl;
	for (int i = 0; i < nSize; ++i)
	{
		if (pContributors[i].nContribution >= 10000)
		{
			bFlag = true;
			cout << pContributors[i].sName << ": $" << pContributors[i].nContribution << endl;
		}
	}
	if (!bFlag)
		cout << "none" << endl;


	/* display Patrons */
	bFlag = false;
	cout << endl;
	cout << "Patrons" << endl;
	for (int i = 0; i < nSize; ++i)
	{
		if (pContributors[i].nContribution < 10000)
		{
			bFlag = true;
			cout << pContributors[i].sName << ": $" << pContributors[i].nContribution << endl;
		}
	}
	if (!bFlag)
		cout << "none" << endl;
}
