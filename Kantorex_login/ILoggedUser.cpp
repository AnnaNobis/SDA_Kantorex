#include "pch.h"
#include "pch.h"
#include "ILoggedUser.hpp"

ILoggedUser::ILoggedUser()
{
	_operations._canBalance = false;
	_operations._canReport = false;
	_operations._canExit = false;
	_operations._canBuy = false;
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
