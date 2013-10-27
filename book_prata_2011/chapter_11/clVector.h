#pragma once

#include <iostream>
#include <cmath>

namespace VECTOR
{
	class clVector
	{
	public:
		enum Mode {RECT, POL}; // RECT for rectangular, POL for Polar modes
	
	private:
		double x; // horizontal value
		double y; // vertical value
		Mode mode; // RECT or POL

		// private methods for setting values
		void set_x();
		void set_y();

	public:
		clVector();
		clVector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~clVector();

		double xval() const {return x;} // report x value
		double yval() const {return y;} // report y value
		double magval() const { return std::sqrt(x * x + y * y); } // report magnitude
		double angval() const { return (x == 0.0 && y == 0.0) ? 0.0 : std::atan2(y, x); } // report angle
		void polar_mode(); // set mode to POL
		void rect_mode(); // set mode to RECT

		// operator overloading
		clVector operator+(const clVector & b) const;
		clVector operator-(const clVector & b) const;
		clVector operator-() const;
		clVector operator*(double n) const;

		// friends
		friend clVector operator*(double n, const clVector & a);
		friend std::ostream & operator<<(std::ostream & os, const clVector & v);
	};
} // end namespace VECTOR