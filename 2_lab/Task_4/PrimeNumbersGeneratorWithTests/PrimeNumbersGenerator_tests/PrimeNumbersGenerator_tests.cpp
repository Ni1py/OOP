#define CATCH_CONFIG_MAIN
#include <iostream>
#include <set>
#include "../../../../catch2/catch.hpp"

#include "../PrimeNumbersGenerator/GeneratePrimeNumbersSet.h"

SCENARIO("Function GeneratePrimeNumbersSet")
{
	WHEN("0")
	{
		THEN("The number of primes is 0")
		{
			CHECK(GeneratePrimeNumbersSet(0).size() == 0);
		}
	}

	WHEN("1")
	{
		THEN("The number of primes is 0")
		{
			CHECK(GeneratePrimeNumbersSet(1).size() == 0);
		}
	}

	WHEN("10")
	{
		THEN("The number of primes is 4 and set is equal to 2, 3, 5, 7")
		{
			std::set<int> primes = { 2, 3, 5, 7 };
			CHECK(GeneratePrimeNumbersSet(10).size() == 4);
			CHECK(GeneratePrimeNumbersSet(10) == primes);
		}
	}
}
