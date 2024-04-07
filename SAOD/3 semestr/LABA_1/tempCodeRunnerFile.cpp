#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>

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
    clock_t t0, t1;

    long *A, n;
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
    bubbleSort(A, n);
    t1 = clock();
    cout << "time =" << 1.0 * (t1 - t0) / CLOCKS_PER_SEC << endl;
}