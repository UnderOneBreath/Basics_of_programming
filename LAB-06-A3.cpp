#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

bool solve(string s)
{
    
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve("F"));
    CHECK(solve("Madam, I’m Adam"));
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
        
}

// main отвечает за ввод-вывод
// int main()
// {

// }
