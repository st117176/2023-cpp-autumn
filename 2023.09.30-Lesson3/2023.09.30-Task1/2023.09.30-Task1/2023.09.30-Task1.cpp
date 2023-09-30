#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	int b = 1;
	std::cin >> a;

	for (int i = 1; b <= a; i++) {
		for (int j = 1; j <= i and b <= a; j++) {
			std::cout << i << " ";
			b++;
		}
	}
	return 0;
}