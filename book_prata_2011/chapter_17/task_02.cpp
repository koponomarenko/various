#include <iostream>
#include <fstream>
using namespace std;

void toFile(const char * fileName);

int main(int argc, char * argv[])
{
	if (argc < 2)
		cerr << "incorrect argument with " << argv[0] << endl;
	else
		toFile(argv[1]);
	
	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}

void toFile(const char * fileName)
{
	ofstream fout(fileName);
	if(!fout.is_open())
	{
		cerr << "Error during opening file: " << fileName << endl;
		exit(EXIT_FAILURE);
	}

    cout << "Enter string: ";
	while (cin.peek() != EOF)
		fout.put(cin.get());

	fout << flush;
	fout.close();
}