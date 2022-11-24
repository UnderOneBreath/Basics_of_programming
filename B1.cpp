#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>
#include <iostream>
using namespace std;

bool simple(int n){
    for(int i=2; i<=floor(sqrt(n)); i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

bool hamming(int n)
{
    if(simple(n) or n==1)
        return 0;
    for(int i=2; i<=floor(sqrt(n)); i++){
        if(n%i==0){
            if(simple(i) && !(i==2||i==3||i==5))
                return 0;
            if(simple(n/i) && !((n/i)==2||(n/i)==3||(n/i)==5))
                return 0;
        }
    }
    return 1;
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы
/*
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=m; i<=n; i++){
        if(hamming(i))
            cout<<i<<" ";
    }
}
*/


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