#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "HtmlDecode.h"

std::map <std::string, std::string> htmlDecode = 
{ 
	{"&quot;", "\""},
	{"&apos;", "\'"},
	{"&lt;", "<"},
	{"&gt;", ">"},
	{"&amp;", "&"}
};

struct htmlInStr
{
	size_t pos;
	std::string html;
};

bool compare(htmlInStr a, htmlInStr b)
{
	return a.pos < b.pos;
}

std::string HtmlDecode(const std::string& html)
{
	std::string strResult = "";
	std::string searchString = "";
	bool flag = false;
	std::vector<htmlInStr> allHtml = {};

	size_t pos = 0;
	while (true)
	{ 
		size_t foundPos = 0;
		for (const auto& code : htmlDecode) 
		{
			foundPos = html.find(code.first, pos);
			if (foundPos != std::string::npos)
			{
				htmlInStr object;
				object.pos = foundPos;
				object.html = code.first;
				allHtml.push_back(object);
			}
		}

		if (!allHtml.empty())
		{
			std::sort(allHtml.begin(), allHtml.end(), compare);
			auto searchString = allHtml[0];
			strResult.append(html, pos, searchString.pos - pos);
			strResult.append(htmlDecode[searchString.html]);
			pos = searchString.pos + searchString.html.length();
			allHtml.clear();
		}
		else
		{
			strResult.append(html, pos, html.length() - pos);
			break;
		}
	}

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
