#pragma once


class clCd_1 // represents a Cd disk
{
private:
	char szPerformers_[50];
	char szLabel_[20];
	int nSelections_; // number of selections
	double nPlayTime_; // playing time in minutes

public:
	clCd_1(char * szPerformers, char * szLabel, int nSelections, double nPlayTime);
	clCd_1();
	virtual ~clCd_1();

	void Report() const; // reports all clCd_1 data
};