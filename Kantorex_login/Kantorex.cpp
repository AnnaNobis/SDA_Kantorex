#include "pch.h"
#include "Kantorex.hpp"
#include <iostream>
#include "ILoggedUser.hpp"
#include "Cashier.hpp"
#include "Administrator.hpp"
#include "Guest.hpp"


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

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Authorization" << std::endl;
			UsersList usersList;
			User u = usersList.getUser(getId());
			std::string firstname = u.getUserFirstname();
			std::string lastname = u.getUserLastname();
			std::cout << "Logged user: " << lastname << ", " << firstname << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "All users:" << std::endl;
			usersList.displayUsers();
			std::cout << std::endl;
			std::cout << std::endl;

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

std::shared_ptr<ILoggedUser> Kantorex::creatLoggedUser(ApplicationRole appRole)
{
	std::shared_ptr<ILoggedUser> currentUser;
	if (appRole == ApplicationRole::ADMINISTRATOR)
	{
		currentUser = std::make_shared<Administrator>();
		return currentUser;
	}
	else if (appRole == ApplicationRole::CASHIER)
	{
		currentUser = std::make_shared<Cashier>();
		return currentUser;
	}
	else if (appRole == ApplicationRole::GUEST)
	{
		currentUser = std::make_shared<Guest>();
		return currentUser;
	}
	return nullptr;
}
