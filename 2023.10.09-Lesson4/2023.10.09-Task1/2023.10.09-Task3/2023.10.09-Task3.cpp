#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* c = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(c + i);
		if (i % 2 != 0)
		{
			std::cout << *(c + i) << " ";
		}
	}
	free(c);

	return 0;
}