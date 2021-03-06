#include <iostream>

#include "clMove.h"

using namespace std;

/*
	Here�s a class declaration:

		class Move
		{
		private:
			double x;
			double y;
		public:
			Move(double a = 0, double b = 0); // sets x, y to a, b
			showmove() const; // shows current x, y values
			Move add(const Move & m) const;
			// this function adds x of m to x of invoking object to get new x,
			// adds y of m to y of invoking object to get new y, creates a new
			// move object initialized to new x, y values and returns it
			reset(double a = 0, double b = 0); // resets x,y to a, b
		};

	Create member function definitions and a program that exercises the class.
*/

void task_06() // let it be kind a main func
{
	clMove Move_1, Move_2(2, 3);

	cout << "Move_1: " << endl;
	Move_1.showmove();
	cout << endl;

	Move_1 = Move_1.add(Move_2);
	cout << "Move_1 after \"Move_1 = Move_1.add(Move_2)\": " << endl;
	Move_1.showmove();
	cout << endl;

	Move_1.reset();
	cout << "Move_1 after Move_1.reset(): " << endl;
	Move_1.showmove();
	cout << endl;
}
