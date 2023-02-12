#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> solve(vector<int> v)
{
    vector<int> answer{};
    for (int i = 0; i < v.size(); i++)
    {
        if (is_prime(v[i]))
            answer.push_back(i);
    }

    return answer;
}

TEST_CASE("Dulustan's tests")
{
    CHECK(solve({1, 2, 3, 4, 5, 6, 7, 8, 9}) == vector<int>{1, 2, 4, 6});
    CHECK(solve({1, 2, 4, 8, 16, 32, 64}) == vector<int>{1});
    CHECK(solve({11, 13, 21, 23, 31, 33, 41, 43, 51, 53, 61, 63}) == vector<int>{0, 1, 3, 4, 6, 7, 9, 10});
    CHECK(solve({183, 177, 179, 147, 149, 143, 107}) == vector<int>{2, 4, 6});
}

// минимум 4 теста
TEST_CASE("Student's tests")
{
    CHECK(solve({1, 3, 9, 27, 81, 243}) == vector<int>{1});
    CHECK(solve({0, 0, 0, 0, 0, 0}) == vector<int>{});
    CHECK(solve({12, 57, 32, 98, 101, 348, 34, 43, 13}) == vector<int>{4, 7, 8});
    CHECK(solve({2022, 1033, 2389, 2222, 3333, 7993}) == vector<int>{1, 2, 5});
}

// main отвечает за ввод-вывод
// int main()
// {

// }
