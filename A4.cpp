#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

bool in_square(double x, double y)
{
    if ((-1 <= x <= 1) && (-1 <= y <= 1))
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
    CHECK(in_square(1, -1));
    CHECK(in_square(0.75, -0.2));
    CHECK(in_square(-0.5, 0.5));
    CHECK(in_square(0.000001, 1));
    CHECK(in_square(0.9999, 0.0001));
    CHECK(!in_square(5, -4));
    CHECK(in_square(0.3, 0.9));
    CHECK(in_square(0.1, 0.1));
}
