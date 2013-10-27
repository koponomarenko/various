#include <iostream>
using namespace std;

/*
	Write a program that asks how many miles you have driven and how many gallons of gasoline you have used 
	and then reports the miles per gallon your car has gotten. 
	Or, if you prefer,the program can request distance in kilometers and petrol in liters 
	and then report the result European style,in liters per 100 kilometers.
*/

void task_06() // let it be kind a main func
{
	cout<<"How many miles you have driven: ";
	int nMiles = 0;
	cin>>nMiles;

	cout<<"How many gallons of gasoline you have used: ";
	int nGallons = 0;
	cin>>nGallons;

	cout<<"Your car has gotten "<<nMiles / float(nGallons)<<" miles per gallon.\n";
}
