#include <iostream>
#include <algorithm>

using namespace std;

class CGraph {

public:

    void inputMatrix(int a[101][101], int& n);
    int shortestRoute(int a[101][101], int n);

private:

};
void CGraph::inputMatrix(int a[101][101], int& n)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
}

int CGraph::shortestRoute(int a[101][101], int n)
{
    int shortRoute = 3000;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if ((i != j) && (j != k) && (i != k))
                {
                    shortRoute = std::min(shortRoute, a[i][j] + a[j][k] + a[i][k]);
                }
            }
        }
    }
    return shortRoute;
}

int main(int argc, char* argv[])
{
    int a[101][101]{ 0 };
    int n = 0;

    CGraph graph;

    graph.inputMatrix(a, n);
    std::cout << graph.shortestRoute(a, n) << std::endl;

    return 0;
}