#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

int my_gcd(int a, int b)
{
    while(a!=0 && b!=0){
        if(a>b)
            a%=b;
        else 
            b%=a;
    }
    return a+b;
}

void simplify(int &num, int &denom)
{
    int nod=my_gcd(num, denom);
    num/=nod; denom/=nod;
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы
// int main()
// {
    
// }


TEST_CASE("Dulustan's tests GCD"){
    CHECK(my_gcd(12,20)==4);
    CHECK(my_gcd(35,56)==7);
    CHECK(my_gcd(100,9900)==100);
    CHECK(my_gcd(999,2775)==111);   
}

// придумайте хотя бы 5 интересных тестов
TEST_CASE("Student's tests GCD"){
    CHECK(my_gcd(14,49)==7);
    CHECK(my_gcd(1001,385)==77);
    CHECK(my_gcd(1000,1)==1);
    CHECK(my_gcd(485,1067)==97);   
    CHECK(my_gcd(24,16)==8);
}

TEST_CASE("Dulustan's tests Simplify"){
    int a=15, b=20;
    simplify(a,b);
    CHECK(a==3); CHECK(b==4);

    a=48, b=120; 
    simplify(a,b);  
    CHECK(a==2); CHECK(b==5);

    a=1680, b=4620; 
    simplify(a,b);  
    CHECK(a==4); CHECK(b==11);   
}

// придумайте хотя бы 5 интересных тестов
TEST_CASE("Student's tests GCD"){
    int a=7, b=63;
    simplify(a,b);
    CHECK(a==1); CHECK(b==9);

    a=39, b=169; 
    simplify(a,b);  
    CHECK(a==3); CHECK(b==13);

    a=1024, b=4096; 
    simplify(a,b);  
    CHECK(a==1); CHECK(b==4);

    a=20, b=75; 
    simplify(a,b);  
    CHECK(a==4); CHECK(b==15);

    a=1001, b=78; 
    simplify(a,b);  
    CHECK(a==77); CHECK(b==6);
}