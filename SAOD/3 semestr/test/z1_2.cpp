#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 1000;
vector<int> spis[MAXN];
int visit[MAXN], way[MAXN], queue[MAXN];
int n, m, start, finish, coun;
void Init(){
    int i,j,k;
    cin>>n>>m;
    for (k=1; k<=m; k++) {
        cin>>i>>j;
        spis[i].push_back(j); spis[j].push_back(i);
    }
    cin>>start>>finish;
}
void Print(int v)
{
    if (v>0) {Print(way[v]); cout<<v<<' ';}
}

void Count(int v){
    if(v>0) {Count(way[v]); coun++;}
}

void bfs(int v) {
    int i=1, j, k=1, u;
    queue[k]=v; visit[v]=1;
    do {
    u=queue[i];
    for (j=0; j<spis[u].size(); j++)
    if ( visit[spis[u][j]]==0)
    {
        visit[spis[u][j]]=1; way[spis[u][j]]=u;
        queue[++k]=spis[u][j];
    }
    i++;
    } while (i<=k);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Init();
    bfs(start);
    Count(finish);
    cout<<coun-1<<endl;
    Print(finish);
}