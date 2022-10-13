#include <iostream>
#include "JSONReader.h"

int main()
{
    JSONReader dataReader;
    dataReader.readCurrencies("JSONTabelaA.json");
    dataReader.wypisz();
}

