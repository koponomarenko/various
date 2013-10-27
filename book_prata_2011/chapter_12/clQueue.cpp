#include "clQueue.h"

#include <cstdlib>


// clQueue methods
clQueue::clQueue(int qs) : qsize(qs)
{
	front = rear = 0; // or nullptr
	items = 0;
}


clQueue::~clQueue()
{
	Node * temp;
	while (front != 0) // while clQueue is not yet empty
	{
		temp = front; // save address of front item
		front = front->next;// reset pointer to next item
		delete temp; // delete former front
	}
}


bool clQueue::isempty() const
{
	return items == 0;
}


bool clQueue::isfull() const
{
	return items == qsize;
}


int clQueue::queuecount() const
{
	return items;
}


// Add item to clQueue
bool clQueue::enqueue(const Item & item)
{
	if (isfull())
		return false;

	Node * add = new Node; // create node
	// on failure, new throws std::bad_alloc exception
	add->item = item; // set node pointers
	add->next = 0; // or nullptr;
	items++;
	if (front == 0) // if clQueue is empty,
		front = add; // place item at front
	else
		rear->next = add; // else place at rear
	rear = add; // have rear point to new node
	return true;
}


// Place front item into item variable and remove from clQueue
bool clQueue::dequeue(Item & item)
{
	if (front == 0)
		return false;

	item = front->item; // set item to first item in clQueue
	items--;
	Node * temp = front; // save location of first item
	front = front->next; // reset front to next item
	delete temp; // delete former first item

	if (items == 0)
		rear = 0;
	return true;
}


// customer method
// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}