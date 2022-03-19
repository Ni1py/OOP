#include <iostream>
#include <string>
#include "HtmlDecode.h"

int main()
{
    std::string str;
    while (std::getline(std::cin, str))
    {
        std::cout << HtmlDecode(str) << "\n";
    }
}
