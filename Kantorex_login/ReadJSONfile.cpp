#include "pch.h"
#include "ReadJSONfile.hpp"

//std::vector<User> ReadJSONfile::read()
//{
//	std::ifstream j(_file);
//	json data = json::parse(j);
//	if (!j.is_open()) {
//		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
//	}
//	std::vector<User> listaU;
//	std::string id;
//	std::string name;
//	std::string surname;
//	std::string login;
//	std::string password;
//	for (auto& elem : data)
//	{
//		id = elem["id"];
//		name = elem["firstname"];
//		surname = elem["lastname"];
//		listaU.emplace_back(name, surname);
//	}
//	//wypisanie na potrzeby testów
//   //std::for_each(listaU.begin(), listaU.end(), [](User c) { std::cout << "id " << c.getUserId() << ". " << c.getUserLastname() << ", " << c.getUserFirstname() << std::endl; });
//	j.close();
//	return listaU;
//}
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
		
		std::cout << elem;

		listaU.emplace_back(name, surname, login, password, User::stringToEnum(appRole));
		
	}
	j.close();
	return listaU;
}