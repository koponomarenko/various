#include <iostream>

#include "TV.h"

using namespace std;

/*

*/

void task_01() // let it be kind a main func
{
	Remote grey;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	grey.RemoteState();

	cout << endl;
	cout << "Try to change remote mode ... \n";
	s42.SetRemoteMode(grey);
	grey.RemoteState();

	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	
	grey.RemoteState();
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	cout << endl;
	cout << "Try to change remote mode ... \n";
	s42.SetRemoteMode(grey);
	grey.RemoteState();
}