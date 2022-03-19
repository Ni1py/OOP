#include "HtmlEncode.h"
#include <iostream>

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

std::string HtmlEncode(const std::string& text)
{
	std::string strResult;
	for (size_t i = 0; i < text.size(); i++)
	{
		switch (text[i])
		{
		case '\"':
			strResult.append(entities.doubleQuote);
			break;
		case '\'':
			strResult.append(entities.apostrophe);
			break;
		case '<':
			strResult.append(entities.signLess);
			break;
		case '>':
			strResult.append(entities.signMore);
			break;
		case '&':
			strResult.append(entities.ampersand);
			break;
		default:
			strResult.append(text, i, 1);
		}
	}
	return strResult;
}

void HtmlEncodeLines(std::istream& input, std::ostream& output)
{
	std::string str;
	while (std::getline(input, str))
	{
		output << HtmlEncode(str) << "\n";
	}
}
