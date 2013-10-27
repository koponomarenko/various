#pragma once

#include <iostream>

class clComplex
{
private:
	double nRealPart_;
	double nImaginaryPart_;

public:
	clComplex(void);
	clComplex(double, double);
	~clComplex(void);

	clComplex operator+(const clComplex &) const;
	clComplex operator-(const clComplex &) const;
	clComplex operator*(const clComplex &) const;
	clComplex operator*(int) const;
	clComplex operator~() const;

	friend clComplex operator*(int n, const clComplex & obj) { return obj * n; }
	friend std::istream & operator>>(std::istream &, clComplex &);
	friend std::ostream & operator<<(std::ostream &, const clComplex &);
};

