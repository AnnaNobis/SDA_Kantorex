#include "LoggedUsersWriter.h"
#include "json/json.hpp"
#include <fstream>
#include "LoggedUsersReader.h"
using json = nlohmann::ordered_json;

std::string LoggedUsersWriter::filePath = "loggedUsers.json";

void to_json(json& j, const LoginData& login) {
	j = {
{"name", login._name},
{"surname", login._surname},
{"dateAndTime", login._dateAndTime},
{"isLogged", login._isLogged} };

}

bool LoggedUsersWriter::checkIfFileExist()
{
	std::ifstream checkedFile(filePath);
	return checkedFile.good();
}

void LoggedUsersWriter::writeNewFile(LoginData login)
{
	std::ofstream stream(filePath);
	json j;
	std::vector<LoginData> vectorToWrite;
	vectorToWrite.push_back(login);
	j = json(vectorToWrite);
	stream << std::setw(4) << j << std::endl;
}

void LoggedUsersWriter::writeToExistingFile(LoginData login)
{
	std::vector<LoginData>fileData = LoggedUsersReader::read();
	fileData.push_back(login);

	std::ofstream stream(filePath);
	json j;
	j = json(fileData);
	stream << std::setw(4) << j << std::endl;
}

void LoggedUsersWriter::write(std::string userName, std::string userSurname, bool isLogged)
{
	LoginData data(userName, userSurname, dateAndTime , isLogged);
	if (checkIfFileExist()) {
		writeToExistingFile(data);
	}
	else {
		writeNewFile(data);
	}

}
