#include <iostream>
#include <cstdlib>

using namespace std;

int comp(const void *i, const void *j)
{
    return *(long *)i - *(long *)j;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long *arr, n;
    scanf("%i", &n);
    arr = new long[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    qsort(arr, n, sizeof(long), comp);

    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
}