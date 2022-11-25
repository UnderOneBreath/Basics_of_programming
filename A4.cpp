#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

bool in_square(double x, double y)
{
    double a, b, c, d;
	int x1 = -1, x2 = 0, x3 = 1, x4 = 0, y1 = 0, y2 = 1, y3 = 0, y4 = -1;
	a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
	b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
	c = (x3 - x) * (y4 - y3) - (x4 - x3) * (y3 - y);
	d = (x4 - x) * (y1 - y4) - (x1 - x4) * (y4 - y);
	if ((a >= 0 && b >= 0 && c >= 0 && d >=0) || (a <= 0 && b <= 0 && c <= 0 && d <=0))
    {
        return true;
    }
    return false;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(in_square(0, 0));
    CHECK(in_square(-1, 0));
    CHECK(in_square(0, 1));
    CHECK(in_square(0.5, -0.2));
    CHECK(in_square(-0.3, 0.2));
    CHECK(in_square(-0.3, -0.3));
    CHECK(in_square(0.4, 0.15));
    CHECK(!in_square(-1.01, 0));
}

// придумайте хотя бы 8 интересных тестов
TEST_CASE("Student's tests")
{
    CHECK(!in_square(1, -1));
    CHECK(in_square(0.75, -0.2));
    CHECK(in_square(-0.5, 0.5));
    CHECK(!in_square(0.000001, 1));
    CHECK(in_square(0.9999, 0.0001));
    CHECK(!in_square(5, -4));
    CHECK(!in_square(0.3, 0.9));
    CHECK(in_square(0.1, 0.1));
}
