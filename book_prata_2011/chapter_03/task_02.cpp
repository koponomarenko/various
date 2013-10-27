#include <iostream>
#include <cmath>
using namespace std;

/*
	Write a short program that asks for your height in feet and inches and your weight in pounds. 
	(Use three variables to store the information.) Have the program report your body mass index (BMI). 
	To calculate the BMI, first convert your height in feet and inches to your height in inches (1 foot = 12 inches).
	Then convert your height in inches to your height in meters by multiplying by 0.0254.
	Then convert your weight in pounds into your mass in kilograms by dividing by 2.2.
	Finally,compute your BMI by dividing your mass in kilograms by the square of your height in meters.
	Use symbolic constants to represent the various conversion factors.
*/

void task_02() // let it be kind a main func
{
	const short kInchesInFeet = 12;

	cout<<"Please, enter your height in feet and inches.\n";

	cout<<"in feet _\b";
	short nHeightInFeet = 0;
	cin>>nHeightInFeet;
	while(!cin)
    {
        cout<<"\nIncorrect input!\a\n";
		cin.clear();
		while(cin.rdbuf()->in_avail())
            cin.get();
		cout<<"Try again: ";
		cin>>nHeightInFeet;
    }

	cout<<"in inches _\b";
	short nHeightInInch = 0;
	cin>>nHeightInInch;
	while(!cin)
    {
        cout<<"\nIncorrect input!\a\n";
		cin.clear();
		while(cin.rdbuf()->in_avail())
            cin.get();
		cout<<"Try again: ";
		cin>>nHeightInInch;
    }

	cout<<"Enter your weight in pounds _\b";
	short nWeightInPounds = 0;
	cin>>nWeightInPounds;
	while(!cin)
    {
        cout<<"\nIncorrect input!\a\n";
		cin.clear();
		while(cin.rdbuf()->in_avail())
            cin.get();
		cout<<"Try again: ";
		cin>>nWeightInPounds;
    }

	/* calculate BMI */
	short nTotalHeightInInch = nHeightInInch + (nHeightInFeet * kInchesInFeet);
	float nHeightInMet = nTotalHeightInInch * 0.0254f;
	float nMassInKg = nWeightInPounds / 2.2f;
	float nBMI = nMassInKg / pow(nHeightInMet, 2);

	cout<<"\nYour body mass index is "<<nBMI<<".\n";
}