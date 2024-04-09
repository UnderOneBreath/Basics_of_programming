#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 1000;
int A[MAXN][MAXN], x[MAXN], y[MAXN], color[MAXN];
int n, m, s; int coun = 0;
void Init(){
    int i,j,k,d;
    cin>>n>>m;
    for (k=1; k<=m; k++) {
    cin>>i>>j>>d;
    A[i][j]=d; A[j][i]=d;
    }
}
void Prima(){
    int i, j, k, z, col1, col2, mind, im, jm;
    for (i = 1; i <= n; i++) color[i] = i;
    z = 0;
    for (k = 1; k < n; k++){
    mind=INT_MAX;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    if( A[i][j] > 0 && color[i] != color[j] && mind > A[i][j] )
    { mind = A[i][j]; im = i; jm = j;}
    z = z + 1;
    x[z] = im; y[z] = jm; s = s + A[im][jm];
    col1 = color[im]; col2 = color[jm];
    for (i = 1; i <= n; i++)
    if (color[i] == col1) color[i] = col2;
    }
}
void print(){
    int i;
    cout << s << endl;
    for(int i = 1; i< n; i++) coun++;
    cout << coun << endl;
    for (i = 1; i < n; i++) cout << x[i] << ' ' << y[i] << endl;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Init(); Prima(); print();
}