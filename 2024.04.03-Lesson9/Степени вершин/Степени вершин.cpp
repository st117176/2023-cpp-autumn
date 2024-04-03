#include <iostream>

class CGraph {
public:
	void outputPowers(int a[101][101], int n);
	void inputMatrix(int a[101][101], int& n);
};

void CGraph::outputPowers(int a[101][101], int n)
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
		std::cout << powers[i] << " ";
	}
}

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

int main(int argc, char* argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph graph;

	graph.inputMatrix(a, n);
	graph.outputPowers(a, n);

	return 0;
}