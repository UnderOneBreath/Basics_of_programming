#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string input = "input.txt", output = "output.txt";

int main()
{
    ifstream inp(input);
    ofstream out(output);

    int n, W;
    inp >> n >> W;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        inp >> arr[i].first >> arr[i].second;
    }

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= arr[i].first; w--)
        {
            dp[w] = max(dp[w], dp[w - arr[i].first] + arr[i].second);
        }
    }

    out << dp[W] << endl;

    inp.close();
    out.close();
    return 0;
}
