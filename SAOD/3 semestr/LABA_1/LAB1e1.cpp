#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>

using namespace std;

int comp(const void *i, const void *j)
{
    return *(long *)i - *(long *)j;
}

int main()
{
    clock_t t0, t1;

    long *arr, n;
    cin >> n;
    arr = new long[n];

    int start = 1;
    int end = 50;
    int x;

    for (int i = 0; i < n; i++)
    {
        x = rand() % (end - start + 1) + start;
        arr[i] = x;
    }
    t0 = clock();
    qsort(arr, n, sizeof(long), comp);

    t1 = clock();
    cout << "time =" << 1.000 * (t1 - t0) / CLOCKS_PER_SEC << endl;
}