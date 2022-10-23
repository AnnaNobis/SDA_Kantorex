#pragma once
#include "ILoggedUser.hpp"


class Guest : public ILoggedUser
{
public:
	Guest();
	ILoggedUser::AllowedOperations getAllowedOperations() override;
	virtual ~Guest() {}
};

