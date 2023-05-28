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

void Hanoi(int n, int a, int c)
{
    if (n == 0)
        return;
    int b;
    b = 6 - a - c;
    Hanoi(n - 1, a, b);
    cout << n << ":" << a << "->" << c << endl;
    Hanoi(n - 1, b, c);
}

int main()
{
    Hanoi(10, 1, 3);
}