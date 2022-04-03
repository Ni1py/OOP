#include <iostream>
#include <string>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../HtmlDecodeProgram/HtmlDecode.h"

SCENARIO("Function HtmlDecode")
{
	WHEN("Enter an empty string")
	{
		THEN("The resulting string is also empty")
		{
			CHECK(HtmlDecode("") == "");
		}
	}

	WHEN("Enter the line: Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s")
	{
		std::string line = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";

		THEN("The resulting line: Cat <says> \"Meow\". M&M\'s")
		{
			std::string resultLine = "Cat <says> \"Meow\". M&M\'s";

			CHECK(HtmlDecode(line) == resultLine);
		}
	}

	WHEN("Enter the line: Cat <says> \"Meow\". M&M\'s")
	{
		std::string line = "Cat <says> \"Meow\". M&M\'s";

		THEN("The resulting line: Cat <says> \"Meow\". M&M\'s")
		{
			std::string resultLine = "Cat <says> \"Meow\". M&M\'s";

			CHECK(HtmlDecode(line) == resultLine);
		}
	}

	WHEN("Enter the line: &lt&amp;")
	{
		std::string line = "&lt&amp;";

		THEN("The resulting line: &lt&")
		{
			std::string resultLine = "&lt&";

			CHECK(HtmlDecode(line) == resultLine);
		}
	}
}

SCENARIO("Function HtmlDecodeLines")
{
	std::ostringstream output;

	WHEN("Enter the line: Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat <says> \"Meow\". M&M\'s\n")
	{
		std::istringstream input("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat <says> \"Meow\". M&M\'s\n");

		THEN("The resulting line: Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s\n")
		{
			std::string resultLine = "Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s\n";
			HtmlDecodeLines(input, output);

			CHECK(output.str() == resultLine);
			CHECK(input.eof());
		}
	}

	WHEN("Enter the empty line")
	{
		std::istringstream input("");

		THEN("The resulting line is also empty")
		{
			HtmlDecodeLines(input, output);

			CHECK(output.str() == "");
			CHECK(input.eof());
		}
	}

	/*WHEN("Enter the line: Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s")
	{
		std::istringstream input("Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s");

		THEN("The resulting line: Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s")
		{
			std::string resultLine = "Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s";
			HtmlDecodeLines(input, output);

			CHECK(output.str() == resultLine);
			CHECK(input.eof());
		}
	}*/
}