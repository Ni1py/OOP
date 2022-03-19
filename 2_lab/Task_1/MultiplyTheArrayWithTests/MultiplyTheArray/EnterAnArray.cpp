#include "EnterAnArray.h"
#include <iostream>
#include <sstream>

const std::string err_argument = "Invalid argument!";
const std::string usage = "Usage: <float> <float>...";

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
				std::cout << err_argument << "\n"
					<< usage << "\n";
				return 1;
			}
			arrayOfFloat.push_back(f);
		}

		return 0;
	}
}
