#define NDEBUG
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

string strmult(char *s, int n)
{
    string snew;
    int len = strlen(s);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < len; i++)
            snew += s[i];
    return snew;
}

int main()
{
    char *s = new char;
    int n = 0;
    cin >> s;
    cin >> n;
    cout << strmult(s, n);
}