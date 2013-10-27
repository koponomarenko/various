#pragma once


typedef int ListItem_t;

struct ListItem
{
	ListItem_t Value_;
	ListItem * pPrev_;
	ListItem * pNext_;

	ListItem(ListItem_t val)
	{
		pNext_ = pPrev_ = 0;
		Value_ = val;
	}
};


class clList
{
	ListItem * pHead_;
	ListItem * pTail_;
	int nSize_;

public:
	clList(void);
	~clList(void);

	bool Size() const { return nSize_; }
	void Add(const ListItem & Item);
	void Visit(void (*pf)(ListItem & Item));
};
