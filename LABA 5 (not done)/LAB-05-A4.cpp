#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> A)
{
    vector<int> b;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1] >= 0 & A[i] >= 0 || A[i - 1] < 0 & A[i] < 0)
        {
            b.push_back(A[i - 1]);
            b.push_back(A[i]);
            break;
        }
    }
    return b;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve({-1, 5, 0, 100}) == vector<int>({5, 0}));
    CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) == vector<int>({10, 36}));
    CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) == vector<int>({3, 10}));
    CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) == vector<int>({-3039, -2023}));
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
}

// main отвечает за ввод-вывод
// int main()
// {

// }
