#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
}

TEST_CASE("Dulustan's tests")
{
    vector<int> a, b;

    a = vector<int>{1, 2, 3, 4, 5};
    b = vector<int>{5, 4, 3, 2, 1};
    solve(a, b);
    CHECK(a == vector<int>({1, 2, 3, 2, 1}));
    CHECK(b == vector<int>({5, 4, 3, 4, 5}));

    a = vector<int>{-7, 7, 11, -8, 22, 31, -50};
    b = vector<int>{7, -77, 88, 31, -19, 0, -46};
    solve(a, b);
    CHECK(a == vector<int>({-7, -77, 11, -8, -19, 0, -50}));
    CHECK(b == vector<int>({7, 7, 88, 31, 22, 31, -46}));

    a = vector<int>{789987, 2022};
    b = vector<int>{789789, 2023};
    solve(a, b);
    CHECK(a == vector<int>({789789, 2022}));
    CHECK(b == vector<int>({789987, 2023}));

    a = vector<int>{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2};
    b = vector<int>{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5};
    solve(a, b);
    CHECK(a == vector<int>({4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2}));
    CHECK(b == vector<int>({5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}));
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
    vector<int> a, b;

    a = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    b = vector<int>{-1, 23, 34, 43, 54, 890, 90, -23, 0, -3};
    solve(a, b);
    CHECK(a == vector<int>({-1, 2, 3, 4, 5, 6, 7, -23, 0, -3}));
    CHECK(b == vector<int>({1, 23, 34, 43, 54, 890, 90, 8, 9, 10}));

    a = vector<int>{0, 0, 0, 0, 0};
    b = vector<int>{0, 0, 0, 0, -1};
    solve(a, b);
    CHECK(a == vector<int>({0, 0, 0, 0, -1}));
    CHECK(b == vector<int>({0, 0, 0, 0, 0}));

    a = vector<int>{11, 0, 43, 5, 40, 23, 85, 33, 12, 300};
    b = vector<int>{34, 23, -2, 3, 5, 0, 12, 85, 90, 12};
    solve(a, b);
    CHECK(a == vector<int>({11, 0, -2, 3, 5, 0, 12, 33, 12, 12}));
    CHECK(b == vector<int>({34, 23, 43, 5, 40, 23, 85, 85, 90, 300}));

    a = vector<int>{13, 89, 23, 95, 934, 23, 229};
    b = vector<int>{548, -343, -234, 854, 48, 84, 2};
    solve(a, b);
    CHECK(a == vector<int>({13, -343, -234, 95, 48, 23, 2}));
    CHECK(b == vector<int>({548, 89, 23, 854, 934, 84, 229}));
}

// main отвечает за ввод-вывод
// int main()
// {

// }
