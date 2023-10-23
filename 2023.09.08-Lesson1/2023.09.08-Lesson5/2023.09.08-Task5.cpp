#include <iostream>

int main(int argc, char* argv[])
{
	int s = 0;
	int t = 0;
	int b = 0;
	std::cin >> v;
	std::cin >> t;

	s = v * t;
	std::cout << ((s % 109) + 109) % 109 + 1;

	return 0;
}