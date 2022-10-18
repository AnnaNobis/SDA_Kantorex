#pragma once
#include <iostream>
#include "../include_libraries/json.hpp"
#include <cstdlib>
#include <vector>
#include "UsersList.hpp"
#include "User.hpp"
#include <fstream>
#include <sstream>
#include <list>
#include "../include_libraries/json.hpp"

using json = nlohmann::json;

static void to_json(json& j, User& u)
{
	j = json{ {"id", u.getUserId()}, {"firstname", u.getUserFirstname()}, {"lastname", u.getUserLastname()} };

}

class ReadFromJSON : public UsersList
{
private:
	std::string _file;
public:
	ReadFromJSON(std::string file)
		: _file(file)
	{}
	ReadFromJSON()
		: ReadFromJSON("users.json")
	{}
	std::vector<User> read();
	void write_vec();
	//void write();
};

