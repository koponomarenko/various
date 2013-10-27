#include <iostream>
#include "clWorker.h"
#include "clQueue.h"
using namespace std;

/*

*/

const int SIZE = 5;

void task_03() // let it be kind a main func
{
	clQueue<clWorker *> lolas;
	clWorker * worker = 0;
	
	char choice = 0;
	do
	{
		cout << "Enter the employee category:\n"
			 << "w: waiter  s: singer "
			 << "t: singing waiter	q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q' || choice == 'Q')
			break;

		switch(choice)
		{
		case 'w': worker = new Waiter;
			break;
		case 's': worker = new Singer;
			break;
		case 't': worker = new SingingWaiter;
			break;
		}
		cin.get();
		worker->Set();
		lolas.Add(worker);
	} while (true);


	while (lolas.Size())
	{
		cout << endl;
		lolas.Get(worker);
		worker->Show();
		delete worker;
	}

	cout << "Bye.\n";
}