#include<iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;

	uint n = 1180960184;

	{
		int sumbits = 0;
		for (int i = 0; i < BITS; ++i)
		{
			sumbits += (n >> i) & 1;
		}
		std::cout << sumbits << std::endl;
	}

	{
		std::cout << "0b ";
		for (int i = BITS - 1; i >= 0; --i)
		{
			std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
		std::cout << std::endl;

		if (n == 0)
		{
			n = ~n;
		}
		else
		{
			int start = BITS - 1;
			int end = 0;
			while ((n >> start & 1) == 0)
			{
				start--;
			}
			while ((n >> end & 1) == 0)
			{
				end++;
			}

			start--; //start = 29
			end++;   //end   = 4
			uint mask = 0;
			mask = ~mask;
			mask = (mask >> (start - end + 1));
			mask = ~mask;
			mask = (mask >> (BITS - start - 1));
			n = n ^ mask;

			{
				std::cout << "0b ";
				for (int i = BITS - 1; i >= 0; --i)
				{
					std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
				}
				std::cout << std::endl;
			}
		}
	}

	{
		uint a = 4561;
		uint b = 8946;
		uint c = 0;

		bool up = 0;
		for (int i = 0; i < BITS; ++i)
		{
			bool bitA = ((a >> i) & 1);
			bool bitB = ((b >> i) & 1);
			bool current = bitA ^ bitB ^ up;

			up = (bitA & bitB) | (bitA & up) | (bitB & up);
			c = c | ((int)current << i);
		}
		std::cout << a << " + " << b << " = " << c << std::endl;
	}

	return 0;
}