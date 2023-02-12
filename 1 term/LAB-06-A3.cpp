#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool solve(string s)
{
    string StringFull = "";
    int k = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) || (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z'))
        {
            StringFull += tolower(s[i]);
        }
    }
    cout << StringFull << endl;
    for (int i = 0; i < StringFull.length(); i++)
    {
        if (StringFull[StringFull.length() - i - 1] != StringFull[i])
            return false;
    }

    return true;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve("F"));
    CHECK(solve("Madam, I'm Adam"));
    CHECK(solve("Do geese see God?"));
    CHECK(solve("No lemon, no melon"));
    CHECK(solve("Are we not drawn onward, we few, drawn onward to new era?"));
    CHECK(!solve("Was it cat I saw?"));
    CHECK(!solve("Borrow or robi"));
    CHECK(!solve("xyztyx"));
}

// минимум 2 положительных теста и 2 отрицательных теста
// придумайте прикольные строки!
TEST_CASE("Student's tests")
{
    CHECK(solve("12345654321"));
    CHECK(solve("Run to Run and nan ur ot NUR"));
    CHECK(solve("Racecar"));
    CHECK(!solve("Fgfg"));
    CHECK(!solve("Human is not god"));
}

// main отвечает за ввод-вывод
// int main()
// {

// }
