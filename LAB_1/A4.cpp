// #define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> V)
{
    int n = V.size(), m = V[0].size();
    for (int j = 0; j < m; j++)
    {
        int min = V[0][j];
        for (int i = 0; i < n; i++)
        {
            if (min > V[i][j])
                min = V[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            if (min == V[i][j])
                V[i][j]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int max = V[i][0];
        for (int j = 0; j < m; j++)
        {
            if (max < V[i][j])
                max = V[i][j];
        }
        for (int j = 0; j < m; j++)
        {
            if (max == V[i][j])
                V[i][j] *= 2;
        }
    }
    return V;
}

// main отвечает за ввод-вывод
int main()
{
    // vector<vector<int>> inp;
    // int n = inp.size(), m = inp[0].size();
    // inp = solve(inp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << '{';
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << inp[i][j] << ", ";
    //     }
    //     cout << "}," << endl;
    // }
    {
        vector<vector<int>> inp, outp;
        inp = {{5, 5, 4, -1}, {6, 0, 7, 2}, {0, -10, -2, -1}};
        outp = {{10, 10, 4, -2}, {6, 0, 14, 2}, {-2, -11, -3, -2}};
        assert(solve(inp) == outp);

        inp = {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
        outp = {{18, 18, 18}, {18, 18, 18}, {18, 18, 18}};
        assert(solve(inp) == outp);

        inp = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
        outp = {{0, 1, 2, 3, 8}, {6, 7, 8, 9, 20}};
        assert(solve(inp) == outp);
    }

    // придумайте три хороших теста
    {
        vector<vector<int>> inp, outp;
        inp = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        outp = {{-2, -2, -2, -2}, {-2, -2, -2, -2}, {-2, -2, -2, -2}};
        assert(solve(inp) == outp);

        inp = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
        outp = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        assert(solve(inp) == outp);

        inp = {{1000, -1001, 1011, -1100}, {-1234, 62356, -11234, 6541}, {135632, -9999, 1123, -13456}};
        outp = {{1000, -1001, 2022, -1100}, {-1235, 124712, -11235, 6541}, {271264, -10000, 1123, -13457}};
        assert(solve(inp) == outp);
    }
}
