#include <iostream>
using namespace std;
const int MaxN = 101, Big = 100000;
int i, j, n, Start, Finish, m, k, d;
int A[MaxN][MaxN], D[MaxN], p[MaxN];
bool Use[MaxN];
void Print(int v)
{
    if (v>0){ Print(p[v]); cout<<v<<' ';}
}
void Init(){
    int i, j;
    cin>>n>>m>>Start>> Finish;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) if (i==j) A[i][j]=0; else
        A[i][j]=Big;
        D[i] = Big;
    }
    for (k=1;k<=m;k++) {
        cin>>i>>j>>d;
        A[i][j]=d; A[j][i]=d;
    }
}
void Dejkstra()
{
    int i,j,M;
    D[0] = Big + 1;
    D[Start] = 0;
    for (i=1;i<=n;i++) {
        M = 0;
        for (j=1; j<=n;j++)
        if (D[j] < D[M] && !Use[j]) M = j;
        Use[M] = true;
        for (j=1;j<=n;j++)
        if (D[j] > A[M][j] + D[M])
        { D[j] = A[M][j] + D[M]; p[j]=M;}
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Init(); Dejkstra();
    if (D[Finish] == Big) cout<<"-1";
    else
    {
        cout<<D[Finish]<<endl; Print(Finish);
    }
}
