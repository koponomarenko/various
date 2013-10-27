#pragma once


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