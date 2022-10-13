#include "pch.h"
#include "UsersList.hpp"
#include <iostream>

std::vector<User>& UsersList::getUsersList()
{
    return _usersList;
}

User UsersList::getUser(int id)
{
    for (auto& user : _usersList)
        if (user.getUserId() == id)
        {
            return user;
        }
        else
        {
            std::cout << "not found" << std::endl;
            return User();
        }
}

User UsersList::getUser(std::string lastName)
{
    for (auto& user : _usersList)
        if (user.getUserLastname() == lastName)
        {
            return user;
        }
        else
        {
            std::cout << "not found" << std::endl;
            return User();
        }
}

void UsersList::addUser(std::string firstname, std::string lastname)
{
    User newUser(firstname, lastname);
    _usersList.push_back(newUser);
}
