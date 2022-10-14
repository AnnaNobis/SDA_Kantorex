// JasonReader.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "JsonReader.h"
#include <iostream>

int main()
{
	JsonReader firstFile;
	firstFile.readFromJason("C:\\Users\\Klaudia\\Desktop\\cpp\\SDA_Kantorex\\vertopal.com_exchange_rates_TabelaA.json");
	firstFile.wypisz();
}

