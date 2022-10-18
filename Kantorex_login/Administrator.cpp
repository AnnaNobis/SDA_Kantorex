#include "pch.h"
#include "Administrator.hpp"
#include <iostream>


Administrator::Administrator()
{
	_operations._canBalance = true;
	_operations._canReport = true;
	_operations._canExit = true;
	_operations._canBuy = false;
	_operations._canSell = false;
}

ILoggedUser::AllowedOperations Administrator::getAllowedOperations()
{
	return _operations;
}
