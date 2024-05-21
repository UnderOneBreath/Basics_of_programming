#include <iostream>
#include <string.h>


using namespace std;


int way[100], visit[100], n, m, k, a[100][100];
int start;
void Print(int v)
{
    if (v > 0)
    {
        Print(way[v]);
        cout << v << ' ';
    }
}
void dfs(int v)
{
    int u;
    visit[v] = 1;
    for (u = 1; u <= n; u++)
        if (a[v][u] > 0 && visit[u] == 0)
        {
            way[u] = v;
            dfs(u);
        }
    Print(v);
    cout << endl;
    visit[v] = 0;
}
void Init()
{
    int i, j, k;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    memset(way, 0, sizeof(way));
    memset(visit, 0, sizeof(visit));
    memset(a, 0, sizeof(a));
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        a[i][j] = 1;
        a[j][i] = 1;
    }
    cin >> start;
}
int main()
{
    Init();
    dfs(start);
}