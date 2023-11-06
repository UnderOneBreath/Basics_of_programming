#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> A)
{
    for (int i = 1; i < A.size(); i += 2)
    {
        swap(A[i - 1], A[i]);
    }
    return A;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve({-1, 5, 0, 100}) == vector<int>({5, -1, 100, 0}));
    CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) == vector<int>({-1, 3, -7, 5, 36, 10, 88, -61}));
    CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) == vector<int>({10, 3, -10, 22, -61, 76, -5, -123, 7}));
    CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) == vector<int>({1039, -2022, -2023, -3039, 777, -2024, 361}));
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
}

// main отвечает за ввод-вывод
// int main()
// {

// }
