#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

/*

*/

static bool isPalindrome(const string & str);

void task_01() // let it be kind a main func
{
	cout << "Enter string: ";
	string str;
	getline(cin, str);
	cout << str << (isPalindrome(str) ? " is palindrome" : " is not palindrome") << endl;
}

bool isPalindrome(const string & str)
{
	string sCopy;
	reverse_copy(str.begin(), str.end(), insert_iterator<string>(sCopy, sCopy.begin()));
	return sCopy == str;
}