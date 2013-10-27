#include <iostream>
using namespace std;

/*
	Write a precursor to a menu-driven program.The program should display a menu
	offering four choices,each labeled with a letter.If the user responds with a letter
	other than one of the four valid choices,the program should prompt the user to
	enter a valid response until the user complies.Then the program should use a
	switch to select a simple action based on the user’s selection. A program run could
	look something like this:
	Please enter one of the following choices:
	c) carnivore p) pianist
	t) tree g) game
	f
	Please enter a c, p, t, or g: q
	Please enter a c, p, t, or g: t
	A maple is a tree.
*/

void task_03() // let it be kind a main func
{
	char ch = 0;

	cout << "Please enter one of the following choices:" << endl
		 << "c) carnivore   p) pianist" << endl
		 << "t) tree        g) game" << endl
		 << "e) Exit" << endl;

	while (cin.get(ch) && ch != 'e' && ch != 'E')
	{
		switch (ch)
		{
		case 'c':
		case 'C':
			cout << "A lion is a carnivore." << endl;
			break;

		case 'p':
		case 'P':
			cout << "A pianist likes play on piano." << endl;
			break;
		
		case 't':
		case 'T':
			cout << "A maple is a tree." << endl;
			break;
		
		case 'g':
		case 'G':
			cout << "A game can bring you joy." << endl;
			break;

		default:
			cout << "Please enter c, p, t, g or e: ";
		}

		if (cin.peek() == '\n')
			cin.get();
	}
}