#include "pch.h"
#include "pch.h"
#include "ILoggedUser.hpp"

ILoggedUser::ILoggedUser()
{
	_operations._canBalance = false;
	_operations._canReport = false;
	_operations._canExit = false;
	_operations._canBuy = false;
	_operations._canSetOperations = false;
	_operations._canSell = false;
}

bool ILoggedUser::getCanSell()
{
	return _operations._canSell;
}

bool ILoggedUser::getCanBuy()
{
	return _operations._canBuy;
}

bool ILoggedUser::getCanBalance()
{
	return _operations._canBalance;
}

bool ILoggedUser::getCanReport()
{
	return _operations._canReport;
}

bool ILoggedUser::getCanExit()
{
	return _operations._canExit;
}

bool ILoggedUser::getCanSetOperationns()
{
	return _operations._canSetOperations;
}

void ILoggedUser::setAllowedOperations(AllowedOperations operations)
{
	_operations = operations;
}

void ILoggedUser::setCanSell(bool canSell)
{
	_operations._canSell = canSell;
}

void ILoggedUser::setCanBuy(bool canBuy)
{
	_operations._canBuy = canBuy;
}

void ILoggedUser::setCanBalance(bool canBalance)
{
	_operations._canBalance = canBalance;
}

void ILoggedUser::setCanReport(bool canReport)
{
	_operations._canReport = canReport;
}

void ILoggedUser::displayAllowedOperations()
{
	std::cout << "Buy Section: "
		<< (_operations._canBuy ? "access granted" : "no access");
	std::cout<< std::endl;
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
