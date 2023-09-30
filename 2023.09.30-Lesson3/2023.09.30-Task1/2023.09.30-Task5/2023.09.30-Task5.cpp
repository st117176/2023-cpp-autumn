#include<iostream>
int main(int argc, char* argv[])
{
	int i = 1;
	int n = 0;
	int a = 0;

	std::cin >> n;

	while (i <= n) {
		int b = i;
		int c = 0;
		while (b) {
			c = c * 10 + b % 10;
			b = b / 10;
		}
		if (i == c) {
			a += 1;
		}

		i += 1;
	}

    std::cout << a;

	return 0;
}
