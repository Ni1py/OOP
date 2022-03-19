#include <iostream>
#include <string>
#include "HtmlEncode.h"

struct HTML
{
	std::string doubleQuote;
	std::string apostrophe;
	std::string signLess;
	std::string signMore;
	std::string ampersand;
};

const HTML entities =
{
	"&quot;",
	"&apos;",
	"&lt;",
	"&gt;",
	"&amp;"
};

const HTML decodeEntities =
{
	"\"",
	"\'",
	"<",
	">",
	"&"
};

int main()
{
	std::string str;
	
	/*while (getline(std::cin, str))
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '&')
			{
				flag = true;
			}
			if (!flag)
			{
				strResult.append(str, i, 1);
			}
			else
			{
				HTMLentities.append(str, i, 1);
			}
			if (str[i] == ';')
			{
				flag = false;
				if (HTMLentities == "&quot;")
				{
					strResult.append(decodeEntities.doubleQuote);
				}
				else if (HTMLentities == "&apos;")
				{
					strResult.append(decodeEntities.apostrophe);
				}
				else if (HTMLentities == "&lt;")
				{
					strResult.append(decodeEntities.signLess);
				}
				else if (HTMLentities == "&gt;")
				{
					strResult.append(decodeEntities.signMore);
				}
				else if (HTMLentities == "&amp;")
				{
					strResult.append(decodeEntities.ampersand);
				}
				HTMLentities.clear();
			}
		}
		strResult += '\n';
	}*/
	while (std::getline(std::cin, str))
	{
		std::cout << HtmlEncode(str) << "\n";
	}
}
