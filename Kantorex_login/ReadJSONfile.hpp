#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include_libraries/json.hpp"
#include "../Kantorex_login/UsersList.hpp"
#include "Encryption.hpp"

using json = nlohmann::json;



void from_json(const json& j, User& data);

class ReadJSONfile
{
private:
	std::string _file;
public:
	ReadJSONfile()
		: _file("users.json")
	{}
	std::vector<User> read();
};

