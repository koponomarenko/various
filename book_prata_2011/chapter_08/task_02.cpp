#include <iostream>
#include <string>
using namespace std;

/*
	The CandyBar structure contains three members. The first member holds the brand
	name of a candy bar. The second member holds the weight (which may have a frac-
	tional part) of the candy bar, and the third member holds the number of calories
	(an integer value) in the candy bar. Write a program that uses a function that takes
	as arguments a reference to CandyBar, a pointer-to-char, a double, and an int and
	uses the last three values to set the corresponding members of the structure. The last
	three arguments should have default values of “Millennium Munch”, 2.85, and 350.
	Also the program should use a function that takes a reference to a CandyBaras an 
	argument and displays the contents of the structure. Use const where appropriate.
*/

struct CandyBar_t
{
	string sBrandName;
	double nWeight;
	int nCalories;
};

inline void FillCandyBar(CandyBar_t & stCandyBar, const char * pStr = "Millennium Munch", double nWeight = 2.85, int nCalories = 350);
inline void DisplayCandyBar(const CandyBar_t & stCandyBar);

void task_02() // let it be kind a main func
{
	CandyBar_t stCandyBar;
	FillCandyBar(stCandyBar);

	cout << endl;
	cout << "Here is your Candy Bar:" << endl;
	DisplayCandyBar(stCandyBar);
	
	cout << endl;
}



void FillCandyBar(CandyBar_t & stCandyBar, const char * pStr, double nWeight, int nCalories)
{
	stCandyBar.sBrandName = pStr;
	stCandyBar.nWeight = nWeight;
	stCandyBar.nCalories = nCalories;
}

void DisplayCandyBar(const CandyBar_t & stCandyBar)
{
	cout << "BrandName: "  << stCandyBar.sBrandName << endl;
	cout << "Weight: "  << stCandyBar.nWeight << endl;
	cout << "Calories: "  << stCandyBar.nCalories << endl;
}