#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<"Bubble Sort:"<<endl;
    int k = 0;
    for(int t = n-1; t >= 1; t--){
        bool sorted = true;
    for(int i = n-1; i>0; i--){
        if(v[i-1] > v[i]){
            swap(v[i-1],v[i]);
            sorted = false;
            for(int j = 0; j<n; j++){
            cout<<v[j]<<" ";
        }
        k++;
        cout<<endl;
        }
    }
    if(sorted){
        break;
    }
    }
    cout<<k;
}