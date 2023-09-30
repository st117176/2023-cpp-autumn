#include <iostream>

int main(int argc, char* argv[])
{
	int f1 = 0;
	int f2 = 1;
	int f3 = 0;
	int n = 0;

	std::cin >> n;

	for (int i = 1; i < n; i++)
	{
		f3 = f2;
		f2 = f1 + f2;
		f1 = f3;
	}
	std::cout << f2;

	return 0;
}