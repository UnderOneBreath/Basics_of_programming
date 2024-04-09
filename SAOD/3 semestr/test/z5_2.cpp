#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int diameter=0;
int FNode=0;



void dfs(vector<vector<int>> &graph,vector<bool> &check, int node, int depth) {
    check[node] = true;
    if (depth > diameter) {
        diameter = depth;
        FNode = node;
    }
     for (int i = 0; i < graph[node].size(); ++i) {
        int tmp = graph[node][i];
        if (!check[tmp]) {
            dfs(graph,check,tmp, depth + 1);
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n=0;
    int m=0;
    int u=0;
    int v=0;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> check(n + 1, false);


    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    diameter = -1;
    dfs(adj,check,1, 0);


   check=vector<bool>(n + 1, false);

    diameter = -1;
    dfs(adj,check,FNode, 0);

    cout << diameter << endl;

    return 0;
}