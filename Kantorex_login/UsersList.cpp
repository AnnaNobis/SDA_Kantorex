#include "pch.h"
#include "UsersList.hpp"
#include <iostream>



UsersList::UsersList()
{
    ReadJSONfile jsonFile;
    _usersList = std::make_shared<std::vector<User>>(jsonFile.read());
}

UsersList::UsersList(std::vector<User> lista)
{
    _usersList = std::make_shared<std::vector<User>>(lista);
}


std::shared_ptr<std::vector<User>> UsersList::getUsersList()
{
    return _usersList;
}

User UsersList::getUser(int id)
{
    for (auto it = _usersList->begin(); it != _usersList->end(); ++it)
    {
        if ((*it).getUserId() == std::to_string(id))
        {
            return (*it);
        }
    }
      
     std::cout << "not found" << std::endl;
     return User();
       
}

User UsersList::getUser(std::string lastName)
{
    for (auto it = _usersList->begin(); it != _usersList->end(); ++it)
    {
        if ((*it).getUserLastname() == lastName)
        {
            return (*it);
        }
    }
            std::cout << "not found" << std::endl;
            return User();
}

void UsersList::addUser(std::string firstname, std::string lastname, std::string login, std::string password, ApplicationRole applicationRole)
{
    User newUser(firstname, lastname, login, password, applicationRole);
    _usersList->push_back(newUser);
}

void UsersList::displayUsers()
{
    for (auto it = _usersList->begin(); it != _usersList->end(); ++it)
{
    std::cout << (*it).getUserId() << ", " << (*it).getUserFirstname() << ", " << (*it).getUserLastname() << std::endl;
}
}

UsersList::~UsersList()
{
    WriteJSONfile file;
    file.write(getUsersList());
}
