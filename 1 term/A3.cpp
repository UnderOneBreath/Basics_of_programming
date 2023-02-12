#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool solve(string s)
{
    string s2 = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z' || isdigit(s[i]))
            s2 += tolower(s[i]);
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] != s2[s2.length() - 1 - i])
            return false;
    }

    return true;
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve("F"));
    CHECK(solve("Madam, I'm Adam"));
    CHECK(solve("Do geese see God?"));
    CHECK(solve("No lemon, no melon"));
    CHECK(solve("Are we not drawn onward, we few, drawn onward to new era?"));  
    CHECK(!solve("Was it cat I saw?"));    
    CHECK(!solve("Borrow or robi"));    
    CHECK(!solve("xyztyx"));  
}

//минимум 2 положительных теста и 2 отрицательных теста
//придумайте прикольные строки!
TEST_CASE("Student's tests"){
    CHECK(solve(""));
    CHECK(solve("123321"));
    CHECK(!solve("1kjk!"));
    CHECK(!solve("kkkk0kkk"));
}

// main отвечает за ввод-вывод
// int main()
// {

// }
