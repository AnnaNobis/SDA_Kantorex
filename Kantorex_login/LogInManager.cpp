#include "pch.h"
#include "LogInManager.hpp"



LogInManager::LogInManager()
{
	setUsername();
	setPassword();
}

void LogInManager::checkUser()
{
	if (checkLogin(_username))
	{
		if (checkPassword(_password))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Authorization" << std::endl;
			displayLoggedUserInfo();
			_role = getAppRole();
		} 
		else
		{
			std::cout << "Invalid password" << std::endl;
			_role = ApplicationRole::GUEST;// na razie, do przemyślenia
		}
	}
	else
	{
		std::cout << "Invalid login" << std::endl;
		_role = ApplicationRole::GUEST;// na razie, do przemyślenia
	}
}

std::shared_ptr<ILoggedUser> LogInManager::creatLoggedUser()
{
	std::shared_ptr<ILoggedUser> currentUser;
	if (_role == ApplicationRole::ADMINISTRATOR)
	{
		currentUser = std::make_shared<Administrator>();
		return currentUser;
	}
	else if (_role == ApplicationRole::CASHIER)
	{
		currentUser = std::make_shared<Cashier>();
		return currentUser;
	}
	else if (_role == ApplicationRole::GUEST)
	{
		currentUser = std::make_shared<Guest>();
		return currentUser;
	}
	return nullptr;
}

void LogInManager::displayLoggedUserInfo()
{
	UsersList usersList;
	User u = usersList.getUser(getId());
	std::string firstname = u.getUserFirstname();
	std::string lastname = u.getUserLastname();
	std::cout << "Logged user: " << lastname << ", " << firstname << std::endl;
	std::cout << std::endl;
	std::cout << "All users:" << std::endl;
	usersList.displayUsers();
	std::cout << std::endl;
}

void LogInManager::setUsername()
{
	std::cout << "KANTOREX application" << std::endl;
	std::cout << "Enter username: " << std::endl;
	std::string username;
	std::cin >> username;
	_username = username;
}

void LogInManager::setPassword()
{
	std::cout << "Enter password" << std::endl;
	std::string password;
	std::cin >> password;
	_password = password;
}