#pragma once
#include "User.hpp"
#include <vector>
#include <memory>
#include <vector>
//#include "../include_libraries/json.hpp"
#include "ReadJSONfile.hpp"
#include "WriteJSONfile.hpp"

class UsersList
{
private:
	std::shared_ptr<std::vector<User>> _usersList;
public:
	UsersList(); 
	std::shared_ptr<std::vector<User>> getUsersList();
	User getUser(int id);
	User getUser(std::string lastName);
	//void addUser(std::string firstname, std::string lastname, std::string login, std::string password, ApplicationRole applicationRole);
	//void addUser(std::string firstname, std::string lastname);
	//void addUser(User user);
	void displayUsers();
	
	virtual~UsersList();
};

