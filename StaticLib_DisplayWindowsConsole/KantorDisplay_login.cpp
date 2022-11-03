#include "pch.h"
#include "KantorDisplay_login.h"

std::shared_ptr<ILoggedUser> KantorDisplay_login::displayLogin()
{

	LogInManager login;
	login.checkUser();
	if (login.isUnknown())
	{
		return nullptr;
	}
	else
	{
		return login.creatLoggedUser();
	}
}



