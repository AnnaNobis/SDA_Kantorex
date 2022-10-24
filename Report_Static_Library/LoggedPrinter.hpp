#pragma once
#include <vector>
#include "ReportData.hpp"
#include "..\JSONLib\LoggedUsersReader.h"
#include "..\JSONLib\LoggedUsersWriter.h"
#include <algorithm>
#include <iostream>

class LoggedPrinter
{
	std::vector<LoginData> loggedData;
	LoggedUsersReader dataFromFile;
public:

	LoggedPrinter(/*std::string filePath*/);
	std::vector<LoginData> ReadLoggReportAll();
	void ReadLoggReportSurname(std::string requestedSurname);


};