#include "FindTheSmallestElement.h"

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