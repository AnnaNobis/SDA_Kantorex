#pragma once
#include "../Report_Static_Library/LoginData.h"
#include <string>
#include <vector>
class LoggedUsersReader
{

	static std::string filePath;
public:
	static std::vector<LoginData>read();
	void changePath(std::string newPath);
};

