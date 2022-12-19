#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int solve(string s)
{
    int k = 0;
	char a = 'a';
	char A = 'A';
	if (s[0] == A or s[0] == a) {
		k++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' and (s[i + 1] == A or s[i + 1] == a)) {
			k++;
		}
	}
	return k;
}

TEST_CASE("Dulustan's tests"){
    CHECK(solve("Madam, I’m Adam")==1);
    CHECK(solve("An apple is a fruit of all fruits")==4);
    CHECK(solve("i love algorithms and automata do you")==3);    
}

//минимум 4 теста
//придумайте прикольные строки!
TEST_CASE("Student's tests"){
    CHECK(solve("Are you all right?")==2);
    CHECK(solve("AAAAAA aaaaaaaa AAAAA aaaaa AAAAAAAaaaa")== 5);
    CHECK(solve("1234 a ad ad adadadadada")== 4);
    CHECK(solve("Learn to write competent sentences in English")==0);
}

// main отвечает за ввод-вывод
vector<string> Extract(string Text) {
    vector<string> Words;
    stringstream ss(Text);
    string Buf;

    while (ss >> Buf)
        Words.push_back(Buf);

    return Words;
}
// int main()
// {
//     cout << Extract("An apple is a fruit of all fruits");
// }
