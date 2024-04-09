#include <iostream>
#include <vector>
using namespace std;

vector<int> con[100001];
bool visited[100001];
int maxDist, maxNode;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > maxDist) {
        maxDist = dist;
        maxNode = node;
    }
    for (int i = 0; i < con[node].size(); i++) {
        int next = con[node][i];
        if (!visited[next]) {
            dfs(next, dist + 1);
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, e, a, b;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    maxDist = -1;
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) visited[i] = false;
    maxDist = -1;
    dfs(maxNode, 0);
    cout << maxDist << endl;
}
