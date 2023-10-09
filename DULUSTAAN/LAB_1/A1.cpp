#define NDEBUG
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solve(int n, int m)
{
    vector<vector<int>> yArray(n, vector<int>(m));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            yArray[i][j] = i + k;
            k += n;
        }
        k = 0;
    }
    return yArray;
}

// main отвечает за ввод-вывод
int main()
{
    // Dulustan's tests
    {
        vector<vector<int>> outp;

        outp = {{1, 2}};
        assert(solve(1, 2) == outp);

        outp = {{1}, {2}, {3}, {4}, {5}};
        assert(solve(5, 1) == outp);

        outp = {{1, 4, 7, 10}, {2, 5, 8, 11}, {3, 6, 9, 12}};
        assert(solve(3, 4) == outp);

        outp = {{1, 7, 13}, {2, 8, 14}, {3, 9, 15}, {4, 10, 16}, {5, 11, 17}, {6, 12, 18}};
        assert(solve(6, 3) == outp);

        // доделайте эти тесты
        // Student's tests
        outp = {{1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16}};
        assert(solve(8, 8) == outp);

        outp = {{1, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51}, {2, 7, 12, 17, 22, 27, 32, 37, 42, 47, 52}, {3, 8, 13, 18, 23, 28, 33, 38, 43, 48, 53}, {4, 9, 14, 19, 24, 29, 34, 39, 44, 49, 54}, {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55}};
        assert(solve(5, 11) == outp);

        outp = {{1, 11, 21, 31},
                {2, 12, 22, 32},
                {3, 13, 23, 33},
                {4, 14, 24, 34},
                {5, 15, 25, 35},
                {6, 16, 26, 36},
                {7, 17, 27, 37},
                {8, 18, 28, 38},
                {9, 19, 29, 39},
                {10, 20, 30, 40}};
        assert(solve(10, 4) == outp);
    }
    cout << "TEST COMPLITED";
}
