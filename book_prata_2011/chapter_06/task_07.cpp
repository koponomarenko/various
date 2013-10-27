#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
	Write a program that reads input a word at a time until a lone q is entered.The
	program should then report the number of words that began with vowels,the num-
	ber that began with consonants, and the number that fit neither of those categories.
	One approach is to use isalpha()to discriminate between words beginning with
	letters and those that don’t and then use an iforswitchstatement to further iden-
	tify those passing the isalpha()test that begin with vowels. A sample run might
	look like this:
	Enter words (q to quit):
	The 12 awesome oxen ambled
	quietly across 15 meters of lawn. q
	5 words beginning with vowels
	4 words beginning with consonants
	2 others
*/

void task_07() // let it be kind a main func
{
	string sWord;
	int nVowels = 0;
	int nConsonants = 0;
	int nOtherWords = 0;

	cout << "Enter words (q to quit):" << endl;
	while (cin >> sWord)
	{
		if (sWord == "q")
			break;

		if (isalpha(sWord[0]))
		{
			switch (sWord[0])
			{
			case 'a': // vowels
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				++nVowels;
				break;

			default: // consonants
				++nConsonants;
			}
		}
		else
			++nOtherWords;
	}

	cout << endl;
	cout << nVowels << " words beginning with vowels" << endl;
	cout << nConsonants << " words beginning with consonants" << endl;
	cout << nOtherWords << " others" << endl;
}
