#include "pch.h"
#include "UsersList.hpp"
#include <iostream>



UsersList::UsersList()
{
   // JSONfilesManager jsonFile;
   // _usersList = std::make_shared<std::vector<User>>(jsonFile.read());
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

void UsersList::addUser(std::string firstname, std::string lastname)
{
    User newUser(firstname, lastname);
    _usersList->push_back(newUser);
}
void UsersList::addUser(User user)
{
    _usersList->push_back(user);
}

void UsersList::displayUsers()
{
    for (auto it = _usersList->begin(); it != _usersList->end(); ++it)
{
    std::cout << (*it).getUserId() << ", " << (*it).getUserFirstname() << ", " << (*it).getUserLastname() << std::endl;
}
}