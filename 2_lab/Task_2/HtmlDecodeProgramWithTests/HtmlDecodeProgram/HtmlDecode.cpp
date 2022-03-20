#include <iostream>
#include "HtmlDecode.h"

struct HTML
{
	std::string doubleQuote;
	std::string apostrophe;
	std::string signLess;
	std::string signMore;
	std::string ampersand;
};

const HTML decodeEntities =
{
	"\"",
	"\'",
	"<",
	">",
	"&"
};

const char ampersand = '&';
const char semicolon = ';';
const std::string doubleQuote = "&quot;";
const std::string apostrophe = "&apos;";
const std::string signLess = "&lt;";
const std::string signMore = "&gt;";
const std::string ampersandHtml = "&amp;";

std::string HtmlDecode(const std::string& html)
{
	std::string htmlEntities;
	std::string strResult;
	bool flag = false;

	for (size_t i = 0; i < html.size(); i++)
	{
		if (html[i] == ampersand)
		{
			flag = true;
		}
		if (!flag)
		{
			strResult.append(html, i, 1);
		}
		else
		{
			htmlEntities.append(html, i, 1);
		}
		if (html[i] == semicolon)
		{
			flag = false;
			if (htmlEntities == doubleQuote)
			{
				strResult.append(decodeEntities.doubleQuote);
			}
			else if (htmlEntities == apostrophe)
			{
				strResult.append(decodeEntities.apostrophe);
			}
			else if (htmlEntities == signLess)
			{
				strResult.append(decodeEntities.signLess);
			}
			else if (htmlEntities == signMore)
			{
				strResult.append(decodeEntities.signMore);
			}
			else if (htmlEntities == ampersandHtml)
			{
				strResult.append(decodeEntities.ampersand);
			}
			else
			{
				strResult.append(htmlEntities);
			}
			htmlEntities.clear();
		}
	}
	strResult.append(htmlEntities);

	return strResult;
}

void HtmlDecodeLines(std::istream& input, std::ostream& output)
{
	std::string str;

	while (std::getline(input, str))
	{
		output << HtmlDecode(str) << "\n";
	}
}
