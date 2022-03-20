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

const char doubleQuote = '\"';
const char apostrophe = '\'';
const char signLess = '<';
const char signMore = '>';
const char ampersand = '&';

std::string HtmlEncode(const std::string& text)
{
	std::string strResult;
	for (size_t i = 0; i < text.size(); i++)
	{
		switch (text[i])
		{
		case doubleQuote:
			strResult.append(entities.doubleQuote);
			break;
		case apostrophe:
			strResult.append(entities.apostrophe);
			break;
		case signLess:
			strResult.append(entities.signLess);
			break;
		case signMore:
			strResult.append(entities.signMore);
			break;
		case ampersand:
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
