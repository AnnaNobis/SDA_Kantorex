#include "pch.h"
#include "ReadJSONfile.hpp"

std::vector<User> ReadJSONfile::read()
{
	std::ifstream j(_file);
	json data = json::parse(j);
	if (!j.is_open()) {
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	std::vector<User> listaU;
	std::string id;
	std::string name;
	std::string surname;
	for (auto& elem : data)
	{
		id = elem["id"];
		name = elem["firstname"];
		surname = elem["lastname"];
		listaU.emplace_back(name, surname);
	}
	//wypisanie na potrzeby testów
   //std::for_each(listaU.begin(), listaU.end(), [](User c) { std::cout << "id " << c.getUserId() << ". " << c.getUserLastname() << ", " << c.getUserFirstname() << std::endl; });
	j.close();
	return listaU;
}
