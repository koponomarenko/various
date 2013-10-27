#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

/*

*/

static bool isPalindrome(const string & str);

void task_02() // let it be kind a main func
{
	cout << "Enter string: ";
	string str;
	getline(cin, str);
	cout << str << (isPalindrome(str) ? " is palindrome" : " is not palindrome") << endl;
}


bool isNotAlpha_Digit(int x) // can be a lambda func (C++11)
{
	return !(isalpha(x) || isdigit(x));
}

bool isPalindrome(const string & str)
{
	string s1, s2;
	s1 = str;
	
	remove_copy_if(s1.begin(), s1.end(), insert_iterator<string> (s2, s2.begin()), isNotAlpha_Digit);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	s1.clear();
	reverse_copy(s2.begin(), s2.end(), insert_iterator<string>(s1, s1.begin()));

	return s1 == s2;
}