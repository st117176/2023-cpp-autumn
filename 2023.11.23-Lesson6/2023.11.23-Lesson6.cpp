#include<iostream>

void hanoi(int n, int from, int to);
void repairHanoi(int n, int from, int to);
void cyclicHanoi(int n, int from, int to);
void unfairHanoi(int n, int from, int to);
void sortedHanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	// Simple Hanoi
	hanoi(n, 1, 3);
	std::cout << std::endl;

	// Repair in hanoi
	repairHanoi(n, 1, 3);
	std::cout << std::endl;

	// Cyclic Hanoi
	cyclicHanoi(n, 1, 3);
	std::cout << std::endl;

	// Unfair Hanoi
	unfairHanoi(n, 1, 3);
	std::cout << std::endl;

	return 0;
}

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - from - to;
	hanoi(n - 1, from, res);
	printf("%d %d %d\n", n, from, to);
	hanoi(n - 1, res, to);
}

void repairHanoi(int n, int from, int to)
{
	int res = 6 - from - to;
	if (n > 0)
	{
		if (from + to == 4)
		{
			repairHanoi(n, from, 2);
			repairHanoi(n, 2, to);
		}
		else
		{
			repairHanoi(n - 1, from, res);
			printf("%d %d %d\n", n, from, to);
			repairHanoi(n - 1, res, to);
		}
	}
}

void cyclicHanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int res = 6 - from - to;
		if (from == to - 1 || (from == 3 && to == 1))
		{
			cyclicHanoi(n - 1, from, res);
			printf("%d %d %d\n", n, from, to);
			cyclicHanoi(n - 1, res, to);
		}
		else
		{
			cyclicHanoi(n - 1, from, to);
			printf("%d %d %d\n", n, from, res);
			cyclicHanoi(n - 1, to, from);
			printf("%d %d %d\n", n, res, to);
			cyclicHanoi(n - 1, from, to);
		}
	}
}

void unfairHanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int tmp = 6 - from - to;
		if (n == 1)
		{
			printf("%d %d %d\n", n, from, to);
		}
		else
		{
			unfairHanoi(n - 1, from, to);
			printf("%d %d %d\n", n, from, tmp);
			unfairHanoi(n - 1, to, from);
			printf("%d %d %d\n", n, tmp, to);
			unfairHanoi(n - 1, from, to);
		}
	}
}