#include "pch.h"
#include "Guest.hpp"
#include <iostream>

Guest::Guest()
{
	_operations._canBalance = false;
	_operations._canReport = false;
	_operations._canExit = true;
	_operations._canBuy = false;
	_operations._canSell = false;
}

ILoggedUser::AllowedOperations Guest::getAllowedOperations()
{
	return _operations;
}
