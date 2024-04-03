#include <iostream>

class CGraph {
public:
    int getEdgesCountFromMatrix(int a[101][101], int& n);
    void inputMatrix(int a[101][101], int& n);
    void outputEdges(int a[101][101], int n);
};

int CGraph::getEdgesCountFromMatrix(int a[101][101], int& n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            count += (a[i][j] != 0);
        }
    }
    return count;
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

void CGraph::outputEdges(int a[101][101], int n)
{
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            m += a[i][j];
        }
    }
    std::cout << n << " " << m << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 1)
            {
                std::cout << i << " " << j << std::endl;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int a[101][101]{ 0 };
    int n = 0;

    CGraph graph;

    graph.inputMatrix(a, n);
    graph.outputEdges(a, n);

    return 0;
}