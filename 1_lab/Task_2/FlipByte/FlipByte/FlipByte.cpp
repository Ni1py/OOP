#include <iostream>

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

int main()
{
	std::cout << "This program changes the order of binary bits to the opposite in an 8-bit decimal integer!\n" << std::endl;
	std::cout << "Enter an 8-bit decimal integer: ";
	unsigned int bits = 0;
	std::cin >> bits;

	if (!std::cin)
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

	return FlipByte(bits);
}
