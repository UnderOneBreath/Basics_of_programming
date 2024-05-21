#include <iostream>
#include <fstream>

using namespace std;

fstream inp("input.txt");
ofstream out("output.txt");

const int MaxN = 101, Big = 100000;
int i, j, n, Ap, Bp, m, k, d;
int A[MaxN][MaxN], D[MaxN], p[MaxN];
bool Use[MaxN];

void Print(int v)
{
    if (v > 0)
    {
        Print(p[v]);
        out << v << ' ';
    }
}
void Init()
{
    int i, j;
    inp >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = Big;
        D[i] = Big;
    }
    for (k = 1; k <= m; k++)
    {
        inp >> i >> j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
    inp >> Ap >> Bp;
}
void Dejkstra()
{
    int i, j, M;
    D[0] = Big + 1;
    D[1] = 0;
    for (i = 1; i <= n; i++)
    {
        M = 0;
        for (j = 1; j <= n; j++)
            if (D[j] < D[M] && !Use[j])
                M = j;
        Use[M] = true;
        for (j = 1; j <= n; j++)
            if (D[j] > A[M][j] + D[M])
            {
                D[j] = A[M][j] + D[M];
                p[j] = M;
            }
    }
}
int main()
{
    Init();
    Dejkstra();

    if (D[Ap] > D[Bp])
        out << Ap;
    else
        out << Bp;

}