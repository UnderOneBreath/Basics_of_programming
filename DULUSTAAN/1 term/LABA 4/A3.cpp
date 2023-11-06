#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <math.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    double distance = 0;
    distance = pow(pow((x2 - x1), 2) + pow((y2 - y1), 2), 0.5);
    // cout << x1 << y1 << x2 << y2 << endl;
    // cout << pow((x2 - x1), 2) << endl;
    // cout << pow((x2 - x1), 2) + pow((y2 - y1), 2) << endl;
    return distance;
}

double solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = 0, b = 0, c = 0, m = 0;
    a = dist(x1, y1, x2, y2);
    b = dist(x2, y2, x3, y3);
    c = dist(x1, y1, x3, y3);
    if ((a + b < c) || (a + c < b) || (b + c < a) || ((a == 0) && (b == 0) && (c == 0)))
    {
        return -1;
    }
    m = max(a, b);
    if (a == b)
    {
        m = a;
    }
    m = max(m, c);
    // cout << m << endl;
    // cout << c << endl;
    return m;
}

// int main()
// {
//     cout << solve(2, 1, 5, 6, 8, 1);
// }

TEST_CASE("Dulustan's tests")
{
    CHECK(dist(0, 0, 1000, 0) == doctest::Approx(1000));
    CHECK(dist(-5, 15, 10, -10) == doctest::Approx(29.154759474));
    CHECK(dist(-12.5, 50000, 12.5, 50200) == doctest::Approx(201.556443707));

    CHECK(solve(0, 0, 6, 0, 3, 2) == doctest::Approx(6));
}

TEST_CASE("Student's tests")
{
    CHECK(solve(2, 1, 5, 6, 8, 1) == doctest::Approx(6));
    CHECK(solve(4, 2, 3, 8, 9, 1) == doctest::Approx(sqrt(85)));
    CHECK(solve(0, 0, 6, 1, 8, -4) == doctest::Approx(sqrt(80)));
    CHECK(solve(-2, -2, 0, 0, 12, -4) == doctest::Approx(sqrt(200)));
    CHECK(dist(0, 0, 9, 0) == doctest::Approx(9));
    CHECK(dist(0, 0, 0, 0) == doctest::Approx(0));
    CHECK(dist(-2, -2, 2, 2) == doctest::Approx(sqrt(32)));
    CHECK(dist(0, -6, 0, 6) == doctest::Approx(12));
    CHECK(solve(0, 0, 0, 0, 0, 0) == doctest::Approx(-1));
}