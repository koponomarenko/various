#include <iostream>
#include <string>
using namespace std;

/*
	Do Programming Exercise 7 but use new to allocate a structure instead of declaring
	a structure variable. Also have the program request the pizza diameter before it
	requests the pizza company name.
*/

void task_08() // let it be kind a main func
{
	struct PizzaInfo
	{
		string sCompanyName;
		float nPizzaDiameter;
		int nPizzaWeight;
	};

	PizzaInfo * pstPizza;
	pstPizza = new PizzaInfo;

	
	/* entering information */

	cout<<"Enter pizza diameter in cm.: ";
	cin>>pstPizza->nPizzaDiameter;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin>>pstPizza->nPizzaDiameter;
	}
	cin.get(); // clear streem from lefted '\n' symbol

	cout<<"Enter Company name: ";
	getline(cin, pstPizza->sCompanyName);
	
	cout<<"Enter pizza weight in gr.: ";
	cin>>pstPizza->nPizzaWeight;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin>>pstPizza->nPizzaWeight;
	}


	/* displaying information */

	cout<<endl;
	cout<<"Company Name: "<<pstPizza->sCompanyName<<endl;
	cout<<"Pizza Diameter: "<<pstPizza->nPizzaDiameter<<endl;
	cout<<"Pizza Weight: "<<pstPizza->nPizzaWeight<<endl;
	cout<<endl;

	delete pstPizza;
}
