#include <iostream>
using namespace std;

template<typename T>
long double sum_values(const T& value)
{
	return value;
}

template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
	return value + sum_values(args...);
}



int main()
{
	cout << "sum: " << sum_values(2, 3.4, 6.6, 3);
	
	cin.ignore(cin.rdbuf()->in_avail()).get();
}
