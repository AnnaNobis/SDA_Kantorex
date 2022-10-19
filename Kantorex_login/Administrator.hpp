#pragma once
#include "ILoggedUser.hpp"
//#include "Display.hpp"

class Administrator : public ILoggedUser
{
private:
	//AllowedOperations _allowedOperations;
public:
	Administrator();
	ILoggedUser::AllowedOperations getAllowedOperations();
	virtual ~Administrator() {}
};

