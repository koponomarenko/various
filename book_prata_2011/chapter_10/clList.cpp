#include "clList.h"


clList::clList(void) : pHead_(0), pTail_(0), nSize_(0)
{
}


clList::~clList(void)
{
	ListItem * del;
	while (pHead_)
	{
		del = pHead_;
		pHead_ = pHead_->pNext_;
		delete del;
	}

	pTail_ = 0;
	nSize_ = 0;
}


void clList::Add(const ListItem & Item)
{
	ListItem * temp = new ListItem(Item);

	if(pHead_ == 0)
		pHead_ = pTail_ = temp;
	else
	{
		pTail_->pNext_ = temp;
		temp->pPrev_ = pTail_;
		pTail_ = pTail_->pNext_;
	}

	nSize_++;
}



void clList::Visit(void (*pf)(ListItem & Item))
{
	for (ListItem * pt = pHead_; pt != 0; pt = pt->pNext_)
		(*pf)(*pt);
}