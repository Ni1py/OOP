#include <algorithm>

#include "MultiplyTheArrayByTheSmallestElement.h"
#include "FindTheSmallestElement.h"

float min;

void MultiplyTheArrayByTheSmallestElement(std::vector<float>& arrayOfFloat)
{
	min = FindTheSmallestElement(arrayOfFloat);
	std::transform(arrayOfFloat.begin(), arrayOfFloat.end(), arrayOfFloat.begin(), [](float fl)
		{
			return fl * min;
		});
}