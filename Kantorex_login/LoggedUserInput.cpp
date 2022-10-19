#include "pch.h"
#include "LoggedUserInput.hpp"

//void CurrentUserInput::handleOutput(ICurrentUser::AllowedOperations currentUserAllOp, int userChoice)
//{
//
//}

//LoggedUserInput::LoggedUserInput(ILoggedUser::AllowedOperations currentUserAllOp)
//{
//	_currentUserAllowedOperations = std::make_shared<ILoggedUser::AllowedOperations>(currentUserAllOp);
//}

LoggedUserInput::LoggedUserInput()
{
	//_currentUserAllowedOperations = getAllowedOperations();
}

bool LoggedUserInput::canBuy()
{
	return getCanBuy();
}

bool LoggedUserInput::canSell()
{
	return getCanSell();
}

bool LoggedUserInput::canBalance()
{
	return getCanBalance();
}

bool LoggedUserInput::canExit()
{
	return getCanExit();
}

bool LoggedUserInput::canRaport()
{
	return getCanReport();
}
