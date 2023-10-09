#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int* c = (int*)malloc(sizeof(int) * n);
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(c + i);
		if (*(c + i) <= 0)
		{
			//
		}
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(c + i) << " ";
	}
	free(c);

	return 0;
}