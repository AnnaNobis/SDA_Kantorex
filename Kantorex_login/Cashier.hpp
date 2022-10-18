#pragma once
#include "ILoggedUser.hpp"
//#include "Display.hpp"

class Cashier : public ILoggedUser
{
private:
	//AllowedOperations _allowedOperations;
public:
	Cashier();
	ILoggedUser::AllowedOperations getAllowedOperations();
	virtual ~Cashier() {}
};

