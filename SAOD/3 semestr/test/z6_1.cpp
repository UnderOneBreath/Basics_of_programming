#include <iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> centerFind(vector<vector<int>> g, int n){
    vector<int> d(n+1, 0);
    queue<int> l;
    for (int i = 1; i <= n; i++)
    {
        d[i] = g[i].size();
        if(d[i] <= 1){
            l.push(i);
        }
    }
    int nl = l.size();
    for (int i = n; i > 2; i -= nl)
    {
        nl = l.size();
        for (int j = 0; j < nl; j++)
        {
            int leaf = l.front();
            l.pop();
            for (int i = 0; i < g[leaf].size(); i++)
            {
                int temp = g[leaf][i];
                if(--d[temp] == 1){
                    l.push(temp);
                }
            }
        }
    }
    vector<int> center;
    while(!l.empty()){
        center.insert(center.begin(), l.front());
        l.pop();
    }
    return center;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    int a, b;
    cin>>n>>m;
    vector<vector<int>> g(n + 1);
    vector<int> center;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    center = centerFind(g, n);
    cout<<center.size()<<endl;
    for (size_t i = 0; i < center.size(); i++)
    {
        cout<<center[i]<<" ";
    }
}