#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> A)
{
    int a = 0, b = 0, count = 0;
    for (int i = 1; i < A.size(); i++)
    {
        a = A[i - 1];
        b = A[i];
        if (b > a)
        {
            // cout << A[i] << " " << A[i+1] << endl;
            count += 1;
        }
    }
    return count;
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve({100000}) == 0);
    CHECK(solve({1,4,7,100}) == 3);
    CHECK(solve({-100,99,88,55}) == 1);
    CHECK(solve({1,-2,3,-4,5,-6,7,-7,8,-8,9,-9}) == 5);
}

//минимум 4 теста
TEST_CASE("Student's tests"){
    CHECK(solve({-100, -99, 0}) == 2);
    CHECK(solve({8,9,1,1}) == 1);
    CHECK(solve({0, 1, 2, -1}) == 2);
    CHECK(solve({1, 2, -2, 4, 5, 6}) == 4);
}

// main отвечает за ввод-вывод
// int main()
// {
//     cout << solve({1,-2,3,-4,5,-6,7,-7,8,-8,9,-9});
// }
