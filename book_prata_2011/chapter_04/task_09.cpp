#include <iostream>
#include <cstring>
using namespace std;

/*
	Do Programming Exercise 6, but instead of declaring an array of three CandyBar
	structures, use new to allocate the array dynamically.
*/

void task_09() // let it be kind a main func
{
	struct CandyBar
	{
		char szBrandName[31];
		float nWeight;
		int nCalories;
	};

	const short cSize = 3;

	CandyBar * paSomeName = new CandyBar[cSize];
	memset(paSomeName, 0, sizeof(CandyBar) * cSize);


	strncpy(paSomeName[0].szBrandName, "First", sizeof(paSomeName[0].szBrandName) - 1);
	paSomeName[0].nWeight = 2.33f;
	paSomeName[0].nCalories = 200;

	strncpy(paSomeName[1].szBrandName, "Second", sizeof(paSomeName[1].szBrandName) - 1);
	paSomeName[1].nWeight = 4.43f;
	paSomeName[1].nCalories = 330;

	strncpy(paSomeName[2].szBrandName, "Third", sizeof(paSomeName[2].szBrandName) - 1);
	paSomeName[2].nWeight = 7.13f;
	paSomeName[2].nCalories = 604;


	for (int i = 0; i < cSize; ++i)
	{
		cout<<"BrandName: "<<paSomeName[i].szBrandName<<endl;
		cout<<"Weight: "<<paSomeName[i].nWeight<<endl;
		cout<<"Calories: "<<paSomeName[i].nCalories<<endl;
		cout<<endl;
	}

	delete [] paSomeName;
}
