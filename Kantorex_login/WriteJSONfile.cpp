#include "pch.h"
#include "WriteJSONfile.hpp"

void WriteJSONfile::write(std::shared_ptr<std::vector<User>> li)
{
	std::ofstream fout("users.json");
	if (!fout.is_open()) {
		std::cout << "file error" << std::endl;
	}
	std::vector<User> list;
	for (auto it = li->begin(); it != li->end(); ++it)
	{
		list.push_back(*it);
	}
	json j;
	j = json(list);

	fout << std::setw(4) << j;
	fout.close();
}
