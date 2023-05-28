#include <iostream>
using namespace std;

void RecTriangle(int n, int i = 1)
{
    if (i <= n)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << "x";
            }
        }
        cout << endl;
        RecTriangle(n, i + 1);
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << "x";
            }
        }
        cout << endl;
    }
    else
    {
        return;
    }
}

int main()
{
    int n = 4;
    RecTriangle(n);
    return 0;
}