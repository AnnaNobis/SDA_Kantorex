#include "pch.h"
#include "Authorization.hpp"


bool Authorization::checkLogin(std::string userLogin)
{
	auto findUserLogin = [userLogin](User user)
	{

		if (userLogin == user.getLogin())
		{
			return true;
		}
		else
		{
			return false;
		}

	};
	auto it = std::find_if((_users.getUsersList())->begin(), (_users.getUsersList())->end(), findUserLogin);
	if (it != (_users.getUsersList())->end())
	{
		_checkedUser = (*it);
		return true;
	}
	else
	{
		return false;
	}
}

bool Authorization::checkPassword(std::string userPassword)
{

	if (userPassword == _checkedUser.getPassword())
	{
		return true;
	}
	else
	{
		return false;
	}

}

User Authorization::getCheckedUser()
{
	return _checkedUser;
}