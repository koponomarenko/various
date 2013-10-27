#include <iostream>
using namespace std;

/*
	Write a program that uses the following functions:
	Fill _array() takes as arguments the name of an array of double values and an
	array size. It prompts the user to enter double values to be entered in the array. It
	ceases taking input when the array is full or when the user enters non-numeric
	input, and it returns the actual number of entries.
	Show_ array() takes as arguments the name of an array of double values and an
	array size and displays the contents of the array.
	Reverse_ array() takes as arguments the name of an array of double values and an
	array size and reverses the order of the values stored in the array.
	The program should use these functions to fill an array, show the array, reverse the
	array, show the array, reverse all but the first and last elements of the array, and then
	show the array.
*/

int Fill_array(double * pArr, int nArrSize);
void Show_array(double * pArr, int nArrSize);
void Reverse_array(double * pArr, int nArrSize);

void task_06() // let it be kind a main func
{
	const int cSize = 10;
	double arrSomeArr[cSize] = {0};

	int nFilledNumb = 0;
	nFilledNumb = Fill_array(arrSomeArr, cSize);
	Show_array(arrSomeArr, nFilledNumb);

	Reverse_array(arrSomeArr, nFilledNumb);
	Show_array(arrSomeArr, nFilledNumb);

	Reverse_array(arrSomeArr + 1, nFilledNumb - 2); // reverse all but the first and last elements
	Show_array(arrSomeArr, nFilledNumb);
}


int Fill_array(double * pArr, int nArrSize)
{
	cout << "Enter double values by spaces: " << endl;
	int i = 0;
	while (i < nArrSize && (cin >> pArr[i]))
	{
		++i;
		if (cin.peek() == '\n')
			break;
	}

	if (!cin)
		cin.clear();

	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	return i;
}


void Show_array(double * pArr, int nArrSize)
{
	cout << "Your array: ";
	for (int i = 0; i < nArrSize; ++i)
		cout << pArr[i] << ' ';
	cout << endl << endl;
}


void Reverse_array(double * pArr, int nArrSize)
{
	double tmp = 0;

	for (int i = 0, j = nArrSize - 1; i < j; ++i, --j)
	{
		tmp = pArr[i];
		pArr[i] = pArr[j];
		pArr[j] = tmp;
	}
}