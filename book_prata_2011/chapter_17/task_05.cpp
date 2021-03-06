#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <iterator>
using namespace std;



int main() // let it be kind a main func
{
	try
	{
		ifstream fin;
		string sBuff;
		set<string> MetFriends;
		set<string> PatFriends;
	
		fin.open("mat.dat");
		if (!fin.is_open())
			throw "Error while opening file: mat.dat";

		while (fin)
		{
			getline(fin, sBuff);
			if (sBuff.size())
				MetFriends.insert(sBuff);
		}
		fin.close();

		cout << "Mat friends list: " << endl;
		copy(MetFriends.begin(), MetFriends.end(), ostream_iterator<string, char>(cout, "\n"));
		cout << endl;

		fin.open("pat.dat");
		if (!fin.is_open())
			throw "Error while opening file: pat.dat";

		while (fin)
		{
			getline(fin, sBuff);
			if (sBuff.size())
				PatFriends.insert(sBuff);
		}
		fin.close();

		cout << "Pat friends list: " << endl;
		copy(PatFriends.begin(), PatFriends.end(), ostream_iterator<string, char>(cout, "\n"));
		cout << endl;

		set<string> overall;
		overall.insert(MetFriends.begin(), MetFriends.end());
		overall.insert(PatFriends.begin(), PatFriends.end());

		cout << "Overall friends list: " << endl;
		copy(overall.begin(), overall.end(), ostream_iterator<string, char>(cout, "\n"));
	}
	catch (string & ex)
	{
		cerr << ex << endl;
	}
	catch (...)
	{
		cerr << "Unknown exception" << endl;
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}
