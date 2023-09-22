#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int n1 = 0;
	int n5 = 0;
	int n10 = 0;
	int n20 = 0;
	int n60 = 0;

	std::cin >> n;

	n60 = n / 60;
	n = n % 60;
	n20 = n / 20;
	n = n % 20;
	n10 = n / 10;
	n = n % 10;
	n5 = n / 5;
	n1 = n % 5; 
	if (n1 and n1 * 15 >= 70) {
		n5 += 1;
		n1 = 0;
	}
	else if (n5 * 70 + n1 * 15 >= 125){
		n10 += 1;
		n5 = 0;
		n1 = 0;
	}
	else if (n10 * 125 + n5 * 70 + n1 * 15 >= 230) {
		n20 += 1;
		n10 = 0;
		n5 = 0;
		n1 = 0;
	}
	else if (n20 * 230 + n10 * 125 + n5 * 70 + n1 * 15 >= 440) {
		n60 += 1;
		n20 = 0;
		n10 = 0;
		n5 = 0;
		n1 = 0;
	}
	std::cout << n1 << " " << n5 << " " << n10 << " " << n20 << " " << n60;

	return 0;
}