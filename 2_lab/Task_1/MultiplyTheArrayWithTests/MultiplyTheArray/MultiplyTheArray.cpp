#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#include "EnterAnArray.h"
#include "MultiplyTheArrayByTheSmallestElement.h"

const std::string enter = "Enter the array elements separated by a space: ";

void OutputAnArray(std::vector<float>& arrayOfFloat)
{
	for (auto& p : arrayOfFloat)
	{
		if (p != arrayOfFloat[arrayOfFloat.size() - 1])
		{
			std::cout << std::fixed << std::setprecision(3) << p << " ";
		}
		else
		{
			std::cout << std::fixed << std::setprecision(3) << p << "\n";
		}
	}
}

int main()
{
	std::vector<float> arrayOfFloat = {};
	std::cout << enter;
	std::string str;
	std::getline(std::cin, str);
	if (EnterAnArray(str, arrayOfFloat))
		return 1;

	MultiplyTheArrayByTheSmallestElement(arrayOfFloat);

	std::sort(arrayOfFloat.begin(), arrayOfFloat.end());

	OutputAnArray(arrayOfFloat);

	return 0;
}
