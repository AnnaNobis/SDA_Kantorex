

#include <iostream>
#include "framework.h"
#include <CalculatorCurrency.h>

int main()
{
    CalculatorCurrency exchangeOne(100.10f, "eur", "pln");
   auto result= exchangeOne.Exchange();

    std::cout << result;
}

