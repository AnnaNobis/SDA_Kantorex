#include "pch.h"
#include "LogInManager.hpp"
#include "../JSONLib/LoggedUsersWriter.h"
#include "../Report_Static_Library/Date.hpp"
#include "../Report_Static_Library/Time.hpp"
#include "../Report_Static_Library/RawDate.hpp"
#include "../StaticLib_DisplayWindowsConsole/Menu_Operations.h"

LogInManager::LogInManager()
{
	setUsername();
	setPassword();
}

void LogInManager::checkUser()
{
	const std::string red("\033[0;37;41m");
	const std::string blue("\033[0;37;44m");
	const std::string green("\033[0;37;42m");
	const std::string reset("\033[0m");

	if (_authorization.checkLogin(_username))
	{
		if (_authorization.checkPassword(_password))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << green << "Authorization" <<reset << std::endl;
			displayLoggedUserInfo();
			_role = (_authorization.getCheckedUser()).getAppRole_enum();
			
			LoggedUsersWriter logger;
			logger.write(_authorization.getCheckedUser().getUserFirstname(), _authorization.getCheckedUser().getUserLastname(), true);			
		} 
		else
		{
			std::cout << red << "Invalid password" << reset << std::endl;
			std::cout << std::endl;
			_role = ApplicationRole::UNKNOWN;
		}
	}
	else
	{
		std::cout<< red << "Invalid login" << reset << std::endl;
		std::cout << std::endl;
		_role = ApplicationRole::UNKNOWN;
	}
}

bool LogInManager::isUnknown()
{
	if (_role == ApplicationRole::UNKNOWN)
	{
		return true;
	}
	else
	{
		return false;
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
	Menu_Operations m;
	m.displayOperationName("KANTOREX application");
	//std::cout << "KANTOREX application" << std::endl;
	std::cout << "Enter username: " << std::endl;
	std::string username;
	std::cin >> username;
	_username = username;
}

void LogInManager::setPassword()
{
	std::cout << "Enter password" << std::endl;
	std::string password;
	_password = hidePassword(password);
}

std::string LogInManager::hidePassword(std::string & password, int size)
{
	char c;
	int i = 0;

		while (((c = _getch()) != 13) && i < size)
		{
			std::cout << "*";
			password += c;
			i++;
		}
		std::cout << std::endl;
	return password;
}
