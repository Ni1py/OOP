#include <iostream>
#include <string>
#include "HtmlEncode.h"

int main()
{
	std::string str;

	while (std::getline(std::cin, str))
	{
		std::cout << HtmlEncode(str) << "\n";
	}
}
