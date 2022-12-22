#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dist(int x1, int x2, int y1, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double solve(vector<double> x, vector<double> y)
{
    cout.precision(12);
    vector<double> setX, setY;
    double SmDistance, distanc;
    int changeaPlace = 0;

    for (int i = 0; i < x.size(); i++)
        for (int j = i + 1; j < y.size(); j++)
        {
            setX.push_back(x[i]);
            setY.push_back(y[i]);
            setX.push_back(x[j]);
            setY.push_back(y[j]);
        }

    SmDistance = dist(setX[1], setX[0], setY[1], setY[0]);
    cout << SmDistance << endl;
    for (int i = 1; i < setX.size(); i++)
    {
        distanc = dist(setX[i - 1], setX[i], setY[i - 1], setY[i]);
        if (distanc < SmDistance)
            SmDistance = distanc;
    }
    return SmDistance;
}

// int main()
// {
//     vector<double> x, y;

//     x = vector<double>{10, 4, 3, 25, 1};
//     y = vector<double>{5, 8, 10, 2, 1};
//     cout << solve(x, y);
// }

TEST_CASE("Dulustan's tests")
{
    vector<double> x, y;

    x = vector<double>{5, 4, 3, 2, 1};
    y = vector<double>{5, 4, 3, 2, 1};
    cout << solve(x, y);
    CHECK(solve(x, y) == doctest::Approx(1.41421356237));

    x = vector<double>{0, -50};
    y = vector<double>{50, 0};
    CHECK(solve(x, y) == doctest::Approx(70.7106781187));
}

TEST_CASE("Student's tests")
{
    vector<double> x, y;
    x = vector<double>{10, 4, 3, 25, 1};
    y = vector<double>{5, 8, 10, 2, 1};
    CHECK(solve(x, y) == doctest::Approx(2.23607));

    x = vector<double>{10, 45, 3, 25, 1};
    y = vector<double>{5, 8, 10, 27, 12};
    CHECK(solve(x, y) == doctest::Approx(2.82843));

    x = vector<double>{10, 4, 34, 25, 1};
    y = vector<double>{8, 8, 10, 2, 0};
    CHECK(solve(x, y) == doctest::Approx(6));

    x = vector<double>{10, 4, 35, 25, 1};
    y = vector<double>{5, 87, 10, 2, 1};
    CHECK(solve(x, y) == doctest::Approx(9.84886));

    x = vector<double>{10, 4, 30, 2, 10};
    y = vector<double>{5, 82, 10, 2, 1};
    CHECK(solve(x, y) == doctest::Approx(4));

    x = vector<double>{10, 4, 3, 250, 1};
    y = vector<double>{57, 8, 10, 22, 1};
    CHECK(solve(x, y) == doctest::Approx(2.23607));
}