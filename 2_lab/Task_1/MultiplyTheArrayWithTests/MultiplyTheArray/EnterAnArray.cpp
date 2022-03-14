#include "EnterAnArray.h"
#include <iostream>
#include <sstream>

int EnterAnArray(const std::string& str, std::vector<float>& arrayOfFloat)
{
	{
		float f;

		std::stringstream ss;
		ss << str;

		while (!ss.eof())
		{
			ss >> f;
			if (ss.fail())
			{
				std::cout << "Invalid argument!\n";
				std::cout << "Please enter: <float> <float>...\n";
				return 1;
			}
			arrayOfFloat.push_back(f);
		}

		return 0;
	}
}
