#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

ifstream inp("input.txt");
ofstream out("output.txt");

int main() {
    
    int N, K;
    int inversAns;

    inp >> N >> K;
    
    int n = ceil(sqrt(N));

    vector<int> b;
    vector<int> a;
    b.resize(n);
    a.resize(N * K + 1);
    fill(b.begin(), b.end(), 0);
    fill(a.begin(), a.end(), 0);


    for (int i = 0; i < K; i++) {
        int res = 0;
        vector<int> arr(N);

        for (int j = 0; j < N; j++)
            inp >> arr[j];
        
        for (int j = 0; j < N; j++) {
            int bin = arr[j] - 1;
            a[bin] = 1;
            b[bin / n] += 1;
            
            for (int k = (bin / n) + 1; k < n; k++)
                res += b[k];
            for (int k = bin + 1; k / n == bin / n; k++)
                res += a[k];
            
        }
        
        inversAns += res;

        fill(b.begin(), b.end(), 0);
        fill(a.begin(), a.end(), 0);
    }

    out << inversAns;

}
