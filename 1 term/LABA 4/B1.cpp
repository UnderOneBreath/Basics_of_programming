#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>
#include <iostream>
using namespace std;

bool hamming(int n)
{
    int k = 0;
    if (n == 1 || n == 0)
        return false;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        if (n % 3 == 0)
            n /= 3;
        if (n % 5 == 0)
            n /= 5;
        if (n == 1)
            return true;
        if (n % 2 != 0 & n % 3 != 0 & n % 5 != 0)
            k += 1;
            if ( k > 7 & n == n)
                return false;
    }
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы

// int main()
// {
//     cout << hamming(44);
// }



 TEST_CASE("Dulustan's tests"){
     CHECK(!hamming(1));
     CHECK(hamming(8));
     CHECK(hamming(12));
     CHECK(hamming(24));
     CHECK(hamming(45));
     CHECK(hamming(384));
     CHECK(!hamming(14));
     CHECK(!hamming(26));
     CHECK(!hamming(44));
     CHECK(!hamming(365));    
    
 }

// тут придумайте хотя бы 10 интересных тестов: 5 положительных и 5 отрицательных
 TEST_CASE("Student's tests"){
     CHECK(!hamming(0));
     CHECK(!hamming(7));
     CHECK(!hamming(49));
     CHECK(!hamming(130));
     CHECK(!hamming(97));
     CHECK(hamming(200));
     CHECK(hamming(25));
     CHECK(hamming(10000));
     CHECK(hamming(48));
     CHECK(hamming(32));    
 }