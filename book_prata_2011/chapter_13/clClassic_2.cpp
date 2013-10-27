#include "clClassic_2.h"

#include <cstring>

using std::strlen;
using std::strncpy;


clClassic_2::clClassic_2(char * szPrimaryWork, char * szPerformers, char * szLabel, int nSelections, double nPlayTime) : clCd_2(szPerformers, szLabel, nSelections, nPlayTime)
{
	if (szPrimaryWork)
	{
		pszPrimaryWork_ = new char[strlen(szPrimaryWork) + 1];
		strcpy(pszPrimaryWork_, szPrimaryWork);
	}
	else
		pszPrimaryWork_ = 0;
}


clClassic_2::clClassic_2(char * szPrimaryWork, const clCd_2 & d) : clCd_2(d)
{
	if (szPrimaryWork)
	{
		pszPrimaryWork_ = new char[strlen(szPrimaryWork) + 1];
		strcpy(pszPrimaryWork_, szPrimaryWork);
	}
	else
		pszPrimaryWork_ = 0;
}


clClassic_2::clClassic_2()
{
	pszPrimaryWork_ = 0;
}


clClassic_2::clClassic_2(const clClassic_2 & c) : clCd_2(c)
{
	if (c.pszPrimaryWork_)
	{
		pszPrimaryWork_ = new char[strlen(c.pszPrimaryWork_) + 1];
		strcpy(pszPrimaryWork_, c.pszPrimaryWork_);
	}
	else
		pszPrimaryWork_ = 0;
}


clClassic_2::~clClassic_2(void)
{
	delete [] pszPrimaryWork_;
}


clClassic_2 & clClassic_2::operator=(const clClassic_2 & c)
{
	if (this == &c)
		return *this;

	clCd_2::operator=(c);

	delete [] pszPrimaryWork_;
	if (c.pszPrimaryWork_)
	{
		pszPrimaryWork_ = new char[strlen(c.pszPrimaryWork_) + 1];
		strcpy(pszPrimaryWork_, c.pszPrimaryWork_);
	}
	else
		pszPrimaryWork_ = 0;

	return *this;
}
