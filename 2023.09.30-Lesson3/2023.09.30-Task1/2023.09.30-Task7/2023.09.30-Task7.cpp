﻿#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 1;
	int a = 0;
	std::cin >> n;

	while (k < n) 
	{
		k = k * 2;
		a = a + 1;
	}
    std::cout << a;

	return 0;
}