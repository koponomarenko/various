#include <iostream>

#include "clStonewt.h"

using namespace std;

/*
	Rewrite the Stonewtclass (Listings 11.16 and 11.17) so that it has a state member
	that governs whether the object is interpreted in stone form,integer pounds form,
	or floating-point pounds form.Overload the <<operator to replace the
	show_stn()andshow_lbs()methods.Overload the addition,subtraction,and
	multiplication operators so that one can add,subtract,and multiply Stonewtvalues.
	Test your class with a short program that uses all the class methods and friends.
*/

inline void DisplayFullInfo(clStonewt & obj)
{
	obj.SetState(clStonewt::STONE);
	cout << obj << endl;
	obj.SetState(clStonewt::POUNDS_INT);
	cout << obj << endl;
	obj.SetState(clStonewt::POUNDS_FLOAT);
	cout << obj << endl;
}

void task_05() // let it be kind a main func
{
	clStonewt incognito(21, 5.5); // uses constructor to initialize

	cout << "The celebrity weighed: " << endl;
	DisplayFullInfo(incognito);

	cout << "clStonewt SomeOne = incognito + 30" << endl;
	clStonewt SomeOne = incognito + 30;
	DisplayFullInfo(SomeOne);

	cout << "clStonewt SomeOne = incognito - 20" << endl;
	SomeOne = incognito - 20;
	DisplayFullInfo(SomeOne);

	cout << "clStonewt SomeOne = incognito * 2" << endl;
	SomeOne = incognito * 2;
	DisplayFullInfo(SomeOne);
}
