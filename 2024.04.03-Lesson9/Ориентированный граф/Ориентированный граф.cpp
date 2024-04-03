#include <iostream>

class CGraph {
public:
	void inputMatrix(int a[101][101], int& n);
	bool isOriented(int a[101][101], int n);
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

bool CGraph::isOriented(int a[101][101], int n)
{
	bool result = false;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][i] == 1)
		{
			return false;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] != a[j][i])
			{
				result = true;
			}
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph graph;

	graph.inputMatrix(a, n);
	std::cout << ((graph.isOriented(a, n)) ? "YES" : "NO") << std::endl;

	return 0;
}