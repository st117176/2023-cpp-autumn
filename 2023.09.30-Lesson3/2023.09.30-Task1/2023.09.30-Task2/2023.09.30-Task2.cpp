#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	std::cin >> a;
	while (a > 0) {
		if (a % 10 != 0) {
			std::cout << a % 10;
			a = a / 10;
		}
		else {
			a = a / 10;
		}
	}
	return 0;
}