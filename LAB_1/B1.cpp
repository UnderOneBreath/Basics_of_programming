#define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int solve(vector<vector<int>> V)
{
    int n = V.size(), gcount = 0, vcount = 0, dcount = 0, maxCount = 0;
    // gorizontal and vertical
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (V[i][j] == 0)
                gcount++;
            if (V[j][i] == 0)
                vcount++;
        }
        if (gcount > maxCount)
            maxCount = gcount;
        if (vcount > maxCount)
            maxCount = vcount;
        gcount = 0;
        vcount = 0;
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n)
                break;
            if (V[i + j][j] == 0)
                dcount++;
        }
    }
    if (dcount > maxCount)
        maxCount = dcount;
    return maxCount;
    // cout << "MaxLenght <0> = " << maxCount;
    // cout << endl;
}

// void OutputArray(vector<vector<int>> V, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << V[i][j];
//         cout << endl;
//     }

// }

// main отвечает за ввод-вывод
int main()
{
    // int n;
    // cin >> n;
    // vector <vector<int>> V(n, vector<int> (n));
    // solve(n);
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

        // Student's tests

        inp = {{0, 0, 0, 0},
               {0, 0, 0, 0},
               {0, 0, 0, 0},
               {0, 0, 0, 0}};
        assert(solve(inp) == 4);

        inp = {{1, 0, 1, 0, 1, 0},
               {0, 1, 0, 1, 0, 1},
               {1, 0, 1, 0, 1, 0},
               {0, 1, 0, 1, 0, 1},
               {1, 0, 1, 0, 1, 0},
               {0, 1, 0, 1, 0, 1}};
        assert(solve(inp) == 6);
        cout << "text compl.";
    }

    // придумайте по одному тесту 4x4 и 6x6
    //{

    //}
    return 0;
}
