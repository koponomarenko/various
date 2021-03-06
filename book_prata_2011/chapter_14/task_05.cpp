#include <iostream>

#include "emp.h"

using namespace std;

/*
	Ответы:
	1. потому что в классах не используются указатели и выделение памяти.
	2. чтобы из-под указателя/ссылки на базовый класс вызывались метода реальных обьектов а не методы базового класса
	3. чтобы избежать нескольких копий его обьектов при множественном наследовании 
	4. он использует данные с классов-родителей
	5. идет автоматическое приведение типа к базовому классу
	6. так делать нельзя, поскольку базовый класс является абстрактным
*/

void task_05() // let it be kind a main func
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout << "-------------------------" << endl;

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout << "-------------------------" << endl;

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	cout << "-------------------------" << endl;

	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	cout << "-------------------------" << endl;

	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << endl;
	cout << "Using an abstr_emp * pointer:" << endl << endl;
	abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
		cout << "-------------------------" << endl;
	}
}
