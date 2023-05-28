#include <iostream>
#include <cstdio>

using namespace std;

void hex(int n)
{
    if (n == 0)
    {
        cout << "0x";
        return;
    }
    hex(n / 16);
    int tmp = n % 16;
    if (tmp < 10)
        cout << tmp;
    else
        cout << (char)('A' + (tmp - 10));
}

int main()
{
    int num = 0;
    cin >> num;
    hex(num);

    return 0;
}