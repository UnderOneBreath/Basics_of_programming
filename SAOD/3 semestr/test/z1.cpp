#include <iostream>
#include <string.h>
using namespace std;

int queue[100], way[100], visit[100], n, m,
k, a[100][100],coun;
int ans=0, start, finish;

void Print(int v){ 
    if (v>0) {
        Print(way[v]); cout<<v<<' ';
        } 
    }

void countPrint(int v){ 
    if (v>0) {
        countPrint(way[v]); coun++;
        } 
    }

void bfs(int st) {
    int i=1, j, k=1, u;
    queue[k]=st; visit[st]=1;
    do {
        u=queue[i];
        for (j=1; j<=n; j++)
        if (a[u][j]>0 && visit[j]==0)
        {
            visit[j]=1; way[j]=u; queue[++k]=j;
        }
        i++;
} while (i<=k);
}
void Init() {
    int i,j,k;
    cin>>n>>m;
    memset(way,0,sizeof(way));
    memset(a,0,sizeof(a));
    for (k=1; k<=m; k++)
    {
        cin>>i>>j; a[i][j]=1; a[j][i]=1;
    }
        cin>>start>>finish;
}
int main() {
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    Init();
    bfs(start);
    countPrint(finish);
    if(coun == 0){
        cout<<coun<<endl;
    }else{
    cout<<coun-1<<endl;}
    Print(finish);
}