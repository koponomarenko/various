#pragma once 

template <typename T>
class clQueue
{
	struct Node	{ T data; Node * next; };

	Node * front_;
	Node * rear_;
	int nSize_;

	clQueue(const clQueue & q) : nSize_(0) { }
	clQueue & operator=(const clQueue & q) { return *this; }

public:
	clQueue();
	virtual ~clQueue();

	void Add(const T & item);
	void Get(T & item);
	int Size() const { return nSize_; }
};


template <typename T>
clQueue<T>::clQueue()
{
	front_ = 0;
	rear_ = 0;
	nSize_ = 0;
}


template <typename T>
clQueue<T>::~clQueue()
{
	Node * tmp;
	while (front_ != 0)
	{
		tmp = front_;
		front_ = front_->next;
		delete tmp;
	}
}


template <typename T>
void clQueue<T>::Add(const T & item)
{
	Node * new_node = new Node;
	new_node->data = item;
	new_node->next = 0;

	if(front_ == 0)
		front_ = new_node;
	else
		rear_->next = new_node;
	rear_ = new_node;
	nSize_++;
}


template <typename T>
void clQueue<T>::Get(T & item)
{
	if (front_ == 0)
		return;

	item = front_->data;
	Node * tmp = front_;
	front_ = front_->next;
	if (front_ == 0)
		rear_ = 0;

	delete tmp;
	nSize_--;
}