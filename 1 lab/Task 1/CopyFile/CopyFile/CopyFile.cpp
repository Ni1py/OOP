#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "CopyFile.h"
using namespace std;

struct Args
{
	string inputFileName;
	string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count!\n";
		cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

void CopyStreams(ifstream & input, ofstream & output)
{
	//копируем содержимое входного файла в выходной 
	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	//проверка правильности аргументов командной строки
	if (!args)
	{
		return 1;
	}

	//открываем входной файл
	ifstream input;
	input.open(args->inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open '" << args->inputFileName << "' for reading!\n";
		return 1;
	}

	//открываем выходной файл
	ofstream output;
	output.open(args->outputFileName);
	if (!output.is_open())
	{
		cout << "Failed to open '" << args->outputFileName << "' for writing!\n";
		return 1;
	}

	CopyStreams(input, output);

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return 1;
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return 1;
	}

	return 0;
}
