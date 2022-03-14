#include <iostream>
#include <fstream>
#include <string>
#include <optional>

std::string ReplaceString(const std::string& subject, const std::string& searchString, const std::string& replacementString)
{
	std::string result = searchString.empty() ? subject : "";

	size_t pos = 0;
	if (!searchString.empty())
	{
		while (true)
		{
			size_t foundPos = subject.find(searchString, pos);
			if (foundPos != std::string::npos)
			{
				result.append(subject, pos, foundPos - pos);
				result.append(replacementString);
				pos = foundPos + searchString.length();
			}
			else
			{
				result.append(subject, pos, subject.length() - pos);
				break;
			}
		}
	}

	return result;
}

void CopyStreamWithReplacement(std::istream& input, std::ostream& output, const std::string& searchString,
	const std::string& replacementString)
{
	std::string line;

	while (getline(input, line))
	{
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
	output.flush();
}

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string search;
	std::string replace;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.search = argv[3];
	args.replace = argv[4];
	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(args->inputFileName);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open '" << args->inputFileName << "' for reading!\n";
		return 1;
	}

	std::ofstream outputFile;
	outputFile.open(args->outputFileName);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open '" << args->outputFileName << "' for writing!\n";
		return 1;
	}

	std::string search = args->search;
	std::string replace = args->replace;

	CopyStreamWithReplacement(inputFile, outputFile, search, replace);

	if (inputFile.bad())
	{
		std::cout << "Failed to read data from input file\n";
		return 1;
	}

	if (!outputFile.flush())
	{
		std::cout << "Failed to write data to output file\n";
		return 1;
	}

	return 0;
}
