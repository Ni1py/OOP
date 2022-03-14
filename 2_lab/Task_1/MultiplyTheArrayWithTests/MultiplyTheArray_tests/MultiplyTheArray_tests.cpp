#include <iostream>
#include <cmath>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../MultiplyTheArray/EnterAnArray.h"
#include "../MultiplyTheArray/OutputAnArray.h"

SCENARIO("Entering an empty line gives an error")
{
	std::vector<float> arrayOfFloat = {};
	REQUIRE(EnterAnArray("", arrayOfFloat) == 1);
}

SCENARIO("Entering only text gives an error")
{
	std::vector<float> arrayOfFloat = {};
	REQUIRE(EnterAnArray("text", arrayOfFloat) == 1);
}

SCENARIO("Entering numbers with text gives an error")
{
	std::vector<float> arrayOfFloat = {};
	REQUIRE(EnterAnArray("5.6784 45 23 text", arrayOfFloat) == 1);
}

SCENARIO("Entering numbers into a vector")
{
	std::vector<float> arrayOfFloat = {};
	EnterAnArray("5.678 45 23", arrayOfFloat);
	REQUIRE(arrayOfFloat[0] == (float)5.678 && arrayOfFloat[1] == (float)45.0 && arrayOfFloat[2] == (float)23.0); //ошибка во 2 и 3
}