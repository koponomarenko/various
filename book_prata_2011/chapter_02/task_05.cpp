#include <iostream>
using namespace std;

/*
	Write a program that has main()call a user-defined function 
	that takes a Celsius temperature value as an argument and then returns the equivalent Fahrenheit value. 
	The program should request the Celsius value as input from the user and display the result,as shown in the following code:
	Please enter a Celsius value: 20
	20 degrees Celsius is 68 degrees Fahrenheit.
	For reference,here is the formula for making the conversion:
	Fahrenheit = 1.8 × degrees Celsius + 32.0
*/

inline float CelsiusToFahrenheit(float Celsius)
{
	return 1.8f * Celsius + 32;
}

void task_05() // let it be kind a main func
{
	float Celsius = 0;
	cout<<"Please enter a Celsius value: ";
	cin>>Celsius;

	cout<<Celsius<<" degrees Celsius is "<<CelsiusToFahrenheit(Celsius)<<" degrees Fahrenheit.\n";
	cout<<"For reference,here is the formula for making the conversion:\n";
	cout<<"Fahrenheit = 1.8 * degrees Celsius + 32.0\n";
}
