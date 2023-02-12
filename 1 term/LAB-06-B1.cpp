#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(string s)
{
    vector<string> a;
    string tempAnswer = "";
    string temp = "";

    int max = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] != ' ' && i != s.size())
            temp += s[i];
        else
        {
            a.push_back(temp);
            temp = "";
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].size() >= max)
        {
            max = a[i].size();
            tempAnswer = a[i];
        }
    }
    return tempAnswer;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve("A jack of all trades is a master of none") == "master");
    CHECK(solve("An idle brain is devils workshop") == "workshop");
    CHECK(solve("Once bitten twice shy") == "bitten");
    CHECK(solve("The grass is greener on the other side of fence") == "greener");
}

// минимум 4 теста
// придумайте прикольные строки!
TEST_CASE("Student's tests")
{
    CHECK(solve("") == "");
    CHECK(solve("Hello World") == "World");
    CHECK(solve("Nice work") == "work");
    CHECK(solve("I see you LOLOL") == "LOLOL");
}

// main отвечает за ввод-вывод
// int main()
// {

// }
