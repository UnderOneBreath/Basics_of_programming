#define NDEBUG
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> V)
{
    int n = V.size();
    vector<vector<int>> Output(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            Output[n - 1 - j][i] = V[i][j];
        }
    }
    return Output;
}

// main отвечает за ввод-вывод
int main()
{

    // Dulustan's tests
    {
        vector<vector<int>> inp, outp;
        inp = {{1, 2}, {3, 4}};
        outp = {{2, 4}, {1, 3}};
        assert(solve(inp) == outp);

        inp = {{6, 6, 6}, {9, 9, 9}, {1, 2, 3}};
        outp = {{6, 9, 3}, {6, 9, 2}, {6, 9, 1}};
        assert(solve(inp) == outp);

        inp = {{11, 12, 13, 14}, {15, 16, 17, 18}, {19, 20, 21, 22}, {23, 24, 25, 26}};
        outp = {{14, 18, 22, 26}, {13, 17, 21, 25}, {12, 16, 20, 24}, {11, 15, 19, 23}};
        assert(solve(inp) == outp);
    }

    // придумайте по одному тесту 5x5 и 6x6
    // Student's tests
    {
        vector<vector<int>> inp, outp;
        inp = {{7, 18, 25, 49, 69},
               {9, 15, 26, 39, 42},
               {57, 65, 75, 88, 99},
               {100, 90, 60, 96, 69},
               {13, 17, 25, 49, 69}};
        outp = {{69, 42, 99, 69, 69},
                {49, 39, 88, 96, 49},
                {25, 26, 75, 60, 25},
                {18, 15, 65, 90, 17},
                {7, 9, 57, 100, 13}};
        assert(solve(inp) == outp);

        inp = {{7, 13, 20, 25, 37, 47},
               {50, 57, 75, 76, 88, 97},
               {100, 102, 105, 120, 122, 130},
               {150, 152, 170, 183, 200, 220},
               {280, 7, 13, 14, 15, 20},
               {30, 37, 50, 57, 75, 76}};
        outp = {{47, 97, 130, 220, 20, 76},
                {37, 88, 122, 200, 15, 75},
                {25, 76, 120, 183, 14, 57},
                {20, 75, 105, 170, 13, 50},
                {13, 57, 102, 152, 7, 37},
                {7, 50, 100, 150, 280, 30}};
        assert(solve(inp) == outp);
        cout << "text compl.";
    }
}
