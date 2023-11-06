// #define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

bool is_pal(double *a, int size)
{
    double *beg = a;
    double *end = a + size - 1;

    while (beg < end)
    {
        if (*beg != *end)
            return false;
        *beg++;
        *end--;
    }
    return true;
}

int main()
{
    // Dulustan's tests
    {
        {
            double a[]{1, 2, 3, 2, 1};
            assert(is_pal(a, 5));
        }

        {
            double a[]{1, -2, 3, 4, 999, 4, 3, -2, 1};
            assert(is_pal(a, 9));
        }

        {
            double a[]{1, 2, 3, 3, 1};
            assert(!is_pal(a, 5));
        }

        {
            double a[]{-77, 23, 365, 366, 23, -77};
            assert(!is_pal(a, 6));
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 2 позитивных и 2 негативных теста
    // Student's tests
    {
        {
            double a[]{5, 6, 7, 8, 99, 8, 7, 6, 5};
            assert(is_pal(a, 9));
        }

        {
            double a[]{12, 23, 34, 45, 46, 45, 34, 23, 12};
            assert(is_pal(a, 9));
        }

        {
            double a[]{-1, -2, -3, 5, -3, -2, -1};
            assert(!is_pal(a, 6));
        }

        {
            double a[]{-7, 2, 3, 3, 2, -7};
            assert(!is_pal(a, 6));
        }
        cout << "SUCCESS!" << endl;
    }
}