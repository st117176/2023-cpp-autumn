#include <iostream>

int main(int argc, char* argv[])
{
	int n = 5;

	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << j + 1; // Задание а
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << i + 1; // Задание б
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << (i + j) % n + 1; // Задание в
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << 2 * n - 1 - (i + j); // Задание г
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << std::max(std::min(i + 1, n - i), std::min(j + 1, n - j)); // Задание д
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << (i + 1) % 2 * (j + 1) + i % 2 * (n - j); // Задание е
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}