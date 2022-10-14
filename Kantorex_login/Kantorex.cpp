#include "pch.h"
#include "Kantorex.hpp"
#include <iostream>
#include "ICurrentUser.hpp"
#include "Cashier.hpp"
#include "Administrator.hpp"
#include "Guest.hpp"



Kantorex::Kantorex()
{
}

ApplicationRole Kantorex::userAuthorization()
{
	std::cout << "Wellcome" << std::endl;
	std::cout << "Enter login" << std::endl;
	std::string login;
	std::cin >> login;
	if (checkLogin(login))
	{
		std::cout << "Enter password" << std::endl;
		std::string password;
		std::cin >> password;

		if (checkPassword(password))
		{
			std::cout << "Authorization" << std::endl;
			return getAppRole();
		}
		else
		{
			std::cout << "Invalid password" << std::endl;
			return ApplicationRole::GUEST;// na razie, do przemyślenia
		}
	}
	else
	{
		std::cout << "Invalid login" << std::endl;
		return ApplicationRole::GUEST;// na razie, do przemyślenia
	}
}

std::shared_ptr<ICurrentUser> Kantorex::creatCurrentUser(ApplicationRole appRole)
{
	//std::shared_ptr<ICurrentUser> currentUser = std::make_shared<ICurrentUser>(currentUser);
	std::shared_ptr<ICurrentUser> currentUser;
	if (appRole == ApplicationRole::ADMINISTRATOR)
	{
		currentUser = std::make_shared<Administrator>();
		//currentUser = new Administrator();
		return currentUser;
	}
	else if (appRole == ApplicationRole::CASHIER)
	{
		currentUser = std::make_shared<Cashier>();
		return currentUser;
	}
	else
	{
		currentUser = std::make_shared<Guest>();
		return currentUser;
	}
}
