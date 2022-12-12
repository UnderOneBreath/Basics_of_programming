// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include <iostream>
using namespace std;

int Syracuse(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3 + 1)/2;
        count++;
    }
    return count;
}

// перед unit-тестированием необходимо закомментировать всю функцию main() 
// и раскомментировать первые две строки программы
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        cout << i << "=" << Syracuse(i) << " ";
    }
}


// TEST_CASE("Dulustan's tests"){
//     CHECK(Syracuse(1)==0);
//     CHECK(Syracuse(2)==1);    
// }

// // тут я поленился вычислять тесты, оставляю это дело за вами
// // придумайте хотя бы 12 интересных тестов
// TEST_CASE("Student's tests"){
//     CHECK(Syracuse(5)==4);
//     CHECK(Syracuse(6)==6); 
//     CHECK(Syracuse(7)==11);
//     CHECK(Syracuse(8)==3); 
//     CHECK(Syracuse(9)==13);
//     CHECK(Syracuse(10)==5); 
// }