#include<iostream>

class CGraph {

public:

    void inputEdges(int a[101][101]);
    void traffic_lights(int a[101][101], int n);

private:

};

int main(int argc, char* argv[])
{
    int a[101][101]{ 0 };
    int n = 0;

    CGraph Graph;

    Graph.inputEdges(a);
    Graph.traffic_lights(a, n);

    return 0;
}

void CGraph::traffic_lights(int a[101][101], int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            count += a[i][j];
        }
        std::cout << count << " ";
        count = 0;
    }
}

void CGraph::inputEdges(int a[101][101])
{
    int n = 0;
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        a[s][e] += 1;
        a[e][s] += 1;
    }

    traffic_lights(a, n);
}