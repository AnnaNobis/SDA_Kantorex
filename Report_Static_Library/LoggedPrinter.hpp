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
	void ReadLoggReportAll(/*std::string requestedName*/);
	void ReadLoggReportSurname(std::string requestedSurname);


};