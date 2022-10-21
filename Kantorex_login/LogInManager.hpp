#pragma once
#include <memory>
#include <iostream>
#include "Authorization.hpp"
#include "ILoggedUser.hpp"
#include "Cashier.hpp"
#include "Administrator.hpp"
#include "Guest.hpp"
#include <conio.h>

class LogInManager
{
	std::string _username;
	std::string _password;
	Authorization _authorization;
	ApplicationRole _role;
public:
	LogInManager();
	void checkUser();
	std::shared_ptr<ILoggedUser> creatLoggedUser();
	void displayLoggedUserInfo();
	void setUsername();
	void setPassword();
	std::string hidePassword(std::string & password);
};

