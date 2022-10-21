#pragma once
#include <string>
#include <vector>
#include "ReportData.h"
#include "ReportReader.h"
class ReportWriter
{
	static std::string filePath;
	static bool checkIfFileExist();
	static void writeNewReport(ReportData data);
	static void writeToExistingReport(ReportData data);
public:
	void changePath(std::string newPath);
	static void writeReport(ReportData data);
};

