#include "pch.h"
#include "Cashier.hpp"
#include <iostream>


Cashier::Cashier()
{
	_operations._canBalance = true;
	_operations._canReport = true;
	_operations._canExit = true;
	_operations._canBuy = true;
	_operations._canSell = true;
}

ILoggedUser::AllowedOperations Cashier::getAllowedOperations()
{
	return _operations;
}
