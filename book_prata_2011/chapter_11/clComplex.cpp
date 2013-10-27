#include "clComplex.h"


clComplex::clComplex(void) : nRealPart_(0.0), nImaginaryPart_(0.0)
{
}

clComplex::clComplex(double nRealPart, double nImaginaryPart) : nRealPart_(nRealPart), nImaginaryPart_(nImaginaryPart)
{
}


clComplex::~clComplex(void)
{
}


clComplex clComplex::operator+(const clComplex & obj) const
{
	return clComplex(this->nRealPart_ + obj.nRealPart_, this->nImaginaryPart_ + obj.nImaginaryPart_);
}


clComplex clComplex::operator-(const clComplex & obj) const
{
	return clComplex(this->nRealPart_ - obj.nRealPart_, this->nImaginaryPart_ - obj.nImaginaryPart_);
}


clComplex clComplex::operator*(const clComplex & obj) const
{
	clComplex tmp;
	tmp.nRealPart_ = (this->nRealPart_ * obj.nRealPart_) - (this->nImaginaryPart_ * obj.nImaginaryPart_);
	tmp.nImaginaryPart_ = (this->nRealPart_ * obj.nImaginaryPart_) + (this->nImaginaryPart_ * obj.nRealPart_);
	return tmp;
}


clComplex clComplex::operator*(int n) const
{
	return clComplex(this->nRealPart_ * n, this->nImaginaryPart_ * n);
}


clComplex clComplex::operator~() const
{
	return clComplex(this->nRealPart_, this->nImaginaryPart_ * (-1));
}


std::istream & operator>>(std::istream & is, clComplex & obj)
{
	std::cout << "real: ";
	is >> obj.nRealPart_;
	if (is)
	{
		std::cout << "imaginary: ";
		is >> obj.nImaginaryPart_;
	}

	return is;
}


std::ostream & operator<<(std::ostream & os, const clComplex & obj)
{
	return os << "(" << obj.nRealPart_ << "," << obj.nImaginaryPart_ << "i)";
}