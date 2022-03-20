#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>

#include "FillInTheDictionary.h"

const std::string err_open1 = "File '";
const std::string err_open2 = "' does not exist!\n";
const std::string err_count = "Lots of arguments!\n";
const std::string usage = "Usage: TheMiniDictionaryProgram.exe <input.txt>\n";
const std::string new_dictionary = "dictionary.txt";
const std::string changes = "В словарь были внесены изменения.";
const std::string save_file = " Введите Y или y для сохранения перед выходом.\n";
const std::string unknown_word = "Неизвестное слово \"";
const std::string rejection = "\". Введите перевод или пустую строку для отказа.\n";

int ReadFile(int argc, char* argv[], std::map<std::string, std::string>& dictionary)
{
    if (argc == 2)
    {
        std::ifstream dictionaryFile;
        dictionaryFile.open(argv[1]);
        if (!dictionaryFile.is_open())
        {
            std::cout << err_open1 << argv[1] << err_open2;
            return 1;
        }

        std::string key;
        std::string meaning;
        while (std::getline(dictionaryFile, key))
        {
            if (!dictionaryFile.eof())
            {
                std::getline(dictionaryFile, meaning);
            }
            dictionary[key] = meaning;
        }
        dictionaryFile.close();
        return 0;
    }
    else if (argc > 2)
    {
        std::cout << err_count << usage;
        return 1;
    }
    else if (argc < 2)
    {
        return 2;
    }
}

void SaveFile(char* argv[], int read, std::map<std::string, std::string>& dictionary, std::string& key, bool& yes)
{
    std::transform(key.begin(), key.end(), key.begin(), tolower);
    if (key == "y")
    {
        if (read == 0)
        {
            std::ofstream dictionaryFile;
            dictionaryFile.open(argv[1]);
            for (auto dict : dictionary)
            {
                dictionaryFile << dict.first << "\n"
                    << dict.second << "\n";
            }
        }
        else
        {
            std::ofstream dictionaryFile;
            dictionaryFile.open(new_dictionary);
            for (auto dict : dictionary)
            {
                dictionaryFile << dict.first << "\n"
                    << dict.second << "\n";
            }
        }
    }
    yes = true;
}

void Translate(char* argv[], int read, std::map<std::string, std::string>& dictionary)
{
    std::string key;
    std::string meaning;
    bool yes = false;
    bool save = false;
    bool end = false;

    while (!yes)
    {
        getline(std::cin, key);

        if (save)
        {
            FillInTheDictionary(key, meaning, dictionary, save);
            continue;
        }

        if (key == "...")
        {
            std::cout << changes << save_file;
            end = true;
            continue;
        }

        if (end)
        {
            SaveFile(argv, read, dictionary, key, yes);
            continue;
        }

        std::transform(key.begin(), key.end(), key.begin(), tolower);
        if (dictionary.find(key) != dictionary.end())
        {
            std::cout << dictionary[key] << "\n";
        }
        else
        {
            std::cout << unknown_word << key << rejection;
            save = true;
            meaning = key;
        }
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::map<std::string, std::string> dictionary;

    int read = ReadFile(argc, argv, dictionary);

    if (read == 1)
    {
        return 1;
    }

    Translate(argv, read, dictionary);

    return 0;
}
