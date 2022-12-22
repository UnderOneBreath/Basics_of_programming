#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> A)
{
    int frst, lst;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < 0)
        {
            frst = i;
            break;
        }
    }
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < 0)
            lst = i;
    }
    swap(A[frst], A[lst]);
    return A;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve({-1, 5, 0, 100}) == vector<int>({-1, 5, 0, 100}));
    CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) == vector<int>({3, -61, 5, -7, 10, 36, -1, 88}));
    CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) == vector<int>({3, 10, 22, -5, 76, -61, -123, -10, 7}));
    CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) == vector<int>({-2024, 1039, -3039, -2023, -2022, 777, 361}));
}

// //минимум 4 теста
TEST_CASE("Student's tests")
{
    CHECK(solve({-1, 5, 0, -100}) == vector<int>({-100, 5, 0, -1}));
    CHECK(solve({-3, -1, 5, -7, 10, 36, -61, -88}) == vector<int>({-88, -1, 5, -7, 10, 36, -61, -3}));
    CHECK(solve({1, -43, 0, -24, -4, 2, -6}) == vector<int>({1, -6, 0, -24, -4, 2, -43}));
    CHECK(solve({-1, 0, 1, 2, 3, 4, -5, 6}) == vector<int>({-5, 0, 1, 2, 3, 4, -1, 6}));
}

// main отвечает за ввод-вывод
// int main()
// {
//     cout << solve({-1, 5, 0, -100});
// }
