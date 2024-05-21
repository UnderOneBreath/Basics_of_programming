#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;

fstream inp("input.txt");
ofstream out("output.txt");

vector<int> queue;
vector<int> way;
vector<int> visit;
vector<vector<int>> a;

int n, m, k;
int ans = 0;
int b;

void Print(int v)
{
    if (v > 0)
    {
        Print(way[v]);
        b += 1;
    }
}
void bfs(int st)
{
    int i = 1, j, k = 1, u;
    queue[k] = st;
    visit[st] = 1;
    do
    {
        u = queue[i];
        for (j = 1; j <= n; j++)
            if (a[u][j] > 0 && visit[j] == 0)
            {
                visit[j] = 1;
                way[j] = u;
                queue[++k] = j;
            }
        i++;
    } while (i <= k);
}


void Init()
{
    int i, j, k;
    inp >> n >> m;
    memset(way, 0, sizeof(way));
    memset(a, 0, sizeof(a));
    for (k = 1; k <= m; k++)
    {
        inp >> i >> j;
        a[i][j] = 1;
        a[j][i] = 1;
    }
}


int main()
{
    Init();
    vector<int> countAns;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bfs(i);
            Print(j);
            countAns.push_back(b);
            b = 0;
        }
        memset(way, 0, sizeof(way));
        memset(queue, 0, sizeof(queue));
        memset(visit, 0, sizeof(visit));
    }
    out << *max_element(countAns.begin(), countAns.end()) - 1;
}