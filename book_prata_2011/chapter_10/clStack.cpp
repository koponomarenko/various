#include "clStack.h"



clStack::clStack() : top(0)
{
}


bool clStack::isempty() const
{
	return top == 0;
}

bool clStack::isfull() const
{
	return top == MAX;
}

bool clStack::push(const Item & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool clStack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}