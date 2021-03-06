#include <iostream>
#include <cstring>

#include "clStack.h"

using namespace std;

/*
	Consider the following structure declaration:

		struct customer {
			char fullname[35];
			double payment;
		};
	
	Write a program that adds and removes customer structures from a stack, repre-
	sented by a Stack class declaration. Each time a customer is removed, his or her
	payment should be added to a running total, and the running total should be
	reported. 
	Note: You should be able to use the Stack class unaltered; just change the
	typedef declaration so that Item is type customer instead of unsigned long.
*/

bool FillCustomerData(customer & Customer);

void task_05() // let it be kind a main func
{
	char ch = 0;
	clStack Customers;
	customer Customer;
	double nRunningTotal = 0;

	do
	{
		cout << "a. add customer" << endl
			 << "b. remove customer" << endl 
			 << "q. quit" << endl << endl;

		cin >> ch;
		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());

		switch (ch)
		{
		case 'a':
		case 'A':
			if (Customers.isfull())
				cout << "Stack is full ..." << endl;
			else
			{
				if (FillCustomerData(Customer))
					Customers.push(Customer);
			}
			break;

		case 'b':
		case 'B':
			if (Customers.isempty())
				cout << "Stack is empty ..." << endl;
			else
			{
				if (Customers.pop(Customer))
				{
					nRunningTotal += Customer.payment;
					cout << "Current nRunningTotal = " << nRunningTotal << endl;
				}
			}
			break;

		case 'q':
		case 'Q':
			cout << "Quit ..." << endl;
			break;

		default:
			cout << "Incorrect input! Try again:" << endl;
		}

		cout << endl;
	} while (ch != 'q' && ch != 'Q');
}



bool FillCustomerData(customer & Customer)
{
	Customer.fullname[0] = '\0';
	cout << "Enter full name: ";
	cin.getline(Customer.fullname, customer::kSize);
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	if (strlen(Customer.fullname) == 0)
	{
		cout << "Error. Name hasn't entered!";
		return false;
	}


	cout << "Enter payment: ";
	Customer.payment = 0;
	while (!(cin >> Customer.payment) || Customer.payment <= 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();

	return true;
}