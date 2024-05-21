# include <iostream>
# include <string>
# include <vector>

using namespace std;

string P,T;
void KMP(const string& S, int b, const string& pattern){
    vector<int> pf (pattern.length());int len;

    pf[0] = 0; len = 0;
    for (int i = 1; i<pattern.length(); ++i){
        while(len>0 && pattern[i] != pattern[len])
            len = pf[len-1];
        if (pattern[i] == pattern[len]) len++;
        pf[i] = len;
    }

    len=0;
    for (int i = b; i<S.length(); ++i){
        while ((len>0) && (pattern[len] != S[i]))
            len=pf[len-1];
        if (pattern[len] == S[i]) len++;
        if (len==pattern.length())

            cout<<(i-pattern.length()+1)<<' ';
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T >> P;
    KMP(T, 0, P);
}