#include "pch.h"
#include "LoggedUsersReader.h"
#include "json/json.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
using json = nlohmann::ordered_json;

std::string LoggedUsersReader::filePath = "loggedUsers.json";

 void from_json(const json& j, LoginData& data) {
	j.at("name").get_to(data._name);
	j.at("surname").get_to(data._surname);
	j.at("dateAndTime").get_to(data._dateAndTime);
	j.at("isLogged").get_to(data._isLogged);
}
std::vector<LoginData> LoggedUsersReader::read()
{
	json j;
	std::ifstream stream(filePath);

	if (!stream.is_open())
	{
		std::cout << "Opening error" << std::endl;
	}

	stream >> j;
	stream.close();
	std::vector<LoginData> vect;

	for ( auto& obj : j) {
		vect.push_back(obj);
	}
	//for_each(vect.begin(), vect.end(), [](LoginData d) {std::cout << d._name << "   " << d._surname << "   " << d._dateAndTime << "   " << d._isLogged << std::endl; });
	return vect;
}

void LoggedUsersReader::changePath(std::string newPath)
{
	filePath = newPath;
}
