#include <iostream>
#include <string>
using namespace std;

/*
	Put together a program that keeps track of monetary contributions to the Society
	for the Preservation of Rightful Influence.It should ask the user to enter the num-
	ber of contributors and then solicit the user to enter the name and contribution of
	each contributor.The information should be stored in a dynamically allocated array
	of structures.Each structure should have two members:a character array (or else a
	string object) to store the name and a double member to hold the amount of the
	contribution. After reading all the data,the program should display the names and
	amounts donated for all donors who contributed $10,000 or more.This list should
	be headed by the label Grand Patrons. After that,the program should list the
	remaining donors.That list should be headed Patrons.If there are no donors in one
	of the categories,the program should print the word “none.” Aside from displaying
	two categories,the program need do no sorting.
*/

void task_06() // let it be kind a main func
{
	struct ContribInfo
	{
		string sName;
		double nContribution;
	};
	
	cout << "Enter a numbers of contributors: ";
	int nSize = 0;
	while (!(cin >> nSize))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input. Try again: "; 
	}
	cin.get();

	ContribInfo * pContributors = new ContribInfo[nSize];

	for (int i = 0; i < nSize; ++i)
	{
		cout << "Person #" << i + 1 << endl;
		cout << "Enter a name of contributor: ";
		getline(cin, pContributors[i].sName);

		cout << "Enter a contribution: ";
		while (!(cin >> pContributors[i].nContribution))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: "; 
		}
		cin.get();
	}


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


	delete [] pContributors;
}
