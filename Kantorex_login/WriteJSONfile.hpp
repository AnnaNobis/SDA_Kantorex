#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include_libraries/json.hpp"
#include "../Kantorex_login/UsersList.hpp"
#include "../Kantorex_login/User.hpp"
#include "Encryption.hpp"

using json = nlohmann::json;


void to_json(json& j, const User& user);

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

