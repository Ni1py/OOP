#include <algorithm>

#include "MultiplyTheArrayByTheSmallestElement.h"

void MultiplyTheArrayByTheSmallestElement(std::vector<float>& arrayOfFloat)
{
	float min = *std::min_element(arrayOfFloat.begin(), arrayOfFloat.end());
	for (size_t i = 0; i < arrayOfFloat.size(); i++)
	{
		arrayOfFloat[i] = arrayOfFloat[i] * min;
	}
}