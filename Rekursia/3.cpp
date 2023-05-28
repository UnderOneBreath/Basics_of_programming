#include <iostream>
#include <vector>
using namespace std;

int N;

void rec(int n, string cur)
{
    for (int i = 1; i < n; i++)
    {
        cout << i << "+";
        rec(n - i, to_string(i) + "+" + cur);
    }
    cout << N << " = " << cur + to_string(n) << endl;
}

int main()
{
    int n = 10;
    rec(n, "");
}