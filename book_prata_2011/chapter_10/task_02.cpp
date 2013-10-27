#include <iostream>

#include "clPerson.h"

/*
	Here is a rather simple class definition:

		class Person {
		private:
			static const LIMIT = 25;
			string lname; // Person�s last name
			char fname[LIMIT]; // Person�s first name
		public:
			Person() {lname = ""; fname[0] = �\0�; } // #1
			Person(const string & ln, const char * fn = "Heyyou"); // #2
			// the following methods display lname and fname
			void Show() const; // firstname lastname format
			void FormalShow() const; // lastname, firstname format
		};

	(It uses both a string object and a character array so that you can compare how
	the two forms are used.) Write a program that completes the implementation by
	providing code for the undefined methods. 
	
	The program in which you use the class
	should also use the three possible constructor calls (no arguments, one argument,
	and two arguments) and the two display methods. Here�s an example that uses the
	constructors and methods:

		Person one; // use default constructor
		Person two("Smythecraft"); // use #2 with one default argument
		Person three("Dimwiddy", "Sam"); // use #2, no defaults
		one.Show();
		cout << endl;
		one.FormalShow();
		// etc. for two and three
*/

void task_02() // let it be kind a main func
{
	clPerson one; // use default constructor
	clPerson two("Smythecraft"); // use #2 with one default argument
	clPerson three("Dimwiddy", "Sam"); // use #2, no defaults

	std::cout << ".Show(): ";
	one.Show();
	std::cout << ".FormalShow(): ";
	one.FormalShow();
	std::cout << std::endl;

	std::cout << ".Show(): ";
	two.Show();
	std::cout << ".FormalShow(): ";
	two.FormalShow();
	std::cout << std::endl;

	std::cout << ".Show(): ";
	three.Show();
	std::cout << ".FormalShow(): ";
	three.FormalShow();
	std::cout << std::endl;
}