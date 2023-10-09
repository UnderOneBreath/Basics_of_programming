#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(string s)
{
    string temp = "";
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            temp += s[i];
        else
        {
            answer = answer.length() <= temp.length() ? temp : answer;
            temp = "";
        } 
    }
    
    return answer.length() <= temp.length() ? temp : answer;
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve("A jack of all trades is a master of none") == "master");
    CHECK(solve("An idle brain is devils workshop") == "workshop");
    CHECK(solve("Once bitten twice shy") == "bitten");    
    CHECK(solve("The grass is greener on the other side of fence") == "greener");
}

//минимум 4 теста
//придумайте прикольные строки!
TEST_CASE("Student's tests"){
    CHECK(solve("") == "");
    CHECK(solve("Hello World") == "World");
    CHECK(solve("YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEY") == "YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEY");
    CHECK(solve("                          ") == "");
    CHECK(solve("vvvvvvvvvvv fffffffffffff iiiii") == "fffffffffffff");
}

// main отвечает за ввод-вывод
// int main()
// {

// }
