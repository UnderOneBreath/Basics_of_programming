#define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void InputEl(vector<vector<int>> V, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            V[i][j] = ((double)rand() / (RAND_MAX)) + 1;
}
void OutputArray(vector<vector<int>> V, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << V[i][j];
}

// main отвечает за ввод-вывод
int main()
{
    int n, count = 0, maxCount = 0, Gcount;
    cin >> n;
    vector<vector<int>> V(n, vector<int>(n));
    InputEl(V, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (V[i][i] == 0)
                Gcount++;
            if (V[i][j] == 0)
                count++;
        }
        if (count > maxCount)
            maxCount == count;
        else if (Gcount > maxCount)
            maxCount == Gcount;
        count == 0;
        Gcount == 0;
    }
    cout << maxCount;
    cout << endl;
    OutputArray(V, n);

    // Dulustan's tests
    {
        vector<vector<int>> inp;
        inp = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
        assert(solve(inp) == 0);

        inp = {{5, 0, 0, -1}, {0, 0, 7, 2}, {0, -10, 0, -1}, {3, 0, 13, 0}};
        assert(solve(inp) == 3);

        inp = {{10, 10, 10}, {10, 0, 10}, {10, 0, 10}};
        assert(solve(inp) == 2);

        inp = {{1, 0, 0, 2, 0}, {0, 3, 0, 0, 4}, {5, 6, 0, 7, 8}, {9, 0, 10, 11, 12}, {13, 0, 0, 0, 14}};
        assert(solve(inp) == 4);
    }

    // придумайте по одному тесту 4x4 и 6x6
    // Student's tests
    //{

    //}
}
