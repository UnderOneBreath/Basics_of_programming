#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

fstream inp("input.txt");
ofstream out("output.txt");

int main() {
    
    int N, M;
    inp >> N >> M;
    
    vector<int> X(N);
    vector<vector<int>> myTable;
    vector<int> Y(N - M + 1);

    for (int i = 0; i < N; i++)
        inp >> X[i];
    
    int n = X.size();
    int K = log2(n) + 1;

    myTable.resize(n, vector<int>(K));

    for (int i = 0; i < n; i++)
        myTable[i][0] = X[i];



    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
            myTable[i][j] = min(myTable[i][j-1], myTable[i + (1 << (j-1))][j-1]);
    


    for (int i = 0; i <= N - M; i++) {
        int j = log2((i + M - 1) - i + 1);
        Y[i] = min(myTable[i][j], myTable[(i + M - 1) - (1 << j) + 1][j]);
    }
    
    for (int i = 0; i < Y.size(); i++) {
        out << Y[i];
        if (i != Y.size() - 1)
            out << " ";
    }




}
