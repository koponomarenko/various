#pragma once


typedef struct customer
{
	static const int kSize = 35;

	char fullname[kSize];
	double payment;
} Item;



class clStack
{
	enum {MAX = 10}; // constant specific to class
	Item items[MAX]; // holds stack items
	int top;

public:
	clStack();

	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item & item); // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item & item); // pop top into item
};
