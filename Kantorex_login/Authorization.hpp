#pragma once
#include <vector>
#include <string>
#include "UsersList.hpp"
#include <iostream>
#include <algorithm>

class Authorization
{
private:
	User _checkedUser;
	UsersList _users;
public:
	bool checkLogin(std::string userLogin);
	bool checkPassword(std::string userPassword);
	User getCheckedUser();
};

