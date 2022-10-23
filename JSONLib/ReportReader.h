#pragma once
#include <vector>
#include <string>
#include "ReportData.h"
class ReportReader
{
	static std::string filePath;
public:
	static std::vector<ReportData>readReport();
	void changePath(std::string newPath);
};

