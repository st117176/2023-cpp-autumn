#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* c = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(c + i);
	}
	for (int j = n - 1; j >= 0; j--)
	{
		std::cout << *(c + j) << " ";
	}
	free(c);

	return 0;
}