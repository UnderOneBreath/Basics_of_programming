#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

long long power(long long x, unsigned k)
{
    long long n = 1;
    for (int i = 0; i < k; i++)
    {
        n *= x;
    }
    return n;
}

long long sum_m(int m)
{
    long long n = 0;
    for (int i = 1; i <= 10; i++)
    {
        n += power(i, m);
    }
    return n;
}
long long answer(int l)
{
    long long k = 0;
    for (int i = 1; i < 11; i++)
    {
        k += pow(i, l);
    }
}
TEST_CASE("Dulustan's tests"){
    CHECK(sum_m(1) == 55);
    CHECK(sum_m(2) == 385);
}

TEST_CASE("Student's tests"){
    CHECK(sum_m(3) == 3025);
    CHECK(sum_m(4) == 25333);
    CHECK(sum_m(5) == 220825);
    CHECK(sum_m(6) == 1978405);
    CHECK(sum_m(7) == 18080425);
    CHECK(sum_m(8) == answer(8));
    CHECK(sum_m(9) == answer(9));
    CHECK(sum_m(10) == answer(10));
    CHECK(sum_m(11) == answer(11));
    CHECK(sum_m(12) == answer(12));
    CHECK(sum_m(13) == answer(13));
}

