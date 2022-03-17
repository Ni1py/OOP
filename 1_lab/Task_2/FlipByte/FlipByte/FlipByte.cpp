#include <iostream>
#include <string>
#include <sstream>

const std::string err_count = "Invalid argument count!";
const std::string usage = "Usage: FlipByte.exe <unsigned int>";
const std::string err_value = "Invalid argument value!";
const std::string err_text = "You have entered the text! Enter a decimal integer!";
const std::string err_limit = "You have entered a number beyond 0-255!";

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
		std::cout << err_count << "\n"
			<< usage << "\n";
		return 1;
	}

	if (!std::strlen(argv[1]))
	{
		std::cout << err_value << "\n";
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
		std::cout << err_text << "\n";
		return 1;
	}

	if (!((bits >= 0) && (bits <= 255)))
	{
		std::cout << err_limit << "\n";
		return 1;
	}

	std::cout << FlipByte(bits) << "\n";

	return 0;
}
