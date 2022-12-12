#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

int digit_root(long long n)
{
    while (n > 9)
    {
        int s = 0;
        while (n > 0)
        {
            s += n % 10;
            n /= 10;
        }
        n = s;
    }
    return n;
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы
// int main()
// {

// }


TEST_CASE("Dulustan's tests"){
    CHECK(digit_root(8)==8);
    CHECK(digit_root(25)==7);
    CHECK(digit_root(99)==9);
    CHECK(digit_root(987)==6);
    CHECK(digit_root(777'777'777'777)==3);
}

TEST_CASE("Student's tests"){
    CHECK(digit_root(888'888'888'888)==6);
    CHECK(digit_root(5678) == 8);
	CHECK(digit_root(111) == 3);
	CHECK(digit_root(871) == 7);
	CHECK(digit_root(111111) == 6);
    CHECK(digit_root(324) == 9);
	CHECK(digit_root(444) == 3);
	CHECK(digit_root(1234) == 1);
}