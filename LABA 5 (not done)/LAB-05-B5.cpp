// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double solve(vector<double> x, vector<double> y)
{
    vector<double> setX, setY;
    double listXY[1][1];
    cout.precision(12);
    double SmDistance = 0;
    int changeaPlace = 0;

    for (int i = 0; i < x.size(); i++)
        for (int j = 0; j < y.size(); j++)
        {
            setX.push_back(setX[i]);
            setY.push_back(setY[i]);
            setX.push_back(setX[j]);
            setY.push_back(setY[j]);
        }
    cout << listXY[0] << endl;
    return SmDistance;
}

int main()
{
    vector<double> x, y;

    x = vector<double>{5, 4};
    y = vector<double>{1, 3};
    cout << solve(x, y);
}

// TEST_CASE("Dulustan's tests")
// {
//     vector<double> x, y;

//     x = vector<double>{5, 4, 3, 2, 1};
//     y = vector<double>{5, 4, 3, 2, 1};
//     cout << solve(x, y);
//     CHECK(solve(x, y) == doctest::Approx(1.41421356237));

//     x = vector<double>{0, -50};
//     y = vector<double>{50, 0};
//     CHECK(solve(x, y) == doctest::Approx(70.7106781187));
// }

// TEST_CASE("Student's tests")
// {
//     vector<double> x, y;
//     x = vector<double>{10, 4, 3, 25, 1};
//     y = vector<double>{5, 8, 10, 2, 1};
//     CHECK(solve(x, y) == doctest::Approx(2.23607));

//     x = vector<double>{10, 45, 3, 25, 1};
//     y = vector<double>{5, 8, 10, 27, 12};
//     CHECK(solve(x, y) == doctest::Approx(27.8029));

//     x = vector<double>{10, 4, 34, 25, 1};
//     y = vector<double>{8, 8, 10, 2, 0};
//     CHECK(solve(x, y) == doctest::Approx(6));

//     x = vector<double>{10, 4, 35, 25, 1};
//     y = vector<double>{5, 87, 10, 2, 1};
//     CHECK(solve(x, y) == doctest::Approx(12.8062));

//     x = vector<double>{10, 4, 30, 2, 10};
//     y = vector<double>{5, 82, 10, 2, 1};
//     CHECK(solve(x, y) == doctest::Approx(8.06226));

//     x = vector<double>{10, 4, 3, 250, 1};
//     y = vector<double>{57, 8, 10, 22, 1};
//     CHECK(solve(x, y) == doctest::Approx(2.23607));
// }