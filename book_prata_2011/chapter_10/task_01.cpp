#include <iostream>
#include <string>

#include "clBankAccount.h"

/*
	Provide method definitions for the class described in Question 5
	and write a short program that illustrates all the features.
*/

void task_01() // let it be kind a main func
{
	int nSum = 0;
	clBankAccount BankAccount("Some Name", "0992233444", 1000);

	BankAccount.DisplayInfo();
	std::cout << std::endl;


	do
	{
		std::cout << "Enter sum to add to your deposit: ";
		nSum = 0;
		while (!(std::cin >> nSum))
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Incorrect input! Try again: ";
		}
		std::cin.get();
	} while (!BankAccount.AddMoney(nSum));

	std::cout << std::endl;
	BankAccount.DisplayInfo();
	std::cout << std::endl;


	do
	{
		std::cout << "Enter sum to withdraw from your deposit: ";
		nSum = 0;
		while (!(std::cin >> nSum))
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Incorrect input! Try again: ";
		}
		std::cin.get();
	} while (!BankAccount.WithdrawingMoney(nSum));


	std::cout << std::endl;
	BankAccount.DisplayInfo();
	std::cout << std::endl;
}

