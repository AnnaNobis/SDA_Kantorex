#include "pch.h"
#include "User.hpp"
#include <iostream>

int User::_id = 0;

int User::getUserId()
{
    return _id;
}

std::string User::getUserLastname()
{
    return _lastname;
}

void User::setUserFirstname(std::string firstname)
{
    _firstname = firstname;
}

void User::setUserLastname(std::string lastname)
{
    _lastname = lastname;
}

std::string User::getUserFirstname()
{
    return _firstname;
}
