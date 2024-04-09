#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> centerFind(vector<vector<int>>& graph, int n) {
    vector<int> deg(n + 1, 0);
    queue<int> leaves;

    for (int i = 1; i <= n; ++i) {
        deg[i] = graph[i].size();
        if (deg[i] <= 1) {
            leaves.push(i);
        }
    }
    int rem = n;
    while (rem> 2) {
        int numl = leaves.size();
        rem -=  numl;
        for (int i = 0; i <  numl; ++i) {
            int leaf = leaves.front();
            leaves.pop();
                for (int i = 0; i < graph[leaf].size(); ++i) {
                    int tmp = graph[leaf][i];
                if (--deg[tmp] == 1) {
                    leaves.push(tmp);
                }
            }
        }
    }
    vector<int> center;
    while (!leaves.empty()) {
        center.insert( center.begin(), leaves.front());
        leaves.pop();
    }
    return center;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n=0;
    int m=0;
    int u=0;
    int v=0;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> center = centerFind(graph, n);
    cout << center.size() << endl;
    for (int i = 0; i < center.size(); ++i) {
        cout << center[i]<< " ";
    }
}


