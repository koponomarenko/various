#include <iostream>
using namespace std;

/*
	Write a C++ program that asks for a distance in furlongs and converts it to yards. (One furlong is 220 yards.)
*/

void task_02() // let it be kind a main func
{
	unsigned long long int nDistFurlongs = 0, nDistYards = 0;
    
    cout<<"Please input distance in furlongs: ";
	cin>>nDistFurlongs;
    while(!cin)
    {
        cout<<"\nIncorrect input!\a\n";
		cin.clear();
		while(cin.rdbuf()->in_avail())
            cin.get();
		cout<<"Try again: ";
		cin>>nDistFurlongs;
    }
    
    nDistYards = nDistFurlongs * 220;
    
    if (nDistFurlongs > nDistYards) // additional ckeck for overflow
    {
        cout<<"Ups!.. Seems like we have got overflow.\n";
        return;
    }
    
    cout<<"So ... "<<nDistFurlongs<<" Furlongs = "<<nDistYards<<" Yards\n";
}