#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &v)
{
    int imin = 0, imax = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[imin] > v[i])
            imin = i;
        if (v[imax] < v[i])
            imax = i;
    }

    imin = v[imin];
    imax = v[imax];

    int i = 0;

    while (i < v.size())
    {
        if (abs(imax - v[i]) > 1 && abs(imin - v[i]) > 1)
            v.erase(v.begin() + i);
        else
            i++;
    }
}

TEST_CASE("Dulustan's tests")
{
    vector<int> v;

    v = {1, 2, 3, 4, 5};
    solve(v);
    CHECK(v == vector<int>{1, 2, 4, 5});

    v = {6, 4, 6, 7, 0, 1, 0, 3};
    solve(v);
    CHECK(v == vector<int>{6, 6, 7, 0, 1, 0});

    v = {-1, 0, -5, -9, -2, -10, -6, -9};
    solve(v);
    CHECK(v == vector<int>{-1, 0, -9, -10, -9});

    v = {777, 776, 778, 7, 7, 8};
    solve(v);
    CHECK(v == vector<int>{777, 778, 7, 7, 8});
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
    vector<int> v;

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    solve(v);
    CHECK(v == vector<int>{1, 2, 9, 10});

    v = {1, 1, 1, 1, 1, 1, 1};
    solve(v);
    CHECK(v == vector<int>{1, 1, 1, 1, 1, 1, 1});

    v = {1, 0, 1, 2, 1, 7, 1};
    solve(v);
    CHECK(v == vector<int>{
                   1,
                   0,
                   1,
                   1,
                   7,
                   1,
               });

    v = {2002, -1845, 304, 12, 0, 123, 2222, 3033, 3034};
    solve(v);
    CHECK(v == vector<int>{-1845, 3033, 3034});
}

// main отвечает за ввод-вывод
// int main()
// {

// }
