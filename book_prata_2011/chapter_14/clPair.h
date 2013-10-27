#pragma once

template <class T1, class T2>
class clPair
{
private:
	T1 a;
	T2 b;

public:
	T1 & first() { return a; }
	T2 & second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }
	clPair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
	clPair() {}
};
