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

void User::setUserFirstname(std::string firstname)
{
    _firstname = firstname;
}

void User::setUserLastname(std::string lastname)
{
    _lastname = lastname;
}

std::string User::getUserFirstname() const
{
    return _firstname;
}
