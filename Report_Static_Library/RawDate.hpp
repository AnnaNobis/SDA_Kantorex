#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <stdio.h>
#define __STDC_WANT_LIB_EXT1__ 1

class RawDate 
{
	std::string _str;
public:
	RawDate();
	std::string getDate();
	void printDate();
};