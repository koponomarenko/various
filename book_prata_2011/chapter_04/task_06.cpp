#include <iostream>
using namespace std;

/*
	The CandyBarstructure contains three members,as described in Programming
	Exercise 5.Write a program that creates an array of three CandyBar structures,ini-
	tializes them to values of your choice,and then displays the contents of each struc-
	ture.
*/

void task_06() // let it be kind a main func
{
	struct CandyBar
	{
		char szBrandName[31];
		float nWeight;
		int nCalories;
	};

	const short cSize = 3;

	CandyBar arrSomeName[cSize] = {
		{"First", 2.33f, 200},
		{"Second", 4.43f, 330},
		{"Third", 7.13f, 604}
	};

	for (int i = 0; i < cSize; ++i)
	{
		cout<<"BrandName: "<<arrSomeName[i].szBrandName<<endl;
		cout<<"Weight: "<<arrSomeName[i].nWeight<<endl;
		cout<<"Calories: "<<arrSomeName[i].nCalories<<endl;
		cout<<endl;
	}
}
