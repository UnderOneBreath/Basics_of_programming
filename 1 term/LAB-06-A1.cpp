#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(string c)
{
    int a = 0, b = 0, k = 0;
    int sizeC = c.size();
    vector <int> n;
    for (int i = 0; i <= sizeC; i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
            a += 1; 
        else if(c[i] >= 'A' && c[i] <= 'Z')
            b += 1;
        else if(c[i] >= 'a' && c[i] <= 'z')
            k += 1;
    }
    n.push_back(b);
    n.push_back(k);
    n.push_back(a);
    return n;
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve("Wanted Dead or Alive 200000$") == vector <int>{3, 14, 6});
    CHECK(solve("One Piece 1997") == vector <int>{2, 6, 4});
    CHECK(solve("10! is 3628800") == vector <int>{0, 2, 9});    
}

// минимум 4 теста
// придумайте прикольные строки!
TEST_CASE("Student's tests"){
    CHECK(solve("Under World 1") == vector <int>{2, 8, 1});
    CHECK(solve("One million doctors") == vector <int>{1, 16, 0});
    CHECK(solve("12345 12345 HAHHAHA good") == vector <int>{7, 4, 10});
    CHECK(solve("UHAHAHAHhahahhah ahaaaaa NIIIICe 0000099999") == vector <int>{14, 16, 10});
}

// main отвечает за ввод-вывод
// int main()
// {

// }
