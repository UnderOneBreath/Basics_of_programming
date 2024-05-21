#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, vector<int>> mp;
vector<int> color;
void dfs(int v,int paint){
    if(color[v] != 0)return;
    color[v] = paint;
    for(int i = 0;i<mp[v].size();i++){
        if(color[mp[v][i]]==0){
            dfs(mp[v][i],paint);
        }
    }
    return;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    color.resize(n + 1);
    for(int i = 1;i <= m;i++){
        int x,y;
        cin>>x>>y;
        if(mp[x].push_back(y));
        -
    }
}