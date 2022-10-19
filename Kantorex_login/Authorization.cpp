#include "pch.h"
#include "Authorization.hpp"
//#include "User.hpp"
//#include <iostream>
//#include <algorithm>




Authorization::Authorization()
{
	checkedUser._id = 0;
	checkedUser._login = "";
	checkedUser._password = "";
}

bool Authorization::checkLogin(std::string userLogin)
{
	auto findUserLogin = [userLogin](AuthorizationDataStructure user)
	{

		if (userLogin == user._login)
		{
			return true;
		}
		else
		{
			return false;
		}

	};
	auto it = std::find_if(authorizationData.begin(), authorizationData.end(), findUserLogin);
	if (it != authorizationData.end())
	{
		checkedUser = (*it);
		return true;
	}
	else
	{
		return false;
	}
}

bool Authorization::checkPassword(std::string userPassword)
{

	if (userPassword == checkedUser._password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

ApplicationRole Authorization::getAppRole()
{
	return checkedUser._applicationRole;
}


std::string Authorization::getLogin(int id)
{
	auto findUserLogin = [id](AuthorizationDataStructure user)
	{

		if (id == user._id)
		{
			return true;
		}
		else
		{
			return false;
		}

	};
	auto it = std::find_if(authorizationData.begin(), authorizationData.end(), findUserLogin);
	if (it != authorizationData.end())
	{
		return (*it)._login;
	}
	else
	{
		return "there is no user with given id";
	}
}

std::string Authorization::getPassword(int id)
{
	auto findUserLogin = [id](AuthorizationDataStructure user)
	{

		if (id == user._id)
		{
			return true;
		}
		else
		{
			return false;
		}

	};
	auto checkedUser = std::find_if(authorizationData.begin(), authorizationData.end(), findUserLogin);
	if (checkedUser != authorizationData.end())
	{
		return (*checkedUser)._password;
	}
	else
	{
		return "there is no user with given id";
	}
}

int Authorization::getId()
{
	return checkedUser._id;
}
