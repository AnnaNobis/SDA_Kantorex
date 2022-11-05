#include "pch.h"
#include "WriteJSONfile.hpp"


void to_json(json& j, const User& user)
{
	j =
	{
	{"id", user.getUserId()},
	{"firstname", user.getUserFirstname()},
	{"lastname", user.getUserLastname()},
	{"login", user.getLogin()},
	{"password", user.getPassword()},
	{"appRole", user.getAppRole_str()},
	};
}

void WriteJSONfile::write(std::shared_ptr<std::vector<User>> li)
{
	std::ofstream fout("users.json");
	if (!fout.is_open()) {
		std::cout << "file error" << std::endl;
	}
	std::vector<User> list;
	Encryption encodeStr;
	for (auto it = li->begin(); it != li->end(); ++it)
	{
		std::string id = encodeStr.encode((*it).getUserId());
		std::string firstname = encodeStr.encode((*it).getUserFirstname());
		std::string lastname = encodeStr.encode((*it).getUserLastname());
		std::string login = encodeStr.encode((*it).getLogin());
		std::string password = encodeStr.encode((*it).getPassword());
		ApplicationRole appRole = (*it).getAppRole_enum();
		User user(id, firstname, lastname, login, password, appRole);
		list.emplace_back(user);
	}
	json j;
	j = json(list);

	fout << std::setw(4) << j;
	fout.close();
}
