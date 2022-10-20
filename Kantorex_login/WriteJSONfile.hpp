#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include_libraries/json.hpp"
#include "../Kantorex_login/UsersList.hpp"
#include "../Kantorex_login/User.hpp"

using json = nlohmann::json;


static void to_json(json& j, const User& user)
{
	j =
	{
	{"id", user.getUserId()},
	{"firstname", user.getUserFirstname()},
	{"lastname", user.getUserLastname()},
	{"login", user.getLogin()},
	{"password", user.getPassword()},
	{"appRole", user.getAppRole_str()},
	};
}

class WriteJSONfile
{
private:
	std::string _file;
public:
	WriteJSONfile()
		: _file("users.json")
	{
	}
	void write(std::shared_ptr<std::vector<User>> li);
};

