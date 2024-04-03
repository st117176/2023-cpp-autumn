#include <iostream>

using namespace std;

class CGraph {
public:
    void evolution(int& n, long long int& first, long long int& second);
};

void CGraph::evolution(int& n, long long int& first, long long int& second) {
    cin >> n;
    cin >> first;
    cin >> second;
    while (first != second)
    {
        if (first > second)
        {
            first = first >> 1;
        }
        else
        {
            second = second >> 1;
        }
    }
    cout << first << endl;
}

int main(int argc, char* argv[])
{
    int n = 0;
    long long int first = 0;
    long long int second = 0;

    CGraph graph;

    graph.evolution(n, first, second);
    return 0;
}