// #define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> V)
{
    int n = V.size(), indexOfMin = 0, indexOfMax = 0, min = V[0][0], max = V[0][0], answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (max < V[i][j])
            {
                max = V[i][j];
                indexOfMax = i;
            }
            if (min > V[j][i])
            {
                min = V[j][i];
                indexOfMin = i;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        answer += V[indexOfMax][i] * V[i][indexOfMin];
    }

    return answer;
}

// main отвечает за ввод-вывод
int main()
{
    // Dulustan's tests
    {
        vector<vector<int>> inp;
        inp = {{1, 2, 3},
               {4, 5, 6},
               {7, 8, 9}};
        assert(solve(inp) == 102);

        inp = {{1, 2},
               {3, 4}};
        assert(solve(inp) == 15);

        inp = {{6, -10, 8, 22},
               {100, 0, 0, 0},
               {11, 17, 7, 91},
               {31, 32, 33, 34}};
        assert(solve(inp) == -1000);

        // придумайте по одному тесту 4x4 и 6x6
        // Student's tests
        // {
        vector<vector<int>> inp;
        inp = {{2, 4, 8, 10},
               {11, 13, 15, 17},
               {104, 201, 345, -752},
               {100, -200, 300, -400}};
        assert(solve(inp) == 45817);

        inp = {{1, 2, 3, 4, 5, 6},
               {7, 8, 9, 10, 11, 12},
               {13, 14, 15, 16, 17, 18},
               {19, 20, 21, 22, 23, 24},
               {25, 26, 27, 28, 29, 30},
               {31, 32, 33, 34, 35, 36}};
        assert(solve(inp) == 3321);
    }
}
