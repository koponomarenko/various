#pragma once

class clMove
{
	double x;
	double y;

public:
	clMove(double a = 0, double b = 0);
	void showmove() const;
	clMove add(const clMove & m) const;
	void reset(double a = 0, double b = 0);
};
