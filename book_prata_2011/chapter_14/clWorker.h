#pragma once

#include <string>

class clWorker // an abstract base class
{
private:
	std::string fullname;
	long id;

protected:
	virtual void Data() const;
	virtual void Get();
	
public:
	clWorker() : fullname("no one"), id(0L) {}
	clWorker(const std::string & s, long n) : fullname(s), id(n) {}

	virtual ~clWorker() = 0; // pure virtual function
	virtual void Set() = 0;
	virtual void Show() const = 0;
};


class Waiter : virtual public clWorker
{
private:
	int panache;
	
protected:
	void Data() const;
	void Get();
	
public:
	Waiter() : clWorker(), panache(0) {}
	Waiter(const std::string & s, long n, int p = 0)
	: clWorker(s, n), panache(p) {}
	Waiter(const clWorker & wk, int p = 0)
	: clWorker(wk), panache(p) {}

	void Set();
	void Show() const;
};


class Singer : virtual public clWorker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};

	void Data() const;
	void Get();
	
private:
	static char *pv[Vtypes]; // string equivs of voice types
	int voice;
	
public:
	Singer() : clWorker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other)
	: clWorker(s, n), voice(v) {}
	Singer(const clWorker & wk, int v = other)
	: clWorker(wk), voice(v) {}

	void Set();
	void Show() const;
};


// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
	
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
	: clWorker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const clWorker & wk, int p = 0, int v = other)
	: clWorker(wk), Waiter(wk,p), Singer(wk,v) {}
	SingingWaiter(const Waiter & wt, int v = other)
	: clWorker(wt),Waiter(wt), Singer(wt,v) {}
	SingingWaiter(const Singer & wt, int p = 0)
	: clWorker(wt),Waiter(wt,p), Singer(wt) {}

	void Set();
	void Show() const;
};