#include <iostream>
using namespace std;

/*
	Write a C++ program that uses three user-defined functions (counting main() as one) and produces the following output:
	Three blind mice
	Three blind mice
	See how they run
	See how they run
	One function,called two times,should produce the first two lines,and the remain-ing function,also called twice,should produce the remaining output.
*/

void foo1();
void foo2();

void task_03() // let it be kind a main func
{
	foo1();
	foo1();

	foo2();
	foo2();
}

void foo1()
{
	cout<<"Three blind mice\n";
}

void foo2()
{
	cout<<"See how they run\n";
}