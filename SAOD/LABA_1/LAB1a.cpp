#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(long *A, long n)
{
    int temp, Tf;
    for (int i = 1; i < n; i++)
    {
        Tf = 1;
        for (int j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                Tf = 0;
            }
        }
        if (Tf == 1)
            break;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long *A, n;
    scanf("%ld", &n);
    A = new long[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &A[i]);
    }

    bubbleSort(A, n);

    for (int i = 0; i < n; i++)
    {
        printf("%ld ", A[i]);
    }
}