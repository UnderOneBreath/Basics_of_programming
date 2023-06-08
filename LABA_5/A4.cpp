#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }
    int k = 0;
    int now;
    int j;
    for(int i = 1; i < n; ++i){
        now = a[i];
        j = i - 1;
        while(j >= 0 && a[j] < now){
            a[j + 1] = a[j];
            j -=1;
            k++;
        }
        a[j+1] = now;
        for(int k = 0; k <= i; k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    cout<<k;
}