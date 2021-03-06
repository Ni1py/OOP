#include <iostream>
#include <string>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

#include "../TheMiniDictionaryProgram/FillInTheDictionary.h"

SCENARIO("Function FillInTheDictionary")
{
	WHEN("Enter the empty line")
	{
		std::map<std::string, std::string> dictionary;
		bool save = true;
		std::string meaning = "cat";

		THEN("The word is skipped")
		{
			FillInTheDictionary("", meaning, dictionary, save);
			CHECK(!save);
		}
	}

	WHEN("Enter the word")
	{
		std::map<std::string, std::string> dictionary;
		bool save = true;
		std::string meaning = "cat";

		THEN("This word will be added to as a key with translation into the dictionary")
		{
			std::map<std::string, std::string> _dictionary;
			_dictionary["cat"] = "кошка";
			FillInTheDictionary("кошка", meaning, dictionary, save);
			CHECK(dictionary == _dictionary);
			CHECK(!save);
		}
	}

	WHEN("Enter the word")
	{
		std::map<std::string, std::string> dictionary;
		bool save = true;
		std::string meaning = "CaT";

		THEN("This word will be added to as a lowercase key with translation into the dictionary")
		{
			std::map<std::string, std::string> _dictionary;
			_dictionary["cat"] = "кошка";
			FillInTheDictionary("кошка", meaning, dictionary, save);
			CHECK(dictionary == _dictionary);
			CHECK(!save);
		}
	}
}
