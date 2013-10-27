#include <iostream>

#include "clBadDude.h"

using namespace std;

/*

*/

const int SIZE = 10;

void task_04() // let it be kind a main func
{
	clPerson * lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Wich character you want to create: \n"
			 << "a: Person		b: Gunslinger" << endl
			 << "c: PokerPlayer		d: BadDude" << endl
			 << "q: quit" << endl
			 << ">";
		cin >> choice;
		while (strchr("abcdq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch(choice)
		{
		case 'a': lolas[ct] = new clPerson;
			break;
		case 'b': lolas[ct] = new clGunslinger;
			break;
		case 'c': lolas[ct] = new clPokerPlayer;
			break;
		case 'd': lolas[ct] = new clBadDude;
			break;
		}
		cin.get();
		lolas[ct]->Set();
		cout << endl;
	}

	if (ct)
		cout << "\nHere is your staff:\n";

	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << "Bye.\n";
}