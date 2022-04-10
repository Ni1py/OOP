#include "GeneratePrimeNumbersSet.h"

#include <vector>

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primeNumbers;
	std::vector<bool> garbage(upperBound + 1, false);
	for (size_t i = 2; i <= upperBound; i++)
	{
		if (!garbage[i])
		{
			primeNumbers.insert(i);
			for (size_t j = i + i; j <= upperBound; j += i)
			{
				garbage[j] = true;
			}
		}
	}

	return primeNumbers;
}
