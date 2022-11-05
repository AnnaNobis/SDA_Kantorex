#include "pch.h"
#include "Encryption.hpp"


std::string Encryption::encode(std::string str)
{
	for (auto& x : str)
	{
		if (isalpha(x))
		{
			if (islower(x))
			{
				encodeChar(x);
			}
			else
			{
				encodeChar_Big(x);
			}
			
		}
		else
		{
			encodeDigit(x);
		}
	}
	return str;
}

void Encryption::encodeChar(char& sign, int key)
{
	if ((sign + key) >= 122)
	{
		int tempKey = key - (122 - sign);
		if (tempKey == 0)
		{
			sign = 122;
		}
		else
		{
			sign = 96 + tempKey;
		}
	}
	else
	{
		sign += key;
	}
}

std::string Encryption::decode(std::string str)
{
	for (auto& x : str)
	{
		if (isalpha(x))
		{
			if (islower(x))
			{
				decodeChar(x);
			}
			else
			{
				decodeChar_Big(x);
			}
			
		}
		else
		{
			decodeDigit(x);
		}
	}
	return str;
}

void Encryption::decodeChar(char& sign, int key)
{
	if ((sign - key) <= 97)
	{
		int tempKey = key - (sign - 97);
		if (tempKey == 0)
		{
			sign = 97;
		}
		else
		{
			sign = 123 - tempKey;
		}
	}
	else
	{
		sign -= key;
	}
}

void Encryption::encodeDigit(char& digit, int key)
{
	if ((digit + key) >= 57)
	{
		int tempKey = key - (57 - digit);
		if (tempKey == 0)
		{
			digit = 57;
		}
		else
		{
			digit = 47 + tempKey;
		}
	}
	else
	{
		digit += key;
	}
}

void Encryption::decodeDigit(char& digit, int key)
{
	if ((digit - key) <= 48)
	{
		int tempKey = key - (digit - 48);
		if (tempKey == 0)
		{
			digit = 48;
		}
		else
		{
			digit = 58 - tempKey;
		}
	}
	else
	{
		digit -= key;
	}
}

void Encryption::encodeChar_Big(char& sign_b, int key)
{
	if ((sign_b + key) >= 90)
	{
		int tempKey = key - (90 - sign_b);
		if (tempKey == 0)
		{
			sign_b = 90;
		}
		else
		{
			sign_b = 64 + tempKey;
		}
	}
	else
	{
		sign_b += key;
	}
}

void Encryption::decodeChar_Big(char& sign_b, int key)
{
	if ((sign_b - key) <= 65)
	{
		int tempKey = key - (sign_b - 65);
		if (tempKey == 0)
		{
			sign_b = 65;
		}
		else
		{
			sign_b = 91 - tempKey;
		}
	}
	else
	{
		sign_b -= key;
	}
}
