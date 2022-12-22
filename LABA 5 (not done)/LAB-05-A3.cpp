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
}

// main отвечает за ввод-вывод
// int main()
// {

// }
