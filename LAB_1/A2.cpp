// #define NDEBUG
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> solve(int n, int m)
{
    vector<vector<char>> Array(n, vector<char>(m));
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp += 1;
            if (temp % 2 != 0)
                Array[i][j] = 'b';
            else
                Array[i][j] = 'w';
        }
        if (m % 2 == 0)
            temp += 1;
    }
    return Array;
}

int main()
{

    // Dulustan's tests
    {
        vector<vector<char>> outp;

        outp = {{'b', 'w'}};
        assert(solve(1, 2) == outp);

        outp = {{'b'}, {'w'}, {'b'}, {'w'}, {'b'}};
        assert(solve(5, 1) == outp);

        outp = {{'b', 'w', 'b', 'w'}, {'w', 'b', 'w', 'b'}, {'b', 'w', 'b', 'w'}};
        assert(solve(3, 4) == outp);

        outp = {{'b', 'w', 'b'}, {'w', 'b', 'w'}, {'b', 'w', 'b'}, {'w', 'b', 'w'}, {'b', 'w', 'b'}, {'w', 'b', 'w'}};
        assert(solve(6, 3) == outp);

        // доделайте эти тесты
        // Student's tests
        outp = {{'b', 'w', 'b'}, {'w', 'b', 'w'}};
        assert(solve(2, 3) == outp);

        outp = {{'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b'},
                {'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w'},
                {'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b'},
                {'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w'},
                {'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b', 'w', 'b'}};
        assert(solve(5, 11) == outp);

        outp = {{'b', 'w', 'b', 'w'},
                {'w', 'b', 'w', 'b'},
                {'b', 'w', 'b', 'w'},
                {'w', 'b', 'w', 'b'},
                {'b', 'w', 'b', 'w'},
                {'w', 'b', 'w', 'b'},
                {'b', 'w', 'b', 'w'},
                {'w', 'b', 'w', 'b'},
                {'b', 'w', 'b', 'w'},
                {'w', 'b', 'w', 'b'}};
        assert(solve(10, 4) == outp);
    }
    cout << "TEST COMPLITED";
}
