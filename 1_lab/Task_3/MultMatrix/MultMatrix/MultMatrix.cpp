#include <iostream>
#include <stdio.h>
#include <optional>

void ReadMatrix(FILE* input, float Matrix3x3[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fscanf_s(input, "%f", &Matrix3x3[i][j]);
		}
	}
}

void MultiplyMatrix(float FirstMatrix3x3[3][3], float SecondMatrix3x3[3][3], float ResultMatrix3x3[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				ResultMatrix3x3[i][j] += FirstMatrix3x3[i][k] * SecondMatrix3x3[k][j];
			}
		}
	}
}

struct Args
{
	char* matrix_file1;
	char* matrix_file2;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: multmatrix.exe <matrix_file1> <matrix_file2>\n";
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

	FILE* matrix_file1, * matrix_file2;

	errno_t err;
	errno_t err1;

	err = fopen_s(&matrix_file1, args->matrix_file1, "r");
	if (err)
	{
		std::cout << "File " << args->matrix_file1 << " was not opened!";
		return 1;
	}

	err1 = fopen_s(&matrix_file2, args->matrix_file2, "r");
	if (err1)
	{
		std::cout << "File " << args->matrix_file2 << " was not opened!";
		return 1;
	}

	float FirstMatrix3x3[3][3] = {};
	ReadMatrix(matrix_file1, FirstMatrix3x3);

	float SecondMatrix3x3[3][3] = {};
	ReadMatrix(matrix_file2, SecondMatrix3x3);

	float ResultMatrix3x3[3][3] = {};
	MultiplyMatrix(FirstMatrix3x3, SecondMatrix3x3, ResultMatrix3x3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j != 2)
			{
				std::cout << ResultMatrix3x3[i][j] << " ";
			}
			else
			{
				std::cout << ResultMatrix3x3[i][j] << std::endl;
			}
		}
	}

	return 0;
}
