#include <iostream>

class CGraph {
public:
    void inputMatrix(int a[101][101], int& n);
};

void CGraph::inputMatrix(int a[101][101], int& n)
{
    int count = 0;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> a[i][j];
            count += a[i][j];
        }
    }
    std::cout << count/2 << std::endl;
}
    
int main(int argc, char* argv[])
{
    int a[101][101]{ 0 };
	int n = 0;
    int count = 0;

    CGraph graph;

    graph.inputMatrix(a, n);

    return 0;
}