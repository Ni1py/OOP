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
	std::string HTMLentities;
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
			HTMLentities.append(html, i, 1);
		}
		if (html[i] == semicolon)
		{
			flag = false;
			if (HTMLentities == doubleQuote)
			{
				strResult.append(decodeEntities.doubleQuote);
			}
			else if (HTMLentities == apostrophe)
			{
				strResult.append(decodeEntities.apostrophe);
			}
			else if (HTMLentities == signLess)
			{
				strResult.append(decodeEntities.signLess);
			}
			else if (HTMLentities == signMore)
			{
				strResult.append(decodeEntities.signMore);
			}
			else if (HTMLentities == ampersandHtml)
			{
				strResult.append(decodeEntities.ampersand);
			}
			HTMLentities.clear();
		}
	}
	return strResult;
}
