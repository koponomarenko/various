#include <iostream>
using namespace std;

/*
	When you join the Benevolent Order of Programmers,you can be known at BOP
	meetings by your real name,your job title,or your secret BOP name.Write a pro-
	gram that can list members by real name,by job title,by secret name,or by a mem-
	ber’s preference.Base the program on the following structure:
		// Benevolent Order of Programmers name structure
		struct bop {
			char fullname[strsize]; // real name
			char title[strsize]; // job title
			char bopname[strsize]; // secret BOP name
			int preference; // 0 = fullname, 1 = title, 2 = bopname
		};
	In the program,create a small array of such structures and initialize it to suitable
	values.Have the program run a loop that lets the user select from different alterna-
	tives:
	a. display by name    b. display by title
	c. display by bopname d. display by preference
	q. quit
	Note that “display by preference”does not mean display the preference member;it
	means display the member corresponding to the preference number.For instance,if
	preference is 1,choice dwould display the programmer’s job title. A sample run
	may look something like the following:
	Benevolent Order of Programmers Report
	a. display by name    b. display by title
	c. display by bopname d. display by preference
	q. quit
	Enter your choice: a
	Wimp Macho
	Raki Rhodes
	Celia Laiter
	Hoppy Hipman
	Pat Hand
	Next choice: d
	Wimp Macho
	Junior Programmer
	MIPS
	Analyst Trainee
	LOOPY
	Next choice: q
	Bye!
*/

void task_04() // let it be kind a main func
{
	const int cStrSize = 65;
	const int cProgrammersSize = 5;

	struct bop {
		char fullname[cStrSize]; // real name
		char title[cStrSize]; // job title
		char bopname[cStrSize]; // secret BOP name
		int preference; // 0 = fullname, 1 = title, 2 = bopname
	};


	bop arrProgrammers[cProgrammersSize] = 
	{
		{"Wimp Macho", "Senior Programmer", "MACHO", 0},
		{"Raki Rhodes", "Junior Programmer", "ROCKET", 1},
		{"Celia Laiter", "Middle Programmer", "MIPS", 2},
		{"Hoppy Hipman", "Analyst Trainee", "HIP-HOP", 1},
		{"Pat Hand", "Half-Middle Programmer", "LOOPY", 2}
	};

	
	cout << "Benevolent Order of Programmers Report" << endl
		 << "a. display by name    b. display by title" << endl
		 << "c. display by bopname d. display by preference" << endl
		 << "q. quit" << endl;


	char ch = 0;

	cout << "Enter your choice: ";
	while (cin.get(ch) && ch != 'q' && ch != 'Q')
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			for (int i = 0 ; i < cProgrammersSize; ++i)
				cout << arrProgrammers[i].fullname << endl;
			break;

		case 'b':
		case 'B':
			for (int i = 0 ; i < cProgrammersSize; ++i)
				cout << arrProgrammers[i].title << endl;			
			break;
		
		case 'c':
		case 'C':
			for (int i = 0 ; i < cProgrammersSize; ++i)
				cout << arrProgrammers[i].bopname << endl;
			break;
		
		case 'd':
		case 'D':
			for (int i = 0 ; i < cProgrammersSize; ++i)
			{
				switch (arrProgrammers[i].preference)
				{
				case 0: // fullname
					cout << arrProgrammers[i].fullname << endl;
					break;
				case 1: // title
					cout << arrProgrammers[i].title << endl;
					break;
				case 2: // bopname
					cout << arrProgrammers[i].bopname << endl;
					break;
				}
			}
			break;

		default:
			cout << "incorrect input." << endl;
		}

		if (cin.peek() == '\n')
			cin.get();
		cout << "Enter your choice: ";
	}
}