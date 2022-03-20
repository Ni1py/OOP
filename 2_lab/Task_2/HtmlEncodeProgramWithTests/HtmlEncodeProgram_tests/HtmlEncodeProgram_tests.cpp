#include <iostream>
#include <string>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../HtmlEncodeProgram/HtmlEncode.h"

SCENARIO("Function HtmlEncode")
{
	WHEN("Enter an empty string")
	{
		THEN("The resulting string is also empty")
		{
			CHECK(HtmlEncode("") == "");
		}
	}

	WHEN("Enter the line: Cat <says> \"Meow\". M&M\'s")
	{
		std::string line = "Cat <says> \"Meow\". M&M\'s";

		THEN("The resulting line: Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s")
		{
			std::string resultLine = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";

			CHECK(HtmlEncode(line) == resultLine);
		}
	}
}

SCENARIO("Function HtmlEncodeLines")
{
	std::ostringstream output;

	WHEN("Enter the line: Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s\n")
	{
		std::istringstream input("Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s\n");

		THEN("The resulting line: Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\n")
		{
			std::string resultLine = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\n";
			HtmlEncodeLines(input, output);

			CHECK(output.str() == resultLine);
			CHECK(input.eof());
		}
	}

	WHEN("Enter the empty line")
	{
		std::istringstream input("");

		THEN("The resulting line is also empty")
		{
			HtmlEncodeLines(input, output);

			CHECK(output.str() == "");
			CHECK(input.eof());
		}
	}

	/*WHEN("Enter the line: Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s")
	{
		std::istringstream input("Cat <says> \"Meow\". M&M\'s\nCat <says> \"Meow\". M&M\'s");

		THEN("The resulting line: Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s")
		{
			std::string resultLine = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\nCat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
			HtmlEncodeLines(input, output);

			CHECK(output.str() == resultLine);
			CHECK(input.eof());
		}
	}*/
}