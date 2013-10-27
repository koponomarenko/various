#pragma once

#include "clCd_1.h"

class clClassic_1 : public clCd_1
{
	char szPrimaryWork_[50];

public:
	clClassic_1(char * szPrimaryWork, char * szPerformers, char * szLabel, int nSelections, double nPlayTime);
	clClassic_1(char * szPrimaryWork, const clCd_1 & d);
	clClassic_1();
	virtual ~clClassic_1(void);
};
