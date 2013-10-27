#include "clStack.h"


clStack::clStack(int n)
{
	top = 0;
	size = n;
	pitems = new Item[size];
}

clStack::clStack(const clStack & st)
{
	top = st.top;
	size = st.size;
	pitems = new Item[size];
	for (int i = 0; i < size; ++i)
		pitems[i] = st.pitems[i];
}


clStack::~clStack()
{
	delete [] pitems;
}


bool clStack::isempty() const
{
	return top == 0;
}


bool clStack::isfull() const
{
	return top == size;
}


bool clStack::push(const Item & item)
{
	if (top < size)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}


bool clStack::pop(Item & item)
{
	if (size > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}


clStack & clStack::operator=(const clStack & st)
{
	if (this == &st)
		return *this;

	top = st.top;
	size = st.size;

	delete [] pitems;
	pitems = new Item[size];
	for (int i = 0; i < size; ++i)
		pitems[i] = st.pitems[i];

	return *this;
}