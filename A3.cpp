#define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// main отвечает за ввод-вывод
int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<int>> Array(n, vector<int>(m));
    for (int count = 0; (count <= m / 2) || (count <= n / 2); count++)
    {
        for (int i = count; i < n - count; i++)
        {
            for (int j = count; j < m - count; j++)
            {
                // for (int f = 0; f < m; f++)
                Array[i][j] = count;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }

    //
    // Dulustan's tests
    {
        vector<vector<int>> outp;

        outp = {{0, 0, 0, 0}};
        assert(solve(1, 4) == outp);

        outp = {{0, 0, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 0, 0}};
        assert(solve(5, 3) == outp);

        outp = {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 1, 2, 2, 1, 0}, {0, 1, 2, 2, 1, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0}};
        assert(solve(6, 6) == outp);
    }

    // доделайте эти тесты
    // Student's tests
    //  {
    //      vector<vector<int>> outp;
    //      outp = ?
    //      assert(solve(8,8) == outp);

    //     outp = ?
    //     assert(solve(7,11) == outp);

    //     outp = ?
    //     assert(solve(10,12) == outp);
    // }
}
