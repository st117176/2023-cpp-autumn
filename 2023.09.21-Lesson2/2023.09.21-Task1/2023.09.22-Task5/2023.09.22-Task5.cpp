#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	if ((n % 10 > 1) and (n % 10 < 5) and ((n / 10 % 10) != 1)){
		std::cout << n << " bochki";
	}
	else if (((n / 10 % 10) != 1) and (n % 10 == 1)) {
		std::cout << n << " bochka";
	}
	else {
		std::cout << n << " bochek";
	}
	return 0;
}