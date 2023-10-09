#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* c = (int*)malloc(sizeof(int) * n);
	int a = 0; // max element
	int b = 0; // min element

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(c + i);
		a = *(c);
		b = *(c);
		for (int j = 0; j < n; ++j)
		{
			if (*(c + j) > a)
			{
				a = *(c + j);
			}
			if (*(c + j) < b)
			{
				b = *(c + j);
			}
		}

	int d = 0;
	d = a;

	for (int k = 0; k < n; ++k)
	{
		if (*(c + k) == a)
		{
			*(c + k) = b;
		}
	}

	for (int k = 0; k < n; ++k)
	{
		if (*(c + k) == b)
		{
			*(c + k) = d;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(c + i) << " ";
	}
	free(c);

	return 0;
}