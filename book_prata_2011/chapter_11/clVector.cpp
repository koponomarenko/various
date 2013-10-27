#include <cmath>

#include "clVector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	// compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);
	// should be about 57.2957795130823

// private methods
	// set x from polar coordinate
	void clVector::set_x()
	{
		x = magval() * cos(angval());
	}


	// set y from polar coordinate
	void clVector::set_y()
	{
		y = magval() * sin(angval());
	}


// public methods
	clVector::clVector() // default constructor
	{
		x = y = 0.0;
		mode = RECT;
	}


	// construct clVector from rectangular coordinates if form is r
	// (the default) or else from polar coordinates if form is p
	clVector::clVector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			x = n1 * cos(n2 / Rad_to_deg);
			y = n1 * sin(n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument to clVector() -- ";
			cout << "clVector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}


	// reset clVector from rectangular coordinates if form is
	// RECT (the default) or else from polar coordinates if
	// form is POL
	void clVector:: reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			x = n1 * cos(n2 / Rad_to_deg);
			y = n1 * sin(n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument to clVector() -- ";
			cout << "clVector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}


	clVector::~clVector() // destructor
	{
	}


	void clVector::polar_mode() // set to polar mode
	{
		mode = POL;
	}


	void clVector::rect_mode() // set to rectangular mode
	{
		mode = RECT;
	}


	// operator overloading
	// add two clVectors
	clVector clVector::operator+(const clVector & b) const
	{
		return clVector(x + b.x, y + b.y);
	}


	// subtract clVector b from a
	clVector clVector::operator-(const clVector & b) const
	{
		return clVector(x - b.x, y - b.y);
	}


	// reverse sign of clVector
	clVector clVector::operator-() const
	{
		return clVector(-x, -y);
	}


	// multiply clVector by n
	clVector clVector::operator*(double n) const
	{
		return clVector(n * x, n * y);
	}


// friend methods
	// multiply n by clVector a
	clVector operator*(double n, const clVector & a)
	{
		return a * n;
	}


	// display rectangular coordinates if mode is RECT,
	// else display polar coordinates if mode is POL
	std::ostream & operator<<(std::ostream & os, const clVector & v)
	{
		if (v.mode == clVector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == clVector::POL)
		{
			os << "(m,a) = (" << v.magval() << ", "
				<< v.angval() * Rad_to_deg << ")";
		}
		else
			os << "clVector object mode is invalid";

		return os;
	}
} // end namespace VECTOR