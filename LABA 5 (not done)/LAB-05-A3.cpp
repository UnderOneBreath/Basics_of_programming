#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> A)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > A[max])
        {
            max = i;
        }
        if (A[i] < A[min])
        {
            min = i;
        }
    }
    swap(A[min], A[max]);
    return A;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve({-1, 5, 0, 100}) == vector<int>({100, 5, 0, -1}));
    CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) == vector<int>({3, -1, 5, -7, 10, 36, 88, -61}));
    CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) == vector<int>({3, 10, 22, -10, -123, -61, 76, -5, 7}));
    CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) == vector<int>({-2022, -3039, 1039, -2023, -2024, 777, 361}));
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
    CHECK(solve({3252, 134, 52, 0, 9999}) == vector<int>({3252, 134, 52, 9999, 0}));
    CHECK(solve({1, 2, 3, 4, 5}) == vector<int>({5, 2, 3, 4, 1}));
    CHECK(solve({42, -123, 412, 332, 500}) == vector<int>({42, 500, 412, 332, 123}));
    CHECK(solve({1, -1, 0, 2}) == vector<int>({1, 2, 0, -1}));
}

// main отвечает за ввод-вывод
// int main()
// {

// }
