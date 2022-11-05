#pragma once
#include <string>

class Encryption
{
private:

public:
	std::string encode(std::string str);
	std::string decode(std::string str);
	void encodeChar(char& sign, int key = 5);
	void decodeChar(char& sign, int key = 5);
	void encodeDigit(char& digit, int key = 5);
	void decodeDigit(char& digit, int key = 5);
	void encodeChar_Big(char& sign, int key = 5);
	void decodeChar_Big(char& sign, int key = 5);
};

