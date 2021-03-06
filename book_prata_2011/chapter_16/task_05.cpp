#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

/*

*/

template <class T>
int reduce(T ar[], int n);

void task_05() // let it be kind a main func
{
	const int kSize = 9;

	// ==================================
	long arr[kSize] = {4, 5, 9, 3, 4, 1, 1, 3};
	long * arrEnd = &arr[kSize - 1];

	cout << "Origin arr: " << endl;
	copy(arr, arrEnd, ostream_iterator<long, char> (cout, " "));
	cout << endl << endl;

	arrEnd = arr + reduce(arr, arrEnd - arr);

	cout << "After reduce func: " << endl;
	copy(arr, arrEnd, ostream_iterator<long, char> (cout, " "));
	cout << endl << endl;

	// ==================================
	string arrStr[kSize] = {"one", "two", "thee", "two", "book", "apple", "book", "two"};
	string * arrStrEnd = &arrStr[kSize - 1];

	cout << "Origin arrStr: " << endl;
	copy(arrStr, arrStrEnd, ostream_iterator<string, char> (cout, " "));
	cout << endl << endl;

	arrStrEnd = arrStr + reduce(arrStr, arrStrEnd - arrStr);

	cout << "After reduce func: " << endl;
	copy(arrStr, arrStrEnd, ostream_iterator<string, char> (cout, " "));
	cout << endl << endl;
}


template <class T>
int reduce(T ar[], int n)
{
	sort(ar, ar + n);
	T * pEnd = unique(ar, ar + n);
	return pEnd - ar;
}