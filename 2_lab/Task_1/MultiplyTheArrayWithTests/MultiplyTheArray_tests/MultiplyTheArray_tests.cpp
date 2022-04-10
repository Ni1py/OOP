#include <iostream>
#include <cmath>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../MultiplyTheArray/EnterAnArray.h"
#include "../MultiplyTheArray/FindTheSmallestElement.h"
#include "../MultiplyTheArray/MultiplyTheArrayByTheSmallestElement.h"

SCENARIO("Function EnterAnArray")
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

SCENARIO("Function FindTheSmallestElement")
{
	WHEN("Vector with the smallest element 0")
	{
		std::vector<float> arrayOfFloat = { 5.678, 45, 0 };

		THEN("The smallest element is 0")
		{
			float zero = FindTheSmallestElement(arrayOfFloat);
			float _zero = 0;
			CHECK(zero == _zero);
		}
	}

	WHEN("Vector with the smallest element -1")
	{
		std::vector<float> arrayOfFloat = { 5.678, -1, 5, -0.5 };

		THEN("The smallest element is -1")
		{
			float negative = FindTheSmallestElement(arrayOfFloat);
			float _negative = -1;
			CHECK(negative == _negative);
		}
	}
}

SCENARIO("Function MultiplyTheArrayByTheSmallestElement")
{
	WHEN("Vector with the smallest element 0")
	{
		std::vector<float> arrayOfFloat = { 5.678, 45, 0 };

		THEN("All elements of the vector are equal to 0")
		{
			MultiplyTheArrayByTheSmallestElement(arrayOfFloat);
			std::vector<float> zeroVector = { 0, 0, 0 };
			CHECK(arrayOfFloat == zeroVector);
		}
	}

	WHEN("Vector with the smallest element -1")
	{
		std::vector<float> arrayOfFloat = { 5.678, -1, 5, -0.5 };

		THEN("All elements with an inverted sign")
		{
			MultiplyTheArrayByTheSmallestElement(arrayOfFloat);
			std::vector<float> invertVector = { -5.678, 1, -5, 0.5 };
			CHECK(arrayOfFloat == invertVector);
		}
	}

	WHEN("Vector with the smallest element 2")
	{
		std::vector<float> arrayOfFloat = { 5.678, 10, 3.2, 2 };

		THEN("All elements are increased by 2 times")
		{
			MultiplyTheArrayByTheSmallestElement(arrayOfFloat);
			std::vector<float> doubledVector = { 5.678 * 2, 10 * 2, 3.2 * 2, 2 * 2 };
			CHECK(arrayOfFloat == doubledVector);
		}
	}
}
