#include <iostream>
#include <stdio.h>

using namespace std;

int i, n, m;
int heap[1000001], a[1000000];
void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

void build(int num)
{
    if (num == 1)
    {
        return;
    }
    if (heap[num] > heap[num / 2])
    {
        swap(heap[num], heap[num / 2]);
        build(num / 2);
    }
}

void Rebuild(int i, int n)
{
    int k;
    if (2 * i > n)
        return;
    if (2 * i + 1 > n)
        k = 2 * i;
    else if (heap[2 * i] > heap[2 * i + 1])
        k = 2 * i;
    else
        k = 2 * i + 1;
    if (heap[i] < heap[k])
    {
        swap(heap[i], heap[k]);
        Rebuild(k, n - 1);
    }
}

void piram_sort()
{
    for (int j = n - 1; j >= 0; j--)
    {
        a[n - 1 - j] = heap[1];
        swap(heap[1], heap[j + 1]);
        Rebuild(1, j);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
        heap[i + 1] = a[i];
        build(i + 1);
    }
    piram_sort();
    for (i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
}