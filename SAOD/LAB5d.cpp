#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
string input = "LAB5d/input.txt", output = "LAB5d/output.txt";

int main() {
    fstream inp(input);
    ofstream out(output);

    string N;
    getline(inp, N);
    


    vector<int> A(N), B(N), C(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> dp(N, INT_MAX);
    dp[0] = A[0];

    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + A[i]; // один человек покупает билет
        if (i > 0) {
            dp[i] = min(dp[i], dp[i - 2] + B[i]); // два человека покупают билеты
        }
        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 3] + C[i]); // три человека покупают билеты
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}