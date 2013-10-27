#include <iostream>
#include <string>
using namespace std;

/*
	William Wingate runs a pizza-analysis service.For each pizza,he needs to record
	the following information:
	The name of the pizza company, which can consist of more than one word
	The diameter of the pizza
	The weight of the pizza
	Devise a structure that can hold this information and write a program that uses a
	structure variable of that type.The program should ask the user to enter each of the
	preceding items of information,and then the program should display that informa-
	tion.Use cin(or its methods) and cout.
*/

void task_07() // let it be kind a main func
{
	struct PizzaInfo
	{
		string sCompanyName;
		float nPizzaDiameter;
		int nPizzaWeight;
	};

	PizzaInfo stPizza;


	/* entering information */

	cout<<"Enter Company name: ";
	getline(cin, stPizza.sCompanyName);
	
	cout<<"Enter pizza diameter in cm.: ";
	cin>>stPizza.nPizzaDiameter;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin>>stPizza.nPizzaDiameter;
	}

	cout<<"Enter pizza weight in gr.: ";
	cin>>stPizza.nPizzaWeight;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin>>stPizza.nPizzaWeight;
	}


	/* displaying information */

	cout<<endl;
	cout<<"Company Name: "<<stPizza.sCompanyName<<endl;
	cout<<"Pizza Diameter: "<<stPizza.nPizzaDiameter<<endl;
	cout<<"Pizza Weight: "<<stPizza.nPizzaWeight<<endl;
	cout<<endl;
}
