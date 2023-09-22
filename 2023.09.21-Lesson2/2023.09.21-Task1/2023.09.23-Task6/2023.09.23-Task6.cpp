#include <iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	int time = 0;

	std::cin >> k;
	std::cin >> m;
	std::cin >> n;

	if (n <= k){
		time = m * 2;
	}
	else if (n * 2 % k == 0) {
		time = m * (n * 2 / k);
	}
	else {
		time = m * (1 + (n * 2 / k));
	}
	std::cout << time;
	return 0;
}