#pragma once
#include <string>
#include <vector>
//#include "ReportData.h"
#include "ReportReader.h"
#include "..\Report_Static_Library\ReportData.hpp"

class ReportWriter
{
	static std::string filePath;
	static bool checkIfFileExist();
	static void writeNewReport(ReportData data);
	static void writeToExistingReport(ReportData data);
	void getTransactionID();
public:
	void changePath(std::string newPath);
	static void writeReport(ReportData data);
	
};

