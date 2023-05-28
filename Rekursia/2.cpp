#include <iostream>
using namespace std;

void rec_cyc(int n, int a, int c)
{
}

// int main()
// {
//     int n, a;
//     rec_cyc(n - 1, a, a);
//     rec_cyc(n - 1, a, a + 1);
//     rec_cyc(n, a, a + 1);

//     rec_cyc(n - 1, a, a);
//     rec_cyc(n - 1, a, a + 1);
// }

void Hanoi(int n, int a)
{
    if (n == 0)
        return;
    int b = (a >= 3) ? 0 : a + 1;

    Hanoi(n - 1, a);
    Hanoi(n - 1, b);
    int c = 6 - a - b;

    cout << n << ":" << a << "->" << c << endl;

    Hanoi(n - 1, c);
    Hanoi(n - 1, a);
}

int main()
{
    Hanoi(5, 1);
    Hanoi(5, 2);
}