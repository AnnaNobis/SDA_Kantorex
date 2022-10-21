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
	data.setUserId(j.at("id"));
	data.setUserFirstname(j.at("firstname"));
	data.setUserLastname(j.at("lastname"));
	data.setLogin(j.at("login"));
	data.setPassword(j.at("password"));
	data.stringToEnum(j.at("appRole"));
}

class ReadJSONfile
{
private:
	
public:
	std::vector<User> read();
};

