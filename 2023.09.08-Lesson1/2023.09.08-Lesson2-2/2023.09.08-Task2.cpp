#include<iostream>

int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	std::cout << ((1 + abs(n))*abs(n)) / 2;
	return 0;
}