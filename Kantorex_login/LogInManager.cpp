#include "pch.h"
#include "LogInManager.hpp"



LogInManager::LogInManager()
{
	setUsername();
	setPassword();
}

void LogInManager::checkUser()
{
	if (_authorization.checkLogin(_username))
	//if (checkLogin(_username))
	{
		if (_authorization.checkPassword(_password))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Authorization" << std::endl;
			displayLoggedUserInfo();
			_role = (_authorization.getCheckedUser()).getAppRole_enum();
		} 
		else
		{
			std::cout << "Invalid password" << std::endl;
			_role = (_authorization.getCheckedUser()).getAppRole_enum();
			//_role = ApplicationRole::GUEST;// na razie, do przemyślenia
		}
	}
	else
	{
		std::cout << "Invalid login" << std::endl;
		_role = (_authorization.getCheckedUser()).getAppRole_enum();
		//_role = ApplicationRole::GUEST;// na razie, do przemyślenia
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
	std::cout << "Logged user: " 
		<< (_authorization.getCheckedUser()).getUserLastname() 
		<< ", " << (_authorization.getCheckedUser()).getUserFirstname() 
		<< std::endl;
	std::cout << std::endl;
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
	//std::cin >> password;
	_password = hidePassword(password);
}

std::string LogInManager::hidePassword(std::string & password)
{
	char c;
	int i = 0;

		while (((c = _getch()) != 13) && i < 8)
		{
			std::cout << "*";
			password += c;
			i++;
		}	
	return password;
}
