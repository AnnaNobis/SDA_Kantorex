#pragma once
#include "ILoggedUser.hpp"

class Cashier : public ILoggedUser
{
public:
	Cashier();
	ILoggedUser::AllowedOperations getAllowedOperations() override;
	virtual ~Cashier() {}
};

