#include <iostream>
#include <string>
#include "Cpmv.h"
using namespace std;

Cpmv GetNewObj()
{
	return Cpmv();
}

int main()
{
	cout << "def: " << endl;
	Cpmv obj1; // def
	cout << endl;
	
	cout << "with arg: " << endl;
	Cpmv obj2("aaa", "bbb"); // with arg
	cout << endl;
	
	cout << "copy: " << endl;
	Cpmv obj3(obj2); // copy
	cout << endl;
	
	cout << "move: // compiler can optimize it ..." << endl;
	Cpmv obj4(Cpmv("ccc", "ddd")); // move
	cout << endl;
	
	cout << "copy assigning: " << endl;
	obj1 = obj2; // copy assigning
	cout << endl;
	
	cout << "move assigning: " << endl;
	obj3 = Cpmv("ttt", "yyy"); // move assigning
	cout << endl;

	
	cin.ignore(cin.rdbuf()->in_avail()).get();
}
