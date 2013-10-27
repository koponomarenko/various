#include <iostream>
using namespace std;

/*
	Writea short program that asks for your height in integer inches and then converts your height to feet and inches.
	Have the program use the underscore character to indicate where to type the response.
	Also use a constsymbolic constant to repre-sent the conversion factor.
*/

void task_01() // let it be kind a main func
{
	const short kInchesInFeet = 12;
	short nHeightInInch = 0;

	cout<<"Please, enter your height in inches: ___\b\b\b";
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

	cout<<"Your height is "<<nHeightInInch / kInchesInFeet<<" feet and "<<nHeightInInch % kInchesInFeet<<" inches.\n";
}