#pragma once
#include <vector>
#include <string>
#include "UsersList.hpp"

class UsersList;

enum class ApplicationRole
{
	ADMINISTRATOR,
	CASHIER,
	GUEST
};

struct AuthorizationDataStructure
{
	int _id;
	std::string _login;
	std::string _password;
	ApplicationRole _applicationRole = ApplicationRole::GUEST;
};
class Authorization
{
private:
	std::vector<AuthorizationDataStructure> authorizationData
	{
		{1,"cashier","1234", ApplicationRole::CASHIER},
		{2,"admin","8888", ApplicationRole::ADMINISTRATOR},
		{3,"guest","9999", ApplicationRole::GUEST}
	};
	AuthorizationDataStructure checkedUser;

public:
	Authorization();
	bool checkLogin(std::string userLogin);
	bool checkPassword(std::string userPassword);
	ApplicationRole getAppRole();
	std::string getLogin(int id);
	std::string getPassword(int id);
};

