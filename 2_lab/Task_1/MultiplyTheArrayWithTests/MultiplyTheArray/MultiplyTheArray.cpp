#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <iterator>

#include "EnterAnArray.h"
#include "MultiplyTheArrayByTheSmallestElement.h"

const std::string enter = "Enter the array elements separated by a space: ";

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

	std::cout << std::fixed << std::setprecision(3);
	std::copy(arrayOfFloat.begin(), arrayOfFloat.end(), std::ostream_iterator<float>(std::cout, " "));

	return 0;
}
