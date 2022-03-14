#include <iostream>
#include <string>
#include <sstream>

unsigned int FlipByte(unsigned int bit)
{
	unsigned int bits_flip = 0;
	for (int i = 0; i < 8; i++)
	{
		if (bit & (1 << i))
		{
			bits_flip |= (1 << 7 - i);
		}
	}
	return bits_flip;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count!\n";
		return 1;
	}

	if (!std::strlen(argv[1]))
	{
		std::cout << "Invalid argument value!\n";
		return 1;
	}

	unsigned int bits = 0;
	std::string str;
	str = argv[1];

	std::stringstream ss;
	ss << str;
	ss >> bits;
	if (ss.fail())
	{
		std::cout << "You have entered the text! Enter a decimal integer!\n";
		return 1;
	}

	if (!((bits >= 0) && (bits <= 255)))
	{
		std::cout << "You have entered a number beyond 0-255!\n";
		return 1;
	}

	std::cout << FlipByte(bits) << "\n";

	return 0;
}
