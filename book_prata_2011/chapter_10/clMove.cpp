#include <iostream>

#include "clMove.h"

using namespace std;

clMove::clMove(double a, double b) : x(a), y(b) // sets x, y to a, b
{
}


// shows current x, y values
void clMove::showmove() const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}



// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
clMove clMove::add(const clMove & m) const
{
	return clMove(this->x + m.x, this->y + m.y);
}



// resets x,y to a, b
void clMove::reset(double a, double b)
{
	x = a;
	y = b;
}

