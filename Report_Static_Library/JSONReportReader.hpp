#pragma once
#include <string>
#include <fstream>
#include "json/json.hpp"
#include "ReportData.hpp"

using json = nlohmann::json;

class JSONReportReader
{
public:
	static std::vector<ReportData> readReport(std::string filePath);

};