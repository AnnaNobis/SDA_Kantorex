#pragma once
#include <string>
#include <vector>
#include "ReportData.hpp"
#include "JSONReportReader.hpp"
class JSONReportWriter
{
	static std::string filePath;
	static bool checkIfFileExist(std::string filePath);
	public:
		//JSONReportWriter(/*str filePath*/);
		static void writeReport(std::string filePath, ReportData data);
		static void writeNewReport(std::string filePath, ReportData data);
		static void writeToExistingReport(std::string filePath, ReportData data);
};