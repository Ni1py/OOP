#include "algorithm"

#include "FindTheSmallestElement.h"

float FindTheSmallestElement(const std::vector<float>& arrayOfFloat)
{
	float min = *std::min_element(arrayOfFloat.begin(), arrayOfFloat.end());
	return min;
}
