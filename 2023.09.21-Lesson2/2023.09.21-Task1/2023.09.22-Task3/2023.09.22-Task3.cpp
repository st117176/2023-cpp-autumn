#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	if ((c = 0) and (d = 0)) {
		std::cout << "NO";
	}
	else if ((a == 0) and (b == 0)) {
		std::cout << "INF";
	}
	else if (a == 0) {
		std::cout << "NO";
	}
	else if ((b * c) == (a * d)) {
		std::cout << "NO";
	}
	else if (b % a == 0) {
		std::cout << (-b) / a;
	}
	else {
		std::cout << "NO";
	}
	return 0;
}