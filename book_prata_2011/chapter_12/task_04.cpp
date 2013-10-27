#include <iostream>

#include "clStack.h"

using namespace std;

/*
Consider the following variation of the clStack class defined in Listing 10.10:
	// clStack.h -- class declaration for the clStack ADT
	typedef unsigned long Item;
	class clStack
	{
	private:
		enum {MAX = 10}; // constant specific to class
		Item * pitems; // holds clStack items
		int size; // number of elements in clStack
		int top; // index for top clStack item
	public:
		clStack(int n = MAX); // creates clStack with n elements
		clStack(const clStack & st);
		~clStack();
		bool isempty() const;
		bool isfull() const;
		// push() returns false if clStack already is full, true otherwise
		bool push(const Item & item); // add item to clStack
		// pop() returns false if clStack already is empty, true otherwise
		bool pop(Item & item); // pop top into item
		clStack & operator=(const clStack & st);
	};

	As the private members suggest, this class uses a dynamically allocated array to hold
	the clStack items. Rewrite the methods to fit this new representation and write a
	program that demonstrates all the methods, including the copy constructor and
	assignment operator.
*/

void task_04() // let it be kind a main func
{
	unsigned long item;
	clStack Stack;

	char ch;
	do
	{
		cout << "a.Set Stack size	b.Add element" << endl
			 << "c.Get element		d.Copy and show stack" << endl
			 << "q.Quit" << endl;

		cout << ">";
		cin >> ch;
		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());
		
		switch (ch)
		{
		case 'a': // Create Stack
		case 'A':
			{
				cout << "Enter size of Stack: ";
				int size = 0;
				while (!(cin >> size))
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Incorrect input! Try again: ";
				}
				cin.get();

				Stack = clStack(size);
			}
			break;

		case 'b': // Add element
		case 'B':
			if (Stack.isfull())
				cout << "Stack already full\n";
			else
			{
				cout << "Enter a number to add: ";
				while (!(cin >> item))
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Incorrect input! Try again: ";
				}
				cin.get();

				Stack.push(item);
			}
			break;

		case 'c': // Get element
		case 'C':
			if (Stack.isempty())
				cout << "Stack already empty\n";
			else
			{
				Stack.pop(item);
				cout << "Item: " << item << " popped\n";
			}
			break;

		case 'd': // Copy and show stack
		case 'D':
			{
				clStack Stack_tmp (Stack);

				while(!Stack_tmp.isempty())
				{
					Stack_tmp.pop(item);
					cout << "Item: " << item << " popped\n";
				}
			}
			break;
		}

		cout << endl;
	} while (ch != 'q' && ch != 'Q');

	cout << "Bye\n";
}