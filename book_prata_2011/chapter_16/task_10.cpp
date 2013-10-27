#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

*/

struct Review {
	std::string title;
	int rating;
	double price;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

void task_10() // let it be kind a main func
{
	// C++98/03. I can't use shared_ptr ... 

	vector<Review> original;
	vector<Review> booksAlphabetical;
	vector<Review> booksByRatingIncr;

	Review temp;
	while (FillReview(temp))
		original.push_back(temp);

	copy(original.begin(), original.end(), insert_iterator< vector<Review> > (booksAlphabetical, booksAlphabetical.begin()));
	sort(booksAlphabetical.begin(), booksAlphabetical.end());

	copy(original.begin(), original.end(), insert_iterator< vector<Review> > (booksByRatingIncr, booksByRatingIncr.begin()));
	sort(booksByRatingIncr.begin(), booksByRatingIncr.end(), worseThan);

	if (original.size() > 0)
	{
		char ch;
		do
		{
			cout << "Select options for displaying books in:" << endl;
			cout << "1. original order" << endl
				 << "2. alphabetical order" << endl
				 << "3. order of increasing ratings" << endl
				 << "4. order of decreasing ratings" << endl
				 << "q. quit" << endl
				 << ">";
			cin >> ch;
			if(cin.rdbuf()->in_avail())
				cin.ignore(cin.rdbuf()->in_avail());

			switch (ch)
			{
			case '1':
				cout << "Rating\tBook\tPrice" << endl;
				for_each(original.begin(), original.end(), ShowReview);
				break;

			case '2':
				cout << "Rating\tBook\tPrice" << endl;
				for_each(booksAlphabetical.begin(), booksAlphabetical.end(), ShowReview);
				break;

			case '3':
				cout << "Rating\tBook\tPrice" << endl;
				for_each(booksByRatingIncr.begin(), booksByRatingIncr.end(), ShowReview);
				break;

			case '4':
				cout << "Rating\tBook\tPrice" << endl;
				for_each(booksByRatingIncr.rbegin(), booksByRatingIncr.rend(), ShowReview);
				break;

			case 'q':
			case 'Q':
				break;

			default:
				cout << "Incorrect Input!"<< endl;
				break;
			}

		} while(ch != 'q' && ch != 'Q');
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
}


bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}


bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	while (!(cin >> rr.rating) || rr.rating < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	
	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	std::cout << "Enter book price: ";
	while (!(cin >> rr.price) || rr.price < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	
	if(cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << "\t" << rr.price << std::endl;
}