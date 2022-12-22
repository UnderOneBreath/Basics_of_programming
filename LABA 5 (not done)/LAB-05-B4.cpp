#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int solve(vector<double> &x, vector<double> &y, double xs, double ys)
{
    int imin = 0;

    for (int i = 0; i < x.size(); i++)
    {
        imin = dist(xs, ys, x[i], y[i]) < dist(xs, ys, x[imin], y[imin]) ? i : imin;
    }

    return imin;
}

TEST_CASE("Dulustan's tests")
{
    vector<double> x, y;

    x = vector<double>{5, 4, 3, 2, 1};
    y = vector<double>{5, 4, 3, 2, 1};
    CHECK(solve(x, y, 0, 0) == 4);

    x = vector<double>{1, 4, -2};
    y = vector<double>{-10, 3, 4};
    CHECK(solve(x, y, 1, 1) == 1);

    x = vector<double>{2, 7, 9, 4, 1, 0, 13};
    y = vector<double>{2, 7, 9, 4, 1, 0, 13};
    CHECK(solve(x, y, 7, 1) == 3);

    x = vector<double>{0, -50};
    y = vector<double>{50, 0};
    CHECK(solve(x, y, -10, 11) == 0);
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
}

// main отвечает за ввод-вывод
// int main()
// {

// }
