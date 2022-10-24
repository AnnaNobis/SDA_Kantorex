#include "pch.h"
#include "User.hpp"
#include <iostream>

int User::_counter = 0;

std::string User::getUserId() const
{
    return _id;
}

std::string User::getUserLastname() const
{
    return _lastname;
}

std::string User::getLogin() const
{
    return _login;
}

std::string User::getPassword() const
{
    return _password;
}

std::string User::getAppRole_str() const
{
    return enumToString(_applicationRole);
}

ApplicationRole User::getAppRole_enum() const
{
    return _applicationRole;
}

std::string User::enumToString(ApplicationRole appRole) const
{
    switch (appRole)
    {
    case ApplicationRole::ADMINISTRATOR :
        return "administrator";
        break;
    case ApplicationRole::CASHIER :
        return "cashier";
        break;
    case ApplicationRole::GUEST :
        return "guest";
        break;
    }
}

ApplicationRole User::stringToEnum(std::string appRole)
{
    if(appRole == "administrator")
        return ApplicationRole::ADMINISTRATOR;
    if(appRole == "cashier")
        return ApplicationRole::CASHIER;
    if (appRole == "guest")
        return ApplicationRole::GUEST;
}

void User::setUserFirstname(std::string firstname)
{
    _firstname = firstname;
}

void User::setUserLastname(std::string lastname)
{
    _lastname = lastname;
}

void User::setLogin(std::string login)
{
    _login = login;
}

void User::setPassword(std::string password)
{
    _password = password;
}

void User::setApplicationRole(ApplicationRole applicatioRole)
{
    _applicationRole = applicatioRole;
}

void User::setUserId(std::string id)
{
    _id = id;
}

std::string User::getUserFirstname() const
{
    return _firstname;
}
