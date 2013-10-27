#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template<class T> // functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) {}
	bool operator()(const T & v) { return v > cutoff; }
};


int main()
{
	TooBig<int> f100(100); // limit = 100
	int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);
	
	// C++11 can use the following instead
	// list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	// list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	
	auto outint = [](int n) { cout << n << " "; };
	
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](int n) { return n > 100; }); // use a named function object
	etcetera.remove_if([](int n) { return n > 200; }); // construct a function object
	cout <<"Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	cin.ignore(cin.rdbuf()->in_avail()).get();
}
