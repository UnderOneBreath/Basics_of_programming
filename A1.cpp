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
// int main()
// {
//     int i = power(10, 2);
//     cout << i;
// }

TEST_CASE("Dulustan's tests"){
    CHECK(power(1,100) == 1);
    CHECK(power(2,7) == 128);
    CHECK(power(2,10) == 1024);  
    CHECK(power(6,5) == 7776);
    CHECK(power(7,13) == 96889010407);
}

TEST_CASE("Student's tests"){
    CHECK(power(1000, 0) == pow(1000, 0));
    CHECK(power(56, 0) == pow(56, 0));
    CHECK(power(73, 2) == pow(73, 2));
    CHECK(power(0, 0) == pow(0, 0));
    CHECK(power(123, 5) == pow(123, 5));
    CHECK(power(2, 3) == 8);
    CHECK(power(1000, 1) == 1000);
    CHECK(power(1001, 2) == 1002001);
    CHECK(power(5, 5) == 3125);
    CHECK(power(10, 0) == 1);
}
