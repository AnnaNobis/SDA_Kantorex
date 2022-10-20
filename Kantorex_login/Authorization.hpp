#pragma once
#include <vector>
#include <string>
#include "UsersList.hpp"
#include <iostream>
#include <algorithm>

//class UsersList;

//enum class ApplicationRole
//{
//	ADMINISTRATOR,
//	CASHIER,
//	GUEST
//};

//class AuthorizationData
//{
//private:
//	//int _id;
//	std::string _id;
//	std::string _login;
//	std::string _password;
//	ApplicationRole _applicationRole = ApplicationRole::GUEST;
//public:
//	//c-tor
//	void setId(std::string id);
//	void setLogin(std::string login);
//	void setPassword(std::string password);
//	void setApplicationRole(ApplicationRole applicatioRole);
//	ApplicationRole getAppRole();
//	std::string getLogin(int id);
//	std::string getPassword(int id);
//	int getId();
//};
class Authorization
{
private:
	//std::shared_ptr<std::vector<User>> _authorizationData;
	//std::vector<AuthorizationData> authorizationData
	//{
	//	{1,"cashier","1234", ApplicationRole::CASHIER},
	//	{2,"admin","8888", ApplicationRole::ADMINISTRATOR},
	//	{3,"guest","9999", ApplicationRole::GUEST}
	//};
	User _checkedUser;
	UsersList _users;
public:
	//Authorization();
	bool checkLogin(std::string userLogin);
	bool checkPassword(std::string userPassword);
	User getCheckedUser();
	//ApplicationRole getAppRole();
	//std::string getLogin(int id);
	//std::string getPassword(int id);
	//int getId();
};

