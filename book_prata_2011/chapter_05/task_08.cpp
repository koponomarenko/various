#include <iostream>
#include <cstring>
using namespace std;

/*
	Write a program that uses an array of charand a loop to read one word at a time
	until the word done is entered.The program should then report the number of
	words entered (not counting done). A sample run could look like this:
	Enter words (to stop, type the word done):
	anteater birthday category dumpster
	envy finagle geometry done for sure
	You entered a total of 7 words.
	You should include the cstring header file and use the strcmp()function to
	make the comparison test.
*/

void task_08() // let it be kind a main func
{
	char szWord[35] = {0};
	int nCountOfWords = 0;


	cout<<"Enter words (to stop, type the word done):"<<endl;
	cin>>szWord; // not safe input
	while(strcmp(szWord, "done"))
	{
		++nCountOfWords;
		cin>>szWord; // not safe input
	}

	cout<<endl;
	cout<<"You entered a total of "<<nCountOfWords<<" words."<<endl;
}
