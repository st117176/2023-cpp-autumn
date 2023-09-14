
#include <iostream>

int main()
{
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	std::cout << ((a + b + abs(a - b)) / 2);
    return 0;
}
