#pragma once

namespace SALES
{
	class clSales
	{
		enum { QUARTERS = 4 };

		double aSales_[QUARTERS];
		double nAverage_;
		double nMax_;
		double nMin_;

	public:
		clSales(const double ar[], int n);

		void Set();
		void Show() const;
	};
}
