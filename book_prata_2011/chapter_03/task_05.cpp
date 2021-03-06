#include <iostream>
using namespace std;

/*
	Write a program that requests the user to enter the current world population 
	and the current population of the U.S.(or of some other nation of your choice).
	Store the information in variables of type long long.
	Have the program display the percent that the U.S.(or other nation’s) population is of the world’s population.
	The output should look something like this:
	Enter the world's population: 6898758899
	Enter the population of the US: 310783781
	The population of the US is 4.50492% of the world population.
	You can use the Internet to get more recent figures.
*/

void task_05() // let it be kind a main func
{
	cout<<"Enter the world's population: ";
	unsigned long long nCurrWorldPopulation = 0;
	cin>>nCurrWorldPopulation;

	cout<<"Enter the population of the US: ";
	unsigned long long nCurrUsPopulation = 0;
	cin>>nCurrUsPopulation;

	cout<<"The population of the US is "<<(nCurrUsPopulation * 100.0) / nCurrWorldPopulation<<"% of the world population.\n";
}
