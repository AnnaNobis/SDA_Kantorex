#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include_libraries/json.hpp"
#include "../Kantorex_login/UsersList.hpp"

using json = nlohmann::json;



static void from_json(const json& j, User& data)
{
	data.setUserFirstname(j.at("firstname"));
	data.setUserLastname(j.at("lastname"));
	data.setUserId(j.at("id"));
}


class ReadJSONfile
{
private:
	std::string _file;
public:
	ReadJSONfile()
		: _file("users.json")
	{
	}
	std::vector<User> read();
};

