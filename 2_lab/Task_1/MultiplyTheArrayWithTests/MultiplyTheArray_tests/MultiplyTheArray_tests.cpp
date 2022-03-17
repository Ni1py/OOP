#include <iostream>
#include <cmath>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../MultiplyTheArray/EnterAnArray.h"

SCENARIO("EnterAnArray")
{
	WHEN("Enter an empty line")
	{
		std::vector<float> arrayOfFloat = {};

		THEN("Returns an error")
		{
			CHECK(EnterAnArray("", arrayOfFloat) == 1);
		}
	}

	WHEN("Enter the text")
	{
		std::vector<float> arrayOfFloat = {};

		THEN("Returns an error")
		{
			CHECK(EnterAnArray("text", arrayOfFloat) == 1);
		}
	}

	WHEN("Enter numbers with text")
	{
		std::vector<float> arrayOfFloat = {};

		THEN("Returns an error")
		{
			CHECK(EnterAnArray("5.6784 45 23 text", arrayOfFloat) == 1);
		}
	}

	WHEN("Enter numbers into a vector")
	{
		std::vector<float> arrayOfFloat = {};
		EnterAnArray("5.678 45 23", arrayOfFloat);
		std::vector<float> _arrayOfFloat = { 5.678, 45, 23 };

		THEN("These numbers appear in the vector")
		{
			REQUIRE(arrayOfFloat == _arrayOfFloat);
		}
	}
}
