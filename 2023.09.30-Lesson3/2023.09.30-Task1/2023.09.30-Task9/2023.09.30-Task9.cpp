﻿#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;

	std::cin >> a;
	std::cin >> b;

	while (a != b)
	{
		if ((a % 2 == 0) and (a / 2) >= b)
		{
			a = a / 2;
			std::cout << ":2\n";
		}

		else
		{
			a--;
			std::cout << "-1\n";
		}
	}

	return 0;
}