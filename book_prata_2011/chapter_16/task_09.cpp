#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

/*

*/

int MyRand()
{
	return rand()%10;
}

void task_09() // let it be kind a main func
{
	int nSize = 500000;
	cout << "nSize = 500 000" << endl;

	clock_t start, end;
	
	vector<int> vi0(nSize);
	generate_n(vi0.begin(), vi0.size(), MyRand); 

	vector<int> vi;
	copy(vi0.begin(), vi0.end(), insert_iterator< vector<int> >(vi, vi.begin()));
	list<int> li;
	copy(vi0.begin(), vi0.end(), insert_iterator< list<int> >(li, li.begin()));


	// check time for both
	cout << "Sort vector: start" << endl;
	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << "Sort vector: end, time spent:" << (double)(end - start)/CLOCKS_PER_SEC << endl;

	cout << "Sort list: start" << endl;
	start = clock();
	li.sort();
	end = clock();
	cout << "Sort list: end, time spent:" << (double)(end - start)/CLOCKS_PER_SEC << endl;

	// reset
	cout << "Reset list" << endl;
	copy(vi0.begin(), vi0.end(), li.begin());

	// check time for list-vector-list
	cout << "Sort list-vector-list: start" << endl;
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "Sort list-vector-list: end, time spent:" << (double)(end - start)/CLOCKS_PER_SEC << endl;
	
	cout << endl;
}
