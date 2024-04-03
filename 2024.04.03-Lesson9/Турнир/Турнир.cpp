#include <iostream>

class CGraph {
public:
    void inputEdges(int a[101][101], int& n);
    bool isTournament(int a[101][101], int n);
};

void CGraph::inputEdges(int a[101][101], int& n)
{
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        a[s][e] += 1;
    }
}

bool CGraph::isTournament(int a[101][101], int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][i] == 1)
        {
            return false;
        }
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i][j] + a[j][i] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
  int a[101][101]{ 0 };
  int n = 0;

  CGraph graph;

  graph.inputEdges(a, n);

  std::cout << ((graph.isTournament(a, n)) ? "YES" : "NO") << std::endl;

  return 0;
}