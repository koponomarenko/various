#include <iostream>
using namespace std;

/*
	Write a template function maxn() that takes as its arguments an array of items of
	type T and an integer representing the number of elements in the array and that
	returns the largest item in the array. Test it in a program that uses the function template
	with an array of six int value and an array of four double values. The program
	should also include a specialization that takes an array of pointers-to-char as
	an argument and the number of pointers as a second argument and that returns the
	address of the longest string. If multiple strings are tied for having the longest
	length, the function should return the address of the first one tied for longest. Test
	the specialization with an array of five string pointers.
*/

template <typename T>
T maxn(const T pArr, int nSize);

template <>
const char ** maxn<const char **>(const char ** pArr, int nSize);


template <typename T>
void show(const T pArr, int nSize);

template <>
void show<const char **>(const char ** pArr, int nSize);


void task_06() // let it be kind a main func
{
	int ArrInt[6] = {1, 7, 3, 4, 5, 6};
	double ArrDouble[4] = {1.1, 2.2, 9.3, 4.4};

	cout << "Int Arr: ";
	show(ArrInt, sizeof(ArrInt)/sizeof(int));
	cout << "Max from Int Arr: " << *maxn(ArrInt, sizeof(ArrInt)/sizeof(int)) << endl;
	cout << endl;
	cout << "Double Arr: ";
	show(ArrDouble, sizeof(ArrDouble)/sizeof(double));
	cout << "Max from Int Arr: " << *maxn(ArrDouble, sizeof(ArrDouble)/sizeof(double)) << endl;


	const char * ArrStr[5] = 
	{
		"First one",
		"Second one",
		"Third one",
		"Fourth one",
		"Fifth one",
	};

	cout << endl;
	cout << "Char ** Arr: " << endl;
	show(ArrStr, 5);
	cout << "Max from Char ** Arr: " << *maxn(ArrStr, 5) << endl;
}


template <typename T>
T maxn(const T pArr, int nSize)
{
	T Largest = &pArr[0];

	for (int i = 0; i < nSize; ++i)
		if (pArr[i] > *Largest)
			Largest = &pArr[i];

	return Largest;
}


template <>
const char ** maxn<const char **>(const char ** pArr, int nSize)
{
	const char ** Largest = &pArr[0];

	for (int i = 0; i < nSize; ++i)
		if (strlen(pArr[i]) > strlen(*Largest))
			Largest = &pArr[i];

	return Largest;
}



template <typename T>
void show(const T pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << pArr[i] << ' ';
	cout << endl;
}

template <>
void show<const char **>(const char ** pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << pArr[i] << endl;
	cout << endl;
}