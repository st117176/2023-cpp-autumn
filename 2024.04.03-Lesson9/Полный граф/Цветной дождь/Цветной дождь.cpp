#include <iostream>

class CGraph {
public:
    void inputMatrix(int a[101][101], int& n);
    int checkBridges(int a[101][101], int n);
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

int CGraph::checkBridges(int a[101][101], int n)
{
    int colors[101] = { 0 };
    int wrongBridges = 0;
    for (int i = 1; i <= n; ++i)
    {
        int color = 0;
        std::cin >> color;
        colors[i] = color;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((a[i][j] == 1) && (colors[i] != colors[j]))
            {
                wrongBridges++;
            }
        }
    }
    return wrongBridges / 2;
}

int main(int argc, char* argv[])
{
    int a[101][101]{ 0 };
    int n = 0;

    CGraph graph;

    graph.inputMatrix(a, n);
    std::cout << graph.checkBridges(a, n) << std::endl;

    return 0;
}