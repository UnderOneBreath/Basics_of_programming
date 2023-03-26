#define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

double sort3(double *a, double *b, double *c)
{
    if (*a > *b)
        swap(*a, *b);
    if (*b > *c)
        swap(*b, *c);
    if (*a > *b)
        swap(*a, *b);
}

int main()
{
    int *p;
    int x = 100;
    p = &x;
    cout << *p;

    // Dulustan's tests
    {
        {
            double a = 1, b = 2, c = 3;
            sort3(&a, &b, &c);
            assert(a == 1 && b == 2 && c == 3);
        }

        {
            double a = -1, b = -2, c = -3;
            sort3(&a, &b, &c);
            assert(a == -3 && b == -2 && c == -1);
        }

        {
            double a = 100, b = -10000, c = 3.14;
            sort3(&a, &b, &c);
            assert(a == -10000 && b == 3.14 && c == 100);
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        {
            double a = 42, b = 50, c = 46;
            sort3(&a, &b, &c);
            assert(a == 42 && b == 46 && c == 50);
        }

        {
            double a = 87, b = 76, c = 46;
            sort3(&a, &b, &c);
            assert(a == 46 && b == 76 && c == 87);
        }

        {
            double a = 2, b = 5, c = 6;
            sort3(&a, &b, &c);
            assert(a == 2 && b == 5 && c == 6);
        }
        cout << "SUCCESS!" << endl;
    }
}