#include "pch.h"
#include "Administrator.hpp"
#include <iostream>


Administrator::Administrator()
{
	_operations._canBalance = true;
	_operations._canReport = true;
	_operations._canExit = true;
	_operations._canBuy = false;
	_operations._canSetOperations = true;
	_operations._canSell = false;
}

ILoggedUser::AllowedOperations Administrator::getAllowedOperations()
{
	return _operations;
}

void Administrator::setAllowedOperations(AllowedOperations operations)
{
	_operations = operations;
}

void Administrator::setCanSell(bool canSell)
{
	_operations._canSell = canSell;
}

void Administrator::setCanBuy(bool canBuy)
{
	_operations._canBuy = canBuy;
}

void Administrator::setCanBalance(bool canBalance)
{
	_operations._canBalance = canBalance;
}

void Administrator::setCanReport(bool canReport)
{
	_operations._canReport = canReport;
}

void Administrator::displayAllowedOperations()
{
	std::cout << "Buy Section: "
		<< (_operations._canBuy ? "access granted" : "no access");
	std::cout << std::endl;
	std::cout << "Sell Section: "
		<< (_operations._canSell ? "access granted" : "no access");
	std::cout << std::endl;
	std::cout << "Balance Section: "
		<< (_operations._canBalance ? "access granted" : "no access");
	std::cout << std::endl;
	std::cout << "Report Section: "
		<< (_operations._canReport ? "access granted" : "no access");
	std::cout << std::endl;
	std::cout << "Set Access Section: "
		<< (_operations._canSetOperations ? "access granted" : "no access");
	std::cout << std::endl;
}
