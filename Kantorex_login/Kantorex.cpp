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

ICurrentUser* Kantorex::creatCurrentUser(ApplicationRole appRole)
{
	ICurrentUser* currentUser = nullptr;
	if (appRole == ApplicationRole::ADMINISTRATOR)
	{
		currentUser = new Administrator();
		return currentUser;
	}
	else if (appRole == ApplicationRole::CASHIER)
	{
		currentUser = new Cashier();
		return currentUser;
	}
	else
	{
		currentUser = new Guest();
		return currentUser;
	}
}
