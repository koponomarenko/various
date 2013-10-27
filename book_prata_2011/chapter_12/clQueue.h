#pragma once


class Customer
{
private:
	long arrive; // arrival time for customer
	int processtime; // processing time for customer

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class clQueue
{
private:
	// Node is a nested structure definition local to this class
	struct Node { Item item; struct Node * next;};
	enum {Q_SIZE = 10};
	// private class members
	Node * front; // pointer to front of clQueue
	Node * rear; // pointer to rear of clQueue
	int items; // current number of items in clQueue
	const int qsize; // maximum number of items in clQueue

	// preemptive definitions to prevent public copying
	clQueue(const clQueue & q) : qsize(0) { }
	clQueue & operator=(const clQueue & q) { return *this;}

public:
	clQueue(int qs = Q_SIZE); // create clQueue with a qs limit
	~clQueue();

	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item); // add item to end
	bool dequeue(Item &item); // remove item from front
};