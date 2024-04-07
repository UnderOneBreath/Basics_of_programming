#include <iostream>
#include <stdio.h>

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, i;
    scanf("%ld", &n);
    A = new long[n];
    for (i = 0; i < n; i++)
    {
        scanf("%ld", &A[i]);
    }
    Sort(A, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%ld ", A[i]);
    }
}