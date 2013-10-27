#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void ShowStr(const string & s) { cout << s << endl; }

class Store
{
	ofstream & os;
public:
	Store(ofstream & fout) : os(fout) {}
	void operator()(const string & s)
	{
		size_t size = s.size();
		os.write((char *) &size, sizeof(size_t));
		os.write(s.data(), size);
	}
};

void GetStrs(ifstream & fin, vector<string> & v)
{
	char ch = 0;
	size_t size = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		fin.read((char *) &size, sizeof(size_t));
		while (size--)
		{
			fin.read((char *) &ch, sizeof(char));
			v[i].push_back(ch);
		}
	}
}

int main()
{
	vector<string> vostr;
	string temp;

	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
		vostr.push_back(temp);

	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
	}
	GetStrs(fin, vistr);
	cout << endl << "Here are the strings read from the file:" << endl;
	for_each(vistr.begin(), vistr.end(), ShowStr);

	cin.ignore(cin.rdbuf()->in_avail()).get();
	return 0;
}

