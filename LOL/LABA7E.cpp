#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream inp("input.txt");
ofstream out("output.txt");

// int a[1000][1000], way[1000], visit[1000], queue[1000];
const int maxn = 100000;
bool visit[maxn + 1];

vector<int> a[maxn + 1];

pair<int, int> dfs(int v) {
    visit[v] = true;
    pair<int, int> res = { v, 0 };

    for (int i = 0; i < a[v].size(); ++i) {
        int u = a[v][i];
        if (!visit[u]) {
            pair<int, int> tmp = dfs(u);
            if (tmp.second + 1 > res.second)
                res = { tmp.first, tmp.second + 1 };
        }
    }
    return res;
    // if (!visit[j])
    // {
    //     visit[j] = 1;
    //     way[j] = u;
    //     queue.push_back(j);
    // }
}

int main() {

    int n, m;
    inp >> n >> m;

    for (int k = 0; k < m; k++) {
        int i, j;
        inp >> i >> j;
        a[i].push_back(j);
        a[j].push_back(i);
    }

    fill(visit, visit + n + 1, false);
    pair<int, int> start = dfs(1);

    fill(visit, visit + n + 1, false);
    pair<int, int> end = dfs(start.first);

    out << end.second;

}