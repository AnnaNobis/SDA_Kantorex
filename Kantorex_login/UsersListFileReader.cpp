	#include "pch.h"
	#include "UsersListFileReader.hpp"


	std::vector<User> ReadFromJSON::read()
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
	for (auto& elem : data["users"])
	{
		id = elem["id"];
		name = elem["firstname"];
		surname = elem["lastname"];
		listaU.emplace_back(name, surname);
	}
	// wypisanie na potrzeby testów
	//std::for_each(listaU.begin(), listaU.end(), [](User c) { std::cout << "id " << c.getUserId() << ". " << c.getUserLastname() << ", " << c.getUserFirstname() << std::endl; });
	j.close();
	return listaU;
	}

	//void ReadFromJSON::to_json_object(json& j, std::vector<User> usersList)
	//{
	//	j = json::parse(usersList);
	//}

	void ReadFromJSON::write_vec()
	{
		std::ofstream fout("users.json");
		if (!fout.is_open()) {
			std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
		}
		json j;
		j["users"];
		fout << j;
		std::shared_ptr<std::vector<User>> temp = getUsersList();
		for (auto it = temp->begin(); it != temp->end(); ++it)
		{
			j["id"] = (*it).getUserId();
			j["firstname"] = (*it).getUserFirstname();
			j["lastname"] = (*it).getUserLastname();
			fout << j;
		}
		fout.close();
	}

	//void ReadFromJSON::write()
	//{

	//	json j_vec(usersList);
	//	std::ofstream fout("users.json");
	//	if (!fout.is_open()) {
	//		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	//	}
	//	fout << std::setw(4) << j_vec;
	//	fout.close();
	//}
