#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

/*

*/

static int reduce(long ar[], int n);

void task_04() // let it be kind a main func
{
	const int kSize = 9;
	long arr[kSize] = {4, 5, 9, 3, 4, 1, 1, 3};
	long * arrEnd = &arr[kSize - 1];

	cout << "Origin arr: " << endl;
	copy(arr, arrEnd, ostream_iterator<long, char> (cout, " "));
	cout << endl << endl;

	arrEnd = arr + reduce(arr, arrEnd - arr);

	cout << "After reduce func: " << endl;
	copy(arr, arrEnd, ostream_iterator<long, char> (cout, " "));
	cout << endl << endl;
}

int reduce(long ar[], int n)
{
	sort(ar, ar + n);
	long * pEnd = unique(ar, ar + n);
	return pEnd - ar;
}