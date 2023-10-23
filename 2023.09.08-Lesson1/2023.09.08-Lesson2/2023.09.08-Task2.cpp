#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;

	std::cin >> n;
	std::cout << ((1 + abs(n))*abs(n)) / 2;

	return 0;
}