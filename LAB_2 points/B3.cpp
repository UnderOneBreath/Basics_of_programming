
#include <cassert>
#include <iostream>
using namespace std;

int range(int *a, int n)
{
    int min = *a, max = *a;
    int v;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) < min)
            min = *(a + i);
        if (*(a + i) > max)
            max = *(a + i);
    }
    v = max - min;
    return v;
}

int main()
{
    // Dulustan's tests
    {
        {
            int a[7] = {1, 2, 3, 4, 5, 6, 7};
            assert(range(a, 7) == 6);
        }

        {
            int a[8] = {-1, 99, -5, 4, 28, -99, 66, 0};
            assert(range(a, 8) == 198);
        }

        {
            int a[4] = {1000, 1000, 1000, 1000};
            assert(range(a, 4) == 0);
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        {
            int a[0] = {};
            assert(range(a, 0) != 5);
        }

        {
            int a[3] = {-100, 0, 100};
            assert(range(a, 3) == 200);
        }

        {
            int a[4] = {1000, 1000, 1000, 1001};
            assert(range(a, 4) == 1);
        }
        cout << "SUCCESS!" << endl;
    }
}