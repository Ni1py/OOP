#include "lib.h"

#include "GeneratePrimeNumbersSet.h"

const std::string errCount = "Invalid usage!";
const std::string usage = "Usage: Program.exe <upperBound> | upperBound - positive number up to the limit of 100000000";
const std::string errValue = "Invalid argument value!";

std::optional<int> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << errCount << "\n"
			<< usage << "\n";
		return std::nullopt;
	}

	std::stringstream ss{ argv[1] };
	int upperBound;
	ss >> upperBound;
	if (ss.fail())
	{
		std::cout << errValue << "\n"
			<< usage << "\n";
		return std::nullopt;
	}

	return std::optional<int>{ upperBound };
}

int main(int argc, char* argv[])
{
	std::optional<int> oUpperBound = ParseArgs(argc, argv);
	if (!oUpperBound)
	{
		return 1;
	}
	int upperBound = oUpperBound.value();

	std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n" << primeNumbers.size() << "\n";
}
