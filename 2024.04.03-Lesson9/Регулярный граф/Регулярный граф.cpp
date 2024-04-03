#include <iostream>

class CGraph {
public:
	void inputMatrix(int a[101][101], int& n);
	bool isRegular(int a[101][101], int n);
};

void CGraph::inputMatrix(int a[101][101], int& n)
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> a[i][j];
		}
	}
}

bool CGraph::isRegular(int a[101][101], int n)
{
	int powers[101] = { 0 };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			powers[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (powers[i] != powers[1])
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph graph;

	graph.inputMatrix(a, n);
	std::cout << ((graph.isRegular(a, n)) ? "YES" : "NO") << std::endl;

	return 0;
}