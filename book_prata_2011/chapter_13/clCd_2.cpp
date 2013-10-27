#include "clCd_2.h"

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strncpy;
using std::strlen;

clCd_2::clCd_2(char * szPerformers, char * szLabel, int nSelections, double nPlayTime)
{
	if (szPerformers)
	{
		pszPerformers_ = new char[strlen(szPerformers) + 1];
		strcpy(pszPerformers_, szPerformers);
	}
	else
		pszPerformers_ = 0;

	if (szLabel)
	{
		pszLabel_ = new char[strlen(szLabel) + 1];
		strcpy(pszLabel_, szLabel);
	}
	else
		pszLabel_ = 0;

	nSelections_ = nSelections;
	nPlayTime_ = nPlayTime;
}


clCd_2::clCd_2()
{
	pszPerformers_ = 0;
	pszLabel_ = 0;
	nSelections_ = 0;
	nPlayTime_ = 0;
}


clCd_2::clCd_2(const clCd_2 & d)
{
	if (d.pszPerformers_)
	{
		pszPerformers_ = new char[strlen(d.pszPerformers_) + 1];
		strcpy(pszPerformers_, d.pszPerformers_);
	}
	else
		pszPerformers_ = 0;

	if (d.pszLabel_)
	{
		pszLabel_ = new char[strlen(d.pszLabel_) + 1];
		strcpy(pszLabel_, d.pszLabel_);
	}
	else
		pszLabel_ = 0;

	nSelections_ = d.nSelections_;
	nPlayTime_ = d.nPlayTime_;
}


clCd_2::~clCd_2()
{
	delete [] pszPerformers_;
	delete []pszLabel_;
}


void clCd_2::Report() const
{
	cout << "Performers: " << (pszPerformers_ ? pszPerformers_ : "none") << endl;
	cout << "Label: " << (pszLabel_ ? pszLabel_ : "none") << endl;
	cout << "Selections: " << nSelections_ << endl;
	cout << "PlayTime: " << nPlayTime_ << endl;
}


clCd_2 & clCd_2::operator=(const clCd_2 & d)
{
	if (this == &d)
		return *this;

	delete [] pszPerformers_;
	if (d.pszPerformers_)
	{
		pszPerformers_ = new char[strlen(d.pszPerformers_) + 1];
		strcpy(pszPerformers_, d.pszPerformers_);
	}
	else
		pszPerformers_ = 0;

	delete []pszLabel_;
	if (d.pszLabel_)
	{
		pszLabel_ = new char[strlen(d.pszLabel_) + 1];
		strcpy(pszLabel_, d.pszLabel_);
	}
	else
		pszLabel_ = 0;

	nSelections_ = d.nSelections_;
	nPlayTime_ = d.nPlayTime_;

	return *this;
}