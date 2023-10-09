// задача без юнит тестов, ура!
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> y >> x;
    vector<vector<char>> V(n + 4, vector<char>(n + 4));
    vector<int> x1{1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> y1{2, 1, -1, -2, -2, -1, 1, 2};

    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 2; j < n + 2; j++)
        {
            V[i][j] = '.';
        }
    }

    V[y + 1][x + 1] = 'K';

    for (int i = 0; i < 8; i++)
    {
        V[y + 1 - y1[i]][x + 1 - x1[i]] = '*';
    }

    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 2; j < n + 2; j++)
        {
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
}
