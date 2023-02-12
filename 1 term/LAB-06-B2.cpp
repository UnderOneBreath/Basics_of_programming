#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string s)
{
    int a = 0;
    int max = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (tolower(s[i]) == 'a')
            a += 1;
        else
        {
            if (a > max)
                max = a;
            a = 0;
        }
    }
    if (a > max)
        max = a;
    return max;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve("Laa A laaal LOL!") == 3);
    CHECK(solve("Arrrg aa cry aaaaaa yaaaa") == 6);
    CHECK(solve("AXAA AXAAXA AXXAAAXA AAAXAAAAAXAAAA AXAXAXAAXAAXA ") == 5);
}

// минимум 4 теста
// придумайте прикольные строки!
TEST_CASE("Student's tests")
{
    CHECK(solve("AliluAllianceia as ") == 1);
    CHECK(solve("polindrom As sasasasa hahahha AAAAAaahehaehae") == 7);
    CHECK(solve("a a a a a aAAAAA A") == 6);
    CHECK(solve("A") == 1);
}

// main отвечает за ввод-вывод
// int main()
// {

// }
