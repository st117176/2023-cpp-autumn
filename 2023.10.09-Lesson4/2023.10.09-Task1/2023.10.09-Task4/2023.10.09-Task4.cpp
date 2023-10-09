#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* c = (int*)malloc(sizeof(int) * n);
	int maxel = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(c + i);
		maxel = *(c);

		for (int j = 0; j < n; ++j)
		{
			if (*(c + i) > maxel)
			{
				maxel = *(c + i);
			}
		}
	}
	std::cout << maxel;
	free(c);

	return 0;
}