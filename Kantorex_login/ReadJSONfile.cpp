#include "pch.h"
#include "ReadJSONfile.hpp"


std::vector<User> ReadJSONfile::read()
{
	std::ifstream j("users.json");
	if (!j.is_open())
	{
		std::cout << "file error" << std::endl;
	}
	json data;
	data = json::parse(j);
	//json data;
	//j >> data;
	std::string id = "";
	std::string name;
	std::string surname;
	std::string login;
	std::string password;
	std::string appRole;
	std::vector<User> listaU;
	for (auto& elem : data) 
	{
		id = elem["id"];
		name = elem["firstname"];
		surname = elem["lastname"];
		login = elem["login"];
		password = elem["password"];
		appRole = elem["appRole"];


		listaU.emplace_back(name, surname, login, password, User::stringToEnum(appRole));
		
	}
	j.close();
	return listaU;
}