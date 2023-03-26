// задача без юнит тестов, ура!
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, y, x;
    cin >> n >> y >> x;
    vector<vector<char>> V(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i == y - 1) || (j == x - 1) || (i - y + 1) == (j - x + 1) || (i - y + 1) == -(j - x + 1))
                V[i][j] = '*';
            else
                V[i][j] = '.';
        }
    }
    V[y - 1][x - 1] = 'Q';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
}
