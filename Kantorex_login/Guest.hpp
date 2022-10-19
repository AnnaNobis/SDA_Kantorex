#pragma once
#include "ILoggedUser.hpp"


class Guest : public ILoggedUser
{
private:
	//AllowedOperations _allowedOperations;
public:
	Guest();
	ILoggedUser::AllowedOperations getAllowedOperations();
	virtual ~Guest() {}
};

