#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
using namespace std;

bool perfect(int n)
{
    int s=1;
    for(int i=2; i<n; i++){
        if(n%i==0)
            s+=i;
    }
    return s==n;
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы
/*
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=m; i<=n; i++){
        if(perfect(i))
            cout<<i<<" ";
    }
}
*/

TEST_CASE("Dulustan's tests"){
    CHECK(perfect(6));
    CHECK(perfect(28));
    CHECK(perfect(496));
    CHECK(perfect(8128));
    CHECK(!perfect(36));
    CHECK(!perfect(490));
    CHECK(!perfect(812));
    CHECK(!perfect(6458));
}

// тут свои тесты можно не делать, ура!
