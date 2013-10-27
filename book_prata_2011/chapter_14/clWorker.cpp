#include "clWorker.h"

#include <iostream>
using namespace std;

// clWorker methods
clWorker::~clWorker() { }


// protected methods
void clWorker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}


void clWorker::Get()
{
	getline(cin, fullname);
	cout << "Enter clWorker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}


// Waiter methods
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	clWorker::Get();
	Get();
}


void Waiter::Show() const
{
	cout << "Category: waiter\n";
	clWorker::Data();
	Data();
}


// protected methods
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}


void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
	continue;
}


// Singer methods
char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
	cout << "Enter singer's name: ";
	clWorker::Get();
	Get();
}


void Singer::Show() const
{
	cout << "Category: singer\n";
	clWorker::Data();
	Data();
}


// protected methods
void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}


void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if ( i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}


// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}


void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}


void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	clWorker::Get();
	Get();
}


void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	clWorker::Data();
	Data();
}