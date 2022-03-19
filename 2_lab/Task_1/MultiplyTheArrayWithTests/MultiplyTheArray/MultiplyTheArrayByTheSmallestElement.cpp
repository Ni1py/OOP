#include "MultiplyTheArrayByTheSmallestElement.h"
#include "FindTheSmallestElement.h"

void MultiplyTheArrayByTheSmallestElement(std::vector<float>& arrayOfFloat)
{
	float min = FindTheSmallestElement(arrayOfFloat);
	for (size_t i = 0; i < arrayOfFloat.size(); i++)
	{
		arrayOfFloat[i] = arrayOfFloat[i] * min;
	}
}