#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	int b = 0;
	std::cin >> a;

	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
		{
			b++;
		}
	}
	std::cout << b;

	return 0;
}