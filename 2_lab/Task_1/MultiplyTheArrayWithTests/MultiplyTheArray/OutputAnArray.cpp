#include <iostream>
#include <vector>
#include <iomanip>
#include "OutputAnArray.h"

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
