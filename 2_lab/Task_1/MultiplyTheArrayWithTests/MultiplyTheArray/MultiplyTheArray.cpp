#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include "EnterAnArray.h"
#include "OutputAnArray.h"

float FindTheSmallestElement(const std::vector<float>& arrayOfFloat)
{
	float min = arrayOfFloat[0];
	for (auto& p : arrayOfFloat)
	{
		if (p < min)
		{
			min = p;
		}
	}
	return min;
}

void MultiplyTheArrayByTheSmallestElement(std::vector<float>& arrayOfFloat)
{
	float min = round(FindTheSmallestElement(arrayOfFloat) * 1000) / 1000;
	for (size_t i = 0; i < arrayOfFloat.size(); i++)
	{
		arrayOfFloat[i] = round(arrayOfFloat[i] * 1000) / 1000 * min;
	}
}

int main()
{
	std::vector<float> arrayOfFloat = {};
	std::cout << "Enter the array elements separated by a space: ";
	std::string str;
	std::getline(std::cin, str);
	if (EnterAnArray(str, arrayOfFloat))
		return 1;

	MultiplyTheArrayByTheSmallestElement(arrayOfFloat);

	std::sort(arrayOfFloat.begin(), arrayOfFloat.end());

	OutputAnArray(arrayOfFloat);

	return 0;
}
