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
    vector<double> x, y;
    x = vector<double>{2, 1, 9, 4, 80, 0, 9};
    y = vector<double>{2, 2, 9, 4, 10, 0, 12};
    CHECK(solve(x, y, 2, 1) == 0);

    x = vector<double>{12, 13, -9, 2};
    y = vector<double>{10, 12, 9, 4};
    CHECK(solve(x, y, 10, 1) == 3);

    x = vector<double>{12, 13, -9, 2};
    y = vector<double>{10, 12, 9, 4};
    CHECK(solve(x, y, 14, 10) == 0);

    x = vector<double>{122, 153, -90, 4, -5};
    y = vector<double>{120, 127, 10, 18, 10};
    CHECK(solve(x, y, 20, -14) == 4);

    x = vector<double>{21, 13, 0, 4, 0, 8, 10};
    y = vector<double>{10, 17, 2, 1, 14, 100, 14};
    CHECK(solve(x, y, -10, 54) == 4);
}

// main отвечает за ввод-вывод
// int main()
// {

// }
