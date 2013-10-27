#pragma once

class clBankAccount
{
	std::string sName_;
	std::string sAccNumber_;
	int nBalance_;
	

public:
	clBankAccount(const std::string & sName = "Empty", const std::string & sAccNumber = "Empty", int nBalance = 0)
	{
		sName_ = sName;
		sAccNumber_ = sAccNumber;
		nBalance_ = nBalance;
	}
	
	void DisplayInfo() const
	{
		std::cout << "Account info:" << std::endl;
		std::cout << "Name: " << sName_ << std::endl;
		std::cout << "Account number: " << sAccNumber_ << std::endl;
		std::cout << "Balance: " << nBalance_ << std::endl;
	}
	
	bool AddMoney(int nSum)
	{
		if (nSum < 0)
		{
			std::cout << "You can't add negative sum" << std::endl;
			return false;
		}
		
		nBalance_ += nSum;
		return true;
	}
	
	bool WithdrawingMoney(int nSum)
	{
		if (nSum > nBalance_)
		{
			std::cout << "You can't withdrawing more money that you have" << std::endl;
			return false;
		}
		
		nBalance_ -= nSum;
		return true;
	}
};