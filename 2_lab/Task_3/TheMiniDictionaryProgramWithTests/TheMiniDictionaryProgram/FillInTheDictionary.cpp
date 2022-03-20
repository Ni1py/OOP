#include "FillInTheDictionary.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>

const std::string word = "Слово \"";
const std::string ignored = "\" проигнорировано.\n";

void FillInTheDictionary(const std::string& key, std::string& meaning, std::map<std::string, std::string>& dictionary, bool& save)
{
    /*setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);*/

    if (!key.empty())
    {
        std::transform(meaning.begin(), meaning.end(), meaning.begin(), tolower);
        dictionary[meaning] = key;
        save = false;
    }
    else
    {
        std::cout << word << meaning << ignored;
        save = false;
    }
}