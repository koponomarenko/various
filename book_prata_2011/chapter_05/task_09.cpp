#include <iostream>
#include <string>
using namespace std;

/*
	Write a program that matches the description of the program in Exercise 8,
	but use a string class object instead of an array. Include the string
	header file and use a relational operator to make the comparison test.
*/

void task_09() // let it be kind a main func
{
	string sWord;
	int nCountOfWords = 0;

	cout<<"Enter words (to stop, type the word done):"<<endl;
	cin>>sWord;
	while(sWord != "done")
	{
		++nCountOfWords;
		cin>>sWord;
	}

	cout<<endl;
	cout<<"You entered a total of "<<nCountOfWords<<" words."<<endl;
}
