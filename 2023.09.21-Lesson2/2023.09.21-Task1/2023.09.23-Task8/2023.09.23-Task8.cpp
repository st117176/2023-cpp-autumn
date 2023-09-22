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

	if (a > b) {
		d = a;
		a = b;
		b = d;
	}
	if (b > c) {
		d = b;
		b = c;
		c = d;
	}
	if (a > b) {
		d = a;
		a = b;
		b = d;
	}
	std::cout << a << " " << b << " " << c;

	return 0;
}