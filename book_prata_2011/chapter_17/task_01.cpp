#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << "Enter string: ";
	int ct = 0;
	while (cin.peek() != '$')
	{
		cin.get();
		ct++;
	}
	cout << "symb before $ : " << ct << endl;


	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}