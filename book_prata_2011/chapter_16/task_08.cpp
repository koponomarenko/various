#include <iostream>
#include <set>
#include <string>
#include <iterator>
using namespace std;

/*

*/

void task_08() // let it be kind a main func
{
	set<string> MetFriends;
	cout << "Enter Mat friends names (quit to quit): " << endl;
	string sTmp;
	getline(cin, sTmp);
	while (sTmp != "quit")
	{
		MetFriends.insert(sTmp);
		getline(cin, sTmp);
	}

	cout << "Mat friends list: " << endl;
	copy(MetFriends.begin(), MetFriends.end(), ostream_iterator<string, char>(cout, "\n"));
	cout << endl;

	set<string> PatFriends;
	cout << "Enter Pat friends names (quit to quit): " << endl;
	getline(cin, sTmp);
	while (sTmp != "quit")
	{
		PatFriends.insert(sTmp);
		getline(cin, sTmp);
	}

	cout << "Pat friends list: " << endl;
	copy(PatFriends.begin(), PatFriends.end(), ostream_iterator<string, char>(cout, "\n"));
	cout << endl;


	set<string> overall(MetFriends);
	overall.insert(PatFriends.begin(), PatFriends.end());

	cout << "Overall friends list: " << endl;
	copy(overall.begin(), overall.end(), ostream_iterator<string, char>(cout, "\n"));
	cout << endl;
}
