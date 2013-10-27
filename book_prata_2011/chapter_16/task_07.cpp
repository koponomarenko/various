#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*

*/

static vector<int> Lotto(int a, int b);

void task_07() // let it be kind a main func
{
	cout << "Enter the number of spots on a lottery card,: ";
	int nNubSpotsCard = 0;
	while (!(cin >> nNubSpotsCard) || nNubSpotsCard <= 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();

	cout << "Enter the number of spots selected at random: ";
	int nNubSpotsRand = 0;
	while (!(cin >> nNubSpotsRand) || nNubSpotsRand <= 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();

	vector<int> winners = Lotto(nNubSpotsCard, nNubSpotsRand);

	cout << "Result: ";
	copy(winners.begin(), winners.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;
}

vector<int> Lotto(int a, int b)
{
	vector<int> v(a);

	for (int i = 0; i < v.size(); ++i)
		v[i] = i + 1;
	random_shuffle(v.begin(), v.end());

	return vector<int>(v.begin(), v.begin() + b);
}
