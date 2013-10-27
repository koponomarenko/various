#include <iostream>
using namespace std;

/*
	Write a program using nested loops that asks the user to enter a value for the
	number of rows to display. It should then display that many rows of asterisks,with
	one asterisk in the first row,two in the second row,and so on. For each row,the
	asterisks are preceded by the number of periods needed to make all the rows
	display a total number of characters equal to the number of rows. A sample run
	would look like this:
	Enter number of rows: 5
	....*
	...**
	..***
	.****
	*****
*/

void task_10() // let it be kind a main func
{
	cout<<"Enter number of rows: ";
	int nRow = 0;
	cin>>nRow;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input. Try again: ";
		cin>>nRow;
	}

	cout<<endl;
	for (int i = 0; i < nRow; ++i)
	{
		for (int j = nRow; j > 0; --j)
			if (j > i+1)
				cout<<'.';
			else
				cout<<'*';

		cout<<endl;
	}
}
