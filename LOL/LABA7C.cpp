#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct tpedge
{
    int fisrtHub, secondHub, dCabel;
};

vector<tpedge> edge;
vector<int> x, y, color;

int n, m, s = 0, CountOfCabel = 0;

void Init() {
    int i, j, k;
    cin >> n >> m;
    edge.resize(m);
    color.resize(n + 1);
    for (k = 0; k < m; k++)
        cin >> edge[k].fisrtHub >> edge[k].secondHub >> edge[k].dCabel;
}

bool Compare(tpedge p1, tpedge p2) {
    return p1.dCabel < p2.dCabel;
}

void Kruskal() {
    int i, j, k, col1, col2;

    for (i = 1; i <= n; i++)
        color[i] = i;
    sort(edge.begin(), edge.end(), Compare);
    j = 0;
    for (k = 0; k < n - 1; k++)
    {
        for (i = k; i < m; i++)
            if (color[edge[i].fisrtHub] != color[edge[i].secondHub])
            {
                x.push_back(edge[i].fisrtHub);
                y.push_back(edge[i].secondHub);
                s = s + edge[i].dCabel;
                CountOfCabel++;
                break;
            }
        col1 = color[x[k]];
        col2 = color[y[k]];
        for (i = 1; i <= n; i++)
            if (color[i] == col1)
                color[i] = col2;
    }
}

void print() {
    cout << s << endl;
    cout << CountOfCabel << endl;
    for (int i = 0; i < n - 1; i++)
        cout << x[i] << ' ' << y[i] << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Kruskal();
    print();
    return 0;
}