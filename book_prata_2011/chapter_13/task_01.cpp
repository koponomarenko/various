#include <iostream>

#include "clClassic_1.h"

using namespace std;

/*
	Start with the following class declaration:
		// base class
		class Cd { // represents a CD disk
		private:
			char performers[50];
			char label[20];
			int selections; // number of selections
			double playtime; // playing time in minutes
		public:
			Cd(char * s1, char * s2, int n, double x);
			Cd(const Cd & d);
			Cd();
			~Cd();
			void Report() const; // reports all CD data
			Cd & operator=(const Cd & d);
		};

	Derive a Classic class that adds an array of char members that will hold a string
	identifying the primary work on the CD. If the base class requires that any functions
	be virtual, modify the base-class declaration to make it so. If a declared
	method is not needed, remove it from the definition.Test your product with the
	following program:

		#include <iostream>
		using namespace std;
		#include "classic.h" // which will contain #include cd.h 
		void Bravo(const Cd & disk);
		int main()
		{
			Cd Cd("Beatles", "Capitol", 14, 35.5);
			Classic Classic = Classic("Piano Sonata in B flat, Fantasia in C",
				"Alfred Brendel", "Philips", 2, 57.17);
			Cd *pcd = &Cd;
			cout << "Using object directly:\n";
			Cd.Report(); // use Cd method
			Classic.Report(); // use Classic method
			cout << "Using type cd * pointer to objects:\n";
			pcd->Report(); // use Cd method for cd object
			pcd = &Classic;
			pcd->Report(); // use Classic method for classic object
			cout << "Calling a function with a Cd reference argument:\n";
			Bravo(Cd);
			Bravo(Classic);
			cout << "Testing assignment:";
			Classic copy;
			copy = Classic;
			copy.Report()
			return 0;
		}
		void Bravo(const Cd & disk)
		{
			disk.Report();
		}
*/

inline void Bravo(const clCd_1 & disk)
{
	disk.Report();
}

void task_01() // let it be kind a main func
{
	clCd_1 Cd("Beatles", "Capitol", 14, 35.5);
	clClassic_1 Classic = clClassic_1("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	clCd_1 * pCd = &Cd;

	cout << "Using object directly:\n";
	Cd.Report(); // use Cd method
	Classic.Report(); // use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pCd->Report(); // use Cd method for cd object
	pCd = &Classic;
	pCd->Report(); // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(Cd);
	Bravo(Classic);

	cout << "Testing assignment:";
	clClassic_1 ClassicCopy;
	ClassicCopy = Classic;
	ClassicCopy.Report();
}

