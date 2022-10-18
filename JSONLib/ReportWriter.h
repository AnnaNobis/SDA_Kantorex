#pragma once
#include <string>
#include <vector>
#include "ReportData.h"
#include "ReportReader.h"
class ReportWriter
{
	static std::string filePath;
	static bool checkIfFileExist(std::string filePath);
public:
	ReportWriter(std::string filePath = "report.json");
	void setFilePath(std::string filePath);
	static void writeReport(ReportData data);
	static void writeNewReport(ReportData data);
	static void writeToExistingReport(ReportData data);
};

//dorobic interfejs
