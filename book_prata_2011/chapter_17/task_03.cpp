#include <iostream>
#include <fstream>
using namespace std;

void copyFiles(const char * file1, const char * file2);

int main(int argc, char *argv[])
{
	if(argc != 3)
		cerr << "Incorrect run: without enough arguments." << endl;
	else
		copyFiles(argv[1], argv[2]);
    
	cout << "File " << argv[1] << " has copied to " << argv[2] << " successfully." << endl;

	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}

void copyFiles(const char * file1, const char * file2)
{
	ifstream fin;
	fin.open(file1, ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "Error during opening file: " << file1 << endl;
		exit(EXIT_FAILURE);
	}

	ofstream fout;
	fout.open(file2, ios_base::out | ios_base::binary);
	if(!fout.is_open())
	{
		cerr << "Error during opening file: " << file2 << endl;
		exit(EXIT_FAILURE);
	}

	//fout << fin.rdbuf(); // what about this?
	
	char buff[512];

	while (fin)
	{
		fin.read(buff, sizeof buff);
		fout.write(buff, fin.gcount());
	}
}