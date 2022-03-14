#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <optional>
#include <cmath>
#include <iomanip>

const int bit_depth = 3;
const std::string err_argument = "Invalid argument!";
const std::string err_count = "Invalid argument count!";
const std::string usage = "Usage: multmatrix.exe <matrix_file1> <matrix_file2>";
const std::string err_text_part1 = "Please enter: ";
const std::string err_text_part2 = "<float> <float> <float>";
const std::string err_open = "Failed to open '";
const std::string err_reading = "' for reading!";
const std::string err_read_data = "Failed to read data from input file!";

int ReadMatrix(std::istream& input, float Matrix3x3[3][3])
{
	std::string str;
	std::stringstream ss;
	size_t i = 0;
	size_t j = 0;

	while (getline(input, str))
	{
		ss.clear();
		ss.str(str);
		while (!ss.eof())
		{
			ss >> Matrix3x3[i][j];
			if (ss.fail())
			{
				std::cout << err_argument << "\n";
				std::cout << err_text_part1  << err_text_part2  << "\n";
				std::cout << "              " << err_text_part2 << "\n";
				std::cout << "              " << err_text_part2 << "\n";
				return 1;
			}
			++j;
		}
		j = 0;
		++i;
	}

	return 0;
}

void MultiplyMatrix(float FirstMatrix3x3[bit_depth][bit_depth], float SecondMatrix3x3[bit_depth][bit_depth], float ResultMatrix3x3[bit_depth][bit_depth])
{
	for (int i = 0; i < bit_depth; i++)
	{
		for (int j = 0; j < bit_depth; j++)
		{
			for (int k = 0; k < bit_depth; k++)
			{
				ResultMatrix3x3[i][j] += round(FirstMatrix3x3[i][k] * 1000) / 1000 * round(SecondMatrix3x3[k][j] * 1000) / 1000;
			}
		}
	}
}

struct Args
{
	std::string matrix_file1;
	std::string matrix_file2;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != bit_depth)
	{
		std::cout << err_count  << "\n"
			<< usage << "\n";
		return std::nullopt;
	}
	Args args;
	args.matrix_file1 = argv[1];
	args.matrix_file2 = argv[2];
	return args;
}

int main(int argc, char* argv[])
{

	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	std::ifstream matrix_file1;
	matrix_file1.open(args->matrix_file1);
	if (!matrix_file1.is_open())
	{
		std::cout << err_open << args->matrix_file1 << err_reading  << "\n";
		return 1;
	}

	std::ifstream matrix_file2;
	matrix_file2.open(args->matrix_file2);
	if (!matrix_file2.is_open())
	{
		std::cout << err_open << args->matrix_file2 << err_reading  << "\n";
		return 1;
	}

	float FirstMatrix3x3[bit_depth][bit_depth] = {};
	if (ReadMatrix(matrix_file1, FirstMatrix3x3))
		return 1;

	float SecondMatrix3x3[bit_depth][bit_depth] = {};
	if (ReadMatrix(matrix_file2, SecondMatrix3x3))
		return 1;

	if (matrix_file1.bad() || matrix_file2.bad())
	{
		std::cout << err_read_data  << "\n";
		return 1;
	}

	float ResultMatrix3x3[bit_depth][bit_depth] = {};
	MultiplyMatrix(FirstMatrix3x3, SecondMatrix3x3, ResultMatrix3x3);

	for (int i = 0; i < bit_depth; i++)
	{
		for (int j = 0; j < bit_depth; j++)
		{
			if (j != bit_depth - 1)
			{
				std::cout << std::fixed << std::setprecision(3) << ResultMatrix3x3[i][j] << " ";
			}
			else
			{
				std::cout << std::fixed << std::setprecision(3) << ResultMatrix3x3[i][j] << "\n";
			}
		}
	}

	return 0;
}
