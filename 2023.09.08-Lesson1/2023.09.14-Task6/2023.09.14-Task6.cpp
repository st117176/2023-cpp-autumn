﻿#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;

	std::cout << ((a + b + abs(a - b)) / 2);

    return 0;
}