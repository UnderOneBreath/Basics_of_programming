#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

long *A;
void Merge(long *A, int p, int q, int r)
{
    long i, k, j;
    long ls = q - p + 1;
    long rs = r - q;
    long *al = new long[ls];
    long *ar = new long[rs];
    for (long s = 0; s < ls; s++)
    {
        al[s] = A[p + s];
    }
    for (long s = 0; s < rs; s++)
    {
        ar[s] = A[q + s + 1];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < ls && j < rs)
    {
        if (al[i] <= ar[j])
        {
            A[k] = al[i];
            i++;
        }
        else
        {
            A[k] = ar[j];
            j++;
        }
        k++;
    }
    while (i < ls)
    {
        A[k] = al[i];
        k++;
        i++;
    }
    while (j < rs)
    {
        A[k] = ar[j];
        k++;
        j++;
    }
    delete[] al;
    delete[] ar;
}

void Sort(long *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        Sort(A, p, q);
        Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    clock_t t0, t1;
    long n, i;
    cin >> n;
    A = new long[n];
    int start = 1;
    int end = 50;
    int x;

    for (int i = 0; i < n; i++)
    {
        x = rand() % (end - start + 1) + start;
        A[i] = x;
    }
    t0 = clock();
    Sort(A, 0, n - 1);
    t1 = clock();
    cout << "time =" << 1.000 * (t1 - t0) / CLOCKS_PER_SEC << endl;
}