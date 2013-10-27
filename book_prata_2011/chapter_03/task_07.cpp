#include <iostream>
using namespace std;

/*
	Write a program that asks you to enter an automobile gasoline consumption figure in the European style (liters per 100 kilometers) 
	and converts to the U.S.style of miles per gallon. 
	Note that in addition to using different units of measurement, the U.S.approach (distance / fuel) is the inverse of the European approach (fuel / dis-tance).
	Note that 100 kilometers is 62.14 miles,and 1 gallon is 3.875 liters. Thus,19 mpg is about 12.4 l/100 km,and 27 mpg is about 8.7 l/100 km.
*/

void task_07() // let it be kind a main func
{
	const float cLitersInGallon = 3.875f;
	const float cMilesIn100Km = 62.14f;

	cout<<"Enter an automobile gasoline consumption figure\n(liters per 100 kilometers): ";
	float nLitersPer100Km = 0;
	cin>>nLitersPer100Km;

	float nMPG = cMilesIn100Km / (nLitersPer100Km / cLitersInGallon);
	cout<<"U.S.style "<<nMPG<<" miles per gallon.\n";
}
