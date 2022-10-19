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

void User::setUserId(std::string id)
{
    _id = id;
}

//User::~User()
//{
//    --_counter;
//}

std::string User::getUserFirstname() const
{
    return _firstname;
}
