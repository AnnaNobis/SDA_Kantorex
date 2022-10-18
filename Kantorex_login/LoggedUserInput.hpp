#pragma once
#include <memory>
#include "ILoggedUser.hpp"
#include "../include_libraries/json.hpp"

class LoggedUserInput : public ILoggedUser
{
protected:
	//std::shared_ptr<ILoggedUser::AllowedOperations> _currentUserAllowedOperations;
	
public:
	//LoggedUserInput(ILoggedUser::AllowedOperations loggedUserAllOp);
	LoggedUserInput();
	bool canBuy();
	bool canSell();
	bool canBalance();
	bool canExit();
	bool canRaport();
};

