
#include <iostream>

int main()
{
	int v;
	int t;
	int a;
	int b;
	std::cin >> v;
	std::cin >> t;

	std::cout << ((v * t % 109) + 109) % 109 + 1;
	return 0;
}

