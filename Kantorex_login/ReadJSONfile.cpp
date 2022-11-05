#include "pch.h"
#include "ReadJSONfile.hpp"

void from_json(const json& j, User& data)
{
	data.setUserId(j.at("id"));
	data.setUserFirstname(j.at("firstname"));
	data.setUserLastname(j.at("lastname"));
	data.setLogin(j.at("login"));
	data.setPassword(j.at("password"));
	data.stringToEnum(j.at("appRole"));
}

std::vector<User> ReadJSONfile::read()
{
	std::ifstream j("users.json");
	if (!j.is_open())
	{
		std::cout << "file error" << std::endl;
	}
	json data;
	data = json::parse(j);
	std::string id = "";
	std::string name;
	std::string surname;
	std::string login;
	std::string password;
	std::string appRole;
	std::vector<User> listaU;
	Encryption decodeStr;
	for (auto& elem : data)
	{
		id = elem["id"];
		name = elem["firstname"];
		surname = elem["lastname"];
		login = elem["login"];
		password = elem["password"];
		appRole = elem["appRole"];


		listaU.emplace_back(decodeStr.decode(id), decodeStr.decode(name), decodeStr.decode(surname), decodeStr.decode(login), decodeStr.decode(password), User::stringToEnum(appRole));

	}
	j.close();
	return listaU;
}