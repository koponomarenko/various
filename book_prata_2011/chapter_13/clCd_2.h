#pragma once


class clCd_2 // represents a Cd disk
{
private:
	char * pszPerformers_;
	char * pszLabel_;
	int nSelections_; // number of selections
	double nPlayTime_; // playing time in minutes

public:
	clCd_2(char * szPerformers, char * szLabel, int nSelections, double nPlayTime);
	clCd_2();
	clCd_2(const clCd_2 & d);
	virtual ~clCd_2();

	void Report() const; // reports all clCd_2 data

	clCd_2 & operator=(const clCd_2 & d);
};